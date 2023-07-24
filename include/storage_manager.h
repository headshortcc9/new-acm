#include <fstream>
#include <iostream>
class storage_manager
{
private:
    std::string db_path;

public:
    storage_manager(/* args */);
    ~storage_manager();
    std::string get_db_path();
};

