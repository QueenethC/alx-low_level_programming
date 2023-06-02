#include <stdlib.h>
#include "lists.h"

/**
 * free_list - To free the linked lists
 * @head: The list_t list to free
 */
void free_list(list_t *head)
{
 list_t *temp;

 while (head)
 {
 temp = head->next;
 free(head->str);
 free(head);
 head = temp;
 }
}
