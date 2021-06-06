//
// Created by lilin on 2021/6/6.
//

#ifndef CHAPTER12_DLL_NODE_H
#define CHAPTER12_DLL_NODE_H

#include <stdbool.h>


typedef struct NODE {
    struct NODE * pre;
    struct NODE * nex;
    int value;
} Node;

bool dll_insert(Node * rootp, int value);
bool dll_remove(Node * rootp, int value);

#endif //CHAPTER12_DLL_NODE_H
