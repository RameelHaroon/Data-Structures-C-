#include "LinkedList.h"

LinkedList::LinkedList() {
	Head = NULL;
}

void LinkedList::isert(int value) {
	Node* newNode = new Node(value);

	if (Head == NULL) {
		Head = newNode;
		return;
	}

	Node* temp = Head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newNode;
}

void LinkedList::deletenode(int offset) {
	Node* temp1 = Head;
	Node* temp2 = Head;

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

void LinkedList::display(){
	Node* temp = Head;
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