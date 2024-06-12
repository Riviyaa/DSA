#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Read the input and store as an array
vector<int> returnArray()
{
    // Read the input as a string
    string stream;
    // Convert the input string to a stream
    getline(cin, stream);
    // Declare a vector array to store the input
    vector<int> inputArray;
    // Declare a variable to store the input
    stringstream iss(stream);
    // Read the input stream and store the input in the array
    int number;
    while (iss >> number)
    {
        inputArray.push_back(number);
    }
    // Return the input array
    return inputArray;
}

int partition(vector<int> &array, int start, int end)
{
    // Pivot is the last element
    int pivot = array[end];
    // Index of starting element
    int i = start - 1;

    // Traverse through each element, compare them with pivot
    for (int j = start; j < end; j++)
    {
        // If element smaller than pivot is found, swap it with the first element greater than pivot
        if (array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }

    // Swap the pivot element with the element next to the last smaller element (i+1)
    swap(array[i + 1], array[end]);

    // Return the position of the pivot
    return i + 1;
}

// Function to implement QuickSort
void quickSortIterative(vector<int> &arr)
{
    if (arr.empty())
    {
        return; // The array is empty
    }

    // Create a stack for storing start and end indices
    stack<int> stack;
    // Push the start and end indices of the array to the stack
    stack.push(0);
    stack.push(arr.size() - 1);

    // While it's not empty
    while (!stack.empty())
    {
        // Pop the end indicex from the stack
        int end = stack.top();
        stack.pop();
        // Pop the start index from the stack
        int start = stack.top();
        stack.pop();

        // Partition the array along the pivot
        int pivotIndex = partition(arr, start, end);

        // If there are elements on the left side of the pivot, push the left side range to stack
        if (pivotIndex - 1 > start)
        {
            stack.push(start);
            stack.push(pivotIndex - 1);
        }

        // If there are elements on the right side of the pivot, push the right side range to stack
        if (pivotIndex + 1 < end)
        {
            stack.push(pivotIndex + 1);
            stack.push(end);
        }
    }
}

int main()
{
    // Read the input and store as an array
    vector<int> inputArray = returnArray();
    // Sort the array using QuickSort Non Recursively
    quickSortIterative(inputArray);
    // Print the sorted array
    for (size_t i = 0; i < inputArray.size(); i++)
    {
        cout << inputArray[i] << " ";
    }
    return 0;
}
