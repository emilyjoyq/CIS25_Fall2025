#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "Employee.h"

// Derived class from Employee: Represents a manager who controls inventory
class InventoryManager : public Employee {
public:
    // Override again to provide a more privileged access level
    void accessLevel() override;
};

#endif
