#include"storage_manager.h"
#include<vector>
#include <fstream>
#include<regex>
#include <unordered_set>
#include "clip.h"
class authenticator
{
private:
    /* data */
    int output_mode;
    /*
        1. show full
        2. copy to clipboard
    */
public:
    authenticator(int output_mode);
    ~authenticator();
    void setOutputMode(int om);
    void vectorRemoveDuplicateItem(std::vector<std::string> &v);
    void get_authenticator(std::string group, std::string acc);
    bool identifier_match(std::string key,std::string pat);
    void outputProgress(std::vector<std::string> items);
    void printRecommend(std::vector<std::string> &input, int type);
};

