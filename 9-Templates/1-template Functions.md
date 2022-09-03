## Introduction

I know if I want to make function to add two integers How I do that 

```cpp
#include<bits/stdc++.h>
using namespace std;
int sum(int x,int y){
reutrn x+y;
};
int main(){
	cout<<sum(2,3)<<endl;
}
```

this is perfect 

but what if I told you I need to make function that add any two variables? 

I mean if I pass to it 2  doubles it will be add them and return value of type double 

and if I pass to it 2 integers it will be add them and return integer value

---

Here is we start talk about templates 

### see this example:

```cpp
#include<bits/stdc++.h>
using namespace std;
template<class t>
t sum(t x, t y) {
	return x + y;
}
int main() {
	int x = 10, y = 12;
	double a = 10.5, b = 11.3;
	cout << sum(x, y) << endl; 
	cout << sum(a, b) << endl;
	// but 
	//cout << sum(a, x) << endl; // this is wrong cause function accept only parameters of one type
}
```

output: 

`22`

`21.8`

but as we see it’s wrong to add 2 different types 

but how we deal with that? 

then I need to define  2 templates 

```cpp
#include<bits/stdc++.h>
using namespace std;
template<class t1,class t2>
t1 sum(t1 x, t2 y) {
	return x + y;
}
int main() {
	int x = 10, y = 12;
	double a = 10.5, b = 11.3;
	cout << sum(a, x) << endl; 
}
```

output: 

`20.5`

### watch out if you replace parameters!

```cpp
#include<bits/stdc++.h>
using namespace std;
template<class t1,class t2>
t1 sum(t1 x, t2 y) {
	return x + y;
}
int main() {
	int x = 10, y = 12;
	double a = 10.5, b = 11.3;
	cout << sum(x, a) << endl; 
}
```

output:

`20`

### why?

cause return type of function is the same type of first parameter 

so when I pass first parameter as double the return type was double 

but when I pass first parameter as int the return type was int and couldn’t treat double 

### but is there is a solution for this problem?

```cpp
#include<bits/stdc++.h>
using namespace std;
template<class t1,class t2>
t1 sum(t1 x, t2 y) {
	return x + y;
}
int main() {
	int x = 10, y = 12;
	double a = 10.5, b = 11.3;
	cout << sum<double>(y, b) << endl; 
}
```

output: 

`23.3`

this <double> make compiler treat with first parameter as double no matter what 

mean even y is an integer the template will become of type double and since the function return type from the same template 

this means that the function will return double also 

---

```cpp
#include<bits/stdc++.h>
using namespace std;
template<class t1,class t2>
t1 sum(t1 x, t2 y) {
	return x + y;
}
int main() {
	int x = 10, y = 12;
	double a = 10.5, b = 11.3;
	cout << sum<double,int>(y, b) << endl; 
}
```

here will make y double and b integer no matter what their type at beginning