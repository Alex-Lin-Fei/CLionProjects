#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define RAII_VARIABLE(vartype, varname, initval, dtor) \
void _dtor_ ## varname (vartype * v) { dtor(*v); }     \
vartype varname _attribute_((cleanup(_dtor_ ## varname))) == (initval)

static int *a;
int *b;

void raiiExample() {
    RAII_VARIABLE(char* ,name, (char*) malloc(32), free);
    strcpy(name, "RAII Example");
    printf("%s", name);
}

int main() {
    if (a == NULL)
        printf("null a ");
    printf("%d\n", a);
    if (b == NULL)
    printf("null b ");
    printf("%d\n", b);
    a = (int*) malloc(sizeof(int));
    b = (int*) malloc(sizeof(int));
    printf("%p %p\n", a, b);
    return 0;
}
