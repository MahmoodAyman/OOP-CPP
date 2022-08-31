## Enumeration

### what is Enumeration?

we used Enum or Enumeration to define constants integer values 

- days of the week can be Enumeration Sat day = 1 , Sun = 2 …. and so on

and we can use it anywhere in program 

---

### How do we define Enumeration in C++?

```cpp
#include<bits/stdc++.h>
using namespace std;

enum seasons { spring, summer, autumn, winter };

int main() {
int s[4] = { spring, summer, autumn, winter };
	for (int i = 0; i < 4; i++) {
		cout << s[i] << endl; // output is an integer value from 0 to 3
	}
}
```

this simply means:

Simplified translation of the previous code is:

```cpp
#include<bits/stdc++.h>
using namespace std;

const int sat = 0;
const int sun = 1;
const int mon = 2;
const int tue = 3;
const int wed = 4; 
const int thu = 5;
const int fri = 6;

int main() {

}
```

---

### some attributes:

- the output of enumeration is a constant integer value
- as you know enumeration is a constant value so you can’t modify them
- the first element of enumeration is equal to 0

---

### what if you want to start from another value, not 0

```cpp
#include<bits/stdc++.h>
using namespace std;
enum days_of_week { sat=1, sun, mon, tue, wed, thu, fri }; 
int main() {
	int days[7] = { sat, sun, mon, tue, wed, thu, fri };
	string d[7] = { "sat", "sun", "mon", "tue", "wed", "thu", "fri" };
	for (int i = 0; i < 7; i++) {
		cout << "the day " << days[i] << " is " << d[i] << endl;
	}
	/*
	* output will be 
	* the day 1 is sat
	  the day 2 is sun
	  the day 3 is mon
	  the day 4 is tue
	  the day 5 is wed
	  the day 6 is thu
	  the day 7 is fri
	*/
}
```

actually you can set every element with value 

```cpp
enum days_of_week { sat = 1, sun = 5, mon = 6, tue = 16, wed = 90, thu = 120, fri = 300 };
```

---