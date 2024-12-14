/*
<--Description -->BMS => bank management system
For BMS users and their banking data to be stored,
we will define a database class that takes care of all operations involving 
        saving and loading data from a file, 
        user login, and the creation and deletion of users. 
Our file users.txt will store all users who have opened an account and their corresponding password. 
Because their login data will be saved in the system,they can log back in at any time:

*/

#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <sstream>
#include <unordered_map>
#include <filesystem>
using namespace std;

//databeses address
extern std::filesystem::path users_data;
extern std::filesystem::path temp_data;
extern std::filesystem::path admin_data;

class Database {
public:
    Database();//constructor

    void saveUsersToFile();
    bool loadUsersFromFile();
    bool loadManagersFromFile();
    void createUser(const string &username, const string &password);
    void deleteUser(const string &username);
    bool login();

private:
    unordered_map<string, pair<string, double>> users;
    unordered_map<string, string> managers;
};

#endif 
