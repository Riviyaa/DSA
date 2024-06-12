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

vector<int> bubbleSort(vector<int> array)
{
    int size = array.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
    return array;
}

int main()
{
    string inputLine;
    getline(cin, inputLine);
    vector<int> array = returnArray(inputLine);
    array = bubbleSort(array);
    for (int element : array)
    {
        cout << element << " ";
    }
    return 0;
}
