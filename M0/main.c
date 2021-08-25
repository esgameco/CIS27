#include <stdio.h>

#include "cis27Lib.h"

int main()
{
	dl_node* head = createDefaultNode();
	dl_node* currentNode = head;
	head->val = 0;
	for (int i = 1; i < 10; i++)
	{
		addNode(currentNode, i%5);
		currentNode = currentNode->next;
	}

	displayNodes(head);
	sortNodes(head);
	printf("\n\n");
	displayNodes(head);
	deleteAllNodes(head);

	return 0;
}