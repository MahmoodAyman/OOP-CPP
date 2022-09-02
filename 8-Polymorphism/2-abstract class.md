# Abstract Class

### what is it?

abstract class is a class that contains at least one pure **virtual function**

### what is pure virtual function?

it’s a virtual function created on base class but must be override in derived class, otherwise the derived class will also become abstract class

by the way pure virtual function also called **abstract function** 💁🏻‍♂️

- you can’t create  object from abstract class only pointers

### See the Example below for better understanding:

```cpp
#include<bits/stdc++.h>
using namespace std;
class shape {
	int width, height;
public:
	void set_width(int width) {
		this->width = width;
	}
	void set_height(int height) {
		this->height = height;
	}
	int get_width() {
		return width;
	}
	int get_height() {
		return height;
	}
	virtual int area() = 0; // this is virtual function 
};
class rectangle : public shape {
public:
	int area() {
		return get_width() * get_height();
	}
};
class triangel : public shape {
public:
	int area() {
		return get_width() * get_height() * 0.5;
	}
};
int main() {
	rectangle rect;
	triangel trgl;
	// shape s;  this is abstract class you can't create objects from 
	shape* s1 = &rect;// now you're fine this is an pointer of class shape pointing to
	// objcet from a class rectangle

	shape* s2 = &trgl; // and this is another pointer pointing to object from a class triangle

	// now let's access virtual function that overrided by pointers 
	s1->set_height(3); s1->set_width(4); // now this is a rectangle with height 3 and width 4

	cout << "area of rectangle is: " << s1->area() << endl;

	s2->set_height(4);
	s2->set_width(5);
	cout << "area of triangle is: " << s2->area() << endl;

}
```

output will be:

`12`

`10`