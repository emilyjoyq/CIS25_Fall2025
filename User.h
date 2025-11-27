#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

// Base class: Represents a generic user of the system
class User {
public:
    // Virtual function so derived classes can customize their access level
    virtual void accessLevel();
};

#endif
