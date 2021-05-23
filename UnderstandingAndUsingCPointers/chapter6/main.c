#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

#define LIST_SIZE 10

typedef struct {
    char *firstName;
    char * lastName;
    char * title;
    int age;
} Person;

Person * list[LIST_SIZE];

void initializePerson(Person * person, const char * fn, const char * ln, const char* title, int age) {
    person->firstName = (char*) malloc(strlen(fn)+1);
    strcpy(person->firstName, fn);
    person->lastName = (char*) malloc(strlen(ln)+1);
    strcpy(person->lastName, ln);
    person->title = (char*) malloc(strlen(title)+1);
    strcpy(person->title, title);
    person->age = age;
}

void deallocatePerson(Person* person) {
    free(person->firstName);
    free(person->lastName);
    free(person->title);
}

void initializeList() {
    for (int i = 0l; i < LIST_SIZE; i++) {
        list[i] = NULL;
    }
}

Person * getPerson() {
    for (int i = 0;  i < LIST_SIZE; i++) {
        if (list[i]) {
            Person* ptr = list[i];
            list[i] = NULL;
            return ptr;
        }
    }
    Person * person = (Person*) malloc(sizeof(Person));
    return person;
}

Person * returnPerson(Person* person) {
    for (int i = 0; i < LIST_SIZE; i++) {
        if (!list[i]) {
            list[i] = person;
            return person;
        }
    }
    deallocatePerson(person);
    free(person);
    person = NULL;
    return NULL;
}

void processOnPerson() {
    Person * ptrPerson;
    ptrPerson = (Person*) malloc(sizeof (Person));
    initializePerson(ptrPerson, "Anthony", "Diaz", "Title", 35);
    printf("%s %s %s %d\n", ptrPerson->firstName, ptrPerson->lastName, ptrPerson->title, ptrPerson->age);
    deallocatePerson(ptrPerson);
    free(ptrPerson);
    ptrPerson=NULL;
}


char menu();
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);

int main() {
//    processOnPerson();
Tree pets;
char choice;

    InitializeTree(&pets);
    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 'a':
                addpet(&pets);
                break;
            case 'l':
                showpets(&pets);
                break;
            case 'f':
                findpet(&pets);
                break;
            case 'n':
                printf("%d pets in club\n", TreeItemCount(&pets));
                break;
            case 'd':
                droppet(&pets);
                break;
            default:
                puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye.");

    return 0;
}

char menu() {
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet      l)show list of pets");
    puts("n) number of pets f) find pets");
    puts("d) delete a pet   q)quit");

    while ((ch = getchar()) != EOF) {
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
            puts("Please enter an a, l, f, n, d or q:");
        else
            break;
    }
    if (ch == EOF)
        ch = 'q';
    return ch;
}

void addpet(Tree * pt) {
    Item item;

    if (TreeIsFull(pt))
        puts("No room in the club");
    else {
        puts("Please enter name of pet: ");
        s_gets(item.petname, SLEN);
        puts("Please enter pet kind:");
        s_gets(item.petkind, SLEN);
        uppercase(item.petname);
        uppercase(item.petkind);
        AddItem(&item, pt);
    }
}

void showpets(const Tree * pt) {
    if (TreeIsEmpty(pt))
        puts("No pets");
    else
        Traverse(pt, printitem);
}

void printitem(Item item) {
    printf("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}

void findpet(const Tree *pt) {
    Item item;

    if (TreeIsEmpty(pt)) {
        puts("No pets");
        return;
    }
    puts("Please enter name of pet you wish to find: ");
    s_gets(item.petname, SLEN);
    puts("Please enter pet kind");
    s_gets(item.petkind, SLEN);
    uppercase(item.petname);
    uppercase(item.petkind);
    printf("%s the %s ", item.petname, item.petkind);
    if (InTree(&item, pt))
        printf("is a member.\n");
    else
        printf("is not a member\n");
}

void droppet(Tree * pt) {
    Item item;

    if (TreeIsEmpty(pt)) {
        puts("No pets");
        return;
    }
    puts("Please enter name of pet you wish to drop: ");
    s_gets(item.petname, SLEN);
    puts("Please enter pet kind");
    s_gets(item.petkind, SLEN);
    uppercase(item.petname);
    uppercase(item.petkind);
    printf("%s the %s ", item.petname, item.petkind);
    if (DeleteItem(&item, pt))
        printf("is dropped from the club\n");
    else
        printf("is not a member\n");
}

void uppercase(char * str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

char * s_gets(char * st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}