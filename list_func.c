#include "main.h"

/**
 * add_node_end - append node at the end of a list
 * @head: a pointer to a pointer of the head
 * @str: the string to be added to the new node
 * Return: a pointer to the new node if success
 */

list_t *add_node_end(list_t **head, const char *str)
{
	char *s;
	int len;
	list_t *node = malloc(sizeof(list_t));
	list_t *last = *head;

	if (node == NULL)
		return (NULL);

	s = _strdup(str);
	if (s == NULL)
	{
		free(node);
		return (NULL);
	}
	len = _strlen(s);
	node->str = s;
	node->len = len;
	node->next = NULL;

	if (last == NULL)
		*head = node;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = node;
	}

	return (node);
}

/**
 * add_node - add new node at the begining of a list
 * @head: the head of the list
 * @str: the string to be added in the list node
 * Return: a pointer to the new node
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *node;
	char *s;

	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);

	s = _strdup(str);
	if (s == NULL)
	{
		free(node);
		return (NULL);
	}

	node->len = strlen(s);
	node->str = s;
	node->next = *head;
	*head = node;

	return (*head);
}


/**
 * free_list - deletes all nodes in a list
 * @head: the head of list to be deleted
 */
void free_list(list_t *head)
{
	list_t *p = NULL;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		free(p->str);
		free(p);
	}
}


/**
 * create - creates a linked list from a string
 * the string is splitted by : and each node contains a word
 * @s: the string from which the list will be created
 * Return: the head of the list
 */

list_t *create(char *s)
{
	char *token;
	const char *delim = ":";
	list_t *head = NULL;

	if (s == NULL)
		return (NULL);
	token = strtok(s, delim);
	while (token != NULL)
	{
		add_node(&head, (const char *) token);
		token = strtok(NULL, delim);
	}

	return (head);
}

/**
 * print_list - prints all elements of a list_t (linked list)
 * @h: the head node of linked list
 * Return: the number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	const list_t *p = h; /* pointer to the first head */
	size_t count = 0;

	while (p != NULL)
	{
		if (p->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%i] %s\n", p->len, p->str);
		p = p->next;
		count++;
	}

	return (count);
}
