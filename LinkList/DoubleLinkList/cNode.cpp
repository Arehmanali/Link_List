#include "cNode.h"

// set value function for setting the value of node
void cNode:: setValue(int v)
{
	value = v;
}
int cNode:: getValue()
{
	return value;
}
void cNode::setNextNode(cNode* nn)
{
	nextNode = nn;
}
cNode *cNode::getNextNode()
{
	return nextNode;
}
