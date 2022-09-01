# Friend Functions and Classes

- table of content 
    - [what is friend function?](#what-is-friend-function)
    - [how to declare friend function?](#how-define-friend-function)
    - [Application of friend function](#applications)
    - [Perfect Example](#lets-take-an-example)

## What is Friend Function?

there could be situations in programming where we want classes to share their private and protected members 

Friend Function is the function that defined Globally in outside the class scope but it still has permission to access private and protected members inside the class

friend functions are not member functions of the class 

---

## how define friend Function?

just define your class and outside it define the function you want to make it friend and put the prototype of this function anywhere in class with keyword ***friend***  before 

```cpp
#include<bits/stdc++.h>
using namespace std;
class my_class {
private:
	int a, b;
public:
	my_class(int x, int y) {
		a = x;
		b = y;
	}
	friend int sum(my_class obj); // just put keyword friend and then prototype of function you want to 
	// make it friend of the class
};
int sum(my_class obj) { // function access class members 
	return obj.a + obj.b;
}
int main() {
	my_class o(5,10);
	cout << sum(o) << endl; // output will be 15
} 
```
--- 

## Applications

uses of friend function is when you want more than one class share the same function then no need to define the same function inside every class again and again 

just define it once and access it inside any class by making it friend to all classes

---

## let’s take an example:

since we know that the rectangle is just a square but with height differs from width we can use the same function to calculate the area of the rectangle and square!

```cpp
#include<bits/stdc++.h>
using namespace std;
class Rectangle { // rectangel class 
private:
	int width, height;
public:
	Rectangle() { // empty constructor
		width = 0;
		height = 0;
	}
	// define getters and setters 
	void set_width(int w) {
		width = w;
	}
	void set_height(int h) {
		height = h;
	}
	int get_width() {
		return width;
	}
	int get_height() {
		return height;
	}
	// friend function
	friend int get_area(int w, int h);
}; // end of rectangle class 

class Square { // square class 
private:
	int side;
public:
	Square() { // empty construcor 
		side = 0;
	} 
	// define getter and setter 
	void set_side(int s) {
		side = s;
	}
	int get_side() {
		return side;
	}
	// friend function
	friend int get_area(int w, int h);
}; // end of square class 

int get_area(int w,int h) { // friend function 
	return w * h;
}

int main() {
	cout << "Enter 1 if square or 2 if rectangle: ";
	int c; cin >> c;
	if (c == 1) {
		Square s; // declare object of square class
		cout << "Enter side of Square to get area: ";
		int si; cin >> si;
		s.set_side(si);
		cout << "Area of the square of side " << si << " = ";
		cout << get_area(s.get_side(), s.get_side()) << endl;
	}
	else {
		Rectangle r;
		cout << "Enter Width of Rectangle: ";
		int w; cin >> w;
		cout << "Enter Height of Rectangel: ";
		int h; cin >> h;
		r.set_width(w);
		r.set_height(h);
		cout << "Area of the rectangle of width " << w << " and height " << h <<" is ";
		cout << get_area(r.get_width(), r.get_height()) << endl;
	}
}
```

---

also you can make friend function make operation on object from a class A and class B at the same time