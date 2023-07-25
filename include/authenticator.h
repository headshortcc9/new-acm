#include"storage_manager.h"
#include<vector>
#include <fstream>
#include<regex>
class authenticator
{
private:
    /* data */
public:
    authenticator();
    ~authenticator();
    void vectorRemoveDuplicateItem(std::vector<std::string> &v);
    void print_recommend(std::vector<std::string> reds);
    void get_authenticator(std::string group, std::string acc);
    bool identifier_match(std::string key,std::string pat);
    void outputProgress(std::vector<std::string> items);
    void printRecommend(std::vector<std::string> const &input);
};

