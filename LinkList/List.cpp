#include "List.h"
#include"cNode.h"
#include<iostream>
using namespace std;

/*default constructor*/
List::List()
{
	headNode = 0;
	currentNode = 0;
	lastcurrentNode = 0;
	size = 0;
}

/* insert function for inserting the new data in the linklist */
void List::insert(int n)
{
	if (currentNode != 0)
	{
		if (currentNode->getNextNode() == 0)
		{
			insertAtLast(n);
		}
		else
		{
			cNode* newNode = new cNode();
			newNode->setNextNode(currentNode->getNextNode());
			currentNode->setNextNode(newNode);
			lastcurrentNode = currentNode;
			currentNode = newNode;
			currentNode->setValue(n);
			size++;
		}
	}
	else
	{
		insertAtBegin(n);
	}
}

/* Print function for printing all the nodes present in linkList */
void List::printAll()
{
	cNode* ptr;
	ptr = new cNode();
	ptr = headNode;
	cout << "My link list is:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ptr->getValue() << endl;
		ptr = ptr->nextNode;
	}
}

/* Function to bring the current Node in the list to head Node*/
void List::start()
{
	lastcurrentNode = 0;
	currentNode = headNode;
}

/* move function for moving the nodes to next node in the list */
void List::move()
{
	lastcurrentNode = currentNode;
	currentNode = currentNode->getNextNode();
}

/* getter function for getting the value of the node */
int List::get()
{
	return currentNode->getValue();
}

/* getter function for getting the total number of nodes in list */
int List::getSize()
{
	return size;
}

/* function for inserting the new node at the start of list */
void List::insertAtBegin(int n)
{
	start();
	cNode* newNode = new cNode();
	newNode->setNextNode(currentNode);
	currentNode = newNode;
	headNode = newNode;
	currentNode->setValue(n);
	size++;
}

/* function for inserting the new nodes at the end of link list */
void List::insertAtLast(int n)
{
	start();
	cNode* ptr;
	ptr = new cNode();
	while (currentNode->nextNode != 0)
	{
		currentNode = currentNode->nextNode;
	}
	lastcurrentNode = currentNode;
	currentNode->setNextNode(ptr);
	currentNode = ptr;
	currentNode->setValue(n);
	currentNode->setNextNode(0);
	size++;
}

/* update the data in the list of nodes by searching the node by taking the position from user */
void List::update(int n)
{
	start();
	int pos;
	cout << "Enter the position of updating node:";
	cin >> pos;
	for (int i = 1; i <= size; i++)
	{
		
		if (i == pos)
		{
			break;
		}
		move();
	}
	lastcurrentNode = currentNode;
	currentNode->setValue(n);
	cout << "value updated succesfully\n";
}

/* delete function for deleting the node from the list */
void List::deleteNode()
{
	start();
	int pos;
	cout << "Enter the index of Node to DELETE:";
	cin >> pos;
	
	if (pos == 0)	// For deleting first Node of List
	{
		cNode* newNode = new cNode();
		newNode = headNode;
		headNode = headNode->nextNode;
		start();
		delete newNode;
		size--;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (i == pos)
			{
				break;
			}
			move();
		}
		lastcurrentNode->setNextNode(currentNode->getNextNode());
		delete currentNode;
		currentNode = lastcurrentNode;
		cout << "Value Deleted Successfully\n";
		size--;
	}
}

/* search function for searching the nodes from the list of nodes */
void List::search()
{
	start();
	int find, index;
	bool found = false;
	cout << "Enter the value of Node to Search:";
	cin >> find;
	for (int i = 1; i <= size; i++)
	{
		if (currentNode->getValue() == find)
		{
			found = true;
			index = i;
			break;
		}
		move();
	}
	if (found)
	{
		cout << "Node you search is found at " << index << " index \n";
	}
	else {
		cout << "Node is Not Found\n";
	}
}

/* insert function for inserting the new node after specified index */
void List::insertNewAfter(int n)
{
	start();
	bool flage=false;
	int index;
	cout << "Enter the index of new Node:";
	cin >> index;
	if (index == 0)
	{
		insertAtBegin(n);
	}else
	{

		for (int i = 1; i <= size; i++)
		{

			if (i == index)
			{
				break;
			}
			move();
		}
	
		cNode* newNode = new cNode();
		newNode->setNextNode(currentNode->getNextNode());
		currentNode->setNextNode(newNode);
		lastcurrentNode = currentNode;
		currentNode = newNode;
		currentNode->setValue(n);
		size++;
	}
}

/* insert new node after the specified data stored in the list */
void List::insertAfter(int n)
{
	start();
	int value;
	cout << "Enter value of previous node for new Node:";
	cin >> value;
	for (int i = 0; i < size; i++)
	{
		if (currentNode->getValue() == value)
		{
			break;
		}
		move();
	}
	cNode* newNode = new cNode();
	newNode->setNextNode(currentNode->getNextNode());
	currentNode->setNextNode(newNode);
	lastcurrentNode = currentNode;
	currentNode = newNode;
	currentNode->setValue(n);
	size++;

}

/* sum function for suming the data stored in the link list */
void List::sum()
{
	int sum = 0;
	start();
	while (currentNode->getNextNode() != 0)
	{
		sum = sum + currentNode->getValue();
		move();
	}
	cout << "\n Sum of all Nodes is:" << sum << endl;
}
void List::reverseNode()
{
	start();
	cNode* next;
	while (currentNode != 0)
	{
		next = currentNode->nextNode;
		currentNode->nextNode = lastcurrentNode;
		lastcurrentNode = currentNode;
		currentNode = next;
	}
	headNode = lastcurrentNode;
}
void List::sorting()
{
	start();
	cNode* temp = new cNode;
	int f;
	for (int i = 0; i < size;++i) {
		temp = currentNode->getNextNode();
		for (int j = i + 1; j < size;++j) {
			if (currentNode->getValue()>temp->getValue()) {
				f = currentNode->getValue();
				currentNode->setValue(temp->getValue());
				temp->setValue(f);
			}
			temp = temp->nextNode;
		}
		move();
	}
}
List::~List()
{
}
