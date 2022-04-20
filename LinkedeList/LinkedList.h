#pragma once
#include"Node.h"
#include<iostream>
using namespace std;

class LinkedList
{
	Node* Head;
public:
	LinkedList();
	void isert(int value);
	void deletenode(int offset);
	void display();
};

