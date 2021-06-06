//
// Created by lilin on 2021/6/6.
//

#ifndef CHAPTER12_SLL_NODE_H
#define CHAPTER12_SLL_NODE_H
#include <stdbool.h>
typedef struct NODE {
    struct NODE * link;
    int value;
} Node;


bool sll_insert(register Node ** linkp, int new_value);
Node * sll_reverse(Node * first);
bool sll_remove(Node ** rootp, Node * node);

#endif //CHAPTER12_SLL_NODE_H
