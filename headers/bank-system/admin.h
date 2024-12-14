#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

class BankManager {
public:
    BankManager();
    bool login();
    bool loadManagersFromFile();

private:
    std::unordered_map<std::string, std::string> managers;
};

#endif
