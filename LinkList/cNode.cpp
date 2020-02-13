#include "cNode.h"
// setter function for setting value of node
void cNode:: setValue(int v)
{
	value = v;
}

// getter function for getting value of node
int cNode:: getValue()
{
	return value;
}

/* Setter function for setting the next Node */
void cNode::setNextNode(cNode* nn)
{
	nextNode = nn;
}

cNode *cNode::getNextNode()
{
	return nextNode;
}
