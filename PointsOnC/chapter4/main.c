#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 128

/*
 * lab 4 实现strncpy
 * */
void copy_n(char dst[], char src[], int n) {
    int idx = 0;
    while (idx < n && *src != '\0')
        *(dst + idx++) = *src++;
    while (idx < n)
        *(dst + idx++) = '\0';
}


/*
 * lab 5 输出重复字符串
 * */
void printLine() {
    char pre[MAX_LEN];
    char now[MAX_LEN];
    bool hasPrint =false;

    if (fgets(pre, MAX_LEN, stdin) != NULL) {
        while (fgets(now, MAX_LEN, stdin) != NULL) {
            if (strcmp(now, pre) == 0 ) {
                if (!hasPrint) {
                    puts(now);
                    hasPrint = true;
                }
            }
            else
                hasPrint = false;
            strcpy(pre, now);
        }
    }
}

/*
 * lab 6
 *
 * */

int substr(char dst[], char src[], int start, int len) {
    int i;
    for (i = start; i < start + len; i++) {
        dst[i - start] = src[i];
        if (src[i] == '\0')
            break;
    }
    if (dst[i-start-1] != '\0')
        dst[i - start] = '\0';
    return i - start;
}

/*
 * lab 7 去除字符串中的多余空格
 * */

void deblank(char string[]) {
//    测量string长度
    int len = 0;
    char *start = string;
    while (*start++ != '\0')
        len++;


    char temp[len];
    start = temp;
    for (int i = 0; i < len; i++) {
        if (string[i] == ' ') {
            if (i + 1 < len && string[i] == string[i + 1])
                continue;
        }
        *start++ = string[i];
    }
    *start = '\0';
    strcpy(string, temp);
    puts(string);
}


int main() {
    char src[] = "abcdefg";
    char dst[9];
    printf("%d\n", substr(dst, src, 3, 2));
    puts(dst);

    return 0;
}
