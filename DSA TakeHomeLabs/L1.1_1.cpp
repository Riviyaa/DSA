#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    if (n == 1)
        cout << "one"; // If the input number is 1, print "one"
    else if (n == 2)
        cout << "two"; // If it's 2, print "two"
    else if (n == 3)
        cout << "three"; // If it's 3, print "three"
    else if (n == 4)
        cout << "four"; // If it's 4, print "four"
    else if (n == 5)
        cout << "five"; // If it's 5, print "five"
    else if (n == 6)
        cout << "six"; // If it's 6, print "six"
    else if (n == 7)
        cout << "seven"; // If it's 7, print "seven"
    else if (n == 8)
        cout << "eight"; // If it's 8, print "eight"
    else if (n == 9)
        cout << "nine"; // If it's 9, print "nine"
    else
        cout << "Greater than 9"; // for anything other than 1-9 print "Greater than 9"
    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
