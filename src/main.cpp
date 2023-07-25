#include"authenticator.h"
using namespace std;

void usage(){
  cout<<"usage"<<endl;
}

int ProcessCommandLine(int argc, const char* argv[]) {
  // if (argc < 2) {
  //   usage();
  //   return -1;
  // }
  int accuracy = 2;
  bool overwrite = false;

  // Regular expression matching --parameter=value.
  // Example: --input=my_file.txt
  // myprogram --input=my_file.txt --timeout=5
  // myprogram --timeout=5 --input=my_file.txt


  regex long_pattern("--(.*)=(.*)");
  regex short_pattern("-(.*)");

  // Iterate each element of argc
  try {
    for (size_t i = 1; i < argc; i++) {
      std::string param_to_search = argv[i];
      std::smatch matches;
      if (std::regex_match(param_to_search, matches, short_pattern)) {
        auto it = matches.begin();
        // The first match because it's the entire string.
        cout<<*it<<endl;
        it++;
      }
        // The second match is the parameter name.
        // if ((*it) == "input") {
        //   // The third match is the parameter value.
        //   it++;
        //   input = *it;
        //   continue;
        // }

      //   // The second match is the parameter name.
      //   if ((*it) == "from") {
      //     // The third match is the parameter value
      //     it++;
      //     from = *it;
      //     continue;
      //   }

      //   if ((*it) == "accuracy") {
      //     it++;
      //     accuracy = std::stoi(*it);
      //     continue;
      //   }

      //   if ((*it) == "overwrite") {
      //     it++;
      //     std::istringstream((*it)) >> std::boolalpha >> overwrite;
      //     continue;
      //   }

      //   usage();
      //   return -1;

      // } else {
      //   usage();
      //   return -1;
      // }
    }
  } catch (const std::exception& e) {
    std::cout << "Exception!" << std::endl;
    usage();
    return -1;
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