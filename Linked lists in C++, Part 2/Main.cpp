#include <iostream>
#include <string>
#include "Class_And_Node.h"

//memory leak catcher declaration.
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

using namespace std;

bool linearSearch(string word, string arr[], size_t length) //iterates through a list. returns true if the search was successful. take the size of the list as a parameter, in order to accurately get the size of a string array.
{
	for ( unsigned int index = 0; index < length; index++) //made the iterator an unsigned int to avoid signed / unsigned warning.
	{
		if (word == arr[index])
		{
			return true;
		}
	}

	return false;
}

void UI() //the UI for the linked list. comment this out in main if you want to manually call and test functions yourself.
{

	linkedList newList;
	string commands[] = { "display","addStart", "deleteStart", "append","pop", "insert","deleteIndex", "help", "exit", "bulk", "clear" };

	while (true) //infinite loop until the command "exit" is ran.
	{
		string input;
		cout << "\nEnter desired command here(type 'help' for command list):\n\n-------------------------------------------------------------------------------------\n" << endl;
		cin >> input;

		//add an iteration and input algorithim here to process incorrect input. when deleteindex and insertIndex are called, create while loop if the length is shorter than two.
		while ( linearSearch(input,commands, sizeof(commands) / sizeof(string)) != true )
		{
			cout << "\nDesired commands is invalid, please re-enter(type 'help' for a list of commands): " << endl;
			cin >> input;
		}

		while ( (input == "insert" || input == "deleteIndex") && newList.getLength() < 2) //protects the user from trying to insert/delete an index that doesn't exist, throwing an exception.
		{
			cout << "\nYou cannot use the command " << input << " on a list with less than 2 values, please re-enter: " << endl;
			cin >> input;
		}

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

		else if (input == "insert") //from testing the code, what i can see is that the maximum index that you can insert at is the list length + 1.
		{
			int value = 0;
			cout << "\nEnter the desired value of the node:" << endl;
			cin >> value;

			int index = 0;
			cout << "\nEnter the desired index you wish to insert the node:" << endl;
			cin >> index;

			while (index <= 1 || index >= newList.getLength() + 1)
			{
				cout << "Given index is outside of the scope of the array. please give an index in the range 1 to " << newList.getLength() << "." << endl;
				cin >> index;
			}

			newList.insert(value, index);
			cout << "Node of value " << value << " was successfully added at index " << index << "." << endl;
		}

		else if (input == "deleteIndex")
		{

			int index = 0;
			cout << "\nEnter the desired index of the node you wish to delete:" << endl;
			cin >> index;

			while (index <= 1 || index >= newList.getLength() + 1)
			{
				cout << "Given index is outside of the scope of the array. please give an index in the range 1 to " << newList.getLength() << "." << endl;
				cin >> index;
			}

			newList.deleteIndex(index);
		}

		else if (input == "clear")
		{
			newList.clear();
		}

	}

	
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

	//delete a desired index of the array. note: may result in an exception throw if you try to call it on the first index(luckily i've put some precautions in place).
	//newList.deleteIndex(3);

	//[NOTE] test any methods you want to below this comment, so that you may always know what methods you can use.

	UI();

	cin.get();
	_CrtDumpMemoryLeaks(); //memory leak catcher function call, to ensure no memory is leaked. it's a bit overkill, i know, but memory can be still leaked, in extreme cases, via smart pointers.
	return 0;
}