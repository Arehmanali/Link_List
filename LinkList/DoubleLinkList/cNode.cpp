#include "cNode.h"

// set value function for setting the value of node
void cNode:: setValue(int v)
{
	value = v;
}

// getter function for getting the value of node
int cNode:: getValue()
{
	return value;
}

// setter function for setting the next node in the list
void cNode::setNextNode(cNode* nn)
{
	nextNode = nn;
}

// getter function for getting the value of next node from the list
cNode *cNode::getNextNode()
{
	return nextNode;
}
