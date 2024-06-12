#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    // Complete the code.
    int a;         // initialize variable name a as an integer
    int b;         // initialize variable name b as an integer
    std::cin >> a; // store the first input in a
    std::cin >> b; // store the second input in b
    for (int n = a; n <= b; n++)
    { // for loop to iterate in numbers between a and b
        if (n == 1)
            cout << "one" << endl; // If the input number is 1, print "one"
        else if (n == 2)
            cout << "two" << endl; // If it's 2, print "two"
        else if (n == 3)
            cout << "three" << endl; // If it's 3, print "three"
        else if (n == 4)
            cout << "four" << endl; // If it's 4, print "four"
        else if (n == 5)
            cout << "five" << endl; // If it's 5, print "five"
        else if (n == 6)
            cout << "six" << endl; // If it's 6, print "six"
        else if (n == 7)
            cout << "seven" << endl; // If it's 7, print "seven"
        else if (n == 8)
            cout << "eight" << endl; // If it's 8, print "eight"
        else if (n == 9)
            cout << "nine" << endl; // If it's 9, print "nine"
        else if (n % 2 == 0)
            cout << "even" << endl; // If number > 9 and it's an even number, print "even"
        else
            cout << "odd" << endl; // Else print "odd"
    }
    return 0;
}