#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
using namespace std;

class BankAccount {
private:
    double balance;           // Tracks how much money the user has
    string transactionsFile;  // Name of the log file

    string currentTimestamp() const;                     // Gets the current date/time
    void log(const string& type, double amount, const string& note); // Logs transactions

public:
    BankAccount(double initial = 0.0, const string& file = "transactions.txt");
    void deposit(double amount, const string& note = "Deposit");
    bool purchase(double amount, const string& note = "Purchase");
    void printBalance() const;
    double getBalance() const;
};

#endif
