## This


it's a keyword means pointer in memory points to object space in memory

```cpp
#include<bits/stdc++.h>
using namespace std;
class my_class {
public:
	void memory_address() {
		cout << this << endl;
	}
};
int main() {
	my_class obj;
	obj.memory_address();
	cout << &obj << endl;
}
```

output of this code will be the same in my case memory address of obj object was **000000E9421CFA24**

---

### now how we can use **this** keyword?

 this can be useful when the parameters of functions it's the same as class members

```cpp
#include<bits/stdc++.h>
using namespace std;
class student {
	string name, id; // without scope private the default scope is private 
	int age;
public:
	student() {
		// see how this keyword work to points to object allocated memory
		this->name = "no name"; // points to name variable address in memory 
		this->id = "0"; // points to id variable address 
	}
	void set_name(string name) {
		this->name = name; // this ->name points to member of object 
		// name without this-> refers to parameter of function
	}
	void set_id(string id) {
		this->id = id;
	}
	void set_age(int age) {
		this->age = age;
	}
	void print() {
		cout << "student name is: " << name << " and his id is: " << this->id << endl;
	}
};
int main() {
	student s;
	s.set_name("Mahmoud");
	s.set_id("231452");
	s.print();
}
```

this code will print: 

student name is: Mahmoud and his id is: 231452

### you can’t use this with .

```cpp
this.name = name;
```

this won’t work