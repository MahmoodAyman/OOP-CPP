# Constructors and Destructors

   ### table of content:
   - [what are consturctors?](#what-are-constructors)
   - [types of constructors](#types-of-constructors)
        - [empty constructor](#empty-constructor)
		- [parameterized constructor](#parameterized-constructor)
		- [copy constructor](#copy-constructor)
   - [perfect example](#perfect-example)
   - [declare obj without parameterized constructor or default constructor!](#define-parameterized-constructor-only-and-declare-object-without-constructor)

## what are constructors?

constructor is a special method that is automatically called when we create an object from a class

one of the most uses is to set initial values to attributes of the class when you create a new object, depending on the fact that the constructor is automatically called when declaring an object

it has some attributes:

- constructor has the same name as the class
- unlike other methods, constructors don’t have return type even a void type... we don't type anything before constructor
- followed by parentheses “ () ”
- class can has more than one constructor
    - if there is more than one constructor with the same type this is called overloading constructors… see the examples below
        - if there are 10 parameterized constructors.. all of them must be different in the number of parameters

```cpp
class MyClass {    
public:          
	MyClass() {   //constructor   
      cout << "Hello World!";
    }
};
```

## 1- types of constructors:

## **empty constructor:**
also called default constructor or no-argument constructor 
 ****called empty cause we don’t pass any parameter to it at all.. (there are no parameters between parentheses ()

```cpp
class MyClass {    
public:          
	MyClass() {   // empty constructor   
      cout << "Hello World!";
    }
};
```

## **Parameterized Constructor**:

constructor that has parameters you can use to set values to class attributes direct when declare object from a class

once you define a parameterized constructor you can't declare object without passing parameters to it if you want to declare object without passing parameters to it you must define default constructor

```cpp
#include<bits/stdc++.h>
using namespace std;
class Triangle {
private:
	float base, hight;
public:
	Triangle(float b, float h) { // parameterized constructor
		base = b;
		hight = h;
	}
	float get_base() {
		return base;
	}
	float get_hight() {
		return hight;
	}
	float area() {
		return 0.5 * get_base() * get_hight();
	}
	void print_area() {
		cout << "area of this triangele = " <<  area() << endl;
	}
};
int main() {
	Triangle t; // no values passed here so values of base and hight will be random
	t.print_area();

	Triangle t1(15,10); // called parametrized constructor so base will be 15 and hight will be 10
	t1.print_area(); // will pring 75

}
```

## **copy constructor** :

### see this:

```cpp
#include<bits/stdc++.h>
using namespace std;
class copy {
private:
	int a1, a2, a3, a4, a5;
public:
	copy(int aa1,int aa2,int aa3,int aa4,int aa5) { 
		a1 = aa1;
		a2 = aa2;
		a3 = aa3;
		a4 = aa4;
		a5 = aa5;
	}
	copy(const copy &c) { 
		// this is parameterized constructor I pass object from the class to it
		// as we see must pass object to it by using   //  const and & 
		a1 = c.a1;
		a2 = c.a2;
		a3 = c.a3;
		a4 = c.a4;
		a5 = c.a5;
	}
};

int main(){
copy c1(1,2,3,4,5) // this will call the parameterized constructor
copy c2(c1) // this will call the copy constructor
}
```

sounds good but what if we have more parameters and attributes? 

---

### perfect example

```cpp
#include<bits/stdc++.h>
using namespace std;
class student {
private:
	string name, id;
	int age, grade;
	double gpa;
public:
	student() { // this is an empty constructor
		cout << "this is empty constructor" << endl;
	}

	student(string n, string i) { // this is parameterized constructor
		cout << "parameterized constructor to set name and id " << endl;
		name = n;
		id = i;
	}
	student(int a, double g) { // another parameterized constructor
		cout << "parameterized constructor to set age and gpa" << endl;
		age = a;
		gpa = g;
	}
	student(int gr) {
		cout << "parameterized constructor to set grade" << endl;
		grade = gr;
	}
	student(string n, string i, int a, double g, int gr) {
		name = n;
		id = i;
		age = a;
		gpa = g;
		grade = gr;
	}
	// this called overloading

	student(const student& s) {
		name = s.name;
		id = s.id;
		age = s.age;
		grade = s.grade;
		gpa = s.gpa;
	}
};

int main() {
	student s1; // cause we don't pass parameters the automatic called construcotr
	// will be the empty one 

	student s2("Mahmoud", "281697"); // first parameterized constructor with parameters 
	//name and id

	student s3(22, 2.5); // second parameterized constructor with age and gpa

	student s4(4);// third parameterized constructor with grade parameter

	student s5("Ayman", "281697",22,2.5,4); // last parameterized constructor

	student s6(s5); // called the copy constructor
}
```

---

## define parameterized constructor only and declare object without constructor:

remember when I told you this: 

> once you define a parameterized constructor you can't declare object without passing parameters to it if you want to declare object without passing parameters to it you must define default constructor
> 

I lied to you 

you can declare object without passing parameters at all but with a little modify on parameterized constructor 

you just need to set an initial values to parameters of parameterized constructor: 

```cpp
#include<bits/stdc++.h>
using namespace std;
class my_class {
public:
	my_class(int x=0, int y=0) {
		cout << x + y << endl;
	}
};
int main() {
	my_class obj;

}
```

now you're fine 😀