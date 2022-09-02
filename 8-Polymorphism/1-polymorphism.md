# polymorphism

table of content
- [Introduction to polymorphism](#introduction)
- [types of polymorphism](#there-are-two-main-types-of-polymorphism)
- [Examples](#examples)
    - [Function Overloading](#function-overloading-example)
    - [operator Overloading](#operator-overloading-example)
    - [Function overriding](#function-overriding-example)
- [read more](#more-about-overriding)

## introduction

first, if you don’t know what is polymorphism at all please read about it from [here](../1-What%20is%20OOP/2-main%20princeples%20in%20OOP.md#Polymorphism) and continue

briefly 

polymorphism means having many forms 

let’s take an example: 

a person who at the same time can have different characteristics. like a person can be student or can be teacher 

same person has different behavior in different situations 

---

### there are two main types of polymorphism

- **compile-time polymorphism:**  this type happen by function overloading or operator overloading
    - **Function overloading**: When there are multiple functions with the same name but different parameters.
        
         Functions can be overloaded by **changing the number of arguments** or/and **changing the type of arguments**
        
    - **Operator Overloading**: we can make use of the addition operator (+) for string class to concatenate two strings. 
    actually we have a section talk about operator overloading you can see from here
- **run-time polymorphism:**  this type achieved by function overriding
    - **Function overriding**: occurs when a derived (sub) class has a definition for one of the member functions of the base (super) class.
     in this case base function is said to be **overridden**.

---

## Examples:

1. compile-time polymorphism: 
    
    ### Function overloading Example:
    
    ```cpp
    #include<bits/stdc++.h>
    using namespace std;
    class my_class {
    private:
    	int var1, var2;
    public:
    	void function(int x) { // function with one int parameter
    		cout << "value of x is" << x << endl;
    	}
    	void function(int x, int y) { // same name of function with two parameters
    		cout << "value of x is: " << x << " and y is: " << y << endl;
    	}
    	void function(double x) { // same name of function with one double parameter
    		cout << "value of x in double is : " << x << endl;
    	}
    };
    
    int main() {
    	my_class obj;
    	obj.function(5);
    	obj.function(5, 3);
    	obj.function(5.2);
    }
    ```
    
    output:
    
    `value of x is5`

    `value of x is: 5 and y is: 3`

    `value of x in double is : 5.2`
    
    ### Operator overloading Example:
    
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
    //getters and setters
    	void set_side(int s) {
    		side = s;
    	}
    	int get_side() {
    		return side;
    	}
    // operator overloading 
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
    
    ouptut:
    
    `10`
    
2. run-time polymorphism 
    
    ### Function overriding Example:
    
    ```cpp
    #include<bits/stdc++.h>
    using namespace std;
    class base_class {
    public:
    	virtual void print() { 
    		cout << "this message from base class print function" << endl;
    	}
    	void show() {
    		cout << "this message from base class show function" << endl;
    	}
    };
    class derived_class : public base_class{
    public:
    	void print() {
    		cout<< "this message from derived class print function" << endl;
    	}
    	void show() {
    		cout << "this message from derived class show function" << endl;
    	}
    };
    
    int main() {
    
    	base_class *b_pointer; // this is pointer 
    
    	derived_class d; // this is object 
    
    	b_pointer = &d; // now assign pointer to this object 
    
    	// yes it's from another class but it also a derived class so we're good 
    	b_pointer->print(); // -> because it's pointer can't use . 
    	// print is a virtual function so it's binded at run time 
    
    	b_pointer->show();
    	//show not a virtual function so it's binded at compile time 
    }
    ```
    
    Notes:
    
    - virtual function is a function declared in base class and can overriding by derived class
    - *b_pointer is a pointer from a class not object so you can assign it to another object as we see above
    - pointers work with ( - >) sign not ( . )
    - virtual function bound at run-time but non virtual function bound at compile time
    
    output of previous code:
    
    `this message from derived class print function`

    `this message from base class show function`
    
    ---
    
    ##### More about overriding: 
    wanna read more about run-time polymorphism? read from [here](https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-cpp/)