#include "../../headers/bank-system/bank_account.h"
#include "../../headers/graphic/graphics.h"
#include <filesystem>
std::filesystem::path updated_data = std::filesystem::path("database") / "user_data.txt";


BankAccount::BankAccount(const std::string &username, Database &db) : username(username), open(true), balance(0), database(db) {
    // Read account balance from file users.txt
    std::ifstream file(users_data);
    std::string line;
    while(std::getline(file, line)) {
        std::istringstream iss(line);
        std::string storedUsername, storedPassword;
        double storedBalance;
        if (iss >> storedUsername >> storedPassword >> storedBalance) {
            if (storedUsername == username) {
                balance = storedBalance;
                break;
            }
        }
    }
}

void BankAccount::Withdraw(double amount) {
    if (open && amount <= balance && amount > 0) {
            balance -= amount;
            transactions.emplace_back("Withdrawal", amount);
            clear_console();
            cout << "Successfully withdrew $" << amount << " from your account." << endl;
            cout << "Your new balance is: " << balance << endl;
            updateBalanceInFile();
    } else {
        cout << "Invalid amount provided or account is deactivated. Contact support for further assistance. " << endl;
    }
}

void BankAccount::Deposit(double amount) {
    if (open && amount > 0) {
            balance += amount;
            transactions.emplace_back("Deposit", amount);
            cout << "Successfully deposited $" << amount << " to your account." << endl;
            cout << "Your new balance is: " << balance << endl;
            updateBalanceInFile();
    } else {
        cout << "Invalid amount provided or account is deactivated. Contact support for further assistance. " << endl;
    }
}

void BankAccount::PrintAccountSummary() {
    cout << "Account Holder: " << username << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Transactions:" << endl;
    for (const Transaction &transaction : transactions) {
        cout << transaction.type << ", Amount: $" << transaction.amount << endl;
    }
    cout << " " << endl;
}

void BankAccount::CloseAccount(Database &database) {
    open = false;
    database.deleteUser(username);
    database.saveUsersToFile();
    cout << "Your account has been closed." << endl;
}

void BankAccount::setUsername(const std::string &newUsername) {
    username = newUsername;
}

void BankAccount::updateBalanceInFile() {
    ifstream inputFile(users_data);
    ofstream outputFile(temp_data);

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string storedUsername, storedPassword;
        double storedBalance;

        if (iss >> storedUsername >> storedPassword >> storedBalance) {
            if (storedUsername == username) {
                outputFile << username << " " << storedPassword << " " << balance << endl;
            } else {
                outputFile << line << endl;
            }
        }
    }

    inputFile.close();
    outputFile.close();
    
    remove(users_data);
    rename(temp_data,updated_data);
}
