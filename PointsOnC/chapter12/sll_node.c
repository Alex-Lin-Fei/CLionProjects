//
// Created by lilin on 2021/6/6.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "sll_node.h"


bool sll_insert(register Node ** linkp, int new_value) {
    register Node *current;
    register Node *new;

    while ((current = *linkp) != NULL && current->value < new_value)
        linkp = &current->link;

    new = (Node *) malloc(sizeof(Node));
    if (new == NULL)
        return false;
    new->value = new_value;
    new->link = current;
    *linkp = new;
    return true;
}




Node * sll_reverse(Node * first) {
    if (first == NULL)
        return NULL;
    else {
        Node *nex = sll_reverse(first->link);
        if (nex) {
            Node * end = nex;
            while (end->link)
                end=end->link;
            end->link = first;
            first = nex;
            end = end->link;
            end->link = NULL;
        }
    }
    return first;
}


bool sll_remove(Node ** rootp, Node * node) {
    register Node * current;

    while ((current = * rootp) != NULL && current != node)
        rootp = &current->link;
    if (current == node) {
        *rootp = current->link;
        free(node);
        return true;
    }
return false;
}
