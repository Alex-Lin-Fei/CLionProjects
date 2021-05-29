#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/*
 * 在数组中寻找某个特定整型值的存储位置
 * */
int * find_int(int key, int array[], int array_len) {
    int i;
    for (i = 0; i < array_len; i++) {
        if (array[i] == key)
            return &array[i];
    }
    return NULL;
}

/*
 * 对值进行偶校验
 * */
int seven_parity(int value, int n_bits) {
    int parity = 0;

    while (n_bits > 0) {
        parity += value & 1;
        value >>=1;
        n_bits--;
    }
    return parity;
}

/*
 * 把一个数组中的元素都设置为0
 * */
void clear_array(int array[], int n_elements) {
    while (n_elements>0)
        array[--n_elements] = 0;
}

/*
 * 接受一个整型值,把它转换为字符并打印,前导a零被删除rray
 * */
void binary_to_ascii(unsigned int value) {
    unsigned int quotient = value / 10;
    if (quotient != 0)
        binary_to_ascii(quotient);
    putchar(value % 10 + '0');
}

/*
 * 计算指定数量的值的平均值
 * */
float average(int n_values, ...) {
    va_list var_arg;
    float sum = 0;

    va_start(var_arg, n_values);
    for (int i = 0; i < n_values; i++) {
        sum += va_arg(var_arg, int);
    }
    va_end(var_arg);
    return sum / n_values;
}


/*
 * exercise 1
 * */
int hermite(int n, int x) {
    if (n <= 0)
        return 1;
    else if (n == 1)
        return 2 * x;
    else
        return 2 * x * hermite(n-1,x) - 2 * (n-1) *hermite(n-2, x);
}

/*
 * exercise 2
 * */
int gcd(int M, int N) {
    if (M < 0 || N < 0)
        return 0;
    if (M % N == 0)
        return N;
    else
        return gcd(N, M % N);
}


/*
 * exercise 3
 * */
int ascii_to_integer(char * string) {
    int ans = 0;
    while (*string!='\0') {
        if (!(*string >= '0' && !string <= '9'))
            return 0;
        ans = ans * 10 + *string-'0';
        string++;
    }
    return ans;
}



/*
 * exercise 4
 * */
int max_list(int first_arg, ...) {
    int max = 0;
    va_list var_arg;
    if (first_arg >= 0) {
        int this_arg;
        max = first_arg;
        va_start(var_arg, first_arg);
        while ((this_arg = va_arg(var_arg, int)) > 0)
            if (this_arg > max)
                max = this_arg;
    }

    return max;
}


/*
 * exercise 5
 * */
void my_printf(char * format, ...) {
    va_list var_arg;
    va_start(var_arg, format);

    while (*format != '\0') {
        if (*format != '%')
            putchar(*format++);
        else {
            switch (*format != '\0'? *format++: '\0' ) {
                case 'd':

                    break;
                case 'f':
                    break;
                case 'c':
                    putchar(va_arg(var_arg, char));
                    break;
                case 's':
                {
                    char * str = va_arg(var_arg, char*);
                    while (*str != '\0')
                        putchar(*str++);
                }

                    break;
            }
        }
    }
}



/*
 * exercise 6
 * */
static char * digits[] = {
        "", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", "SIX ", "SEVEN ", "EIGHT ", "NINE ",
        "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN", "FOURTEEN ", "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ",
        "EIGHTEEN ", "NINETEEN "
};

static char * tens[] = {
        "TWENTY ", "THIRTY", "FORTY ", "FIFTY ", "SIXTY ", "SEVENTY ",
        "EIGHTY ", "NINETY "
};


static char * magnitudes[] = {
        "", "THOUSAND ", "MILLION ", "BILLION "
};

static void do_one_group(unsigned int amount, char *buffer, char ** magnitudes) {
    if (amount / 1000 > 0)
        do_one_group(amount / 1000, buffer, magnitudes + 1);


    amount %= 1000;
    int value = amount / 100;
    if (value > 0) {
        strcat(buffer, digits[value]);
        strcat(buffer, "HUNDRED ");
    }

    value = amount % 100;
    if (value >= 20) {
        strcat(buffer, tens[value / 10]);
        value %= 10;
    }

    if (value > 0)
        strcat(buffer, digits[value]);

    if (amount > 0)
        strcat(buffer, *magnitudes);
}

void written_amount(unsigned int amount, char * buffer) {
    if (amount == 0)
        strcpy(buffer, "ZERO ");
    else {
        *buffer = '\0';

    }
}


int main() {
    printf("%d", max_list(-1));
    return 0;
}
