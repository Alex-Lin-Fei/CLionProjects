#include <stdio.h>
#include <malloc.h>
#include "dll_node.h"

int main() {
//    Node *root = (Node*)malloc(sizeof(Node));
//
//    sll_insert(&root, 5);
//    sll_insert(&root, 2);
//    sll_insert(&root, 3);
//    sll_insert(&root, 1);
//
//    Node * head = root;
//    while (head) {
//        printf("%d ", head->value);
//        head = head->link;
//    }
//    printf("\n");
//    root = sll_reverse(root);
//    head = root;
//    while (head) {
//        printf("%d ", head->value);
//        head = head->link;
//    }
    Node *root = (Node *) malloc(sizeof(Node));

    dll_insert(root, 0);
    dll_insert(root, 6);
    dll_insert(root, 2);
    dll_insert(root, 1);
    dll_insert(root, 5);
    dll_insert(root, 3);

    for (Node * head = root->nex; head!=NULL; head=head->nex)
        printf("%d ", head->value);
    printf("\n");
    dll_remove(root, 1);
    for (Node * head = root->nex; head!=NULL; head=head->nex)
        printf("%d ", head->value);
    printf("\n");
    dll_remove(root, 5);
    for (Node * head = root->nex; head!=NULL; head=head->nex)
        printf("%d ", head->value);

    printf("\n");
    dll_remove(root, 2);
    for (Node * head = root->nex; head!=NULL; head=head->nex)
        printf("%d ", head->value);

    printf("\n");
    dll_remove(root, 3);
    for (Node * head = root->nex; head!=NULL; head=head->nex)
        printf("%d ", head->value);

    printf("\n");
    dll_remove(root, 6);
    for (Node * head = root->nex; head!=NULL; head=head->nex)
        printf("%d ", head->value);

    printf("\n");
    dll_remove(root, 0);
    for (Node * head = root->nex; head!=NULL; head=head->nex)
        printf("%d ", head->value);

    return 0;
}
