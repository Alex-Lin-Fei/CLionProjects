#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10



char * strrstr(const char * s1, const char * s2) {
    register char * last;
    register char * current;
    last = NULL;
    if (*s1 != '\0') {
        current = strstr(s1, s2);
        while (current != NULL) {
            last = current;
            current = strstr(last+1, s2);
        }
    }
    return last;
}

char * strrpbrk(const char * str, const char * group) {
    register char * last;
    register char * current;
    last = NULL;
    if (*str != '\0') {
        current = strpbrk(str, group);
        while (current != NULL) {
            last = current;
            current = strpbrk(last+1, group);
        }
    }
    return last;
}


/*
 * exercise 1
 * */
void printPer(int a, int b) {
    printf("%d %.2f\n", a, a * 1.0 / b * 100);
}
void f() {
    int ctrl_num = 0;
    int blank_num = 0;
    int digit_num = 0;
    int lower_num = 0;
    int upper_num = 0;
    int punctuation_num = 0;
    int unprint_num = 0;
    int sum = 0;

    int ch;
    while ((ch = getchar()) != EOF) {
        if (iscntrl(ch))
            ctrl_num++;
        else if (isblank(ch))
            blank_num++;
        else if (isdigit(ch))
            digit_num++;
        else if (islower(ch))
            lower_num++;
        else if (isupper(ch))
            upper_num++;
        else if (ispunct(ch))
            punctuation_num++;
        else
            unprint_num++;
        sum++;
    }

    printf("ctrl number: ");
    printPer(ctrl_num, sum);
    printf("blanck number: ");
    printPer(blank_num, sum);
    printf("digit number: ");
    printPer(digit_num, sum);
    printf("lower number:a ");
    printPer(lower_num, sum);
    printf("upper number: ");
    printPer(upper_num, sum);
    printf("punctuation number: ");
    printPer(punctuation_num, sum);
    printf("another number: ");
    printPer(unprint_num, sum);
}


/*
 * exercise 2
 * */
size_t my_strnlen(char const * string, int size) {
    int len;
    for (len = 0; len < size; len++)
        if (*string++ == '\0')
            break;
    return len;
}

/*
 * exercise 3
 * */
char * my_strcpy(char * dst, char *src, int size) {
    strncpy(dst, src, size);
    dst[size - 1] = '\0';

    return dst;
}

/*
 * exercise 4
 * */
char * my_strcat(char * dst, char const * src, int size) {
    int length;
    size--;
    length = size - (int) my_strnlen(dst, size);
    if (length > 0)
        strncat(dst, src, length);

    return dst;
}


/*
 * exercise 5
 * */
void my_strncat(char *dest, char * src, int dest_len) {
    dest_len -= (int)strlen(dest) + 1;
    if (dest_len > 0)
        strncat(dest, src, dest_len);
}



/*
 * exercise 6
 * */
char * my_strcpy_end(register char * dst, register char * src) {
    while ((*dst++ = *src++) != '\0')
        continue;
    return dst - 1;
}

/*
 * exercise 7
 * */
char * my_strrchr(char const *str, int ch) {
    char *last = NULL;
    while ((str = strchr(str, ch)) != NULL) {
        last = str;
        str++;
    }
    return last;
}


/*
 * exercise 8
 * */
char * my_strnchr(char const * str, int ch, int which) {
    char *last = NULL;
    while ((str = strchr(str, ch)) != NULL) {
        last = str;
        str++;
        if (--which == 0)
            break;
    }
    return last;
}


/*
 * exercise 9
 * */
int count_chars(char const * str, char const * chars) {
    int count = 0;
    while ((str = strpbrk(str, chars)) != NULL)
    {
        count++;
        str++;
    }
    return count;
}

int palindrome(char * string) {
    char * ps = string;
    char * pt = string;
    while (*pt != '\0')
        pt++;
    pt--;
    while (true) {
        while (ps < pt && !isalpha(*ps))
            ps++;

        while (pt > ps && !isalpha(*pt))
            pt--;
        if (pt <= ps)
            return 1;

        if (tolower(*pt) != tolower(*ps))
            return 0;
        ps++;
        pt--;
    }
}

/*
 * exercise 11
 * */
int count_the() {
    int ch;
    FILE *fp;
    int state = 0;
    int count = 0;

    if ((fp = fopen("/home/lilin/CLionProjects/PointsOnC/chapter9/file", "r")) == NULL) {
        fprintf(stderr, "cannot open file");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        switch (state) {
            case 0: {
                if (ch == 't')
                    state = 1;
                else if (ch != ' ' && !ispunct(ch))
                    state = 4;
            }
                break;
            case 1: {
                if (ch == 'h')
                    state = 2;
                else if (ch == ' ' || ispunct(ch))
                    state = 0;
                else
                    state = 4;
            }
                break;
            case 2: {
                if (ch == 'e')
                    state = 3;
                else if (ch == ' ' || ispunct(ch))
                    state = 0;
                else state = 4;

            }
                break;
            case 3: {
                if (ch == ' ' || ispunct(ch)) {
                    state = 0;
                    count++;
                } else state = 4;
            }
            case 4: {
                if (ch == ' ' || ispunct(ch))
                    state = 0;
            }
            default:
                break;
        }
    }
    if (state == 3)
        count++;

    return count;
}

/*
 * exercise 12
 * */
int prepare_key(char *key) {
    register char *keyp;
    register int character;
    register char *dup;

    if (*key == '\0')
        return 0;

//    convert to upper
    for (keyp = key; (character = *keyp) != '\0'; keyp++) {
        if (!isupper(character)) {
            if (!islower(character))
                return 0;
            *keyp = toupper(character);
        }
    }

    for (keyp = key; (character = *keyp) != '\0';) {
        dup = ++keyp;
        while ((dup = strchr(dup, character)) != NULL)
            strcpy(dup, dup + 1);
    }

    for (character = 'A'; character <= 'Z'; character++) {
        if (strchr(key, character) == NULL) {
            *keyp++ = character;
            *keyp = '\0';
        }
    }

    return 1;
}




/*
 * exercise 14
 * */
void encrypt(char *data, char const * key) {
    while (*data != '\0') {
        if (isalpha(*data)) {
            if (islower(*data))
                *data = tolower(*(key + *data - 'a'));
            else
                *data = *(key + *data - 'A');
        }
        data++;
    }
}




/*
 * exercise 14
 * */
void decrypt(char *data, char const * key) {
    while (*data != '\0') {
        if (isalpha(*data)) {
            if (islower(*data))
                *data = tolower('A' + (strchr(key, toupper(*data)) - key));
            else
                *data = 'A' + (strchr(key, *data) - key);
        }
        data++;
    }
}


/*
 * exercise 15
 * */
void dollars(char * dest, char const * src) {
}



/*
 * exercise 16
 * */
int format(char * format_string, char const *digit_string) {

}


/*
 * exercise 17
 * */
char * edit(char * pattern, char const * digits) {

}

int main(int argc, char * argv[]) {
    char key[100] = "trailblazers";
    char data[100] = "attack at dawn";
    prepare_key(key);
    puts(key);
    encrypt(data, key);
    puts(data);
    decrypt(data, key);
    puts(data);

    return 0;
}
