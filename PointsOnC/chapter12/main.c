#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>
#include "dll_node.h"


/*
 * exercise 7 concordance list
 * */

/*
 * word structure
 * */
typedef struct WORD {
    char * word;
    struct WORD * next;
}Word;


/*
 * list structure
 * */
typedef struct LIST {
    char letter;
    struct LIST * next;
    Word * word_list;
}List;


int concordance_insert(List ** pList, const char * the_word) {
    char first_char;
    List *current_list;
    Word **pWord;
    Word *current_word;
    Word *new_word;
    int comparison;

    /*
     * judge is a valid word
     * */
    first_char = *the_word;
    if (!islower(first_char))
        return false;

    /*
     * search the list
     * */
    while ((current_list = *pList) != NULL && current_list->letter < first_char)
        pList = &current_list->next;

    /*
     * no such a list head with the character
     * */
    if (current_list == NULL || current_list->letter > first_char) {
        List *new_list;

        new_list = (List *) malloc(sizeof(List));
        if (new_list == NULL)
            return false;
        new_list->letter = first_char;
        new_list->next = current_list;
        *pList = new_list;  //insert
        new_list->word_list = NULL;
        current_list = new_list;
    }

    /*
     * find this list and find the word
     * */
    pWord = &current_list->word_list;
    while ((current_word = *pWord) != NULL) {
        comparison = strcmp(the_word, current_word->word);
        if (comparison >= 0)
            break;
        pWord = &current_word->next;
    }


    //exist
    if (comparison == 0)
        return false;

    //insert a new word
    new_word = (Word *) malloc(sizeof(Word));

    if (new_word == NULL)
        return false;
    new_word->word = (char *) malloc(strlen(the_word) + 1);

    if (new_word->word == NULL)
        return false;

    strcpy(new_word->word, the_word);

    new_word->next = current_word;
    *pWord = new_word;

    return true;
}

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
