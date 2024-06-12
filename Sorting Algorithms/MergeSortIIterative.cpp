#include <iostream>
#include <sstream>
#include <vector>

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

vector<int> merge(vector<int> array, int start, int center, int end)
{                                           // Merge the two arrays
    int leftArraySize = center - start + 1; // Size of the left array
    int rightArraySize = end - center;      // Size of the right array
    vector<int> leftArray(leftArraySize);   // Declare a vector to store the left array
    vector<int> rightArray(rightArraySize); // Declare a vector to store the right array

    for (int i = 0; i < leftArraySize; ++i)
    {
        leftArray[i] = array[start + i]; // Store the left array elements in the vector
    }

    for (int j = 0; j < rightArraySize; ++j)
    {
        rightArray[j] = array[center + 1 + j]; // Store the right array elements in the vector
    }

    int i = 0, j = 0, k = start; // Declare variables to store the indices of the left and right arrays
    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {                                // If the left array element is less than or equal to the right array element
            array[k++] = leftArray[i++]; // Store the left array element in the array
        }
        else
        {                                 // If the right array element is less than the left array element
            array[k++] = rightArray[j++]; // Store the right array element in the array
        }
    }

    while (i < leftArraySize)
    { // Store the remaining elements of the left array in the array
        array[k++] = leftArray[i++];
    }
    while (j < rightArraySize)
    { // Store the remaining elements of the right array in the array
        array[k++] = rightArray[j++];
    }
    return array; // Return the merged array
}

vector<int> mergeSortIterative(vector<int> array)
{                                      // Sort the array using merge sort
    size_t arrayLength = array.size(); // Length of the array
    for (size_t currentSize = 1; currentSize <= arrayLength - 1; currentSize = 2 * currentSize)
    { // Merge subarrays in bottom up manner
        for (size_t leftStart = 0; leftStart < arrayLength - 1; leftStart += 2 * currentSize)
        {                                                                         // Pick starting point of different subarrays of current size
            int center = min(leftStart + currentSize - 1, arrayLength - 1);       // Find ending point of left subarray
            int rightEnd = min(leftStart + 2 * currentSize - 1, arrayLength - 1); // Find ending point of right subarray
            array = merge(array, leftStart, center, rightEnd);                    // Merge subarrays
        }
    }
    return array;
}

int main()
{
    vector<int> array = returnArray(); // Read the input and store as an array
    size_t arrayLength = array.size(); // Length of the array
    array = mergeSortIterative(array); // Sort the array using merge sort
    for (size_t i = 0; i < arrayLength; i++)
    { // Print the sorted array
        cout << array[i] << " ";
    }
    return 0;
}
