#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template<typename T>
class LinkedList
{
	Node<T>* Last;
public:
	LinkedList();
	void insert(T value);
	void insertAtStart(T value);
	void deletenode();
	void deleteAtStart();
	void display();
	

};
template<typename T>
LinkedList<T>::LinkedList() {
	Last = NULL;
}
template<typename T>
void LinkedList<T>::insert(T value) {
	Node<T>* newNode = new Node<T>(value);

	if (Last == NULL) {
		newNode->next = newNode;
	}
	else {
		newNode->next = Last->next;
		Last->next = newNode;
	}

	Last = newNode;
}
template<typename T>
void LinkedList<T>::insertAtStart(T value) {
	Node<T>* newNode = new Node<T>(value);
	if (Last == NULL) {
		newNode->next = newNode;
		Last = newNode;
	}
	else {
		newNode->next = Last->next;
		Last->next = newNode;
	}
	
}
template<typename T>
void LinkedList<T>::display() {
	Node<T>* curr = Last->next;

	while (curr != Last) {
		cout << curr->data << " ";
		curr=curr->next;
	}
	cout << curr->data << " ";
	cout << endl;

}
template<typename T>
void LinkedList<T>::deletenode() {
	Node<T>* Todelete = Last;
	if (Last == NULL || Last->next == Last) {
		Last = NULL;
		delete Todelete;
	}

	Node<T>* temp = Last->next;

	while (temp->next != Last) {
		temp = temp->next;
	}
	temp->next = Last->next;
	Last = temp;
	delete Todelete;
}
template<typename T>
void LinkedList<T>::deleteAtStart() {
	Node<T>* Todelete = Last->next;
	if (Last == NULL || Last->next == Last) {
		return;
	}

	Node<T>* temp = Last->next;

	temp = temp->next;
	Last->next = temp;

	delete Todelete;

}