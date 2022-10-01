## Exception Handling

this phase is after finished code.. this is when shown when user start using our program 

### Example:

assume that at any point of your program you want from user to Enter the hour 

we know that the input value at this time will be number between 1 and 12! 

what if user Enter invalid value like string or negative or number more that 12 

### Ways to solve this:

1. Stop the Program (from user side it called **The program has been crashed** )
2. Send alert to user that there is a problem and then restart the program 
3. Send alert to user and give him access to solve the problem  
4. Complete the program and solve the problem from your side! 

and this is the best  

---

### Testing Phase (try .. catch)

make user test the program in a specific range 

if user do something wrong stop else go to the second phase

```cpp
#include<bits/stdc++.h>

using namespace std;
int main() {
    int hour;
    cin.exceptions(cin.failbit);
    try { // try to take hor as input and see what the input

        cin >> hour;

        if (hour < 1 || hour > 12) {
            throw hour; // mean stop trying this is error and throw it to catch statement
            // see you need to throw something to catch state
        }

        cout << "the time is " << hour << ":00\n"; // if everything of will print this
    }
    catch (int hour) { // this is the variable you pass by throw
        cout << "the time you Enter " << hour << " is wrong value\n"; // if something wrong
    }
}
```

`cin.exceptions(cin.failbit);`

this line not important but it gives compiler hint that might be an error down

---

### you can make more that one catch statement

it like if and else if statements!