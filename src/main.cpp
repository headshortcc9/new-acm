#include"authenticator.h"
#include "config.h"
#include<map>
#define VERSION "@PROJECT_VERSION@"
using namespace std;
int dm = 2;
void usage(){
  cout<<"Usage: acm [OPTION...] [GROUP] [ACCOUNT_ID]"<<endl<<endl;
  cout<<"  -a    Show all group."<<endl;
  cout<<"  -d    Display password/token instead of copying to clipboard."<<endl;
  cout<<"  -h    Usage."<<endl;
  cout<<"  --get-storage    Get path of storage file."<<endl;
  cout<<"Report bugs to nghianx.t94@gmail.com"<<endl;
}

int ProcessCommandLine(int argc, const char* argv[]) {

  regex long_pattern("--(.*)");
  regex short_pattern("-([a-z]*)");
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
          dm=1;
        }else if(*it == "-a"){
          searchs.push_back("#");
        }else if(*it == "-e"){
          string cmd = "vim "+storage_manager::get_db_path();
          system(cmd.c_str());
          return 1;
        }else if(*it == "-h"){
          usage();
          return 1;
        }else if(*it == "-v"){
          cout<<"Account Manager version "<<PROJECT_VER<<endl;
          return 1;
        }
        else{
          throw 403;
        }
        it++;
      }
      //
      if (std::regex_match(param_to_search, matches, long_pattern)) {
        auto it = matches.begin();
        // The first match because it's the entire string.
        if (*it == "--get-storage"){
          cout<<storage_manager::get_db_path()<<endl;
          return 1;
        }
        else{
          throw 404;
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
      authenticator au(dm);
      au.get_authenticator(searchs[0],"#");
    }else if(searchs.size() == 2){
      authenticator au(dm);
      au.get_authenticator(searchs[0],searchs[1]);
    }
    else{
      usage();
    }
  } 
  catch(int e){
      cout<<"exception "<<e<<endl;
  }
    return 0;
}

int main(int argc, const char** argv){
  ProcessCommandLine(argc,argv);
  return 0;
}