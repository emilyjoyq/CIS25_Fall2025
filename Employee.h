#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"

// Derived class from User: Represents an employee
class Employee : public User {
public:
    // Override the access level from User to provide Employee-specific access
    void accessLevel() override;
};

#endif
