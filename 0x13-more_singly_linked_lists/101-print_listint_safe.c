#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t list
 *
 * @head: Pointer to the start of the list
 *
 * Return: The number of nodes of the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t			 num_of_nodes = 0;
	const listint_t *curr_node	  = NULL;
	const listint_t *previously_visited[1024];
	size_t			 i;

	if (head == NULL)
	{
		/* head a of the list is a NULL pointer */
		return (0);
	}

	curr_node = head;
	while (curr_node != NULL)
	{
		/* check if current node has been visited previously */
		for (i = 0; i < num_of_nodes; i++)
		{
			if (curr_node == previously_visited[i])
			{
				printf("-> [%p] %d", (void *) curr_node, curr_node->n);
				printf("\n");
				return (num_of_nodes);
			}
		}

		printf("[%p] %d\n", (void *) curr_node,
			   curr_node->n); /* print node's data */
		previously_visited[num_of_nodes]
			= curr_node;			 /* save the visited node */
		num_of_nodes++;				 /* increment the number of nodes by 1 */
		curr_node = curr_node->next; /* set the next node as curr node */
	}

	return (num_of_nodes);
}
