#pragma once



template<typename T>
class Stack
{
	T arr[max];
	
    int top;
public:
	Stack();
	bool push(T);
	char pop();
	bool isempty();
	void clear();
	T peek();
};

template<typename T>
T Stack<T>::peek() {
	return arr[top];
}
template<typename T>
Stack<T>::Stack() {
	top = -1;
}

template<typename T>
bool Stack<T>::push(T item) {
	if (top < max) {
		arr[++top] = item;
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
char Stack<T>::pop() {
	T item;
	if (top > -1) {
		item = arr[top--];
		return item;
	}
}
template<typename T>
bool Stack<T>::isempty() {
	if (top == -1)
		return true;
	else
		return false;
}

template<typename T>
void Stack<T>::clear() {
	top = -1;
}