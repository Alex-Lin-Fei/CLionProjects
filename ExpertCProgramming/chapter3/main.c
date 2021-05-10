#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

enum type_tag { IDENTIFIER, QUALIFIER, TYPE};

struct token {
    char type;
    char string[MAX_TOKEN_LEN];
};

int top = -1;
struct token stack[MAX_TOKENS];
struct token this;

#define pop stack[top--]
#define push(s) stack[++top] = s

//推断标识符类型
enum type_tag classify_string() {
    char *s = this.string;
    if (!strcmp(s, "const ")) {
        strcpy(s, "read-only");
        return QUALIFIER;
    }

    if (!strcmp(s, "volatile"))
        return QUALIFIER;
    if (!strcmp(s, "void"))
        return TYPE;
    if (!strcmp(s, "char"))
        return TYPE;
    if (!strcmp(s, "signed"))
        return TYPE;
    if (!strcmp(s, "unsigned"))
        return TYPE;
    if (!strcmp(s, "short"))
        return TYPE;
    if (!strcmp(s, "int"))
        return TYPE;
    if (!strcmp(s, "float"))
        return TYPE;
    if (!strcmp(s, "double"))
        return TYPE;
    if (!strcmp(s, "long"))
        return TYPE;
    if (!strcmp(s, "struct"))
        return TYPE;
    if (!strcmp(s, "union"))
        return TYPE;
    if (!strcmp(s, "enum"))
        return TYPE;

    return IDENTIFIER;
}



void gettoken() {
    char *p = this.string;

    while ((*p = getchar()) == ' ')
        continue;

    if (isalnum(*p)) {
        while (isalnum(*++p = getchar()))
            continue;
        ungetc(*p, stdin); //退回一个字符
        *p = '\0';
        this.type = classify_string();
        return;
    }

    if (*p == '*') {
        strcpy(this.string, "point to");
        this.type = '*';
        return;
    }

    this.string[1] = '\0';
    this.type = *p;
    return;
}


void read_to_first_identifier() {
    gettoken();
    while (this.type != IDENTIFIER) {
        push(this);
        gettoken();
    }

    printf("%s is ", this.string);
    gettoken();
}

void deal_with_arrays() {
    while (this.type == '[') {
        printf("array ");
        gettoken();
        if (isdigit(this.string[0])) {
            printf("0..%d ", atoi(this.string) - 1);
            gettoken();
        }
        gettoken();
        printf("of ");
    }
}

void deal_with_function_args() {
    while (this.type != ')') {
        gettoken();
    }
    gettoken();
    printf("function returning ");
}

void deal_with_pointers() {
    while (stack[top].type == '*') {
        printf("%s ", pop.string);
    }
}

void deal_with_declarator() {
//    处理标识符之后可能存在的数组/函数
    switch (this.type) {
        case '[': deal_with_arrays();break;
        case '(': deal_with_function_args();
    }

    deal_with_pointers();
    while (top>=0) {
        if (stack[top].type == '(') {
            pop;
            gettoken();
            deal_with_declarator();
        } else {
            printf("%s ", pop.string);
        }
    }
}

int main() {
    read_to_first_identifier();
    deal_with_declarator();
    printf("\n");

    return 0;
}
