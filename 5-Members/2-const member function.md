# const objects and const member functions

- table of contents
    - [what constants ?](#what-constants)
    - [const objects and const member functions](#now-what-about-constant-object-from-a-class)
    - [What's important of constant](#whats-important)


## what constants ?
define variable as constant make it impossible to modify the value of it 

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
	const double pi = 3.14;
	pi += 1; // wrong cause pi is constant 
}
```

---

## now what about constant object from a class?

if you define a constant object from a class 

that means that this object *constant* can’t access any methods inside class but constant methods… which called ***Const Member Function***  

A const member function can be called by any type of object. Non-const functions can be called by non-const objects only.

```cpp
#include<bits/stdc++.h>
using namespace std;
class Time {
private:
	int hour, minute, second;
public:
	Time(int h, int m, int s) { 
		hour = h;
		minute = m;
		second = s;
	}
	void print() const { // constant function 
		cout << "The time is " << hour << " : " << minute << "and " << second << " seconds" << endl;
	}
};
int main() {
	const Time t(12, 0, 0); // const object can access const member function 
	Time t1(1, 12, 30); // can access any member function const or non const 

	t.print();	//output will be: The time is 12 : 0and 0 seconds
	t1.print();// output will be: 	The time is 1 : 12 and 30 seconds
}
```

see in const member function we write const after prototype of the function not before it 

---

## what’s important?

if you want to declare object can access a specific methods only you can use const with object and const with functions and methods you want