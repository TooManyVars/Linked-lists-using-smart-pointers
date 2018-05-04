#include <iostream>
#include <string>
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
	
	if (length == 0)
	{
		cout << "\n[List is empty, perhaps add some nodes?]" << endl;
	}

	else if (length > 0)
	{
		cout << "All nodes: \n--------------------------------" << endl;
		gap();
		/*create a temporary node which will point at each index.
		at each index, output the data and the next node, before having the temp node point to the value of the next node. **/
		shared_ptr<node>temp;
		temp = head;

		while (temp->next != nullptr)
		{
			cout << "-----node value: " << temp->getData() << "\n-----" << "pointing to node at: " << temp->getNextNode() << endl;
			temp = temp->next;
			gap();
		}

		//the very last node wasnt being output, so i output it manually.
		cout << "-----node value: " << temp->getData() << "\n-----" << "pointing to node at: " << temp->getNextNode() << endl;

		cout << "\nTotal list length: " << getLength() << endl;
		gap();
	}


	cout << "--------------------------------" << endl;
	
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

void linkedList::deleteNodeFront()//right now, the delete node front method throws an exception when trying to delete a node from the front of the list when there are only two nodes.
{

	//process:
	//re-assign the head node if the length of the list is more than 1. if it isn't, make the head point to null.

	if (length == 0)
	{
		emptyList();
	}

	else if (length <= 1)
	{
		head = nullptr;
		length--;
		cout << "--------------------------------\nNode has now been deleted.\n--------------------------------" << endl;
	}

	else if (length > 1)
	{
		head = head->next;

		length--;

		cout << "--------------------------------\nA node has now been deleted from the front of the list. Showing updated list.\n--------------------------------" << endl;
		gap();
		displayNodes();
	}

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

	cout << "\nNew node(s) successfully added to the front of the list." << endl;
}

void linkedList::appendNode(int value)
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

	cout << "\n A new node has been appended to the end of the list." << endl;
	

} 

void linkedList::popNode() //currently expiriencing problems in which popping with a list with a length of 1 or lower causes an exception throw.
{
	//what we can do is just have the second to last pointer point to null, and put it into the tail node.


	//if statment checking if there is only one node in the array. if there is, don't try to iterate through the array(that will cause an exception to be thrown), simply make head and tail nullptr.
	if (length == 1)
	{
		tail = nullptr;
		head = nullptr;

		length--;

		cout << "--------------------------------\nA node has now been deleted from the end of the list. Showing updated list.\n--------------------------------" << endl;
		displayNodes();
	}


	 else if (length > 0)
	{
		shared_ptr<node>currentNode;
		shared_ptr<node>previousNode;

		currentNode = head;

		while (currentNode->next != nullptr)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		previousNode->next = nullptr;
		tail = previousNode;

		length--;

		cout << "--------------------------------\nA node has now been deleted from the end of the list. Showing updated list.\n--------------------------------" << endl;
		displayNodes();
	}

	else
	{
		cout << "\nThe list is empty, meaning that there was nothing to delete from the end of the list. terminating action pop()." << endl;
	}


}


void linkedList::insert(int value, int index) //needs rigourus testing and improvements.
{
		//then, use a for loop to iterate through the list until you get to the desired position.
		shared_ptr<node>newNode = make_shared<node>();
		newNode->data = value;

		shared_ptr<node>currentNode;
		shared_ptr<node>previousNode;

		currentNode = head;

		for (int i = 1; i < index; i++)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		//point the previous node to the newNode, and the newNode to the next node.
		previousNode->next = newNode;
		newNode->next = currentNode;
		length++; //increase the lenghth of the list.
}

void linkedList::deleteIndex(int index)
{
	if (index <= length) //check to see if the given index was in range.
	{
		shared_ptr<node>currentNode;
		shared_ptr<node>previousNode;

		currentNode = head;

		for (int i = 1; i < index; i++)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		//instead of the previous node pointing to the currnent node, point it to the node that the current node is pointing at.
		previousNode->next = currentNode->next;

		length--;

		cout << "--------------------------------\nA node has now been deleted from the front of the list. Showing updated list.\n--------------------------------" << endl;
		displayNodes();
	}
}

void linkedList::help()
{
	cout << "\n-------------------------------------------------------------------------------------" << endl;
	cout << "Command list\n\n\n----------------[Functions related to the start of the list]-------------------------\n\n-addStart: adds a node to the front of the list.\n\n-deleteStart: deletes a node currently at the start of the list.\n" << endl;
	cout << "----------------[Functions related to the end of the list]---------------------------\n\n-append: adds a node to the front of the list.\n\n-pop: deletes a node currently at the end of the list.\n" << endl;
	cout << "----------------[Functions related to a particular index of the list]----------------\n\n-insertIndex: adds a node a desired position in the list.\n\n-deleteIndex: deletes a desired index in the list.\n" << endl;
	cout << "----------------[Miscellaneous methods]----------------------------------------------\n\n-exit: Exits the program.\n\n-display: shows all the nodes within the list(throws an exception if the list is empty). \n" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
}