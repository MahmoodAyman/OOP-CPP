# more in inheritance 

table of content
- [What is inherited automatically](#what-is-inherited-automatically)
- [how to specify constructor](#how-to-specify-which-default-constructor-will-be-called-by-the-derived-class-in-the-declaration)
- [Inherit from more than one class](#inherit-from-more-than-one-class)


### What is inherited automatically?

there are somethings that inherited directly when you create a derived class : 

- constructors and destructor
- operator overloading =()
- friend functions

```cpp
#include<bits/stdc++.h>
using namespace std;
class Espresso {
protected:
	string coffe;
public:
	Espresso() {
		cout << "Just coffe ";
	}
};
class latte :public Espresso {
	string milk;
public:
	latte() {
		cout << "with extra milk" << endl;
	}
};
int main() {
	latte l;
	// l inherit Espresso constructor 
	// so ouptut is 
	// Just coffe with extra milk

}
```
--- 

### How to specify which default constructor will be called by the derived class in the declaration

```cpp
#include<bits/stdc++.h>
using namespace std;
class Espresso {
protected:
	string coffe;
public:
	Espresso() { // default constructor
		cout << "Just coffe ";
	}
	Espresso(int x) {// parameterized constructor 
		cout << "by default this cup has " << x << " spoons of sugar " << endl;
	}
};
class latte :public Espresso {
	string milk;
public:
	latte() {
		cout << "with extra milk" << endl;
	}
	latte(int x) {
		cout << "this cup of latte has " << x << " extra spoons of sugar" << endl;
	}
};
int main() {
	latte l(2); // this is the latte class parameterized constructor 
}
```

output will be :  

 `"this cup of latte has x extra spoons of sugar"`

now see this: 

```cpp
#include<bits/stdc++.h>
using namespace std;
class Espresso {
protected:
	string coffe;
public:
	Espresso() { // default constructor
		cout << "Just coffe ";
	}
	Espresso(int x) {// parameterized constructor 
		cout << "by default this cup has " << x << " spoons of sugar " << endl;
	}
};
class latte :public Espresso {
	string milk;
public:
	latte() {
		cout << "with extra milk" << endl;
	}
	latte(int x):Espress(x) { // that means pass the same x to Espresso parameterized consturctor
		cout << "this cup of latte has " << x << " extra spoons of sugar" << endl;
	}
};
int main() {
	latte l(2); // this is the latte class parameterized constructor 
}
```

ouput:

`by default this cup has 2 spoons of sugar
this cup of latte has 2 extra spoons of sugar`

---

### Inherit from more than one class?

one class can inherit from one or more classes actually: 

```cpp
#include<bits/stdc++.h>
using namespace std;
class Name {
private:// private but I will access them by set and get
	string name;
public:
	Name() {
		name = "no name";
	}
	void set_name(string name) {
		this->name = name;
	}
	string get_name() {
		return  name;
	}
};
class ID {
private: // private but I will access them by set and get
	string id; 
public:
	ID() {
		id = "0";
	}
	void set_id(string id) {
		this->id = id;
	}
	string get_id() {
		return id;
	}
};
class student : public Name, public ID {
public:
	student(string name, string id) {
		set_name(name); // see how I access name and Id by set 
		set_id(id);
	}
	void print() {// see how I access name and Id by get
		cout << "student name is: " << get_name() << " and his id is: " << get_id() << endl;
	}
};
int main() {
	student s("Mahmoud", "123456");
	s.print();
}
```

outpu:

`student name is: Mahmoud and his id is: 123456`