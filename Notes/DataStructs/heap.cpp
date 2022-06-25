#include <iostream>

using namespace std;

class Heap
{
public:
    int getParent(int i){

    };

    void buildHeap(int array[], int size)
    {
        int start = getParent(size - 1);
        for (int i = start; i >= 0; i--)
        {
            int key = array[i];
            int newPos = heapifyDown(i, key);
            array[newPos] = key;
        }
    };

    int heapifyDown(int i, int key){};

    int heapifyUp(int i, int key){

    };

    int leftChild(int i){};

    int rightChild(int i){};
};