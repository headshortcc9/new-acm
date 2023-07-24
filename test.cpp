#include<iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <unordered_set>

using namespace std;

void vectorRemoveDuplicateItem(std::vector<string> &v)
{
    std::vector<string>::iterator itr = v.begin();
    std::unordered_set<string> s;
 
    for (auto curr = v.begin(); curr != v.end(); ++curr)
    {
        if (s.insert(*curr).second) {
            *itr++ = *curr;
        }
    }
 
    v.erase(itr, v.end());
}

void print(std::vector<string> &input)
{ 
    vectorRemoveDuplicateItem(input);  
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}


void printRecommend(std::vector<string> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

void outputProgress(vector<string> items){
  if(items.size() == 3){
    cout<<"Token: "<<items[2]<<endl;
  }
  else if(items.size() == 4){
    cout<<"Username: "<<items[2]<<endl;
    cout<<"Password: "<<items[3]<<endl;
  }
}
bool identifier_match(string key,string pat) {
  string pattern =  ".*"+pat+".*";
  if (regex_match (key, regex(pattern))) return true;
  else return false;
}
void read_file(string group, string acc) {
    ifstream MyReadFile("db/db.txt");
    string s;
    string identifier = "stg";
    try
    {
      vector<string> gRecommends;
      vector<string> accRecommends;
      vector<string> fullAcc;
      while (getline (MyReadFile, s)) 
      { 
        size_t pos = 0;
        std::string token;
        pos = s.find(":");
        if(s[s.length()-1] != ':' || s[0] == ':') throw 101;
        string g1 = s.substr(0, pos);
        if(identifier_match(g1,group)){
          if(g1 == group){
            gRecommends.clear();
            gRecommends.push_back("#");
            vector <string> items;
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

      //Checking Group
      if(gRecommends.size() == 0) throw 102;
      else{
        if(gRecommends[0] != "#"){
            cout<<"Group Recommend"<<endl;
            print(gRecommends);
        }else{
          if(accRecommends.size() == 0 ){
            cout<<"Show full account"<<endl;
            print(fullAcc);
          }else{
            if(gRecommends[0] != "#"){
              cout<<"Account Recommend"<<endl;
              print(accRecommends);
            }
          }

        }
      }


    }
    catch(int e){
        cout<<e<<endl;
    }
      //cout << myText << endl;
}
int main(int argc, char** argv){
  read_file(argv[1],argv[2]);
  //cout<<identifier_match("argo","ar");
  return 0;
}