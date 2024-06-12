#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

int powerSum(int X, int N)
{
    // Create a helper function
    function<int(int, int)> helper = [&](int X, int num) { // this function tracks the count
        int val = X - pow(num, N);                         // val is the difference between X and num raised to the power of N
        if (val == 0)
        { // if val is 0, return 1
            return 1;
        }
        else if (val < 0)
        { // if val is less than 0, return 0
            return 0;
        }
        return helper(X, num + 1) + helper(val, num + 1); // return the sum of the helper function called with X and num + 1 and val and num + 1
    };

    // Call the helper function
    return helper(X, 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

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
