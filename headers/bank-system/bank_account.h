#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "./transaction.h" 
#include "./database.h" 

class BankAccount {
public:
    BankAccount(const std::string &username, Database &db);

    void Withdraw(double amount);
    void Deposit(double amount);
    void PrintAccountSummary();
    void CloseAccount(Database &database);
    void setUsername(const std::string &newUsername);

private:
    std::string username;
    bool open;
    double balance;
    std::vector<Transaction> transactions;
    Database &database;

    void updateBalanceInFile();
};

#endif
