#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Class to represent a jewlrey item
class Item {
public:
    string name;
    int quantity;
    
    // Save jewlrey item to a file
    void saveToFile() {
        ofstream out("items.txt", ios::app);
        if (out.is_open()) {
            out << name <<"," << quantity << endl;
            out.close();
            cout << "Jewlrey item has been saved to file successfully!" << endl;
        } else {
            cout << "Unable to open the file." << endl;
        }
    }
    
    // Load and display all saved jewlrey items
    void loadFromFile() {
        ifstream in("items.txt");
        if (in.is_open()) {
            string line;
            cout << "\nJewlrey inventory list from file:\n";
            while (getline(in, line)) {
                cout << " - " << line << endl;
            }
            in.close();
        } else {
            cout << "Unable to open the file for reading." << endl;
        }
    }
};

int main() {
    Item jewelry;
    
    // Asking user for jewelry details
    cout << "Enter the name of the jewelry item: ";
    getline(cin, jewelry.name);
    
    cout << "Enter the quantity: ";
    cin >> jewelry.quantity;
    
    // Save the item to the file
    jewelry.saveToFile();
    
    // Show the user what it on the file currently
    jewelry.loadFromFile();
    
    return 0;
}
