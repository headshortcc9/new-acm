#include"authenticator.h"

authenticator::authenticator(){

}

authenticator::~authenticator(){

}
void authenticator::get_authenticator(std::string group, std::string acc) {
    std::ifstream MyReadFile(storage_manager::get_db_path());
    std::string s;
    try
    {
      std::vector<std::string> gRecommends;
      std::vector<std::string> accRecommends;
      std::vector<std::string> fullAcc;
      while (getline (MyReadFile, s)) 
      { 
        size_t pos = 0;
        std::string token;
        pos = s.find(":");
        if(s[s.length()-1] != ':' || s[0] == ':') throw 101;
        std::string g1 = s.substr(0, pos);
        if(identifier_match(g1,group)){
            if(g1 == group){
                gRecommends.clear();
                gRecommends.push_back("#");
                std::vector <std::string> items;
                while ((pos = s.find(":")) != std::string::npos) {
                items.push_back(s.substr(0, pos));
                s.erase(0, pos + 1);
                }
                if(identifier_match(items[1],acc)){
                if(items[1] == acc){
                    accRecommends.clear();
                    accRecommends.push_back("#");
                    if(items.size() < 2 || items.size() > 4){
                    throw 103;
                    }
                    else{
                    outputProgress(items);
                    break;
                    }
                }
                else{
                    accRecommends.push_back(items[1]);
                }
                }else{
                fullAcc.push_back(items[1]);
                }
            }
            else{
                gRecommends.push_back(g1);
            }
        }
      }
    MyReadFile.close();
      //Checking Group
      if(gRecommends.size() == 0) throw 102;
      else{
        if(gRecommends[0] != "#"){
            std::cout<<"Group Recommend"<<std::endl;
            printRecommend(gRecommends);
        }else{
          if(accRecommends.size() == 0 ){
            std::cout<<"Show full account"<<std::endl;
            printRecommend(fullAcc);
          }else{
            if(gRecommends[0] != "#"){
              std::cout<<"Account Recommend"<<std::endl;
              printRecommend(accRecommends);
            }
          }

        }
      }
    }
    catch(int e){
        std::cout<<e<<std::endl;
    }    //cout << myText << endl;
}


bool authenticator::identifier_match(std::string key,std::string pat) {
  std::string pattern =  ".*"+pat+".*";
  if (std::regex_match (key, std::regex(pattern))) return true;
  else return false;
}

void authenticator::outputProgress(std::vector<std::string> items){
  if(items.size() == 3){
    std::cout<<"Token: "<<items[2]<<std::endl;
  }
  else if(items.size() == 4){
    std::cout<<"Username: "<<items[2]<<std::endl;
    std::cout<<"Password: "<<items[3]<<std::endl;
  }
}

void authenticator::printRecommend(std::vector<std::string> const &input)
{
    std::cout<<"Did you mean ?"<<std::endl;
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}