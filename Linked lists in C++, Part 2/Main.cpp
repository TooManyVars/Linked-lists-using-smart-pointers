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
			int values = 0; //the amount of nodes the user wants to create.

			cout << "------------------------------------------------------------------------------------" << endl;
			cout << "\nHow many nodes would you like to create?" << endl;
			cin >> values;

			//loop input until it is 5 or lower, or higher than 0.
			while (values > 5 || values <= 0)
			{
				cout << "\nNumber of desired nodes is not within the range 0 to 5, please re-enter:" << endl;
				cin >> values; //causes a stack overflow error? either way, entering a number too high(or not a number at all, say, maybe a string or float causes some kind of infinite loop
			}

			//depending on the amount of desired nodes to be entered, an array of that size is created.
			///const int constNodes = values; //put the values into a const variable, given that when creating the array, the number of elements have to be const.


			//we need to make values(the number of nodes the user wants to create) into a const variable, so that we can use said value to create the list.


			//perhaps creating a function that returns a const int will surfice(https://code.sololearn.com/ccY4RQopFO3a/#cpp).


			///int nodes[constNodes] = {};

			//if (values == 1)
			//{
			//	list<int>nodes = { NULL };
			//}

			//else if (values == 2)
			//{
			//	list<int>nodes = { NULL, NULL };
			//}

			//else if (values == 3)
			//{
			//	list<int>nodes = { NULL, NULL, NULL };
			//}

			//else if (values = 4)
			//{

			//}
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