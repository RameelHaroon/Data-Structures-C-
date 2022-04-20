#pragma once
#include<iostream>
using namespace std;
#define max 1000

template<typename T>
class Queue
{
	T MyQueue[max];
	int front;
	int rear;
public:
	Queue();
	void enQueue(T value);
	char deQueue();
	bool isEmpty();
	bool isFull();
};
template<typename T>
Queue<T>::Queue() {
    front = -1;
    rear = -1;
}
template<typename T>
void Queue<T>::enQueue(T value) {
    if (isFull()) {
        cout << endl << "Queue is full!!";
    }
    else {
        if (front == -1)
            front = 0;
        rear++;
        MyQueue[rear] = value;

    }
}
template<typename T>
char Queue<T>::deQueue() {
    T value;
    if (isEmpty())
    {

        return(-1);
    }
    else
    {
        value = MyQueue[front];
        if (front >= rear)
        {
            front = -1;
            rear = -1;
        }
        else {
            front++;
        }

        return(value);
    }
}
template<typename T>
bool Queue<T>::isFull() {
    if (front == 0 && rear == max - 1)
        return true;

    return false;
}
template<typename T>
bool Queue<T>::isEmpty() {
    if (front == -1)
        return true;
    return false;
}