#include <stdio.h>

void foo(const char ** p) {

}

void bar(const char * p) {

}

int main(int argc, char ** argv) {
    foo(argv);
    char * x;
    bar(x);
    return 0;
}
