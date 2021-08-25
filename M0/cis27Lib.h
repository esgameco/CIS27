#pragma once

#include <stdio.h>

/*
* Linked List
*/
typedef struct Node
{
	struct Node* next;
	struct Node* prev;
	int val;
} dl_node;

struct DoublyLinkedList
{
	struct Node* head;
};

// Adds node to DoublyLinkedList
void addNode(dl_node* node, int val)
{
	dl_node* next = node->next;
	dl_node n;
	n.next = next;
	n.prev = node;
	n.val = val;
	node->next = &n;
	if (next == NULL)
		next->prev = node->next;
}

// Displays all items in a doubly-linked list
void displayNodes(dl_node* node)
{
	dl_node* currNode = node;
	while (currNode->prev)
		currNode = currNode->prev;

	while (currNode->next)
	{
		printf("%d", currNode->val);
		currNode = currNode->next;
	}
}