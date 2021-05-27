#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20            /*所能处理的最大列号*/
#define MAX_INPUT 1000          /*每个输入行的最大长度*/

int read_column_numbers(int columns[], int max);
void rearrange(char * output, char const * input, int n_columns, const int columns[]);

int main() {
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    /*
     * 读取该串列标号
     * */
    n_columns = read_column_numbers(columns, MAX_COLS);

    while (gets(input) !=NULL) {
        printf("Original input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s\n", output);
    }

    return EXIT_SUCCESS;
}


int read_column_numbers(int columns[], int max) {
    int num = 0;
    int ch;

    /*
     * 取得列标号 如果读取的数小于0就停止
     * */

    while (num < max && scanf("%d", &columns[num]) == 1
           && columns[num] >= 0)
        num += 1;

//    if (num % 2 != 0) {
//        puts("Last column number is not paired");
//        exit(EXIT_FAILURE);
//    }

    /*
     * 丢弃该行中包含的最后一个数字的那部分内容
     * */
    while ((ch = getchar()) != EOF && ch != '\n')
        ;
    return num;
}

void rearrange(char * output, char const * input, int n_columns, const int columns[]) {
    int col;    /*columns数组的下标*/
    int output_col;     /*输出列计数器*/
    int len;        /*输入行的长度*/

    len = strlen(input);
    output_col = 0;

    /*
     *  处理每对列标号
     * */

    for (col = 0; col < n_columns; col += 2) {
        int nchars = (col + 1 == n_columns ? len : columns[col + 1]) - columns[col] + 1;

        /*
         * 如果输入行结束或者输出输出行数组已满
         * */
        if (columns[col] >= len)
            continue;
        if (output_col == MAX_INPUT - 1)
            break;

        /*
         * 输出行空间不够
         * */
        if (output_col + nchars > MAX_INPUT - 1)
            nchars = MAX_INPUT - output_col - 1;

        /*
         * 复制相关的数据
         * */
        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }

    output[output_col] = '\0';
}
