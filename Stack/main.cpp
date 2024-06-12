#include <iostream>
#include "StackArray.h"

int main() {
    StackArray stackFromArray(5);
    stackFromArray.push(1);
    stackFromArray.push(2);
    stackFromArray.display();
    return 0;
}
