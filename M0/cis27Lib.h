#pragma once

#include <stdio.h>
#include <stdbool.h>

// Todos:

// TODO: Use integer instead of importing bool library

/*
* Linked List
*/
struct Node
{
	struct Node* next;
	struct Node* prev;
	int val;
	bool nextExists;
	bool prevExists;
} const dl_node_d = {NULL, NULL, 0, false, false};

typedef struct Node dl_node;

struct DoublyLinkedList
{
	struct Node* head;
};

// Creates a default node
dl_node* createDefaultNode()
{
	dl_node* newNode = malloc(sizeof(dl_node));
	*newNode = dl_node_d;
	return newNode;
}

// Frees node and ties loose connections
void freeNode(dl_node* node)
{
	if (node->prevExists && node->nextExists)
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	else
	{
		if (node->nextExists)
			node->next->prevExists = false;
		if (node->prevExists)
			node->prev->nextExists = false;
	}
	free(node);
	node = NULL;
}

// Swaps the places of two nodes
void swapNodes(dl_node* node1, dl_node* node2)
{
	dl_node* tmp = node1->prev;
	node1->next = node2->next;
	node1->prev = node2;
	node2->prev = tmp;
	node2->next = node1;
}

// Adds node to DoublyLinkedList
void addNode(dl_node* node, int val)
{
	dl_node* newNode = createDefaultNode();
	if (node->nextExists)
	{
		newNode->next = node->next;
		newNode->nextExists = true;
	}
	else
		newNode->nextExists = false;
	newNode->prev = node;
	newNode->val = val;
	newNode->prevExists = true;
	
	node->next = newNode;
	node->nextExists = true;
	if (newNode->nextExists)
		newNode->next->prev = node->next;
}

// Displays all items in a doubly-linked list
void displayNodes(dl_node* node)
{
	dl_node* currNode = node;
	while (currNode->prevExists)
		currNode = currNode->prev;

	while (currNode->nextExists)
	{
		printf("%d", currNode->val);
		currNode = currNode->next;
	}
	// Display the last one
	printf("%d", currNode->val);
}

// Deletes all nodes within a doubly-linked list
void deleteAllNodes(dl_node* node)
{
	dl_node* currNode = node;
	while (currNode->prevExists)
		currNode = currNode->prev;

	while (currNode->nextExists)
	{
		currNode = currNode->next;
		freeNode(currNode->prev);
	}
	free(currNode);
}

// Sorts doubly-linked list using bubble sort
// TODO: Fix
void sortNodes(dl_node* head)
{
	dl_node* currNode;
	bool done = false;
	while (!done)
	{
		currNode = head;
		done = true;
		while (currNode->nextExists)
		{
			if (currNode->val > currNode->next->val)
			{
				swapNodes(currNode, currNode->next);
				done = false;
			}
			currNode = currNode->next;
		}
	}
}