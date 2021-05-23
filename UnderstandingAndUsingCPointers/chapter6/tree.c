//
// Created by lilin on 2021/5/23.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*局部数据类型*/
typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

/*局部函数的原型*/
static Trnode * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode(Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * root, void(*pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Trnode ** ptr);
static void DeleteAllNodes(Trnode* root);


/*函数定义*/

void InitializeTree(Tree * ptree) {
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree) {
    if (!ptree->root)
        return true;
    else
        return false;
}


bool TreeIsFull(const Tree * ptree) {
    if (ptree->size == MAXITEM)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree) {
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree) {
    Trnode *new_node;

    if (TreeIsFull(ptree)) {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    if (SeekItem(pi, ptree).child) {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;
    }

    new_node = MakeNode(pi);
    if (!new_node) {
        fprintf(stderr, "Could not create node\n");
        return false;
    }

    ptree->size++;
    if (!ptree->root)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);

    return true;
}


bool InTree(const Item * pi, const Tree * ptree) {
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}


bool DeleteItem(const Item * pi, Tree * ptree) {
    Pair look;

    look = SeekItem(pi, ptree);
    if (!look.child)
        return false;

    if (look.parent == NULL)
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;
    look.child = NULL;

    return true;
}


void Traverse(const Tree * ptree, void(*pfun)(Item item)) {
    if (ptree) {
        InOrder(ptree->root, pfun);
    }
}


void DeleteAll(Tree * ptree) {
    if (ptree) {
        DeleteAllNodes(ptree->root);
    }
    ptree->root = NULL;
    ptree->size = 0;
}




/*局部函数定义*/
static Trnode * MakeNode(const Item * pi) {
    Trnode * new_node = (Trnode*) malloc(sizeof(Trnode));
    if (new_node) {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right=NULL;
    }

    return new_node;
}



static bool ToLeft(const Item * i1, const Item * i2) {
    int res;

    if ((res = strcmp(i1->petname, i2->petname)) < 0)
        return true;
    else if (res == 0 && strcmp(i1->petkind, i2->petkind) < 0)
        return true;
    else
        return false;
}


static bool ToRight(const Item * i1, const Item * i2) {
    int res;

    if ((res = strcmp(i1->petname, i2->petname)) > 0)
        return true;
    else if (res == 0 && strcmp(i1->petkind, i2->petkind) > 0)
        return true;
    else
        return false;
}


static void AddNode(Trnode * new_node, Trnode * root) {
    if (ToLeft(&new_node->item, &root->item)) {
        if (root->left == NULL)
            root->left = new_node;
        else
            AddNode(new_node, root->left);
    }
    else if (ToRight(&new_node->item, &root->item)) {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else
    {
        fprintf(stderr, "location error in addnode()\n");
        exit(1);
    }
}


static void InOrder(const Trnode * root, void(*pfun)(Item item)) {
    if (root) {
        InOrder(root->left, pfun);
        pfun(root->item);
        InOrder(root->right, pfun);
    }
}


static Pair SeekItem(const Item * pi, const Tree * ptree) {
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (!look.child)
        return look;

    while (look.child) {
        if (ToLeft(pi, &look.child->item)) {
            look.parent = look.child;
            look.child = look.child->left;
        } else if (ToRight(pi, &look.child->item)) {
            look.parent = look.child;
            look.child = look.child->right;
        } else
            break;
    }
    return look;
}


static void DeleteNode(Trnode ** ptr) {
    Trnode  * temp;

    if (!(*ptr)->left) {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }

    else if (!(*ptr)->right) {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }

    else {
        for (temp = (*ptr)->right; temp->left; temp = temp->left)
            continue;
        temp->left = (*ptr)->left;
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
}


static void DeleteAllNodes(Trnode* root) {
    Trnode *pright;

    if (root) {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}
