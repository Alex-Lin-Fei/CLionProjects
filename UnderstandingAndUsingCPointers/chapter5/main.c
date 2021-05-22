#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

char * staticFormat(const char *name, size_t quantity, size_t weight) {
    static char buffer[24];
    sprintf(buffer, "Item: %s Quantity: %u Weight: %u", name, quantity, weight);
    return buffer;
}

int compare(const char *s1, const char * s2) {
    return strcmp(s1, s2);
}


char * stringToLower(const char * s) {
    char *scp = (char *) malloc(strlen(s) + 1);
    char *tmp = scp;
    while (*s) {
        *tmp++ = tolower(*s++);
    }
    *tmp = '\0';
    printf("%s\n", scp);
    return scp;
}

int compareIgnoreCase(const char* s1, const char * s2) {
    char * sl1 = stringToLower(s1);
    char * sl2 = stringToLower(s2);
    int res = strcmp(sl1, sl2);
    free(sl1);
    free(sl2);
    return res;
}


void displayString(char * names[], int size) {
    for (int i = 0; i < size; i++)
        printf("%s\n", names[i]);
}

void sort(char * array[], int size, int (*cmp)(const char* , const char *)) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (cmp(array[i], array[j]) > 0) {
                char * tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void test() {
    char * names[] = {"Alice", "Bob", "Antony", "Smith", "Jonny"};
    sort(names, 5, compareIgnoreCase);
    displayString(names, 5);
}

int main() {
    int x;
    int y;
    printf("%p %p\n", &x, &y);

    char *part1 = staticFormat("Axle", 25, 45);
    printf("part1: %s\n", part1);

    char * part2 = staticFormat("Piston", 55,5);
    printf("part1: %s\n", part1);
    printf("part2: %s\n", part2);


    test();

    return 0;
}
