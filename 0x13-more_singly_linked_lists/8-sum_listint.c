#include "lists.h"

/**
 * sum_listint - To calc total sum of all data in listint_t list
 * @head: The first node in the linked lists
 *
 * Return: The result of the sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
