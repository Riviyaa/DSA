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

vector<int> selectionSort(vector<int> array)
{
    int size = array.size();
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        swap(array[minIndex], array[i]);
    }
    return array;
}

int main()
{
    string inputLine;
    getline(cin, inputLine);
    vector<int> array = returnArray(inputLine);
    array = selectionSort(array);
    for (int element : array)
    {
        cout << element << " ";
    }
    return 0;
}
