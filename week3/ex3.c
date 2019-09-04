#include <stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void print_list(struct node* head) {
	struct node* temp = head;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void insert_node(struct node* prev, struct node* new_cell) {
	new_cell->next = prev->next;
	prev->next = new_cell;
}

void delete_node(struct node* head, struct node* n) {
	struct node* temp = head;
	struct node* del = n;
	if (head == del) {
		head->next = NULL;
		return;
	}
	while (temp->next != NULL) {
		if (temp->next == del) {
			if (temp->next->next != NULL) {
				temp->next = temp->next->next;
				return;
			}
			else {
				temp->next = NULL;
				return;
			}
		}
		temp = temp->next;
	}
}

int main() {
	struct node *a = NULL;
	a = malloc(sizeof(struct node));
	struct node *b = NULL;
	b = malloc(sizeof(struct node));
	struct node *c = NULL;
	c = malloc(sizeof(struct node));
	struct node *d = NULL;
	d = malloc(sizeof(struct node));
	struct node *e = NULL;
	e = malloc(sizeof(struct node));
	a->data = 56;
	b->data = 98; 
	c->data = 2;
	d->data = 18;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;
	e->data = 1515;
	e->next = NULL;

	print_list(a);
	printf("\n");
	insert_node(b, e);
	print_list(a);
	printf("\n");
	delete_node(a, d);
	print_list(a);
	printf("\n");
	delete_node(a, a);
	print_list(b);
}