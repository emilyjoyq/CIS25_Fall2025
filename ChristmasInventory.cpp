#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;     // Name of the gift
    int quantity;    // How many gifts to wrap
};

// Function to display all gifts in the inventory
void displayInventory(Item gifts[], int size) {
    cout << "\n🎄 Christmas Gift Wrapping List 🎄\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << gifts[i].name
             << " — Quantity: " << gifts[i].quantity << endl;
    }
    cout << "----------------------------------\n";
}

// Function to search for a gift by name
void searchGift(Item gifts[], int size, string searchName) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (gifts[i].name == searchName) {
            cout << "🎁 You need to wrap " << gifts[i].quantity
                 << " of \"" << gifts[i].name << "\".\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "❌ Gift not found in the list.\n";
    }
}

int main() {
    const int SIZE = 5;
    Item gifts[SIZE];

    cout << "=== Christmas Gift Wrapping Tracker ===\n";

    // Ask user to enter 5 gifts and their quantities
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter name for gift #" << i + 1 << ": ";
        getline(cin, gifts[i].name);
        cout << "Enter quantity to wrap: ";
        cin >> gifts[i].quantity;
        cin.ignore(); // clear newline
    }

    // Display all gifts
    displayInventory(gifts, SIZE);

    // Search feature
    string searchName;
    cout << "Enter a gift name to check how many to wrap: ";
    getline(cin, searchName);
    searchGift(gifts, SIZE, searchName);

    cout << "\n✨ All set! Don’t forget to add ribbons and bows! ✨\n";
    return 0;
}

