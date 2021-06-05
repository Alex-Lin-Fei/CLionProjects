#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

/*
 * exercise 1
 * */
void * my_calloc(size_t num, size_t size) {
    size_t memory_num = num * size;

    void * ptr = malloc(memory_num);
    if (ptr) {
        char * pc = ptr;
        while (--memory_num >= 0) {
            *pc++ = '\0';
        }
    }
    return ptr;
}


/*
 * exercise 2
 * */
int * read_array() {
    int *array;
    int value; //输入数值
    int count = 0; //目前输入数目
    int size; //array大小

    size = SIZE;
    array = (int *) malloc((size + 1) * sizeof(int)); //保留第一个位置存储总数目

    if (array == NULL) {
        return NULL;
    }

    while (scanf("%d", &value) == 1) {
        count++;
        if (count > size) {
            size += SIZE;
            array = realloc(array, (size + 1) * sizeof(int));
            if (array == NULL) {
                return NULL;
            }
        }
        array[count] = value;
    }

    if (count < size) {
        array = realloc(array, (count + 1) * sizeof(int));
        if (array == NULL) {

        }
    }
    array[0] = count;
    return array;
}


/*
 * exercise 3
 * */
char * read_string() {
    static char * buffer;
    char * bp;
    char * string;
    char ch;
    int count=0;
    int size = 0;

bp = buffer;
    do {
        ch = (char)getchar();
        if (ch == '\0' || ch == '\n')
            ch = '\0';
        count++;
        if (count > size) {
            size += SIZE;
            buffer = (char *) realloc(buffer,
                    size * sizeof(char)
            );
            if (buffer == NULL)
                return NULL;
            bp = buffer + count - 1;
        }

        *bp++ = ch;
    } while (ch != '\0');


    string = (char*)malloc(count*sizeof(char));
    strcpy(string, buffer);

    return string;
}


int main() {
    char  x[] = "eee";
    char *p = x;
    while (true) {
        if (*p == '\0') {
            printf("\\0");
            break;
        }
        else
            printf("%c", *p++);
    }
//    char * string = read_string();
//    puts(string);
    printf("%lu %lu", strlen(x), sizeof x / sizeof(char));

    return 0;
}
