#include"authenticator.h"

authenticator::authenticator(int om){
  output_mode=om;
}

authenticator::~authenticator(){

}
void authenticator::get_authenticator(std::string group, std::string acc) {
    try
    {
      std::ifstream MyReadFile(storage_manager::get_db_path());
      std::string s;
      std::vector<std::string> gRecommends;
      std::vector<std::string> accRecommends;
      std::vector<std::string> fullAcc;
      std::vector<std::string> fullGroup;
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
          }else{
            fullGroup.push_back(g1);
          }
        
      }
      MyReadFile.close();
      //Checking Group
      if(gRecommends.size() == 0) {
         if(group == "#"){
          std::cout<<"All group: "<<std::endl;
          vectorRemoveDuplicateItem(fullGroup);
          printRecommend(fullGroup);
         }else{
          std::cout<<"Could not found group "<<group<<std::endl;
         }
      }
      else{
        if(gRecommends[0] != "#"){
          vectorRemoveDuplicateItem(gRecommends);
            if(gRecommends.size() == 1){
              get_authenticator(gRecommends[0],acc);
            }else{
              std::cout<<"Could not found group, ";
              printRecommend(gRecommends);
            }
        }else{
          if(accRecommends.size() == 0 ){
            printRecommend(fullAcc);
          }else{
            if(accRecommends[0] != "#"){
              if(accRecommends.size() == 1){
                get_authenticator(group,accRecommends[0]);
              }else{
                std::cout<<"Could not found account, "<<std::endl;
                printRecommend(accRecommends);
              }
            }
          }
        }
      }
    }
    catch(int e){
        std::cout<<"Error: "<<e<<std::endl;
    }    //cout << myText << endl;
}


bool authenticator::identifier_match(std::string key,std::string pat) {
  std::string pattern =  ".*"+pat+".*";
  if (std::regex_match (key, std::regex(pattern))) return true;
  else return false;
}

void authenticator::outputProgress(std::vector<std::string> items){
  
  if(items.size() == 3){
    if(output_mode == 1){
      std::cout<<"Your token: "<<std::endl<<items[2]<<std::endl;
    }else{
      std::cout<<"Token has been copied !"<<std::endl;
      clip::set_text(items[2]);
    }
  }
  else if(items.size() == 4){
    std::cout<<"Username: "<<items[2]<<std::endl;
    if(output_mode == 1){
      std::cout<<"Password: "<<items[3]<<std::endl;
    }else{
      clip::set_text(items[3]);
    }
  }
}

void authenticator::vectorRemoveDuplicateItem(std::vector<std::string> &v)
{
    std::vector<std::string>::iterator itr = v.begin();
    std::unordered_set<std::string> s;
 
    for (auto curr = v.begin(); curr != v.end(); ++curr)
    {
        if (s.insert(*curr).second) {
            *itr++ = *curr;
        }
    }
 
    v.erase(itr, v.end());
}

void authenticator::printRecommend(std::vector<std::string> &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

void authenticator::setOutputMode(int om){
  output_mode=om;
}