// program named mainreturn.cpp
#include <iostream>
#include <regex>
#include "lib/usage.h"
using namespace std;


int ProcessCommandLine(int argc, const char* argv[]) {
  if (argc < 2) {
    usage();
    return -1;
  }

  std::string input = "default_file.txt";
  std::string from = "japanese";
  int accuracy = 2;
  bool overwrite = false;

  // Regular expression matching --parameter=value.
  // Example: --input=my_file.txt
  // myprogram --input=my_file.txt --timeout=5
  // myprogram --timeout=5 --input=my_file.txt


  regex pattern("--(.*)=(.*)");

  // Iterate each element of argc
  try {
    for (size_t i = 1; i < argc; i++) {
      std::string param_to_search = argv[i];
      std::smatch matches;
      if (std::regex_match(param_to_search, matches, pattern)) {
        auto it = matches.begin();
        // The first match because it's the entire string.
        it++;

        // The second match is the parameter name.
        if ((*it) == "input") {
          // The third match is the parameter value.
          it++;
          input = *it;
          continue;
        }

        // The second match is the parameter name.
        if ((*it) == "from") {
          // The third match is the parameter value
          it++;
          from = *it;
          continue;
        }

        if ((*it) == "accuracy") {
          it++;
          accuracy = std::stoi(*it);
          continue;
        }

        if ((*it) == "overwrite") {
          it++;
          std::istringstream((*it)) >> std::boolalpha >> overwrite;
          continue;
        }

        usage();
        return -1;

      } else {
        usage();
        return -1;
      }
    }
  } catch (const std::exception& e) {
    std::cout << "Exception!" << std::endl;
    usage();
    return -1;
  }
  std::cout << "input: " << input << std::endl;
  std::cout << "from: " << from << std::endl;
  std::cout << "accuracy: " << accuracy << std::endl;
  std::cout << "overwrite: " << std::boolalpha << overwrite << std::endl;

  return 0;
}
int main() {
  const char* argv[] = {"test", "--input=my_file.txt", "--from=Japanese",
                        "--accuracy=a", "--overwrite=true"};
    const char* argv[] = {"test", "--input=my_file.txt", "--from=Japanese",
                        "--accuracy=a", "--overwrite=true"};
  return ProcessCommandLine(5, argv);
}
