
## see this example of given initial value to attributes of class out of constructor:
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

---
## see this example of calling method before define it
##  and define it out of the class!
```cpp
#include <bits/stdc++.h>
#include<cstring>
using namespace std;
class person {
private:
	string name, id;
	int age;
public:
	person(string name, string id, int age) {
		this->name = name;
		this->id = id;
		this->age = age;
		// this refers to object attributes 
		// whitout else refers to parameters passed to constructor

		print();
		// as we say we can call method before define it based on concept of 
		// encapsulation
	}
	void print();
	// can define method like this and continue it out of the class
};
void person::print() {
	cout << "person Name is: " << name << endl;
	cout << "his ID = " << id << endl;
	cout << "and his age = " << age << endl;
}
int main() {
	person p("Mahmoud", "123456789", 22);
}
```