#include "lists.h"

/**
 * free_listint - To free linked lists
 * @head: listint_t Lists to free
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
