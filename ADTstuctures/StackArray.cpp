//
// Created by Rivindu Thareendra  on 2024-02-24.
//
#include <iostream>

using namespace std;

class StackArray
{               // Define a new class named Stack
private:        // Start of the private section
    int size;   // An integer to hold the size of the stack
    int *stack; // A pointer to an integer array to hold the stack elements
    int top;    // An integer to hold the index of the top element in the stack
public:         // Start of the public section
    StackArray(int size)
    {                          // Constructor that takes the size of the stack as an argument
        top = -1;              // Initialize the top index to -1, indicating an empty stack
        this->size = size;     // Set the size of the stack
        stack = new int[size]; // Allocate memory for the stack array
    }

    void push(int data)
    { // Method to push an element onto the stack
        if (top < size)
        {                      // If the stack is not full
            top++;             // Increment the top index
            stack[top] = data; // Store the data at the new top index
        }
        else
        {                              // If the stack is full
            cout << "Stack is full\n"; // Print a message
        }
        return; // End the method
    }

    void pop()
    { // Method to pop an element from the stack
        if (isEmpty())
        {                                       // If the stack is empty
            cout << "Stack is already empty\n"; // Print a message
        }
        else
        {          // If the stack is not empty
            top--; // Decrement the top index
        }
        return; // End the method
    }

    bool isEmpty()
    { // Method to check if the stack is empty
        if (top == -1)
        {                // If the top index is -1
            return true; // The stack is empty
        }
        else
        {                 // If the top index is not -1
            return false; // The stack is not empty
        }
    }

    bool isFull()
    { // Method to check if the stack is full
        if (top == size - 1)
        {                // If the top index is equal to the size minus 1
            return true; // The stack is full
        }
        else
        {                 // If the top index is not equal to the size minus 1
            return false; // The stack is not full
        }
    }

    int stackTop()
    { // Method to get the top element of the stack
        if (isEmpty())
        {                               // If the stack is empty
            cout << "Stack is empty\n"; // Print a message
            return -1;                  // Return -1
        }
        else
        {                      // If the stack is not empty
            return stack[top]; // Return the top element of the stack
        }
    }

    void display()
    { // Method to display the elements of the stack
        if (isEmpty())
        {               // If the stack is empty
            cout << ""; // Print nothing
        }
        else
        { // If the stack is not empty
            for (int i = top; i >= 0; i--)
            {                            // For each element in the stack, from top to bottom
                cout << stack[i] << " "; // Print the element followed by a space
            }
            cout << endl; // Print a newline
            return;       // End the method
        }
    }
};