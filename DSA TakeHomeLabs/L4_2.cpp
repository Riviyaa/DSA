#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// Function definition, takes a vector of integers as argument
int lilysHomework(vector<int> arr)
{

    // Create a copy of the input array
    vector<int> sortedArr(arr);
    // Sort the copy in ascending order
    sort(sortedArr.begin(), sortedArr.end());

    // Create another copy of the input array
    vector<int> reverseSortedArr(arr);
    // Sort this copy in descending order
    sort(reverseSortedArr.begin(), reverseSortedArr.end(), greater<int>());

    // Create two more copies of the input array to perform swaps
    vector<int> arrCopy1(arr), arrCopy2(arr);
    // Initialize swap counters for both ascending and descending order
    int swaps = 0, reverseSwaps = 0;

    // Iterate over the input array
    for (size_t i = 0; i < arr.size(); i++)
    {
        // If the current element is not in its correct position in the ascending order
        if (arrCopy1[i] != sortedArr[i])
        {
            // Find the correct position of the current element in the sorted array
            auto correctPos = find(arrCopy1.begin() + i, arrCopy1.end(), sortedArr[i]) - arrCopy1.begin();
            // Swap the current element with the element at its correct position
            swap(arrCopy1[i], arrCopy1[correctPos]);
            // Increment the swap counter for ascending order
            swaps++;
        }
    }

    // Iterate over the input array again
    for (size_t i = 0; i < arr.size(); i++)
    {
        // If the current element is not in its correct position in the descending order
        if (arrCopy2[i] != reverseSortedArr[i])
        {
            // Find the correct position of the current element in the reverse sorted array
            auto correctPos = find(arrCopy2.begin() + i, arrCopy2.end(), reverseSortedArr[i]) - arrCopy2.begin();
            // Swap the current element with the element at its correct position
            swap(arrCopy2[i], arrCopy2[correctPos]);
            // Increment the swap counter for descending order
            reverseSwaps++;
        }
    }

    // Return the minimum of the two swap counters
    return min(swaps, reverseSwaps);
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

    int result = lilysHomework(arr);

    cout << result << "\n";

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
