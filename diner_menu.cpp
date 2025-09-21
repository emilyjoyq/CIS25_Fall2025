#include <iostream>
#include <string>
using namespace std;

// Show the menu choices
void menu() {
    cout << "1. Steak\n";
    cout << "2. Pasta\n";
    cout << "3. Pizza\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

// Options for steak
void steakOption() {
    string doneness;
    cout << "How would you like your steak cooked? ";
    cin >> doneness;
    cout << "Your" << doneness << " steak will be served shortly." << endl;
}

// Options for pasta
void pastaOption() {
    string type;
    cout << "What type of pasta would you like? ";
    cin >> type;
    cout << "Your " << type << " pasta is being prepared now!" <<endl;
}

// Options for pizza
void pizzaOption() {
    int slices;
    cout << "How many slices would you like?";
    cin >> slices;
    cout << "Your pizza with" << slices << "slices is on the way";
}

int main () {
    int choice;
    
    // keep asking user until they choose exit
    while (true) {
        menu ();        //displays menu
        cin >> choice;  // gets user's choice
        
        if (choice ==1) {
            steakOption();
        }
        else if (choice ==2) {
            pastaOption();
        }
        else if (choice ==3) {
        }
        else if (choice ==4) {
            cout << "Exiting menu." << endl;
            break;
        }
        else {
            cout << "Not a provided choice, please select from the menu options." <<endl;
        }
        
        cout << endl;
    }
    return 0;
}
