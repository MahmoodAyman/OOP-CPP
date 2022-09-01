## operator overloading

- table of content
    - [what is operator overloading?](#what-is-operator-overloading)
    - [Methods to add two objects](#we-can-create-method-to-add-2-objects-to-each-other)
    - [another way to add two objects](#another-way-to-add-2-objects-is)
    - [operator overloading](#operator-overloading-1)
    - [How compiler understand operator overloading](#how-compiler-understand-this)


## what is operator overloading?

let’s say we create 3 objects and we want to add object **one** and object **two** and put the result in object **three**

can we do this with just + operator? 

```cpp

#include<bits/stdc++.h>
using namespace std;
class square {
private:
	int side;
public:
	square() {
		side = 0;
	}
	square(int s) {
		side = s;
	}
	void set_side(int s) {
		side = s;
	}
	int get_side() {
		return side;
	}
};
int main() {
	square s1(5), s2, s3;
	s2.set_side(5);
	s3 = s2 + s1;
}
```

absolutely this is wrong
compiler don't know how to add 2 objects of this class actually

### we can create method to add 2 objects to each other?

```cpp
#include<bits/stdc++.h>
using namespace std;
class square {
private:
	int side;
public:
	square() {
		side = 0;
	}
	square(int s) {
		side = s;
	}
	void set_side(int s) {
		side = s;
	}
	int get_side() {
		return side;
	}
	void add(square s1, square s2) {
		side = s1.get_side() + s2.get_side();
	}
};
int main() {
	square s1(5), s2, s3;
	s2.set_side(5);
	s3.add(s1, s2);
	cout << s3.get_side() << endl;
}
```

previous code will work perfectly and output will be 10 

### another way to add 2 objects is:

sounds same code but there  is a little different 

trace it

```cpp
#include<bits/stdc++.h>
using namespace std;
class square {
private:
	int side;
public:
	square() {
		side = 0;
	}
	square(int s) {
		side = s;
	}
	void set_side(int s) {
		side = s;
	}
	int get_side() {
		return side;
	}
	square add(square s1) { // make function return obj
		square s;
		s.set_side(s1.get_side()+ this->side);
		return s;
	}
};
int main() {
	square s1(5), s2, s3;
	s2.set_side(5);
	s3=s1.add(s2); 
	cout << s3.get_side() << endl;
}
```

---

### there is a third different way:

## operator overloading:

here’s where you can use the operator **+** only to add 2 objects to each other

```cpp
#include<bits/stdc++.h>
using namespace std;
class square {
private:
	int side;
public:
	square() {
		side = 0;
	}
	square(int s) {
		side = s;
	}
	void set_side(int s) {
		side = s;
	}
	int get_side() {
		return side;
	}
	square operator +(square s1) {
		square s;
		s.set_side(s1.get_side()+ this->side);
		return s;
	}
};
int main() {
	square s1(5), s2, s3;
	s2.set_side(5);
	s3=s1+s2;
	cout << s3.get_side() << endl;
}
```

you can make this with any operator you want and make compiler understand it 

---

## How compiler understand this?

actually compiler under stand it as a function but function named operator+ 

```cpp
s3 = s1.operator+(s2);
// this is how compiler translate it 
```

acutally this is a right way to write function 

```cpp
s3=s1+s2; == s3=s1.operator+(s2);
```

---