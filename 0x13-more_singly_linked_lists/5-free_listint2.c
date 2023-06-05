#include "lists.h"

/**
 * free_listint2 - To free linked lists
 * @head: A pointer for the listint_t List to free
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

        *head = NULL;
}
