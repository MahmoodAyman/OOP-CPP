# Static 
- table of content:
    - [Static Variables](#static-variable)
    - [Static Members](#static-members)
    - [Static Fucntions](#static-can-be-function-not-just-variable);
## Static Variable
let's see first what is static Variables

see this:

```cpp
#include<bits/stdc++.h>
using namespace std;
void Func() {
	int x = 0;
	x++;
	cout << x << endl;
}
int main() {
	Func(); //output 1
	Func(); //output 1
	Func(); //output 1
	Func(); //output 1
}
```

let’s add keyword **static** to variable x

```cpp
#include<bits/stdc++.h>
using namespace std;
void Func() {
	static int x = 0;
	x++;
	cout << x << endl;
}
int main() {
	Func(); //output 1
	Func(); //output 2
	Func(); //output 3
	Func(); //output 4
}
```

from the example above we can see that using the keyword static to declare a variable makes the variable common to all functions…

in other words, the variable x will allocate space in memory only one time and will use for the entirety program

and that also means the lifetime of the static variable is the lifetime of the program

---

## Static members 

see this code 

```cpp
#include<bits/stdc++.h>
using namespace std;
class student {
private:
	static int counter; // static variable means it common to all objects 
	// created from that class 
	string name, id;
	int first, second, final, total;
public:
	student() {
		name = "no name";
		id = "0";
		first = second = final = 0;
		counter++; // increase static variable
		cout << "The Number of Students : " << counter << endl;
	}
};
int student::counter = 0; // set initial value to static counter = 0
int main() {
	student s1, s2;
	// count of s1 will equal to 1 
	// count of s2 will equal to 2 
	// and so on...
	student s[10]; // create 10 objects 
	// first element counter will equal to 3
}
```

---
    
## static can be function not just variable

```cpp
#include<bits/stdc++.h>
using namespace std;
class student {
private:
	static int counter; // static variable means it common to all objects 
	// created from that class 
	string name, id;
	int first, second, final, total;
public:
	student() {
		name = "no name";
		id = "0";
		first = second = final = 0;
		counter++; // increase static variable

	}
	static void print_counter() {
		cout << "The Number of Students : " << counter << endl;
	}
};
int student::counter = 0; // set initial value to static counter = 0
int main() {
	student::print_counter(); // anothre way to call static function 
	// will output 0 cause you still not declare objects from class 

	student s1; // declare object 
	s1.print_counter(); // way to call function 
	
}
```
**you can’t call functions like this till it’s static**