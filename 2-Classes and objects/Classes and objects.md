# Classes and objects

## 

as you see the structure of the class start with :

class name of class {

inside class we define scopes.. there are 3 scopes

- **private scope**: put all attributes inside this scope and this means you can access these only inside class and can’t access them in main function for example
- **Public scope**:  all methods inside this scope and this means you can access them anywhere in your program. usually we put methods inside this scope and call it member methods of functions.. there are main methods you need to put in you class in general
    - **set**: set methods are void functions used to set values in your attributes
    - get: get methods are functions with specific type depends on which attribute you need this function to return and this type of functions used to get the values you already set by set methods
    - more methods and functions that update and modify the attributes
- **protected scope**: same as private scope you can’t access members inside it outside the class but can be accessed by any subclasses

we will know about subclasses soon

};

---

## here simple example on classes for car

this code sounds long but it’s to easy and readable so don’t fear 

```cpp
#include <iostream>
using namespace std;
class car
{
private: // scope 
// all attributes inside private scope called member private and you can access it in this class only
    string car_name, car_color;
    int max_speed, car_model;
public:
    // setters to set values to attributes 
    void set_name(string name)
    {
        car_name = name;
    }
    void set_color(string color)
    {
        car_color = color;
    }
    void set_max_speed(int speed)
    {
        max_speed = speed;
    }
    void set_model(int model)
    {
        car_model = model;
    }
    // getters to get values you already set by setters
    string get_name()
    { // will not has parameters it's already has value
        return car_name;
    }
    string get_color()
    {
        return car_color;
    }
    int get_max_speed()
    {
        return max_speed;
    }
    int get_model()
    {
        return car_model;
    }
    /* other methods */
    void print()
    {
        cout << "Name: " << get_name() << endl;
        cout << "Color: " << get_color() << endl;
        cout << "Max Speed: " << get_max_speed()<< " km/h" << endl;
        cout << "Model: " << get_model() << endl;
    }

// all those function called member functions and to call them inside main you need to  define object from this class
};
// unlike non member function you can call it without define objects cause it's out of the class
void non_member_print_function (){
    cout << "this is non member function you can call me without define object" << endl;
}
int main()
{
    // define object from car class 
    car BMW;
    // set values to attributes by call methods inside class
    BMW.set_name("BMW");
    BMW.set_color("Black");
    BMW.set_model(2020);
    BMW.set_max_speed(350);
    // member print method to print the values you set above 
    BMW.print();

    non_member_print_function(); // non member function without 
}
```

---

in the same way, you can translate any real-world object into a programming object for example a person, employee, or student….