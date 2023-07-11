#include<iostream>
#include <fstream>
#include <vector>

using namespace std;

void print(std::vector<string> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}
void read_file() {
    ifstream MyReadFile("db/db.txt");
    string s;
    string group = "argo";
    string identifier = "stg";
    try
    {
      int status = 0;
      while (getline (MyReadFile, s)) 
      {
        size_t pos = 0;
        std::string token;
        pos = s.find(":");
        if(s[s.length()-1] != ':' || s[0] == ':') throw 101;
        if(s.substr(0, pos) == group){
          vector <string> items;
          while ((pos = s.find(":")) != std::string::npos) {
            items.push_back(s.substr(0, pos));
            s.erase(0, pos + 1);
          }
          if(items[1] == identifier){
            if(items.size() < 2 || items.size() > 4){
              throw 103;
            }
            else{
              if(items.size() == 3){
                cout<<"Token: "<<items[2]<<endl;
              }
              else if(items.size() == 4){
                cout<<"Username: "<<items[2]<<endl;
                cout<<"Password: "<<items[3]<<endl;
              }
            }
            break;
          }
          status++;
          cout<<endl;
        }
      }
      if(status == 0) throw 102;
    }
    catch(int e){
        cout<<e<<endl;
    }
      //cout << myText << endl;
}
int main(){
  read_file();
  return 0;
}