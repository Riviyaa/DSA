#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> returnArray()
{                  // Read the input and store as an array
    string stream; // Read the input as a string
    getline(cin, stream);
    vector<int> inputArray;   // Declare a vector array to store the input
    stringstream iss(stream); // Convert the input string to a stream
    int number;               // Declare a variable to store the input
    while (iss >> number)
    { // Read the input stream and store the input in the array
        inputArray.push_back(number);
    }
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

// Function to implement QuickSort
void quickSortRecursive(vector<int> &array, int start, int end)
{
    // Base case: If the start index is greater or equal to end index, the function returns
    if (start > end)
        return;

    // pi is partitioning index, array[p] is now at right place
    int partitioningIndex = partition(array, start, end);

    // Separately sort elements before partition and after partition
    quickSortRecursive(array, start, partitioningIndex - 1);
    quickSortRecursive(array, partitioningIndex + 1, end);
}


vector<int> randomArray(int size)
{ // Generate a random array

    vector<int> array(size); // Declare a vector to store the random array
    int max = 100;
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % max; // Generate a random number and store it in the array
    }
    return array;
}

// THIS FUNCTION CONTAINS THE CODE SNIPPET TO PLOT THE GRAPHS
int main()
{
    vector<double> iterativeTimes;
    vector<double> recursiveTimes;
    vector<double> arrayLengths;
    for (int i = 3; i <= 50; i += 2)
    {
        vector<int> array = randomArray(i);
        auto start1 = chrono::high_resolution_clock::now();
        quickSortRecursive(array, 0, i - 1);
        auto end1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
        recursiveTimes.push_back(duration1.count());
        auto start2 = chrono::high_resolution_clock::now();
        quickSortIterative(array);
        auto end2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
        iterativeTimes.push_back(duration2.count());
        arrayLengths.push_back(i);
    }

    cout << "Array Lengths: " ;
    for (int number : arrayLengths)
    {
        cout << number << ",";
    }
    cout << endl;

    cout << "Recursive Times: " ;
    for (int number : recursiveTimes)
    {
        cout << number << ",";
    }
    cout << endl;

    cout << "Iterative Times: " ;
    for (int number : iterativeTimes)
    {
        cout << number << ",";
    }
    cout << endl;

    return 0;
}
