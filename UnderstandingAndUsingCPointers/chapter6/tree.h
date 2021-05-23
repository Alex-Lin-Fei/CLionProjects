//
// Created by lilin on 2021/5/23.
//

#ifndef CHAPTER6_TREE_H
#define CHAPTER6_TREE_H
#include <stdbool.h>

#define SLEN 20
typedef struct item {
    char petname[SLEN];
    char petkind[SLEN];
} Item;

#define MAXITEM 10

typedef struct trnode {
    Item item;
    struct trnode * left;
    struct trnode * right;
} Trnode;

typedef struct tree {
    Trnode * root;  /*point to the root of tree*/
    int size;       /*items of tree*/
} Tree;

/*函数原型*/

/*操作：       初始化树*/
/*前置条件：     ptree指向一棵树*/
/*后置条件：     树被初始化*/
void InitializeTree(Tree * ptree);

bool TreeIsEmpty(const Tree* ptree);

bool TreeIsFull(const Tree * ptree);

int TreeItemCount(const Tree * ptree);

bool AddItem(const Item * pi, Tree * ptree);

bool InTree(const Item * pi, const Tree * ptree);

bool DeleteItem(const Item * pi, Tree * ptree);

void Traverse(const Tree * ptree, void(*pfun)(Item item));

void DeleteAll(Tree * ptree);

#endif //CHAPTER6_TREE_H
