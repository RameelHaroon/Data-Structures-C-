#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template<typename T>
class LinkedList
{
	Node<T>* Head;
public:
	LinkedList();
	void isert(int value);
	void deletenode(int offset);
	void display();
	void removeDuplicates();
	void bubblesort();
	void deletemiddle();
	int length();
};
template<typename T>
void LinkedList<T>::removeDuplicates() {
	Node<T>* temp1 = Head;				
	Node<T>* temp2 = nullptr;			
	Node<T>* temp3 = nullptr;			
	while (temp1->next != NULL) {				
		if (temp1->data == temp1->next->data) { 
			temp2 = temp1->next;				
			temp1->next = temp2->next;	
			delete temp2;
		}
		else {									
			temp2 = temp3 = temp1->next;		

			while (temp2 != NULL) {

				if (temp1->data == temp2->data) { 
					temp3->next = temp2->next;
					delete temp2;
					temp2 = temp3->next;
				}
				else {							
					temp3 = temp2;
					temp2 = temp2->next;
				}
			}

			temp1 = temp1->next;
		}
		}
		
}

template<typename T>
LinkedList<T>::LinkedList() {
	Head = NULL;
}
template<typename T>
void LinkedList<T>::isert(int value) {
	Node<T>* newNode = new Node<T>(value);

	if (Head == NULL) {
		Head = newNode;
		return;
	}

	Node<T>* temp = Head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
}
template<typename T>
void LinkedList<T>::deletenode(int offset) {
	Node<T>* temp1 = Head;
	Node<T>* temp2 = Head;

	if (offset == 1) {
		Head = Head->next;
		delete temp1;
		return;
	}


	while (offset > 1) {
		temp2 = temp1;
		temp1 = temp1->next;
		offset--;
	}

	temp2->next = temp1->next;
	delete temp1;
}
template<typename T>
void LinkedList<T>::display() {
	Node<T>* temp = Head;
	int len = 0;
	while (temp->next != NULL) {
		len++;
		temp = temp->next;
	}
	temp = Head;
	for (int i = 0; i <= len; i++) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
template<typename T>
int LinkedList<T>::length() {
	Node<T>* temp = Head;
	int count = 0;
	while (temp!= NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}
template<typename T>
void LinkedList<T>::bubblesort() {
	Node<T>* temp2 = nullptr;
	Node<T>* temp1 = nullptr;
	int temp = 0;
	for (int i = 0; i < length(); i++) {
		temp2 = Head;
		temp1 = Head->next;
		for (int j = 0; j < length() - i-1; j++) {
			if (temp1->data > temp2->data) {
				temp = temp1->data;
				temp1->data = temp2->data;
				temp2->data = temp;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}

	
}
template<typename T>
void LinkedList<T>::deletemiddle() {
	Node<T>* temp2 = Head;
	Node<T>* temp1 = Head->next;
	int offset = length() / 2;
	while (1) {
		offset--;
		if (offset == 0) {
			temp2->next = temp1->next;
			break;
		}
		temp2 = temp2->next;
		temp1 = temp1->next;
	}
}