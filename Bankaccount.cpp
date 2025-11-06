#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <chrono>
#include <ctime>
using namespace std;

// The BankAccount class stores a user's balance & allows them to make deposits & purchase
class BankAccount {
private:
    double balance;           // Tracks how much money the user currently has
    string transactionsFile;
    
    string currentTimestamp() const {
        using std::chrono::system_clock;
        auto now = system_clock::now();
        time_t t = system_clock::to_time_t(now);
        tm tm{};
#ifdef _WIN32
        localtime_s(&tm, &t);
#else
        localtime_r(&t, &tm);
#endif
        char buf[20];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
        return string(buf);
    }
    
    // Saves a description of what the user just did
    void log(const string& type, double amount, const string& note) {
        ofstream out(transactionsFile, ios::app);
        if (!out) {
            cerr << "ERROR: Could not open " << transactionsFile << " for writing.\n";
            return;
        }
        out << currentTimestamp() << "  "
        << setw(8) << left << type << "  "
        << (type == "Deposit" ? "+" : "-")
        << "$" << fixed << setprecision(2) << amount << "   "
        << "Balance: $" << balance << "   "
        << "Note: " << note << "\n";
    }
    
public:
    // Creates a new account with an optional starting balance
    BankAccount(double initial = 0.0, const string& file = "transactions.txt")
    : balance(initial), transactionsFile(file)
    {
        if (initial > 0.0) {
            log("Deposit", initial, "Initial funding");
        }
    }
    
    // Allows the user to add money to their account
    void deposit(double amount, const string& note = "Deposit") {
        if (amount <= 0) {
            cout << "Please enter a positive deposit amount.\n";
            return;
        }
        balance += amount;
        cout << "Deposited $" << fixed << setprecision(2) << amount << endl;
        log("Deposit", amount, note);
    }
    
    // Allows the user to make a purchase that deducts money from their balance
    bool purchase(double amount, const string& note = "Purchase") {
        if (amount <= 0) {
            cout << "Purchase amount must be positive.\n";
            return false;
        }
        if (amount > balance) {
            cout << "Purchase declined: not enough money in your account.\n";
            return false;
        }
        balance -= amount;
        cout << "Purchase approved! You spent $" << amount
        << ". New balance: $" << balance << endl;
        log("Purchase", amount, note);
        return true;
    }
    
    // Shows the user how much money they have left
    void printBalance() const {
        cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
    }
    
    // Allows other parts of the program to get the current balance
    double getBalance() const { return balance; }
};

int main() {
    std::cout << "=== Welcome to the Simple Bank App ===\n";

    BankAccount myAccount(0.0);

    std::cout << "\nDepositing $500...\n";
    myAccount.deposit(500.00, "Initial deposit");

    std::cout << "\nBuying coffee for $6.25...\n";
    myAccount.purchase(6.25, "Coffee");

    std::cout << "\nBuying textbook for $120.49...\n";
    myAccount.purchase(120.49, "Textbook");

    std::cout << "\nFinal balance:\n";
    myAccount.printBalance();

    std::cout << "All transactions saved to transactions.txt\n";
    return 0;
}

