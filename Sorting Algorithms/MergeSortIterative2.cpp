#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> returnArray(){ //Read the input and store as an array
    string stream; //Read the input as a string
    getline(cin,stream); 
    vector<int> inputArray; //Declare a vector array to store the input
    stringstream iss(stream); //Convert the input string to a stream
    int number; //Declare a variable to store the input
    while (iss >> number){ //Read the input stream and store the input in the array
        inputArray.push_back(number); 
    }
    return inputArray;
}

vector<int> merge(vector<int>& array, size_t leftStart, size_t leftEnd, size_t rightStart, size_t rightEnd) {//Merge the two array
    vector<int> tempArray; //Declare a vector to store the merged array
    size_t i = leftStart, j = rightStart; //Declare variables to store the indices of the left and right arrays
    while (i <= leftEnd && j <= rightEnd) { //Start Merging
        if (array[i] <= array[j]) { //If the left array element is less than or equal to the right array element
            tempArray.push_back(array[i++]); //Store the left array element in the merged array
        } else { //else
            tempArray.push_back(array[j++]); //Store the right array element in the merged array
        }
    }
    while (i <= leftEnd) { //Store the remaining elements of the left array in the merged array
        tempArray.push_back(array[i++]);
    }
    while (j <= rightEnd) { ////Store the remaining elements of the right array in the merged array
        tempArray.push_back(array[j++]);
    }
    return tempArray; //Return the mreged array
}

vector<int> mergeSortIterative(vector<int> array){ //Sort the array using merge sort
    size_t arrayLength = array.size(); //Length of the array
    size_t len = 1; //Initialize the length of the subarray
    while (len < arrayLength){ //Merge subarrays in bottom up manner
        size_t i = 0; //Initialize the index of the subarray
        while ( i < arrayLength){ //Merge subarrays of size len
            size_t leftStart = i; //Initialize the starting point of the left subarray
            size_t leftEnd = i + len - 1; //Initialize the ending point of the left subarray
            size_t rightStart = i + len; //Initialize the starting point of the right subarray
            size_t rightEnd = i + len*2 - 1; ////Initialize the ending point of the right subarray
            if (leftEnd >= arrayLength){ //If the left subarray is greater than the array length
                break; //Break
            }
            if (rightEnd >= arrayLength){ //If the right subarray is greater than the array length
                rightEnd = arrayLength - 1; //Set the ending point of the right subarray to the array length
            }
            vector<int> tempArray = merge(array,leftStart,leftEnd,rightStart,rightEnd); //Merge subarrays
            for (size_t j = 0; j < rightEnd - leftStart +1; j++){
                array[i+j] = tempArray[j];
            }
            i = i + 2*len;
        }
        len = 2 * len;
    }
    return array;
}

int main(){
    vector<int> array = returnArray(); //Read the input and store as an array
    size_t arrayLength = array.size(); //Length of the array
    array = mergeSortIterative(array); //Sort the array using merge sort 
    for (size_t i = 0; i < arrayLength; i++){ //Print the sorted array
        cout << array[i] << " ";
    }
    return 0;
}