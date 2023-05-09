#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - The function prints
 * all elements of a listint_t list
 * @head: the pointer to head
 * Return: numbers of nodes
 */
size_t print_listint(const listint_t *head)
{
	const listint_t *curr;
	unsigned int n;

	curr = head;
	n = 0;
	while (curr != NULL)
	{
		printf("%i\n", curr->n);
		curr = curr->next;
		n++;
	}

	return (n);
}

/**
 * add_nodeint - adds a new node
 * at the beginning of a listint_t list
 * @head: pointer to a pointer of the start of the list
 * @n: integer to be included in the node
 * Return: address of the new element or NULL if fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newest;

	newest = malloc(sizeof(listint_t));
	if (newest == NULL)
		return (NULL);

	newest->n = n;
	newest->next = *head;
	*head = newest;

	return (newest);
}

/**
 * free_listint - The function that frees a listint_t list
 * @head: lists to be freed
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *curr;

	while (head != NULL)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}