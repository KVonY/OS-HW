#include <fifo.h>
#include <list.h>
#include <stdio.h>
#include <stdlib.h>

struct list_type *list;

int init_queue() {
    list = malloc(sizeof(struct list_type));
    init_list(list);
    return 0;
}


int queue(void* element) {
    insert_head(list, element);
    return 0;
}


void* dequeue() {
    return extract_tail(list);
}


int size() {
    return list_size(list);
}