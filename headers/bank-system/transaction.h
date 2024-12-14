#include <string>

class Transaction {
public:
    std::string type; // Type of transaction
    double amount; // Amount transacted

    Transaction(const std::string &t, double a) : type(t), amount(a) {}
};