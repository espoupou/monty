#include "monty.h"

/**
 * add_dnodeint - append double linked list to node
 * @head: the head
 * @n: the new node value
 * Return: the new node
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new, *h = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free_datas();
		exit(EXIT_FAILURE);
	}

	while (h != NULL && h->prev != NULL)
		h = h->prev;

	new->n = n;
	new->prev = NULL;
	new->next = h;

	if (h != NULL)
		h->prev = new;

	*head = new;

	return (new);
}

/**
 * add_dnodeint_end - append to double linked list
 * @head: the head
 * @n: the new node value
 * Return: the new node
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *h = *head;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free_datas();
		exit(EXIT_FAILURE);
	}

	while (h != NULL && h->next != NULL)
		h = h->next;

	new->n = n;
	new->next = NULL;

	if (h != NULL)
	{
		h->next = new;
	}
	else
	{
		*head = new;
	}

	new->prev = h;

	return (new);
}

/**
 * delete_dnodeint_at_index - deletes the node at index of a
 * dlistint_t linked list
 *
 * @head: head of the list
 * @index: index of the new node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *h1, *h2;
	unsigned int i;

	h1 = *head;

	if (h1 != NULL)
		while (h1->prev != NULL)
			h1 = h1->prev;

	i = 0;

	while (h1 != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = h1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				h2->next = h1->next;

				if (h1->next != NULL)
					h1->next->prev = h2;
			}

			free(h1);
			return (1);
		}
		h2 = h1;
		h1 = h1->next;
		i++;
	}

	return (-1);
}

/**
 * free_dlistint - free double linked list
 * @head: the head
 * Return: nothing
 */

void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
