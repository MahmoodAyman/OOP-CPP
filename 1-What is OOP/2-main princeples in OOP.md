# what is main principle of OOP?

## Abstraction
Abstraction is the idea of hiding the implementation details of a class from the user.

for example, We all know how to turn the TV on, but we don’t need to know how it works in order to enjoy it. 

This is important because it lets you avoid repeating the same work multiple times.

---

## Encapsulation
Encapsulation describes the idea of bundling attributes and methods that work on that data within one unit. **class**
This concept is also often used to hide an object's internal representation or state from the outside. This is called information hiding. 

and an influential part of encapsulation is the ability to restrict access to the data. and also you can call methods that are members of the class even before you define it since **encapsulation** allow you to deal with attributes and methods inside the class as a unit.

for better understanding encapsulation see this code:  
```cpp
class my_class {
private:
	int x, y;
public:
	my_class() {
		cout << "this is consturctor" << endl;
		void print(); // call function 
	}
	void print() { // then declare it! 
		cout << "you can call me before define me because of encapsulation" << endl;
	}
};
```

---
## inheritance

Inheritance is one of the core concepts in OOP and from its name, it’s a mechanism where you can derive a class from another class or inherent attributes and methods from a class to another.

we can call class that inherit from another as ***derived class*** from ***base class***

---
## Polymorphism
Polymorphism is the ability to use a single interface for differing underlying implementations.

in simple words, polymorphism is allow programmers to use the same word to mean different things.

one form of polymorphism is **method overloading**.
and that's when the same code is used to perform different tasks.

another form of polymorphism is **method overriding**.
tha't, when values of variables passed to a method, imply different meanings.
