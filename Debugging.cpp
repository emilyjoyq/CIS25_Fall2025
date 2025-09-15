#include <iostream>
using namespace std;

int main() {
    int choice;
    
    // Display the main menu options to the user
    cout << "1. Add Item\n2, View Items\n3. Exit\n";
    cout << "CHoose an option: ";
    cin >> choice; // User enters choice here
 
    if (choice == 1) {
        // Ask user for three numbers
        float n1, n2, n3;
        cout << "Enter three numbers: ";
        cin >> n1 >> n2 >> n3;
        
        // Check which one is the largest number
        if (n1 >= n2) {
            if (n1 >= n3) {
                cout << "Largest number: " << n1 << endl;
            } else {
                cout << "Largest number: " << n3 << endl;
            }
        }
    }
    else if (choice == 2)
        // If user picks option 2
        cout << "Displaying items...\n";
    else if (choice == 3)
        // If user picks option 3
        cout << "Exiting...\n";
    else
        // If user enters something not on the menu
        cout << "Invalid option.\n";
    
    return 0;
}
