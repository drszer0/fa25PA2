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
        if (size >= 64) { return;}
        data[size] = idx;
        upheap(size, weightArr);
        size++;

    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size <= 0)
        {
            return -1;
        }
        int tmp = data[0];
        weightArr[0] = weightArr[size - 1];
        size--;
        downheap(0, weightArr);
        return tmp;

        // Replace root with last element, then call downheap()
        // return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {

        // TODO: swap child upward while smaller than parent
        int parentpos = (pos - 1) / 2;
        // int tmp;
        while ((weightArr[data[parentpos]] > weightArr[data[pos]]) && pos > 0) // the second part is to
        {
                // tmp = data[parentpos];
                // data[parentpos] = data[pos];
                // data[pos] = tmp;
            swap(weightArr[data[pos]], weightArr[data[parentpos]]);
            pos = parentpos;
            parentpos = (parentpos - 1) / 2;
        }


    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        if (size <= 1)
        {
            cout << "empty heap" << endl;
            return;
        }

        // int tmp;


        while (true) {
            int leftChildPos =  pos * 2 + 1;
            int rightChildPos =  pos * 2 + 2;
            int smallestPos = pos;
            if (leftChildPos < size && weightArr[data[leftChildPos]] > weightArr[data[smallestPos]] )
            {
                smallestPos = leftChildPos;
            }
            if (rightChildPos < size && weightArr[data[rightChildPos]] > weightArr[data[smallestPos]])
            {
                smallestPos = rightChildPos;
            }

            if (smallestPos != pos)
            {
                swap(weightArr[data[pos]], weightArr[data[smallestPos]]);
                // tmp = weightArr[smallestPos];
                // weightArr[smallestPos] = weightArr[pos];
                // weightArr[pos] = tmp;
                data[pos] = data[smallestPos];
            }
            else { break;}
            // the graveyard of attempts down bellow

        //     if (weightArr[current] < max(weightArr[rightChildPos], weightArr[leftChildPos])
        //
        //     if (weightArr[leftChildPos] >= weightArr[rightChildPos])
        //     {
        //         swap(weightArr[leftChildPos], weightArr[current]);
        //         current = leftChildPos;
        //         leftChildPos = (current * 2) + 1;
        //         rightChildPos = (current * 2) + 2;
        //     }
        //     if (weightArr[rightChildPos] > weightArr[leftChildPos]) {
        }
        // if (size <= 1)
        // {
        //     return;
        // }
        // if (weightArr[leftChildPos] > weightArr[0])
        // {
        //     swap(weightArr[leftChildPos], weightArr[0]);
        // }




    }
};

#endif