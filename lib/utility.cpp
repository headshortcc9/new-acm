#include "utility.h"

vector <string> stringSplit(string s,string delimiter){
  vector <string> rs;
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
      token = s.substr(0, pos);
      rs.push_back(token);
      s.erase(0, pos + delimiter.length());
  }
  return rs;
}

void print_vector(std::vector<string> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

bool search(string key,string line){
  string expr = "(.*)"+key+"(.*)";
    regex pattern(expr);
    smatch matches;
    if (regex_match(line, matches,pattern)) {
        auto it = matches.begin();
        return true;
    }
    return false;
}