#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENLEN 64
#define MAXTOKENS 100

enum type_tag { IDENTIFIED, QUALIFIER, TYPE};

struct token {
    char type;
    char string[MAXTOKENLEN];
};

int top = -1;


/*保存第一个标识符之前的所有标记*/
struct token stack[MAXTOKENS];

/*保存刚读入的标记*/
struct token this;

//实用程序
//字符串分类
enum type_tag classify_string() {
    if (!strcmp(this.string, "const")) {
        strcpy(this.string, "read-only");
        return QUALIFIER;
    }
    if (!strcmp(this.string, "volatile"))
        return QUALIFIER;
    if (!strcmp(this.string, "void"))
        return TYPE;
    if (!strcmp(this.string, "char"))
        return TYPE;
    if (!strcmp(this.string, "signed"))
        return TYPE;
    if (!strcmp(this.string, "unsigned"))
        return TYPE;
    if (!strcmp(this.string, "short"))
        return TYPE;
    if (!strcmp(this.string, "int"))
        return TYPE;
    if (!strcmp(this.string, "float"))
        return TYPE;
    if (!strcmp(this.string, "double"))
        return TYPE;
    if (!strcmp(this.string, "long"))
        return TYPE;
    if (!strcmp(this.string, "struct"))
        return TYPE;
    if (!strcmp(this.string, "union"))
        return TYPE;
    if (!strcmp(this.string, "enum"))
        return TYPE;
    return IDENTIFIED;
}

//读取下一个标记
void gettoken() {
    char *p = this.string;

    while ((*p = getchar()) == ' ')
        continue;

    if (isalnum(*p)) {
        while (isalnum(*++p = getchar()))
            continue;
        ungetc(*p, stdin);
        *p = '\0';
        this.type = classify_string();
        return;
    }

    if (*p == '*') {
        strcpy(this.string, "pointer to");
        this.type = '*';
        return;
    }

    this.string[1] = '\0';
    this.type = *p;
    return;
}


void read_to_first_identifier() {
    gettoken();
    while (this.type != IDENTIFIED) {
        stack[++top] = this;
        gettoken();
    }
    printf("%s is ", this.string);
    gettoken();
}

void deal_with_arrays() {
    while (this.type == '[') {
        printf("array ");
        gettoken(); //有可能是数字或者]
        if (isdigit(this.string[0])) {
            printf("0..%d ", atoi(this.string) - 1);
            gettoken();
        }
        gettoken(); //读取 ]之后的下一个字符
        printf("of ");
    }
}



int main() {

}
