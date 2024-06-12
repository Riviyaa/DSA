#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

// Function to partition an array around a pivot
vector<int> partition(vector<int> arr)
{
    // Create two empty vectors to hold elements less than and greater than the pivot
    vector<int> left, right;

    // Choose the first element of the array as the pivot
    int pivot = arr[0];

    // Loop over the array, starting from the second element
    for (size_t i = 1; i < arr.size(); i++)
    {
        // If the current element is less than the pivot, add it to the left vector
        if (arr[i] <= pivot)
        {
            left.push_back(arr[i]);
        }
        // If the current element is greater than the pivot, add it to the right vector
        else if (arr[i] >= pivot)
        {
            right.push_back(arr[i]);
        }
    }

    // Add the pivot to the end of the left vector
    left.push_back(pivot);

    // Append the right vector to the end of the left vector
    left.insert(left.end(), right.begin(), right.end());

    // Return the left vector, which now contains all elements partitioned around the pivot
    return left;
}

// Main function
int main()
{
    string n_temp;
    // Read the first line of input (the size of the array)
    getline(cin, n_temp);

    // Convert the size to an integer and trim any leading or trailing whitespace
    size_t n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    // Read the second line of input (the array)
    getline(cin, arr_temp_temp);

    // Trim any leading or trailing whitespace from the array
    string arr_temp = ltrim(rtrim(arr_temp_temp));

    // Split the array into a vector of strings
    vector<string> arr_temp_split = split(arr_temp);

    // Initialize a vector of integers with the size of the array
    vector<int> arr(n);

    // Loop over the vector of strings
    for (size_t i = 0; i < n; i++)
    {
        // Convert each string to an integer and add it to the vector of integers
        int arr_item = stoi(arr_temp_split[i]);

        arr[i] = arr_item;
    }

    // Perform the quicksort partition operation on the array
    vector<int> result = partition(arr);

    // Loop over the result
    for (size_t i = 0; i < result.size(); i++)
    {
        // Print each element of the result
        cout << result[i];

        // If the current element is not the last one, print a space after it
        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }

    // Print a newline character
    cout << "\n";

    // Return 0 to indicate successful execution
    return 0;
}