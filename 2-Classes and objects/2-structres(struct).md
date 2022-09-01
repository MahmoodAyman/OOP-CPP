# Struct 

- table of contents
    - [Struct](#what-is-struct)
    - [basic way to define struct](#simple-way-to-define-struct-in-c);
    - [function of return type struct](#you-can-make-function-of-return-type-struct)
    - [array of struct](#you-can-create-an-array-of-struct)
    - [some notes](#some-notes)

### what is struct?

in a simple definition, it’s a way to define a new datatype… just like class  

or we can say it’s a way to group a related variables, each variable in struct called member

---

### simple way to define struct in c++

```cpp
#include<bits/stdc++.h>
using namespace std;
struct car { // define a struct to 
	string name, color; // add related variables 
	int model, max_speed;
};
int main() {
	car c1; // declare a variable of type car 
	c1.name = "BMW"; // access struct members
	c1.color = "red";
	c1.model = 2020;
	c1.max_speed = 350;
}
```

### another way to set values to struct variables

```cpp
#include<bits/stdc++.h>
using namespace std;
struct car { 
	string name, color; 
	int model, max_speed;
};
int main() {
	car c1 = { "BMW","red",2020,350 }; // name , color , model, max_speed 
}
```

### you can declare variable of type struct out of main function

```cpp
#include<bits/stdc++.h>
using namespace std;
struct person {
	string name, id;
	int age;
}p1,p2;
int main() {
	p1.name = "Mahmoud";
	p1.id = "1234567";
	p1.age = 22;
	p2.name = "Ayman";
	p2.id = "1324576";
	p2.age = 52;
	cout << "first person Name is: " << p1.name << " and his age is" << p1.age << " years old" << endl;
}
```

### you can make function of return type struct

```cpp
#include<bits/stdc++.h>
using namespace std;
struct person {
	string name, id;
	int born_date;
	int age = 0;
}p1,p2;
person calculate_age(person x) {
	x.age = 2022 - x.born_date;
	return x; // return struct of type person 
}
int diff_between_ages(person x, person y) {
	return abs(x.age - y.age);
}
int main() {
	p1.name = "Mahmoud";
	p1.id = "1234567";
	p1.born_date = 2000;
	p2.name = "Ayman";
	p2.id = "1324576";
	p2.born_date = 1971;
	p1.age = calculate_age(p1).age;
	p2.age=calculate_age(p2).age;
	cout << "difference between ages = " << diff_between_ages(p1, p2) << endl;
}
```

### you can create an array of struct

```cpp
#include<bits/stdc++.h>
using namespace std;
struct car {
	string name, color;
	int model, max_speed;
};
int main() {
	car c[10]; // array of type car and size 10 
	for (int i = 0; i < 10; i++) {
		cin >> c[i].name >> c[i].color >> c[i].model >> c[i].max_speed;
	}
	cout << "------------------------------------------------" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "the car number "<<i<<" name is : " << c[i].name << endl;
		cout << "and it's color is " << c[i].color << endl;
		cout << "max speed = " << c[i].max_speed << ", and it's " << c[i].model << endl;
		cout << "------------------------------------------------" << endl;
	}
}
```

---

### some notes

- you can’t compare two structs to each other but you can compare variables inside these two structs
- you can declare struct as new data type inside classes