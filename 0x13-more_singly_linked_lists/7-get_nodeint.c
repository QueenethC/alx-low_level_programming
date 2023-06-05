#include "lists.h"

/**
 * get_nodeint_at_index - To return node at a certain index in a linked lists
 * @head: The first node in a linked lists
 * @index: For the index of the node to be returned
 *
 * Return: A pointer for the node we are looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}
