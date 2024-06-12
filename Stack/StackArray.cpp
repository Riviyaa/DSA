//
// Created by Rivindu Thareendra  on 2024-02-24.
//

#include "StackArray.h"
#include <iostream>

using namespace std;

class Stack {
private:
    int size;
    int *stack;
    int top;
public:
    StackArray(int size) {
        top = -1;
        this->size = size;
        stack = new int[size];
    }

    void push(int data){
        if (top < size){
            top++;
            stack[top] = data;
        } else {
            cout << "Stack is full\n";
        }
        return;
    }

    void pop(){
        if (isEmpty()){
            cout << "Stack is already empty\n";
        } else {
            top--;
        }
        return;
    }

    bool isEmpty(){
        if (top == -1){
            return true;
        } else {
            return false;
        }
    }

    bool isFull(){
        if (top == size - 1){
            return true;
        } else {
            return false;
        }
    }

    int stackTop(){
        if (isEmpty()){
            cout << "Stack is empty\n";
            return -1;
        } else {
            return stack[top];
        }
    }


    void display(){
        if (isEmpty()){
            cout << "";
        } else {
            for (int i = top; i >= 0; i--){
                cout << stack[i] << " ";
            }
            cout << endl;
            return;
        }
    }
};