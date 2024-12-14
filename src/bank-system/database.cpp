#include "../../headers/bank-system/database.h"
#include "../../headers/graphic/graphics.h"
#include <iostream>
#include <string>
#include <filesystem>

using namespace std;
std::filesystem::path users_data = std::filesystem::path("database") / "user_data.txt";
std::filesystem::path temp_data = std::filesystem::path("database") / "temp_data.txt";
std::filesystem::path admin_data = std::filesystem::path("database") / "admin_data.txt";

Database::Database() {
    loadUsersFromFile();
    loadManagersFromFile();
}

void Database::saveUsersToFile() {
    ofstream userFile(users_data);

    for (const auto &user : users) {
        userFile << user.first << " " << user.second.first << " " << user.second.second << endl;
    }
    userFile.close();
}

bool Database::loadUsersFromFile() {
    ifstream userFile(users_data);
    if (!userFile) {
        return false;
    }

    string line;
    while (getline(userFile, line)) {
        istringstream iss(line);
        string username, password;
        if (iss >> username >> password) {
            users[username].first = password;
        }
    }

    userFile.close();
    return true;
}

bool Database::loadManagersFromFile() {
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

void Database::createUser(const string &username, const string &password) {
    users[username] = make_pair(password, 0.0);
    saveUsersToFile();
    cout << "User created successfully." << endl;
    delay_time(2);
}

void Database::deleteUser(const string &username) {
    users.erase(username);
}

bool Database::login() {
    string username, password;
    cout << BLUE+"Enter username: "+CYAN;
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Enter password: ";
        cin >> password;

        if (users[username].first == password) {
            return true;
        }
    }
    cout << "Incorrect username or password. Try again." << endl;
    return false;
}
