#include <iostream>
#include <string>
using namespace std;

//Define a struct that stores both a product name & ID number
struct Item {
    string name;
    int id;
};

int binarySearch(Item* arr, int size, int targetID) {
    int low = 0;
    int high = size - 1;
    
    // Loop continues until the search range is empty
    while (low <= high) {
        int mid = low + (high - low) / 2; // Middle index for comparison
        
        if (arr[mid].id == targetID) {
            return mid; // Item found, return its index
        }
        else if (arr[mid].id < targetID) {
            return mid;
        }
        else if (arr[mid].id < targetID) {
            // User's target ID is larger
            low = mid + 1;
        }
        else {
            // User's target ID is smaller
            high = mid - 1;
        }
    }
    return -1;
}

// Main Program
int main() {
    int numItems = 100; // Inventory holds 100 items

    // Allocate memory BEFORE using the array
    Item* inventory = new Item[numItems];

    // Fill the inventory with data
    for (int i = 0; i < numItems; ++i) {
        inventory[i].id = 1000 + i;
        inventory[i].name = "Item" + to_string(i + 1);
    }

    int searchID;
    cout << "Enter the ID of the item you want to find: ";
    cin >> searchID;

    // Use binary search to find item's position
    int result = binarySearch(inventory, numItems, searchID);

    if (result != -1) {
        cout << "\nItem found!\n";
        cout << "Name: " << inventory[result].name << endl;
        cout << "ID: " << inventory[result].id << endl;
    } else {
        cout << "\nSorry, there's no item with the ID "
             << searchID << " found in the inventory.\n";
    }

    delete[] inventory;
    return 0;
}
