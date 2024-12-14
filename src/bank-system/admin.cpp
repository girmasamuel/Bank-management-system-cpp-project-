#include "../../headers/graphic/graphics.h"
#include "../../headers/bank-system/admin.h"
#include "../../headers/bank-system/database.h"
#include <string>

using namespace std;

BankManager::BankManager() {
    loadManagersFromFile();
}

bool BankManager::login() {
string username, password;
        cout << BLUE+"Enter admin username: ";
        cin >> username;
        if (managers.find(username) != managers.end()) {
            cout << "Enter password: ";
            cin >> password;

            if (managers[username] == password) {
                return true;
            }
        }
        cout << "Incorrect login. Please try again. " << endl;
        return false;
}

bool BankManager::loadManagersFromFile() {
    ifstream managerFile(admin_data);
    if (!managerFile) {
        return false;
    }

    string line;
    while (getline(managerFile, line)) {
        istringstream iss(line);
        string username, password;
        if (iss >> username >> password) {
            managers[username] = password;
        }
    }
    managerFile.close();
    return true;
}
