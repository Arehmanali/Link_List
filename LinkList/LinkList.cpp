#include<iostream>
#include "cNode.h"
#include "List.h"
using namespace std;
int main()
{
	
	List myLinkList;	
	myLinkList.insert(73);
	myLinkList.insert(334);
	myLinkList.insert(43);
	myLinkList.insert(43);
	myLinkList.printAll();
	myLinkList.insertAtBegin(34);
	myLinkList.printAll();
	myLinkList.insertAtLast(23);
	myLinkList.printAll();
	myLinkList.reverseNode();
	myLinkList.printAll();
	myLinkList.sorting();
	myLinkList.printAll();
	myLinkList.update(9);
	myLinkList.printAll();
	myLinkList.deleteNode();
	myLinkList.printAll();
	myLinkList.search();
	myLinkList.insertNewAfter(78);
	myLinkList.printAll();
	myLinkList.sum();
	myLinkList.insertAfter(321);
	myLinkList.printAll();

	return 0;

}
