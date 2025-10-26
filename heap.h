//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;



struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        weightArr[size] = idx;
        upheap(size, weightArr);
        size++;

    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size <= 0)
        {
            return -1;
        }
        int tmp = weightArr[0];
        weightArr[0] = weightArr[size - 1];
        size--;
        downheap(0, weightArr);
        return tmp;

        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {

        // TODO: swap child upward while smaller than parent
        int parentpos = (pos - 1) / 2;
        // int tmp;
        while (pos != 0 && (weightArr[parentpos] > weightArr[pos])) // the second part is to
        {
                // tmp = data[parentpos];
                // data[parentpos] = data[pos];
                // data[pos] = tmp;
            swap(weightArr[pos], weightArr[parentpos]);
            pos = parentpos;
            parentpos = (parentpos - 1) / 2;
        }


    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int leftChildPos =  0 * 2 + 1;
        int rightChildPos =  0 * 2 + 2;

        if (size <= 1)
        {
            return;
        }
        if (weightArr[leftChildPos] > weightArr[0])
        {
            swap(weightArr[leftChildPos], weightArr[0]);
        }




    }
};

#endif