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
        size--;
        data[0] = data[size];
        downheap(0, weightArr);


        return tmp;

        // Replace root with last element, then call downheap()
        // return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {

        // TODO: swap child upward while smaller than parent
        while (pos > 1)
        {
            int parentpos = (pos - 1) / 2;
            if (weightArr[data[parentpos]] < weightArr[data[pos]])
            {
                swap(weightArr[data[pos]], weightArr[data[parentpos]]);
                pos = parentpos;
            }
            else {break; }
        }
        // int parentpos = (pos - 1) / 2;
        // // int tmp;
        // while ((weightArr[data[parentpos]] > weightArr[data[pos]]) && pos > 0) // the second part is to
        // {
        //         // tmp = data[parentpos];
        //         // data[parentpos] = data[pos];
        //         // data[pos] = tmp;
        //     swap(weightArr[data[pos]], weightArr[data[parentpos]]);
        //     pos = parentpos;
        //     parentpos = (parentpos - 1) / 2;
        // }


    }

    void downheap(int pos, int weightArr[])
    {
        // TODO: swap parent downward while larger than any child

        while (true)
        {
            int smallestPos = pos;
            int leftChildPos =  pos * 2 + 1;
            int rightChildPos =  pos * 2 + 2;

            if (leftChildPos < size && weightArr[data[leftChildPos]] > weightArr[data[smallestPos]] )
            {
                smallestPos = leftChildPos;
            }
            if (rightChildPos < size && weightArr[data[smallestPos]] < weightArr[data[rightChildPos]])
            {
                smallestPos = rightChildPos;
            }

            if (smallestPos == pos)
            {
                break;
            }
            // tmp = weightArr[smallestPos];
            // weightArr[smallestPos] = weightArr[pos];
            // weightArr[pos] = tmp;
            swap(data[pos], data[smallestPos]);
            pos = smallestPos;
        }
    }
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
        // if (size <= 1)
        // {
        //     return;
        // }
        // if (weightArr[leftChildPos] > weightArr[0])
        // {
        //     swap(weightArr[leftChildPos], weightArr[0]);
        // }
};

#endif