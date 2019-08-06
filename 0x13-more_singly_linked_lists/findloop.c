#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	struct List *next;
} List;

/**
 * find_loop - find a loop in a linked list
 *  Based on code from
 *  http://geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list (method 3)
 *  except this one actually works!
 * @head: pointer to first item in list
 * Return: a pointer to the start of the loop, or NULL
 */
List *find_loop(List *head)
{
	List *slow = head, *fast = head;

	do {
		if (!fast || !fast->next)
			return (NULL); /* found end of list */
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);
	/* found loop */
	if (slow == head) /* loop starts at head */
		return (head);
	do {
		head = head->next;
		fast = fast->next;
	} while (head != fast);
	return (fast);
}

List *make_list(int base_len, int loop_len)
{
	int i;
	List *head, *next, *loop, *first;

	if (base_len + loop_len == 0)
		return (NULL);

	first = head = malloc(sizeof(*head));
	for (i = 0; i < base_len; i++)
	{
		next = malloc(sizeof(*next));
		head->next = next;
		head = next;
		printf("-");
	}
	loop = head;
	for (i = 0; i < loop_len; i++)
	{
		next = malloc(sizeof(*next));
		head->next = next;
		head = next;
		printf("x");
	}
	printf("\n");
	if (loop_len)
		head->next = loop;
	else
		head->next = NULL;
	return (first);
}

int search_list(List *head, List *item)
{
	int i = 0;

	while (head != item)
	{
		printf("-");
		head = head->next;
		i++;
	}
	return i;
}

int main(int argc, char **argv)
{
	List *list, *loop;
	int i=atoi(argv[1]),j=atoi(argv[2]);
	list = make_list(i,j);
	loop = find_loop(list);
	printf("\n%d\n", search_list(list, loop));
	printf("base: %d, loop: %d, total: %d\n", i,j,i+j);
	return (0);
}
