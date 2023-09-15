#include"storage_manager.h"

// storage_manager::storage_manager(){
//     db_path = "./db/db.txt";
// }

std::string storage_manager::get_db_path(){
    std::string homedir(getpwuid(getuid())->pw_dir);
    return homedir+"/.nxnenv/.acm";
}