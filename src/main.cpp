#include"authenticator.h"
#include<map>
using namespace std;

void usage(){
  cout<<"usage"<<endl;
}

int ProcessCommandLine(int argc, const char* argv[]) {

  regex long_pattern("--(.*)=(.*)");
  regex short_pattern("-(.*)");
  regex search_key_pattern("[a-z].*");

  // Iterate each element of argc
  try {
    vector<string> searchs;
    for (size_t i = 1; i < argc; i++) {
      std::string param_to_search = argv[i];
      std::smatch matches;
        //set short option
      if (std::regex_match(param_to_search, matches, short_pattern)) {
        auto it = matches.begin();
        // The first match because it's the entire string.
        if (*it == "-d"){
          cout<<*it<<endl;
        }else if(*it == "-a"){
          searchs.push_back("#");
        }
        else{
          throw 101;
        }
        it++;
      }
      //detect account
      if (std::regex_match(param_to_search, matches, search_key_pattern)) {
          auto it = matches.begin();
          searchs.push_back(*it);
          it++;
      }
    }

    if(searchs.size() == 1){
      authenticator au(1);
      au.get_authenticator(searchs[0],"#");
    }else if(searchs.size() == 2){
      authenticator au(1);
      au.get_authenticator(searchs[0],searchs[1]);
    }
    else{
      cout<<"show usage !"<<endl;
    }
  } 
  catch(int e){
      cout<<"exception "<<e<<endl;
  }
    return 0;
}

int main(int argc, const char** argv){
  
  //cout<<storage_manager::get_db_path()<<endl;
  //authenticator sm;
  //sm.get_authenticator("argo","ar");  
  //cout<<identifier_match("argo","ar");
  ProcessCommandLine(argc,argv);
  return 0;
}