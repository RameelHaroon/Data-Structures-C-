#pragma once
template<typename T>
class Node
{
public:
	T data;
	Node* previous;
	Node(T);
};
template<typename T>
Node<T>::Node(T num) {
	data = num;
	previous = nullptr;
}

