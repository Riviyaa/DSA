#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> closestNumbers(vector<int> arr)
{
    // Create a copy of the input array and sort it
    vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());

    // Initialize the result vector and the minimum difference
    vector<int> result;
    int minDiff = INT_MAX;

    // Loop over the sorted array, starting from the second element
    for (size_t i = 1; i < sorted.size(); i++)
    {
        // Calculate the difference between the current element and the previous one
        int diff = sorted[i] - sorted[i - 1];

        // If this difference is less than the current minimum difference
        if (diff < minDiff)
        {
            // Update the minimum difference
            minDiff = diff;

            // Clear the result vector and add the pair of elements with the new minimum difference
            result.clear();
            result.push_back(sorted[i - 1]);
            result.push_back(sorted[i]);
        }
        // If this difference is equal to the current minimum difference
        else if (diff == minDiff)
        {
            // Add the pair of elements with this difference to the result vector
            result.push_back(sorted[i - 1]);
            result.push_back(sorted[i]);
        }
    }

    // Return the result vector
    return result;
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

    vector<int> result = closestNumbers(arr);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }

    cout << "\n";

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
