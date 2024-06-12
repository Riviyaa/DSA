#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>

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

vector<int> mergeSortRecursive(vector<int> array, int start, int end)
{ // Sort the array using merge sort recursively
    if (start < end)
    {                                                       // If the start index is less than the end index
        int center = (start + end) / 2;                     // Find the center index
        array = mergeSortRecursive(array, start, center);   // Sort the left half of the array
        array = mergeSortRecursive(array, center + 1, end); // Sort the right half of the array
        array = merge(array, start, center, end);           // Merge the sorted halves
    }
    return array;
}

vector<int> mergeSortIterative(vector<int> array)
{                                      // Sort the array using merge sort iteratively
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

void printTimes(vector<int> array, string prompt)
{
    cout << prompt + ": " + "[";
    for (int time : array)
    {
        cout << time << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> iterativeTimes;
    vector<int> recursiveTimes;
    vector<int> bubbleTimes;
    vector<int> insertionTimes;
    vector<int> selectionTimes;

    for (int i = 3; i <= 50; i += 2)
    {
        vector<int> array = randomArray(i);
        auto start1 = chrono::high_resolution_clock::now();
        mergeSortRecursive(array, 0, i - 1);
        auto end1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
        recursiveTimes.push_back(duration1.count());
        auto start2 = chrono::high_resolution_clock::now();
        mergeSortIterative(array);
        auto end2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
        iterativeTimes.push_back(duration2.count());
        auto start3 = chrono::high_resolution_clock::now();
        bubbleSort(array);
        auto end3 = chrono::high_resolution_clock::now();
        auto duration3 = chrono::duration_cast<chrono::microseconds>(end3 - start3);
        bubbleTimes.push_back(duration3.count());
        auto start4 = chrono::high_resolution_clock::now();
        insertionSort(array);
        auto end4 = chrono::high_resolution_clock::now();
        auto duration4 = chrono::duration_cast<chrono::microseconds>(end4 - start4);
        insertionTimes.push_back(duration4.count());
        auto start5 = chrono::high_resolution_clock::now();
        selectionSort(array);
        auto end5 = chrono::high_resolution_clock::now();
        auto duration5 = chrono::duration_cast<chrono::microseconds>(end5 - start5);
        selectionTimes.push_back(duration5.count());
    }
    printTimes(iterativeTimes, "Iterative Times");
    printTimes(recursiveTimes, "Recursive Times");
    printTimes(bubbleTimes, "Bubble Sort Times");
    printTimes(insertionTimes, "Insertion Sort Times");
    printTimes(selectionTimes, "Selection Sort Times");
}
