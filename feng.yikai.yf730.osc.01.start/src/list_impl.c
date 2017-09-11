#include <list.h>
#include <stdlib.h>
#include <stdio.h>


void init_list(struct list_type *l) {
	l->head = NULL;
	l->tail = NULL;
}
	
	
void insert_head(struct list_type *l, void* element) {
	cell* new_cell = malloc(sizeof(cell));
	new_cell->content = element;
	new_cell->previous = NULL;
	new_cell->next = l->head;
	if (l->head != NULL)
		l->head->previous = new_cell;
	l->head = new_cell;
	if (l->tail == NULL)
			l->tail = l->head;
}


void* extract_head(struct list_type *l) {
	/* TODO */
	void* result = NULL;
	cell *old_head = l->head;

	if (old_head == NULL) {
		printf("Cannot extract head from an empty stack.\n");
		exit(0);
	}
	else if (old_head != NULL && old_head->next == NULL) {
		result = old_head->content;
		l->head = NULL;
		l->tail = NULL;
		free(old_head);
	}
	else {
		result = old_head->content;
		l->head = old_head->next;
		l->head->previous = NULL;
		old_head->next = NULL;
		free(old_head);
	}
	return result;
}


void* extract_tail(struct list_type *l) {
	/* TODO */
	void* result = NULL;
	cell *old_tail = l->tail;

	if (old_tail == NULL) {
		printf("Cannot extract head from an empty stack.");
	}
	else if (old_tail != NULL && old_tail->previous == NULL) {
		result = old_tail->content;
		l->head = NULL;
		l->tail = NULL;
		free(old_tail);
	}
	else {
		result = old_tail->content;
		l->tail = old_tail->previous;
		l->tail->next = NULL;
		old_tail->previous = NULL;
		free(old_tail);
	}
	return result;
}


int list_size(struct list_type *l) {
	/* TODO */
	int counter = 1;
	cell *pointer = l->head;
	while (pointer->next != NULL) {
		counter ++;
		pointer = pointer->next;
	}
	return counter;

}
	