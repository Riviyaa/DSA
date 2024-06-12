#include <iostream>
#include <chrono>
#include "StackArray.cpp" // Include the array-based implementation header
#include "StackLL.cpp"  // Include the linked list-based implementation header

void testArrayStack()
{
    StackArray arrayStack(20);
    auto start = std::chrono::high_resolution_clock::now();

    // Perform operations on arrayStack
    // Push operations
    arrayStack.push(8);
    arrayStack.push(10);
    arrayStack.push(5);
    arrayStack.push(11);
    arrayStack.push(15);
    arrayStack.push(23);
    arrayStack.push(6);
    arrayStack.push(18);
    arrayStack.push(20);
    arrayStack.push(17);

    // Display
    arrayStack.display();

    // Pop operations
    arrayStack.pop();
    arrayStack.pop();
    arrayStack.pop();
    arrayStack.pop();
    arrayStack.pop();

    // Display
    arrayStack.display();

    // Push operations
    arrayStack.push(4);
    arrayStack.push(30);
    arrayStack.push(3);
    arrayStack.push(1);

    // Display
    arrayStack.display();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Time elapsed for array based implementation: " << duration << " nanoseconds\n";
}

void testLinkedListStack()
{
    StackLL linkedListStack;
    auto start = std::chrono::high_resolution_clock::now();

    // Perform operations on linkedListStack
    // Push operations
    linkedListStack.push(8);
    linkedListStack.push(10);
    linkedListStack.push(5);
    linkedListStack.push(11);
    linkedListStack.push(15);
    linkedListStack.push(23);
    linkedListStack.push(6);
    linkedListStack.push(18);
    linkedListStack.push(20);
    linkedListStack.push(17);

    // Display
    linkedListStack.display();

    // Pop operations
    linkedListStack.pop();
    linkedListStack.pop();
    linkedListStack.pop();
    linkedListStack.pop();
    linkedListStack.pop();

    // Display
    linkedListStack.display();

    // Push operations
    linkedListStack.push(4);
    linkedListStack.push(30);
    linkedListStack.push(3);
    linkedListStack.push(1);

    // Display
    linkedListStack.display();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Time elapsed for linked-list based implementation: " << duration << " nanoseconds\n";
}

int main()
{
    // Test array-based implementation

    testArrayStack();

    // Test linked list-based implementation

    testLinkedListStack();

    return 0;
}
