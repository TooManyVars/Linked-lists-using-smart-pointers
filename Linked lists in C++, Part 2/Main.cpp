#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include "Class_And_Node.h"

//memory leak catcher declaration.
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

using namespace std;

void UI() //the UI for the linked list. comment this out in main if you want to manually call and test functions yourself.
{

	linkedList newList;
	list<string>commands = { "display","addStart", "deleteStart", "append","pop", "insertIndex","deleteIndex", "help", "exit", "bulk" };
	//char input;

	while (true) //infinite loop.
	{
		string input;
		cout << "\nEnter desired linked list command here(type 'Help' for command list):\n\n-------------------------------------------------------------------------------------\n" << endl;
		cin >> input;

		if (input == "help")
		{
			newList.help();
		}

		else if (input == "exit")
		{
			exit(0);
		}

		else if (input == "display")
		{
			newList.displayNodes();
		}

		else if (input == "addStart")
		{
			int value = 0;
			cout << "------------------------------------------------------------------------------------" << endl;
			cout << "\nPlease enter the desired value of the node: " << endl;
			cin >> value; //the program spazzes when you enter something other than an integer.

			newList.pushNodeFront(value);

			cout << "\nA new node was pushed to the front of the list, with value " << value << "." << endl;
		}

		else if (input == "deleteStart")
		{
			newList.deleteNodeFront();
		}

		else if (input == "bulk")
		{

			//algorithim: have an array of five values; iterate through the array and get input for each index, and then call the bulk nodes functionality, using the five indexes.

			int inputs[5] = {};

			for (int index = 0; index <= (sizeof(inputs) / sizeof(int) - 1); index++)
			{
				cout << "\nPlease enter the value of node " << index + 1 << ": " << endl;
				cin >> inputs[index];
			}

			newList.bulkNodes(inputs[0], inputs[1],inputs[2], inputs[3], inputs[4]);
		}

		else if (input == "append")
		{
			int value = 0;
			cout << "\nEnter the desired value of the node: " << endl;
			cin >> value;
			newList.appendNode(value);
		}

		else if (input == "pop")
		{
			newList.popNode();
		}

		else if (input == "insertIndex")
		{
			int value = 0;
			cout << "\nEnter the desired value of the node:" << endl;
			cin >> value;

			int index = 0;
			cout << "\nEnter the desired index you wish to insert the node:" << endl;
			cin >> index;

			if(newList.getLength() == 0) //check if the list is empty. if it is, simply append the given node.
			{
				cout << "\nList was previously empty: appending node to the end of the list." << endl;
				newList.appendNode(value);
			}

			else if (newList.getLength() > 0)
			{
				newList.insert(value, index);
				cout << "Node of value " << value << " was successfully added at index " << index << "." << endl;
			}

			
			newList.insert(value, index);
		}

	}

	//newList.help();
	
}

int main()
{

	linkedList newList;
	
	//function overview:

	//push a new node onto the front of the list, making it the head node.
	//newList.pushNodeFront(19);

	//push up to five nodes onto the end of the list. the head is constantly re-assigned.
	//newList.bulkNodes(79,34,55,33,2);


	//[note]: for now, if you've only added items to the list, there will be no tail node, meaning that an exception will be thrown when you try to get data from the tail.

	//displays all the nodes currently within the list.
	//newList.displayNodes();

	//deletes the front node, re-assinging the head node.
	//newList.deleteNodeFront();
	
	//getters for the data and the next node of the head.
	//cout << newList.head->getData() << endl;
	//cout << newList.head->getNextNode() << endl;

	//pushes a node onto the end of the list.
	//newList.appendNode(15);

	//deletes the node on the end of the list.
	//newList.popNode();

	//inserts a new node of a particular value at a specific index.
	//newList.insert(4, 4);

	//delete a desired index of the array. note: will result in an exception throw if you try to call it on the first index.
	//newList.deleteIndex(3);

	//[NOTE] test any methods you want to below this comment.

	UI(); //current bug: i get a read access violation when calling displayNodes within the UI function, but not within main.
	//linkedList n;
	//n.bulkNodes(1, 2, 34, 45);
	//n.displayNodes();

	cin.get();
	_CrtDumpMemoryLeaks(); //memory leak catcher function call, for the sake of safety.
	return 0;
}