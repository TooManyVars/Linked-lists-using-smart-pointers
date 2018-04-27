#pragma once

#include <iostream>
#include <memory>

using namespace std;

struct node
{

public:
	int data;
	shared_ptr<node>next;

	int getData() { return data; }
	shared_ptr<node>getNextNode() { return next; }
};

class linkedList
{
	//function overview in the main() file.

private:
	//essentially reports how many nodes are in the list.
	int length;

	//this function seems to be useless at the moment.w
	void assignTail(); //assigns a new tail node, so that if we only make the list in bulk or pushNodeFront, tail isn't null.

	void gap() { cout << " " << endl; } //used to format code desirably.

public:

	int getLength() { return length; }

	shared_ptr<node>head;
	shared_ptr<node>tail;

	linkedList();
	void displayNodes();

	//functions related to the front of the list.
	void pushNodeFront(int value); 
	void deleteNodeFront(); 
	

	//functions related to the end of the list.
	void appendNode(int value);
	void bulkNodes(int value1 = NULL, int value2 = NULL, int value3 = NULL, int value4 = NULL, int value5 = NULL); //create up to 5 nodes and add them to the list all in one function.
	void popNode(); //deletes the node at the end of the list.


	//functions related to a specific index of the list.
	void insert(int value, int index);
	void deleteIndex(int index);
};