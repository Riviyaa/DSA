//
// Created by Rivindu Thareendra  on 2024-02-24.
//

#ifndef UNTITLED_STACKARRAY_H
#define UNTITLED_STACKARRAY_H

namespace std {

    class StackArray {
    private:
        int size;
        int *stack;
        int top;

    public:
        StackArray (int size);

        void push(int data);

        void pop();

        bool isEmpty();

        bool isFull();

        int stackTop();

        void display();
    };

    };

} // std

#endif //UNTITLED_STACKARRAY_H
