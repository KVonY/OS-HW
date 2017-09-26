#include <stack.h>
#include <stdlib.h>
#include <stdio.h>
#include <list.h>


struct list_type *list;

int init_stack() {
    list = malloc(sizeof(struct list_type));
    init_list(list);
    return 0;
}


int push(void* element) {
    insert_head(list, element);
    return 0;
}


void* pop() {
    return extract_head(list);
}


int size() {
    return list_size(list);
}