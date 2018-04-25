#include <iostream>
#include <memory>
#include "Class_And_Node.h"

linkedList::linkedList()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}


void linkedList::assignTail()
{
	//iterate through till the end of the list until you hit a node with a null next value.
	shared_ptr<node>currentNode;
	shared_ptr<node>previousNode;

	currentNode = head;

	while (currentNode != nullptr)
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	//once we've reached this point, assign the tail node to the current node.
	tail = previousNode;

}

void linkedList::displayNodes()
{
	cout << "All nodes: \n--------------------------------" << endl;
	//create a temporary node which will point at each index. 
	//at each index, output the data and the next node, before having the temp node point to the value of the next node.
	shared_ptr<node>temp;
	temp = head;

	while (temp->next != nullptr)
	{
		cout << "node value: " << temp->getData() << "\n" << "pointing to node at: " << temp->getNextNode() << endl;
		temp = temp->next;
		gap();
	}

	//the very last node wasnt being output, so i output it manually.
	cout << "node value: " << temp->getData() << "\n" << "pointing to node at: " << temp->getNextNode() << endl;

	cout << "\nTotal list length: " << getLength() << endl;
}


void linkedList::pushNodeFront(int value)
{
	shared_ptr<node> newNode = make_shared<node>();
	newNode->data = value;
	newNode->next = head;
	head = newNode;

	assignTail();

	length++;

}

void linkedList::deleteNodeFront()
{

	//process:
	//re-assign the head node. that's it.
	head = head->next;

	cout << "--------------------------------\nA node has now been deleted from the front of the list. Showing updated list.\n--------------------------------" << endl;
	displayNodes();

	length--;

}


void linkedList::bulkNodes(int value1, int value2, int value3, int value4, int value5)
{
	//gather all values into the array and induvidually check if the values are null.
	//If, in one instance, for example the first, is not null, then create a node, store value1 in the data of the node, and then push it to th end of the array.
	int values[] = { value1, value2, value3, value4, value5 };

	for (int index = 0; index < (sizeof(values) / sizeof(int)); index++)
	{
		if (values[index] != NULL)
		{
			//with this function being called, there's no need to handle length locally, as it's handled within the function.
			appendNode(values[index]); //at each iteration, take the value, make a node with the data being set to the value, and then push it onto the end of the list.
		}
	}

	assignTail();
}

void linkedList::appendNode(int value) //there's a read access violation being thrown with this function here. requires re-working.
{
	
	shared_ptr<node>newNode = make_shared<node>();
	newNode->next = nullptr;
	newNode->data = value;

	//check if the length of the list before adding this node is 0, if so, make this node the head node too.
	if (getLength() == 0) //this condition will likely only be true if this is the first node being appended to the list.
	{
		head = newNode;
		tail = newNode;
	}

	else //if the length is more than 0, iterate through the list to get to the second to last value.
	{
		shared_ptr<node> currentNode;
		shared_ptr<node> previousNode;


		currentNode = head;

		while (currentNode != nullptr)
		{
			previousNode = currentNode;
			currentNode = currentNode->getNextNode();
		}

		previousNode->next = newNode;
		tail = newNode;

		
	}

	length++;
	
	
} 

void linkedList::popNode()
{
	//do this in the next session.
}