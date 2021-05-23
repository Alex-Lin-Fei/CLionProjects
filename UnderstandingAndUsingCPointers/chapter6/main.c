#include <stdio.h>
#include <malloc.h>
#include <string.h>

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


int main() {
    processOnPerson();
    return 0;
}
