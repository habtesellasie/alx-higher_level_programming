#include "lists.h"
#include <stdlib.h>

/**
 * _realloc - A function that reallocates a memory
 * @pointer: The pointer to the previous memory block
 * @older_size: The size of the old memory
 * @newer_size: The size of the new memory
 * Return: new memory block or NULL
 */
void *_realloc(void *pointer, unsigned int older_size, unsigned int newer_size)
{
	void *new_pointer;
	unsigned int minm_size = older_size < newer_size ? older_size : newer_size;
	unsigned int i;

	if (newer_size == older_size)
		return (pointer);
	if (pointer != NULL)
	{
		if (newer_size == 0)
		{
			free(pointer);
			return (NULL);
		}
		new_pointer = malloc(newer_size);
		if (new_pointer != NULL)
		{
			for (i = 0; i < minm_size; i++)
				*((char *)new_pointer + i) = *((char *)pointer + i);
			free(pointer);
			return (new_pointer);
		}
		free(pointer);
		return (NULL);
	}
	else
	{
		new_pointer = malloc(newer_size);
		return (new_pointer);
	}
}



/**
 * check_cycle - The function that checks if a
 * singly linked list has a cycle in it
 * @list: list head
 * Return: 0 if unsuccess 1 if success
 */

int check_cycle(listint_t *list)
{
	listint_t *fastest, *slower = list;

	if (list == NULL)
		return (0);

	fastest = list->next;
	while (slower != NULL && fastest != NULL && fastest->next != NULL)
	{
		if (slower == fastest)
			return (1);
		fastest = fastest->next->next;
		slower = slower->next;
	}
	return (0);
}
