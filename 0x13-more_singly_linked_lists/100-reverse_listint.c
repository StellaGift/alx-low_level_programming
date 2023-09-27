#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list
 *
 * @head: Pointer to pointer to the first node of the list
 *
 * Return: Pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_node = NULL;
	listint_t *next_node = NULL;

	if (head == NULL || *head == NULL)
	{
		return (NULL);
	}

	while (*head != NULL)
	{
		next_node	  = (*head)->next; /* store the next node */
		(*head)->next = prev_node;	   /* let next point to prev node */
		prev_node	  = (*head);	   /*curr node becomes prev node */
		(*head)		  = next_node;	   /*next node becomes curr node */
	}

	/* the last prev_node after the loop should now be the head */
	*head = prev_node;

	/* return a pointer to the first node of the reversed list */
	return (*head);
}
