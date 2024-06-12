#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include <stack>

using namespace std::chrono;
using namespace std;

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

int main()
{
    vector<int> arrayLengths;
    for (size_t i = 3; i < 50; i += 2)
    {
        arrayLengths.push_back(i);
    }
    vector<double> recursiveTimes;
    vector<double> iterativeTimes;

    // Open two different files to write data for Gnuplot
    std::ofstream dfile1("recursiveQuickSort.txt", std::ios::trunc);
    dfile1 << "# Array Length vs Sorting Time(ns)" << endl;

    std::ofstream dfile2("iterativeQuickSort.txt", std::ios::trunc);
    ;
    dfile2 << "# Array Length vs Sorting Time(ns)" << endl;

    for (int size : arrayLengths)
    {
        vector<int> arr(size);
        vector<int> arr_backup = arr;
        // Initialize the array with random values
        for (int i = 0; i < size; ++i)
            arr[i] = rand();

        double total_time1 = 0;
        double total_time2 = 0;
        int runs = 5;

        for (int i = 0; i < runs; i++)
        {
            auto start1 = high_resolution_clock::now();
            quickSortRecursive(arr, 0, size - 1);
            auto end1 = high_resolution_clock::now();

            double time1 = duration_cast<nanoseconds>(end1 - start1).count();
            total_time1 += time1;
        }

        double average_time1 = total_time1 / runs;
        recursiveTimes.push_back(average_time1);

        for (int i = 0; i < runs; i++)
        {
            auto start2 = high_resolution_clock::now();
            quickSortIterative(arr_backup);
            auto end2 = high_resolution_clock::now();

            double time2 = duration_cast<nanoseconds>(end2 - start2).count();
            total_time2 += time2;
        }

        double average_time2 = total_time2 / runs;
        iterativeTimes.push_back(average_time2);

        // Write data to the files
        dfile1 << size << " " << average_time1 << endl;
        dfile2 << size << " " << average_time2 << endl;
    }

    // Close the files
    dfile1.close();
    dfile2.close();

    // Plotting the graph using Gnuplot
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "set title 'Quick Sort: Recursive Algorithm vs Iterative Algorithm'\n");
    fprintf(gnuplotPipe, "set xlabel 'Array Length'\n");
    fprintf(gnuplotPipe, "set ylabel 'Time Taken (nanoseconds)'\n");
    fprintf(gnuplotPipe, "plot 'recursiveQuickSort.txt' with linespoints title 'Recurive Algorithm', 'iterativeQuickSort.txt' with linespoints title 'Iterative Algorithm'\n");
    fflush(gnuplotPipe);

    return 0;
}