#include <stdio.h>
#include <string.h>
/*
 * 返回参数值中1的位的个数
 * */
int count_one_bits(unsigned value) {
    int ones;
    for (ones = 0; value != 0; value = value>>1) {
        if ((value & 1) != 0) // if ((value & 1) != 0)
            ones++;
    }
    return ones;
}

/*
 * exercise 1
 * */
void upperToLower() {
    char ch;
    while ((ch = getchar()) != EOF) {
        if (ch >= 'A' && ch <= 'Z')
            ch = 'a' + ch - 'A';
        putchar(ch);
    }
}


/*
 * exercise 2
 * */
void encode() {
    char ch;
    while ((ch = getchar()) != EOF) {
        if (ch >= 'A' && ch <= 'Z')
            ch = 'A' + (ch - 'A' + 13) % 26;
        else if (ch >= 'a' && ch <= 'z')
            ch = 'a' + (ch - 'a' + 13) % 26;
        putchar(ch);
    }
}

/*
 * exercise 3
 * */
unsigned int reverse_bits(unsigned int value) {
    unsigned int ans = 0;
    for (int i = 0; i < sizeof(unsigned int) * 8; i++) {
        ans = ans * 2 + (value & 1);
        value >>= 1;
    }
    return ans;
}


void binary(unsigned int num) {
    while (num) {
        printf("%d", num % 2);
        num /= 2;
    }
    putchar('\n');
}


/*
 * exercise 4
 * */

unsigned int character_offset(unsigned int bit_number) {
    return bit_number / (sizeof (char) * 8);
}

unsigned int bit_offset(unsigned int bit_number) {
    return bit_number % (sizeof (char) * 8);
}

void set_bit(char bit_array[], unsigned int bit_number) {
    bit_array[character_offset(bit_number)] |= 1 << bit_offset(bit_number);
}

void clear_bit(char bit_array[], unsigned int bit_number) {
    bit_array[character_offset(bit_number)] &= ~(1 << bit_offset(bit_number));
}

void assign_bit(char bit_array[],  unsigned int bit_number, int value) {
    if (value != 0)
        set_bit(bit_array, bit_number);
    else
        clear_bit(bit_array, bit_number);
}

int test_bit(char bit_array[], unsigned int bit_number) {
    return (bit_array[character_offset(bit_number)] & 1 << bit_offset(bit_number)) != 0;
}

/*
 * exercise 5
 * */
int store_bit_field(int original_value, int value_to_store,
                    unsigned starting_bit, unsigned ending_bit) {
//    获取掩码mask
    unsigned x = 0xffff;
    x <<= ending_bit;
    unsigned y = 0xffff;
    y <<= starting_bit + 1;
    unsigned mask = x ^y;
    printf("%#x %#x %#x\n", x, y, mask);
    unsigned unmask = ~mask;

//    需要修改的部分置为0
    original_value &= unmask;

//    处理添加的位
    value_to_store <<= ending_bit;
    value_to_store &= mask;

//添加
    original_value |= value_to_store;
    return original_value;
}


int main() {
    printf("%#x\n", store_bit_field(0x0,0x1,4,4));
    return 0;
}
