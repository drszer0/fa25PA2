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

    void push(int idx, int weightArr[]) { // idx is index and weightArr[idx] is frequency of said character
        // TODO: insert index at end of heap, restore order using upheap()
        if (size >= 64) { return;}
        data[size] = idx; // stores index in that particular size in the heap.
        upheap(size, weightArr); //
        size++;

    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size <= 0)
        {
            return -1;
        }
        int tmp = data[0]; // stores index of the min in the heap.
        size--;
        data[0] = data[size];
        downheap(0, weightArr);


        return tmp;
    }

    void upheap(int pos, int weightArr[]) {

        // TODO: swap child upward while smaller than parent
        while (pos > 1)
        {
            int parentpos = (pos - 1) / 2;
            if (weightArr[data[parentpos]] > weightArr[data[pos]])
            {
                swap(data[pos], data[parentpos]); // swapped indexes
                pos = parentpos;
            }
            else {break; }
        }
    }

    void downheap(int pos, int weightArr[])
    {
        // TODO: swap parent downward while larger than any child

        while (true)
        {
            int smallestPos = pos;
            int leftChildPos =  pos * 2 + 1;
            int rightChildPos =  pos * 2 + 2;

            if (leftChildPos < size && weightArr[data[smallestPos]] > weightArr[data[leftChildPos]] ) // flipped both operators.
            {
                smallestPos = leftChildPos; // checks current pos with the left
            }
            if (rightChildPos < size && weightArr[data[smallestPos]] > weightArr[data[rightChildPos]])
            {
                smallestPos = rightChildPos; // checks smallest of (pos or left) with the right
            }

            if (smallestPos == pos) // this is the base case which ends our for loop.
            {
                break;
            }
            swap(data[pos], data[smallestPos]); // fixes the positions
            pos = smallestPos; // reassigns index.
        }
    }

};

#endif