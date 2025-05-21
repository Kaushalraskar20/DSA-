#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int front, rear, capacity;
    int* queue;
    
    
    Queue(int c)
    {
        front = 0;
        rear = -1;
        capacity = c;
        queue = new int[c];
    }

    
    Queue() { delete[] queue; }

    
    void queueEnqueue(int data)
    {
        
        if (rear == capacity - 1) {
            printf("\nQueue is full\n");
            return;
        }

      
        queue[++rear] = data;
    }

};