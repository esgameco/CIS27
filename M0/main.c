#include <stdio.h>

#include "cis27Lib.h"

int main()
{
	dl_node head;
	for (int i = 0; i < 10; i++)
	{
		addNode(&head, i);
	}

	displayNodes(&head);

	return 0;
}