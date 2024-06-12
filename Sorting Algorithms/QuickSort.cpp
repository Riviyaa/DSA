#include <iostream>
#include <sstream>
#include <vector>

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

// Function to partition the array on the basis of pivot
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

int main()
{
    // Read the input and store as an array
    vector<int> inputArray = returnArray();
    // Sort the array using QuickSort
    quickSortRecursive(inputArray, 0, inputArray.size() - 1);
    // Print the sorted array
    for (size_t i = 0; i < inputArray.size(); i++)
    {
        cout << inputArray[i] << " ";
    }
    return 0;
}
