#pragma once
#include<iostream>
#include"Node.h"
using namespace std;

template<typename T>
class CircularQueue
{
	Node<T>* front;
	Node<T>* rear;
public:
	CircularQueue();
	void Enqueue(T num);
	void display();
	T dequeue();
	bool isEmpty();
	
};
template<typename T>
CircularQueue<T>::CircularQueue() {
	front = NULL;
	rear = NULL;
}
template<typename T>
void CircularQueue<T>::Enqueue(T num) {
	Node<T>* n = new Node<T>(num);
	if (front == NULL && rear == NULL) {
		n->next = n;
		front = rear = n;
		return;
	}
	rear->next = n;
	n->next = front;
	rear = n;
}
template<typename T>
void CircularQueue<T>::display() {
	Node<T>* temp = front;
	while (temp->next != front) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " " << endl;
}

template<typename T>
bool CircularQueue<T>::isEmpty() {
	if (front == NULL && rear==NULL)
		return true;
	else
		return false;
}
template<typename T>
T CircularQueue<T>::dequeue() {
	if (isEmpty()) {
		cout << "Queue is empty!\n";
		return -1;
	}
	T returnvalue = front->data;
	if (rear == front) {
		delete front;
		front = rear = NULL;
	}
	else {
		Node<T>* temp = front;
		front = front->next;
		rear->next = front;
		delete temp;
	}
	return returnvalue;
}