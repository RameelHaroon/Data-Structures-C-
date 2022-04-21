#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template<typename T>
class Stack
{
	Node<T>* top;
public:
	Stack();
	void push(T);
	int pop();
	bool isEmpty();
	void display();
};

template<typename T>
Stack<T>::Stack() {
	top = nullptr;
}
template<typename T>
void Stack<T>::push(T num) {
	Node<T>* temp = new Node<T>(num);

	temp->previous = top;

	top = temp;
}
template<typename T>
int Stack<T>::pop() {
	Node<T>* temp = top;
	if (!isEmpty()) {

		top = top->previous;
	}
	int value = temp->data;
	delete temp;
	return value;
}
template<typename T>
bool  Stack<T>::isEmpty() {
	if (top->previous == nullptr)
		return true;
	return false;
}

template<typename T>
void Stack<T>::display() {
	Node<T>* temp = top;

	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->previous;
	}
	cout << endl;
}
