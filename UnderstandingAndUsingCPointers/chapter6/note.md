#指针和结构体  
##为结构体分配内存  
分配的内存大小至少是各个字段的长度和。实际长度会大于这个和，因为结构体各字段之间可能会有填充，某些数据类型需要对齐到特定边界就会产生填充  
意味着：  
+ 要谨慎使用指针算术运算  
+ 结构体数组的元素之间可能存在额外的内存  

##结构体释放问题  
为结构体分配内存时，运行时系统不会自动为结构体内部的指针分配内存，类似地，结构体消失时也不会释放内部的指针指向的内存  

##避免malloc/free开销  
重复分配和释放结构体会产生一些开销，可能导致巨大的性能瓶颈。因此为分配的结构体单独维护一个表  
```c
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

```
运行结果：  
```c
Anthony Diaz Title 35
```
