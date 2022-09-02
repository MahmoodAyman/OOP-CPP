# Unary Operator overloading

- table of content 
    - [what is unary operator](#what-is-the-unary-operator)
    - [unary operations on objects](#to-make-postfix-unary-operations)
    - [prefix unary operations](#to-make-a-prefix-unary-operator)
    - [postfix unary operations](#to-make-postfix-unary-operations)
    - [assign object with perform unary operation](#assign-object-to-another-one-with-doing-unary-operation-on-it)
    - [convert objects to negative](#convert-values-to-negative-or-positive)
    - [! operator](#operator)
    - [+= and -= operations](#or---operations)

to understand this file you need to know **this** keyword you can read about it from [here](../2-Classes%20and%20objects/3-this.md)

## what is the unary operator?

it’s when you want to make operations in one variable only 

```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
	int x = 0,y;
	y = x++;
	cout << y << endl;
	y = ++x;
	cout << y << endl;
}
```

difference between **++x** and **x++:**

 

- **x++:** called postfix and in this case we first print the value of x which is 0 and then increase it by 1
- **++x:** called prefix and in this case we first increase value of x by 1 and then print it

so the value now in first cout line will be **0** and in a second cout line will be **2**

trace it if you confused ****

---

previously we know how to add two objects to each other… now we need to know how to make unary operations on object

```cpp
#include<bits/stdc++.h>
using namespace std;
class my_class {
	int x, y;
public:
	my_class(int i = 0, int j = 0) {
		x = i;
		y = j;
	}
};
int main() {
	my_class obj;
	obj++;
	++obj;
}
```

**absolutely will not work… now** what will we do?

# how to perform unary operations on object?

### to make a prefix unary operator:

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
	void show() {
		cout << x << " " << y << endl;
	}
	void operator++() { // prefix unary operator 
		x++;
		y++;
	}

};
int main() {
	my_class obj;
	++obj; // prefix 
	obj.show();
}
```

this will not work for postfix we need to make a one for postfix 

### to make postfix unary operations:

same as previous code just add **int**  as a parameter 💁🏼‍♂️

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
	void show() {
		cout << x << " " << y << endl;
	}
	void operator++(int) { // just add int as a parameter 
		x++;
		y++;
	}

};
int main() {
	my_class obj;
	obj++; // postfix unary operation 
	obj.show();
}
```

### output for two codes will be:  1 1

---

till now you can’t assign object to another and make unary operator at the same time

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
	void show() {
		cout << x << " " << y << endl;
	}
	void operator++() {
		x++;
		y++;
	}

};
int main() {
	my_class obj,obj1;
	obj1= ++obj;
	obj.show();
}
```

this is still wrong and won’t run 

### assign object to another one with doing unary operation on it:

keep in your mind how postfix and prefix unary operations work actually and trace the code below 

- another thing you need to know is that since you need to assign object to another then the unary operator overloading method will return object right?

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
	void show() {
		cout << x << " " << y << endl;
	}
	my_class operator++() {// prefix 
		// first increase values by 1 and then put it into new object 
		my_class temp;
		temp.x = this->x++;
		temp.y = this->y++;
		return temp;
	}
	my_class operator++(int) { // postfix 
		// first put into new object then increase by 1 
		my_class temp = *this; // save values before increasing 

		this->x++;// increase values 
		this->y++;

		// return values without increasing that you saved before 
		return temp;
	}

};
int main() {
	my_class obj,obj1;
	obj1= obj++; // put obj into obj1 then increase values of obj by 1
	obj.show(); // should print 1 1 since you increase values 
	obj1.show();// should print 0 0 since you assign obj before increasing values
}
```

---

### convert values to negative or positive?

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
	void show() {
		cout << x << " " << y << endl;
	}
	my_class operator-() {
		my_class temp;
		temp.x = -this->x;
		temp.y = -this->y;
		return temp;
	}

};
int main() {
	my_class obj(1,2), obj1;
	obj1 = -obj;
	obj1.show();

}
```

---

### ! operator

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
	bool operator!() {
		return (x == 0 && y == 0); // will return true when x = 0 and y =0 
	}

};
int main() {
	my_class obj(1, 1);
	if (!obj) { // means if obj.x=0 and obj.y=0 print this 
		cout << "true" << endl;
	}
	else { // if one of them not equal to zero print this 
		cout << "false" << endl;
	}

}
```

---

### += or -= operations

```cpp
int main() {
	int x = 1, y = 3;
	y += x;
	cout << y << endl;

}
```

how to make like this operations on objects:

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
	my_class operator +=(my_class o) {
		this->x += o.x;
		this->y += o.y;
		return *this; // reutrn this object after perform this operations 
	}
	void print() {
		cout << x << " " << y << endl;
	}
};
int main() {
	my_class obj(1, 2), obj1(2, 3);
	obj += obj1; 
	obj.print();
	// output will be 3 5 
}
```

same as previous to make -= unary operation or any other