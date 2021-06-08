#include <stdio.h>
#include <ctype.h>

/*
 * program 4
 * */
void binary_to_ascii(unsigned int value) {
    unsigned int quotient;

    quotient = value/10;
    if (quotient)
        binary_to_ascii(quotient);
    putchar(value % 10 + '0');
}


/*
 * exercise 1
 * */

/*
 * define a function to judge whether a ch can print
 * */
int is_not_print(int ch) {
    return !isprint(ch);
}


/*
 * 区别每种类型的分类函数的跳转表
 * */
static int(*test_func[])(int) = {
        iscntrl,
        isspace,
        isdigit,
        islower,
        isupper,
        ispunct,
        is_not_print
};

#define N_CATECOGIES (sizeof(test_func) / sizeof(test_func[0]))

char *label[] = {
        "control",
        "space",
        "digit",
        "islower",
        "isupper",
        "ispunct",
        "is_not_print"
};

int count[N_CATECOGIES];
int total;

void printChar() {
    int ch;
    int category;

    while ((ch = getchar()) != EOF) {
        total++;

        for (category = 0; category < N_CATECOGIES; category++) {
            if (test_func[category](ch))
                count[category]++;
        }
    }
    if (total == 0)
        printf("No characters in the print\n");
    else {
        for (category = 0; category < N_CATECOGIES; category++) {
            printf("%3.0f%% %s characters\n", count[category] * 100.0 / total, label[category]);
        }
    }
}

int main() {

    return 0;
}
