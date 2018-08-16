#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct quene_type {
	struct node *head;
	struct node *tail;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

struct quene_type *create()
{
	struct quene_type *q = malloc(sizeof(struct quene_type));
	if (q == NULL)
		terminate("create failure");

	q->head = NULL;
	q->tail = NULL;

	return q;
}

void initailize_quene(struct quene_type *q, int num)
{
	struct node *new = malloc(sizeof(struct node));
	if (new == NULL)
		terminate("initailize quene failure");

	new->data = num;
	new->next = q->head;
	q->head = new;
	q->tail = q->head;
}

void enter(struct quene_type *q, int num)
{
	struct node *new = malloc(sizeof(struct node));
	if (new == NULL)
		terminate("enter failure");

	new->data = num;
	(q->tail)->next = new;
	q->tail = new;
}

void out(struct quene_type *q)
{
	struct node *temp;

	temp = q->head;
	q->head = (q->head)->next;
	free(temp);
}

int main()
{	
	struct quene_type *q;
	q = create();
	initailize_quene(q, 15);
	enter(q, 16);
	enter(q, 17);
	out(q);
	printf("%d", (q->head)->data);


	return 0;
}