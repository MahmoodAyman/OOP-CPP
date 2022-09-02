## How we can take object as input?

table of content
- [cin>>](#cin)
- [cout<<](#cout)
- [input and ouptu sample](#full-example)
- [access element of array defined inside class by object name](#how-we-can-access-array-inside-class-by-name-of-class-only)
- [update element of array defined inside class by object name](#what-if-you-need-to-update-the-value-of-element-in-array-inside-class-not-just-print-it)

```cpp
#include<bits/stdc++.h>
using namespace std;
class my_class {
	int x, y;
public:
	my_class(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	void print() {
		cout << x << " " << y << endl;
	}
};

int main() {
	my_class obj;
	cin >> obj; // wrong 
}
```

this is wrong but How we deal with that? 

we going to use **istream** and **ostream** from <iostream> library: 

those operators must be friend functions only 

### cin>>

first thing we will deal with that as operator 

operator >> 

for better understanding explanation will be on code: 

```cpp
istream&operator>>(istream &input,my_class &c) { // function of return type istream
	// istream is an class in iostream library 
	// and to take object from my_class as input I need to pass a parameter of type my_class
	input >> c.x >> c.y; // take x and y from object c in object input 
	return input; // return input... object of istream class 
}
```

---

### cout<<

```cpp
ostream& operator<<(ostream& output, my_class& c) { // same as previous but for cout or print
	// osteram is a class in iostream library and I take object from it
	output << c.x << " " << c.y;
	return output;
}
```

you can handle the output to be anything you want and in any order 

---

### full example:

```cpp
#include<bits/stdc++.h>
using namespace std;
class my_class {
	int x, y;
public:
	my_class(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	void print() {
		cout << x << " " << y << endl;
	}
	friend istream& operator>>(istream& input, my_class& c); // make it friend to access x and y
	friend ostream& operator<<(ostream& output, my_class& c); // make output friend also
};
istream&operator>>(istream &input,my_class &c) { // function of return type istream
	// istream is an class in iostream library 
	// and to take object from my_class as input I need to pass a parameter of type my_class
	input >> c.x >> c.y; // take x and y from object c in object input 
	return input; // return input... object of istream class 
}
ostream& operator<<(ostream& output, my_class& c) { // same as previous but for cout or print
	// osteram is a class in iostream library and I take object from it
	output << c.x << " " << c.y;
	return output;
}
int main() {
	my_class obj;
	cin >> obj;
	cout << obj << endl;
}
```

this may be used instead of get and set

---

### what if you have class contains array and want to access elements?

```cpp
#include<bits/stdc++.h>
using namespace std;
class my_class {
	int arr[3];
public:
	my_class(int (arr)[3]={0}) { // this is how you pass array to constructor
		// make parameter equal to 0 just to make no need to default constructor
		for (int i = 0; i < 3; i++) {
			this->arr[i] = arr[i] + 2;
		}
	}
};
int main() {
	my_class obj;
	cout << obj[2] << endl; // wrong 
}
```

this is wrong 

but as we used to… how can fix that? 

### How we can access array inside class by name of class only:

like this: 

```cpp
#include<bits/stdc++.h>
using namespace std;
class my_class {
	int arr[3];
public:
	my_class() {
		for (int i = 0; i < 3; i++) {
			this->arr[i] = i + 2;
		}
	}
	int operator[](int idx) { // this operator take index and return content of index
		return this->arr[idx];
	}
};
int main() {
	my_class obj;
	cout << obj[2] << endl;
}
```

this is perfectly work

---

one more thing

### what if you need to update the value of element in array inside class not just print it

the previous code will not work actually 

it need to a little modify

just add reference sign to the operator

```cpp
#include<bits/stdc++.h>
using namespace std;
class my_class {
	int arr[3];
public:
	my_class() { 
		for (int i = 0; i < 3; i++) {
			this->arr[i] = i + 2;
		}
	}
	int&operator[](int idx) {
		return this->arr[idx];
	}
};
int main() {
	my_class obj;
	obj[2] = 0;
	cout << obj[2] << endl;
}
```
---