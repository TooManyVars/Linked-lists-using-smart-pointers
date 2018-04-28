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

	linkedList newOb;
	list<string>commands = { "addStart", "deleteStart", "append","pop", "insertIndex","deleteIndex", "help", "exit" };
	//char input;

	while (true) //infinite loop.
	{
		string input;
		cout << "\nEnter desired linked list command here(type 'Help' for command list):\n\n-------------------------------------------------------------------------------------\n" << endl;
		cin >> input;

		if (input == "help")
		{
			newOb.help();
		}

		else if (input == "exit")
		{
			exit(0);
		}
	}

	//newOb.help();

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
	UI();
	

	cin.get();
	_CrtDumpMemoryLeaks(); //memory leak catcher function call, for the sake of safety.
	return 0;
}