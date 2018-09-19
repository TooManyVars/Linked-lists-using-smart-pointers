#pragma once

#include <iostream>
#include <memory>

using namespace std;

struct node
{

public:
	int data;
	shared_ptr<node>next; //the next node in the list.

	int getData() { return data; }
	shared_ptr<node>getNextNode() { return next; }
};

class linkedList
{
	//The full function overview in the main.cpp file.

private:
	//essentially reports how many nodes are in the list. private because there's not much need to make it otherwise.
	int length;

	void assignTail(); //assigns a new tail node, so that if we only make the list using the method pushNodeFront, tail isn't null.

	void gap() { cout << " " << endl; } //helper method used to format code desirably.

public:

	int getLength() { return length; } //getter function for length.
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

	//misellaneous functionality.
	void help();
	void emptyList() { cout << "--------------------------------\nThere were no nodes within the list to delete. method terminated.\n--------------------------------" << endl; }
	void clear(); //clears the entire linked list.
};