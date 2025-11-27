#include "InventoryManager.h"

// Inventory Manager override of access level
// This user has the highest inventory privileges for managing items
void InventoryManager::accessLevel() {
    cout << "Inventory Manager: Full Inventory Control Access" << endl;
}
