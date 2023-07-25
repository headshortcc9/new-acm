#include <iostream>
class storage_manager
{
private:
    static std::string db_path;

public:
    storage_manager(/* args */);
    ~storage_manager();
    static std::string get_db_path();
};

