#include <iostream>
#include <string>
using namespace std;

// This class represents one product with an ID, name, and price
class Product {
private:
    int id;            // Stores the product's identification number
    string name;       // Stores the product's name
    double price;      // Stores the product's price

public:
    // Constructor assigns the values passed in to the private class variables
    Product(int productID, string productName, double productPrice) {
        id = productID;          // Assigns the product ID
        name = productName;      // Assigns the product name
        price = productPrice;   // Assigns the product price
        cout << "Product object created successfully.\n"; // Confirms creation
    }

    // Destructor displays a message when the program is finished using the object
    ~Product() {
        cout << "Product object destroyed. Memory released.\n";
    }

    // Function displays all the stored product information to the user
    void printDetails() const {
        cout << "\n--- Product Details ---\n";   // Prints a header
        cout << "Product ID: " << id << endl;   // Displays the product ID
        cout << "Product Name: " << name << endl; // Displays the product name
        cout << "Price: $" << price << endl;   // Displays the product price
    }
};

int main() {
    // This creates a Product object named featuredItem using the constructor
    // The values are passed in the order: ID, name, and price
    Product featuredItem(301, "Solar-Powered Backpack Charger", 79.99);

    // Display the product information
    featuredItem.printDetails();

    return 0;
}
