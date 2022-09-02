see this code first:

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
	my_class operator +(int n) {
		my_class temp;
		temp.x = this->x + n;
		temp.y = this->y + n;
		return temp;
	}
	
};
int main() {
	my_class obj1(1, 2), obj2(2, 3), obj;
	obj = obj1 + 2; // as compiler read it will be obj1.operator+(2)
	obj.print(); // output will be 3 4 
}
```

### now what about:

```cpp
obj=2+obj1;
```

this is totally wrong cause as we know compiler read it as: 2.operator+(obj1); 

and there is nothing in language like this at all 

### now how we solve this?

we need to make operator+ to perform the previous operation 

```cpp
obj= .operator+(2,obj1) 
// there is nothing in language like this 
```

as we see we need to call operator+ method

but in this time operator+ method is non member in our class we need to make 

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
	friend my_class operator+(int x,my_class c);
};
my_class operator+(int x,my_class c)  { // watch order of parameters 
	my_class temp;
	temp.x = x + c.x;
	temp.y = x + c.y;
	return temp;
}
int main() {
	my_class obj1(1, 2), obj2(2, 3), obj;
	obj = 2 + obj1;
	obj.print();
}
```