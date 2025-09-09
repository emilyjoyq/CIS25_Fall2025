
#include <iostream>
#include <string>
using namespace std;

int main() {
    // variables storing input values
    string productName;
    int amount = 0;
    double price = 0.0;
    
    // prompts users for inputs
    cout << "Enter product name: v";
    cin >> productName;
    
    cout << "Enter amount: ";
    cin >> amount;
    
    cout << "Enter price per unit: ";
    cin >> price;
    
    // calculate and displays the total cost
    double total = amount * price;
    cout << "The total cost of " << productName << "is: $" << total <<endl;
    
    return 0;
}
