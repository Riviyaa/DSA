#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'insertionSort1' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

void insertionSort1(int n, vector<int> arr)
{
    int temporary = arr[n - 1]; // store the value of the last unsorted array element inside a temporary variable
    int i = n - 2;              // initialize the variable i to the index of the second last element of the array

    while (i >= 0 && arr[i] > temporary)
    {                        // while i is a valid index and its greater then temporary value
        arr[i + 1] = arr[i]; // store the value of the current element i in the element right after it
        i--;                 // decrements the value of i by 1

        for (int j = 0; j < n; j++)
        {                          // for loop to iterate over the elements in the array
            cout << arr[j] << " "; // print the elements in the array with a space between them
        }
        cout << "\n"; // prints a newline
    }

    arr[i + 1] = temporary; // store the value of the temporary variable in the corect place of the array

    for (int j = 0; j < n; j++)
    {                          // for loop to iterate over the elements in the array
        cout << arr[j] << " "; // print the elements in the array with a space between
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort1(n, arr);

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
