# Inheritance

table of content: 
- [Whatis Inheritance](#what-is-it)
- [Access Modifiers](#access-modifiers)
- [Example](#how-to-inherent-from-a-class)
- [types of inheritance](#types-of-inheritance)
- [Overriding](#override)

### what is it?

Inheritance is one of the core concepts in OOP and from its name, it’s a mechanism where you can derive a class from another class or inherent attributes and methods from a class to another.

- another meaning of inheritance: 
Inheritance is a way to reuse code. It allows you to create a new class that is a modified version of an existing class. The new class is called a subclass, and the existing class is called a superclass. The subclass inherits all of the public and protected methods from the superclass. It can also add its own methods in addition to inheriting methods from the superclass.


in **c++** we call classes:
**base class --> derived class**
in **java** its name is:
**super class --> sub class**

---

### Access Modifiers

in order to understand what can be derived class or subclass access from super or base class

you need to know about access modifiers and their permissions ad we previously talk about [Access Modifiers](../2-Classes%20and%20objects/1-Classes%20and%20objects.md#access-modifiers).

Now all you need to know that ***derived class*** can’t access attributes and methods in **private scope** in ***base class*** but can access what’s in **protected** or **public** scope

---

### How to Inherent from a class

```cpp
#include<bits/stdc++.h>
using namespace std;
class person {
protected:
	string name, id;
	int age;
public:
	void set_values(string name, string id, int age) {
		this->name = name;
		this->id = id;
		this->age = age;
	}
};
class student : public person { // here is the inheritance 
	// student is a derived class from a person class that inherent public 
protected:
	double gpa;
public:
	void set_gpa(double g) {
		gpa = g;
	}
};

class teacher : public person { // here is a new derived class inherent from a base class person 
protected: 
	double salary;
public:
	void set_salary(double s) {
		salary = s;
	}
};
```

`the word public beside class person's name when inheriting from it means we inherit everything inside the class as it is
clearly, we inherit what's protected as protected
and what's public as it's`

and as we know we can’t access what’s private in base class by super class … actually we inherit it but we can’t access it!!

both **student** and **teacher** classes has attributes and methods of **person** class and their own attributes and methods 

```cpp
int main() {
	student s;
	s.set_values("Mahmoud", "123456", 22);
	s.set_gpa(3.2);
	teacher t;
	t.set_values("Ayman", "123990", 40);
	t.set_salary(1320.4);
}
```

as you see how to declare object from a class student and class teacher and give them attributes of person class 

`we know already that the set_values function does not exist in student and teacher classes but is still can use… and this is because we inherit it from a person's class`

---

### types of Inheritance

```cpp
class A {
	int x; // private scope
protected:
	int y;
public:
	int z;
};
class B : public A { // public keyword mean we inherit everything in A as it is 
	int a;
};
class C :A { // no keyword means we inherite members in A  as private in  class C 
// A.x, A.y, and A.z are all in class C in a private scope 
	// == class C : private A{}; 
};
```

but what’s the difference at all?

**difference appear in main function:**

```cpp
#include<bits/stdc++.h>
using namespace std;
class A {
	int x;
protected:
	int y;
public:
	int z;
};
class C :A { 
	int c;
public:
	int d;
	int get_y() {
		return y; // from class A 
	}
};
int main() {
	C obj;
	obj.d = 3;
	obj.get_y(); 
}
```

---

### Override

what if type of Inheritance is private and we need to make some members public? 

```cpp
#include<bits/stdc++.h>
using namespace std;
class base_class {
	int i; // private
public:
	int j, k; 
	void set_i(int i) {
		this->i = i;
	}
	int get_i() {
		return i;
	}
};
class derived_class : private base_class { // type of inherent is private 
	// what if we need to inherent some members as public? 
	// that called override
public:
	base_class :: j; // make j public again 
	base_class::set_i; // make method public 
	base_class::get_i;
};
// now in main be derived class you can access i in base_class by set_i method 
int main() {
	derived_class obj;
	obj.set_i(5);
	cout << obj.get_i() << endl;
}
```