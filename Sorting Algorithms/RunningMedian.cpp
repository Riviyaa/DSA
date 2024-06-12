#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
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

// Function to calculate and print the median of a vector
void getMedian(vector<int> &data)
{
    // Sort the data in ascending order
    quickSortRecursive(data, 0, data.size() - 1);
    // Get the size of the data
    int n = data.size();
    // If the size is even
    if (n % 2 == 0)
    {
        // The median is the average of the two middle elements
        cout << fixed << setprecision(1) << (double)(data[n / 2 - 1] + data[n / 2]) / 2 << endl;
    }
    else
    {
        // If the size is odd, the median is the middle element
        cout << fixed << setprecision(1) << (double)data[n / 2] << endl;
    }
}

// Function to create all possible sub-arrays of a given array
vector<vector<int>> createSubArrays(vector<int> &data)
{
    // Vector to store the sub-arrays
    vector<vector<int>> subArrays;
    // Loop over the data
    for (size_t i = 0; i < data.size(); i++)
    {
        // Create a sub-array from the start of the data to the current element
        vector<int> subArray(data.begin(), data.begin() + i + 1);
        // Add the sub-array to the list of sub-arrays
        subArrays.push_back(subArray);
    }
    // Return the list of sub-arrays
    return subArrays;
}

// Main function
int main()
{
    // Get the data
    vector<int> data = returnArray();
    // Create the sub-arrays
    vector<vector<int>> subArrays = createSubArrays(data);
    // Loop over the sub-arrays
    for (vector<int> &subArray : subArrays)
    {
        // Calculate and print the median of the sub-array
        getMedian(subArray);
    }
    // Return 0 to indicate successful execution
    return 0;
}