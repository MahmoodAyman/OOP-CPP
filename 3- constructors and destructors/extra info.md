
see this example:
```cpp
#include <iostream>
using namespace std;
class person {
private:
    string name,id;
    int age;
    string address;
public:
    person(string n, string i):name("Mahmoud"),id("281697")
        // these values after :  will be initial values 
    {
        cout << this->name << " " << this->id << endl;
        cout << "this is parameterized constructor" << endl;
    }
    ~person() {
        cout << "this is destructor" << endl;
    }
};
int main() {
    person p1("Ayman", "1111"); // this object will called parameterized constructor
    // the output will be Mahmoud , 281697

}
```

I mean you can set values out of the constructor and you can set values in the constructor too.