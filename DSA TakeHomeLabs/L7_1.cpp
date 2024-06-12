#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    // Use a vector to simulate the heap
    vector<int> heap;

    while (Q--) {
        int type, x;
        cin >> type;
        switch (type) {
        case 1: // Add x to the heap
            cin >> x;
            heap.push_back(x);
            push_heap(heap.begin(), heap.end(), greater<int>());
            break;
        case 2: // Delete x from the heap
            cin >> x;
            auto it = find(heap.begin(), heap.end(), x);
            swap(*it, heap.front());
            pop_heap(heap.begin(), heap.end(), greater<int>());
            heap.pop_back();
            break;
        case 3: // Print the minimum element in the heap
            cout << heap.front() << endl;
            break;
        }
    }

    return 0;
}