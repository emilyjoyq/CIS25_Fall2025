#include "User.h"

// Default access level for a generic user
// This is the least powerful access and will be overridden in derived classes
void User::accessLevel() {
    cout << "General User: Limited Access" << endl;
}
