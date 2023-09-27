#include "lists.h"
/**
 * free_nodes - Frees the nodes of a listint_t linked list
 * from the start ptr(inclusive) till end ptr(exclusive)
 * and sets the start ptr to NULL
 *
 * @start: Double pointer to the start node (inclusive)
 * @end: Pointer to the end node (exclusive)
 *
 * Return: The size of the list that was freed
 */
size_t free_nodes(listint_t **start, listint_t *end)
{
	listint_t *curr_node, *temp_node;
	size_t	   list_size = 0;

	if (start == NULL || *start == NULL)
	{
		return (0);
	}

	for (curr_node = *start; curr_node != end;)
	{
		temp_node = curr_node;
		curr_node = curr_node->next;
		list_size++;
		free(temp_node);
	}

	*start = NULL; /* set start to NULL */
	return (list_size);
}

/**
 * handle_edge_cases - Handles various edge cases for the linked list.
 * When the list is empty. When only one node pointing to itself &
 * When there are multiple nodes that all point back to head
 *
 * @head: Double pointer to the head node
 *
 * Return: The size of the list that was freed
 */
int handle_edge_cases(listint_t **head)
{
	/*listint_t *temp_node = NULL;*/
	/*int	   list_size = 0;*/

	if (head == NULL || *head == NULL) /* there is no list, so no cycle*/
		return (0);

	if ((*head)->next == *head)
	{ /* check if the list has only one node that points to itself */
		free(*head); /* free the head */
		*head = NULL;
		return (1);
	}

	return (-1);
}

/**
 * free_listint_safe - Frees a listint_t list
 *
 * @h: Double pointer to the start of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tortoise = NULL, *hare = NULL;
	listint_t *temp_node = NULL, *meetup = NULL;
	size_t	   list_size = 0;

	if (handle_edge_cases(h) > -1) /* edge case found */
		return ((size_t) handle_edge_cases(h));

	for (tortoise = *h, hare = *h; tortoise != NULL;)
	{
		if (hare == NULL) /*we have a regular non-cycle linked list*/
			break;
		/* tortoise & hare algorithm used to detect a cycle linked list */
		temp_node = tortoise;
		tortoise  = tortoise->next;
		/* hare->next is checked for NULL to prevent dereferencing a NULL ptr */
		if (hare->next == NULL)
			hare = NULL; /* hare is short-circuited to NULL */
		else			 /* proceed with double traversal by hare */
			hare = (hare->next)->next;
		if (tortoise == hare) /* if tortoise == hare, cycle detected */
		{ /* reset tortoise to head & save hare as the meetup node */
			tortoise = *h;
			meetup	 = hare;
			while (tortoise != hare)
			{ /* tortoise == hare at the node that starts the cycle */
				temp_node = hare;
				tortoise  = tortoise->next;
				hare	  = hare->next;
				/* free nodes from meetup till node before start-cycle node */
				free(temp_node);
				list_size++;
			}
			/* free nodes from head till node before meetup node */
			return (free_nodes(h, meetup));
		}
	}
	/* handle regular non-cycle linkedlist */
	return (free_nodes(h, NULL)); /* free from head till last node (NULL) */
}
