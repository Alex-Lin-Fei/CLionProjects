//#include <stdio.h>
//#include <string.h>
//
//#define DUMBCOPY for (i = 0; i < 65536; i++) destination[i] = source[i]
//
//#define SMARTCOPY memcpy(destination, source, 65536)
//
//
//void test() {
//#if defined(__GNUC__)
//# if defined(__i386__)
//    /* Enable Alignment Checking on x86 */
//        __asm__("pushf\norl $0x40000,(%esp)\npopf");
//# elif defined(__x86_64__)
///* Enable Alignment Checking on x86_64 */
//    __asm__("pushf\norl $0x40000,(%rsp)\npopf");
//# endif
//#endif
//
//
//    union {
//        char a[10];
//        int i;
//    }u;
//
//    printf("%p\n", &(u.a[0]));
////    int *p = (int *)&(u.a[0]);
////   *p = 17;
////    printf("p: %p; *p: %d\n", p, *p);
//
////    int *q = 0xddc53018;
////    *q = 18;
//}
//
//int main() {
//    char source[65536], destination[65536];
//    int i, j;
//    for (j = 0; j < 100; j++)
//        DUMBCOPY;
////        SMARTCOPY;
//
//
//test();
//    return 0;
//}

#include <stdlib.h>

#if defined(__GNUC__)
# if defined(__i386__)
/* Enable Alignment Checking on x86 */
        __asm__("pushf\norl $0x40000,(%esp)\npopf");
# elif defined(__x86_64__)
/* Enable Alignment Checking on x86_64 */
__asm__("pushf\norl $0x40000,(%rsp)\npopf");
# endif
#endif

int main(int argc, char **argv) {

    union{
        char a[10];
        int i;
    }u;
    int *p =(int*)&(u.a[1]);
    *p =17;
}