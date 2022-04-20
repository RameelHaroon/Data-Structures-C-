#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;

	Node(int n) {
		data = n;
		next = NULL;
	}
};

