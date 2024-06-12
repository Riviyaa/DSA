#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;       // Make the largest element the root
    int left = 2 * root + 1;  // left of root is always 2*i + 1
    int right = 2 * root + 2; // right of root is always 2*i + 2

    // When left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // When right child is larger than the current largest element
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // When the largest element is no longer the root
    if (largest != root)
    {
        // Change the largest element to the root
        int temporary = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temporary;

        // Do the above steps recursively
        heapify(arr, n, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // Start from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i); // Do the heapify operation

    // Extract the elements from the end of the array
    for (int i = n - 1; i > 0; i--)
    {
        // Put the largest element in the end
        int temporary = arr[0];
        arr[0] = arr[i];
        arr[i] = temporary;

        // Do the heapify operation again
        heapify(arr, i, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    string input;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> heap_arr;

    while (ss >> num)
    {
        heap_arr.push_back(num);
    }

    int n = heap_arr.size();

    heapSort(heap_arr.data(), n);

    displayArray(heap_arr.data(), n);
}