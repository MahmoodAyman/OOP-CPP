# relational operations

it’s operation to compare 2 or more numeric or character string or logical data 

the result of comparison either true (1) or false (0) 

see the code below: 

```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
	int x = 1, y = 2;
	if (x == y) {

	}
	else if (x > y) {

	}
	else if (x < y) {

	}
}
```

---

### now how we can perform those operations to objects?

see this code:

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
	bool operator==(my_class c) {
		return (x == c.x && y == c.y);
	}
	bool operator<(my_class c) {
		return (x < c.x&& y < c.y);
	}
	bool operator>=(my_class c) {
		return (x >= c.x && y >= c.y);
	}
	bool operator!=(my_class c) {
		return (x != c.x && y != c.y);
	}
};
int main() {
	my_class c1(2, 3), c2(2, 3),c3(1,1);
	if (c1 == c2) {
		cout << "this is application of operator == " << endl;
	}
	if (c3 < c1) {
		cout << "this is application of operator < " << endl;
	}
	if (c1 >= c3) {
		cout << "this is application of operator >= " << endl;
	}
	if (c1 != c3) {
		cout << "this is application of operator !=" << endl;
	}
}
```