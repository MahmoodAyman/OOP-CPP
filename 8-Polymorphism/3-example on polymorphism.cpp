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
	virtual int area() = 0;
	void print_area() {// see this function 
		cout << this->area() << endl;
	}
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

	shape* s1 = &rect;
	shape* s2 = &trgl; 

	s1->set_height(3); 
	s1->set_width(4); 
	
	s1->print_area(); // see which child class called print area function to understand 
	// now what this-> in function reffers to ? 
	
	s2->set_height(4);
	s2->set_width(5);

	s2->print_area();
}

// output is 12 and 10 