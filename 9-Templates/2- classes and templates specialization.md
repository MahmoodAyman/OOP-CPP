## Templates with classes

can’t create class and attributes of type template in normal way there are some rules 

- you need to define type of class inside <> signs
- when you define member function outside class you need redefinition for template
- when you try to create object of the class in main you need to define type of data between <>

### see this code:

and read comments for understanding 

```cpp
#include<bits/stdc++.h>
using namespace std;
template<class t>
class my_class {
	t one, two;
public:
	my_class(t a,t b){
		one = a;
		two = b;
	}
	t max(); // function of return type t
};

template<class t> // this line must be written 
t my_class<t>::max() { // see how define template member function outside the class 
	return (first > second ? first : second);
}// this function return max between first 

int main() {
	my_class <int>obj(10, 20); // see you need to set type of data you want inside <>
}
```

---

## Templates specialization

that means not calling class till passing to the parameterized constructor a specific type of data

### see this example:

```cpp
#include<bits/stdc++.h>
using namespace std;
template<class t>
class my_class {
public:
	my_class(t a,t b){
		cout << "this is default class when no special type of data passed to constructor" << endl;
		cout << "just template" << endl;
	}
};

template <>// template specialization 
class my_class<char> {
public:
	my_class(char a, char b) {
		cout << "this is special class when parameterized constructor has parameters of type char" << endl;
	}
};

int main() {
	my_class<int>obj1(1, 2); // this will call first class cause it's arguments not chars

	my_class <char>obj('a', 'b');// this will call the second definition of class
}
```