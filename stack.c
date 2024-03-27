#include "monty.h"

/**
 * add_dnodeint - Adds a node at the
 * beginning of a doubly linked list
 * @head: Pointer to the list
 * @n: The data of the node to be added
 * Return: Address of the new node
 * NULL in failure
 */

dlistint_t *add_dnodeint(stack_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * add_dnodeint_end - Adds a node to a
 * doubly linekd list at the end
 * @head: pointer to the list
 * @n: The data to be put in the node
 * Return: Pointer to the new node
 * NULL in failure
 */

dlistint_t *add_dnodeint_end(stack_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));
	dlistint_t *current = *head;

	if (!new)
		return (NULL);

	new->n = n;
	if (!*head)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
		return (new);
	}

	while (current && current->next)
		current = current->next;

	new->prev = current;
	new->next = NULL;
	current->next = new;
	return (new);
}

/**
 * free_dlistint - Frees a doubly
 * linked list
 * @head: The head node of the list
 * Return: Nothing (void)
 */

void free_dlistint(stack_t *head)
{
	while (head && head->next)
	{
		head = head->next;
		free(head->prev);
	}
	if (!head->next)
		free(head);
}
