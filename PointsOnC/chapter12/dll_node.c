//
// Created by lilin on 2021/6/6.
//
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "dll_node.h"

bool dll_insert(register Node * rootp, int value) {
    Node *this;
    Node *next;
    Node *newnode;

    for (this = rootp; (next = this->nex) != NULL; this = next) {
        if (next->value == value)
            return false;
        if (next->value > value)
            break;
    }

    newnode = (Node *) malloc(sizeof(Node));
    newnode->value=value;

    newnode->nex = next;
    this->nex = newnode;

    if (next)
        next->pre = newnode;
    else
        rootp->pre = newnode;
    if (this != rootp) {
        newnode->pre = this;
    } else {
        newnode->pre = NULL;
    }
    return 1;
}

bool dll_remove(Node * rootp, int value) {
    register Node * this;

    for (this = rootp->nex; this != NULL; this=this->nex) {
        if (this->value == value)
            break;
    }
    if (this==NULL)
        return false;

    //头指针
    if (rootp->nex == this) {
        if (this->nex != NULL) {
            rootp->nex = this->nex;
            this->nex->pre = NULL;
            free(this);
        } else {
            rootp->nex = NULL;
            rootp->pre = NULL;
            free(this);
        }
    } else {
        if (this->nex != NULL) {
            this->pre->nex = this->nex;
            this->nex->pre = this->pre;
            free(this);
        } else { //尾指针
            rootp->pre = this->pre;
            this->pre->nex = NULL;
            free(this);
        }
    }

    return true;
}
