#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
 * exercise 2
 * 读取源代码并确保花括号都匹配
 * */
bool lab2(char * sourcecode) {
    int len = strlen(sourcecode);
    int num = 0;

    for (int i = 0; i < len; i++) {
        if (sourcecode[i] == '{')
            num++;
        else if (sourcecode[i] == '}') {
            num--;
            if (num < 0)
                return false;
        } else
            continue;
    }
    return num == 0;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
