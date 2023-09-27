#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 *
 * @head: Pointer to the start of the list
 *
 * Return: The address of node where loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	/* we use the tortoise & hare algorithm to detect a loop */
	listint_t *tortoise = head;
	listint_t *hare		= head;

	if (head == NULL) /* there is no list, so no loop*/
		return (NULL);

	/* traverse through the loop with both tortoies & hare */
	/* hare is the fastest so will reach end of list if no loop */
	/* thus we check for tortoise && tortoise->next being NULL */
	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare	 = (hare->next)->next;
		if (tortoise == hare) /* if tortoise == hare, loop detected */
			break;
	}

	if (tortoise == hare)
	{
		/*reset tortoise to head but leave hare the same*/
		tortoise = head;
		while (tortoise != hare)
		{ /* increment tortoise & hare till they meet */
			tortoise = tortoise->next;
			hare	 = hare->next;
		}
		/* return the node where the loop starts */
		return (tortoise);
	}

	/* either hare or hare->next is NULL so noo loop detected */
	return (NULL);
}
