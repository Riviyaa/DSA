#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>

using namespace std;

vector<int> returnArray(string inputLine)
{
    istringstream inputStream(inputLine);
    vector<int> array;
    int number;
    while (inputStream >> number)
    {
        array.push_back(number);
    }
    return array;
}

vector<int> insertionSort(vector<int> array)
{
    for (int i = 1; i < array.size(); i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    return array;
}

int main()
{
    string inputLine;
    getline(cin, inputLine);
    vector<int> array = returnArray(inputLine);
    array = insertionSort(array);
    for (int element : array)
    {
        cout << element << " ";
    }
    return 0;
}
