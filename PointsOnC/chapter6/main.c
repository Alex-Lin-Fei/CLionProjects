#include <stdio.h>
#include <stdbool.h>

#define SIZE 1000

#define MAX_VALUE 10000
#define MAX_BIT_NUMBER ((MAX_VALUE - 3) / 2)
#define B_SIZE (MAX_BIT_NUMBER / sizeof(char) + 1)

/*
 * 计算一个字符串的长度
 * */
size_t strlen(char *string) {
    int length = 0;
    while (*string++ != '\0')
        length++;
    return length;
}
/*
 * 给定一个指向以NULL结尾的指针列表的指针,在列表中的字符串中查找一个特定字符
 * */
bool find_char(char **strings, char value) {
//    char *string;
//    while ((string = *strings++) != NULL) {
//        while (*string != '\0') {
//            if (*string++ == value)
//                return true;
//        }
//    }
//    return false;
    while (*strings++ != NULL) {
        while (**strings != '\0') {
            if (*(*strings)++ == value)
                return true;
        }
    }
    return false;
}

/*
 * exercise 1
 * */
char *e_find_char(char const *source, char const *chars) {
    char *temp;
    while (*source != '\0') {
        temp = chars;
        while (*temp != '\0') {
            if (*temp++ == *source)
                return source;
        }
        source++;
    }
    return NULL;
}

/*
 * exercise 2
 * */
//返回匹配后的位置
char * match(char * str, char * substr) {
    while (*substr != '\0') {
        if (*str++ != *substr++)
            return NULL;
    }
    return str;
}

int del_substr(char *str, char const *substr) {
    char *next;
    while (*str != '\0') {
        next = match(str, substr);
        if (next != NULL)
            break;
        str++;
    }
    if (*str == '\0')
        return 0;
    while (*next != '\0')
        *str++ = *next++;
    *str='\0';
    return 1;
}


/*
 * exercise 3
 * */

void reverse_string(char *string) {
    char *start = string;
    char *end = string;

    while (*end != '\0')
        end++;
    end--;
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

/*
 * exercise 4
 * */
void eratosthenes() {
//    全部初始化为1

    char sieve[SIZE];
    char *sp;
    int number;

    for (sp = sieve; sp < &sieve[SIZE];)
        *sp++ = 0;

    for (number = 3;; number += 2) {
        sp = sieve + (number - 3) / 2;
        if (sp >= &sieve[SIZE])
            break;
        if (*sp == 0)
            continue;
        while (sp += number, sp < &sieve[SIZE])
            *sp = 0;
    }

    printf("2 ");
    for (number = 3, sp = sieve; sp < &sieve[SIZE]; number += 2, sp++)
        if (*sp)
            printf("%d ", number);
}

/*
 * exercise 5 位数组实现exercise 4
 * */

signed int character_offset(unsigned int bit_number) {
    return bit_number / (sizeof(char) * 8);
}


signed int bit_offset(unsigned int bit_number) {
    return bit_number % (sizeof(char) * 8);
}

void set_bit(char bit_array[], int bit_number) {
    bit_array[character_offset(bit_number)] |= 1 << bit_offset(bit_number);
}

void clear_bit(char bit_array[], int bit_number) {
    bit_array[character_offset(bit_number)] &= ~(1 << bit_offset(bit_number));
}

int test_bit(char bit_array[], int bit_number) {
    return bit_array[character_offset(bit_number)] & 1 << bit_offset(bit_number);
}

void bit_eratosthenes() {
    char sieve[B_SIZE];
    char *sp;
    int number;

    int bit_number;

    for (sp = sieve; sp < &sieve[B_SIZE];)
        *sp++ = 0xff;


    for (number = 3; number <= MAX_VALUE; number+=2) {
        bit_number = (number - 3) / 2;
        if (!test_bit(sieve, bit_number))
            continue;
        while ((bit_number += number) <= MAX_BIT_NUMBER)
            clear_bit(sieve, bit_number);
    }
//    printf("2 ");
    int n_primes = 1;
    int limit = 1000;
    for (bit_number = 0, number = 3; number <= MAX_VALUE; bit_number += 1, number += 2) {
        if (number > limit) {
            printf("%d-%d: %d\n", limit - 1000, limit, n_primes);
            limit += 1000;
            n_primes = 0;
        }
        if (test_bit(sieve, bit_number)) {
//            printf("%d ", number);
            n_primes += 1;
        }
    }
    printf("%d-%d: %d\n", limit - 1000, limit, n_primes);
}



int main() {
    bit_eratosthenes();

    return 0;
}
