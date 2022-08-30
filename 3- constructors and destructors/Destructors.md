## What is the Destructor?

it’s the opposite of the constructor

it’s similar to constructor in some attributes and different in other 

---

## what is attributes of destructor?

- has the same name of class but has “~” before

```cpp
class MyClass {    
public:          
	MyClass() {   //constructor   
      cout << "Hello World!";
    }
	~MyClass() {   //destructor   
      cout << "Hello World!";
    }
};
```

- class has only one destructor and can’t has more
- destructor job is delete the object that has been created from the class from memory
- destructor  Delete in order from closest to end to beginning

```cpp
#include <iostream>
using namespace std;
class square {
private: 
	int side;
public:
	square(int side) {
		this->side = side;
	}
	~square() {
		cout << "the deleted square has side = " << this->side << endl;
	}
};
int main() {
	square s1(10), s2(20);
		 // output will be from destructor and will be: 
	  // the deleted square has side = 20
	  // the deleted square has side = 10
// that means destructor delete the last object first
}
```

---