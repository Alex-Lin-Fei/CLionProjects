#include "my_err.h"
#include <fcntl.h>

/*
 * 图3-1 测试标准输入能否被设置偏移量
 * */
//int main() {
//    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
//        printf("cannot seek\n");
//    else
//        printf("seek OK\n");
//    exit(0);
//}


/*
 * 图３-2 创建一个具有空洞的文件
 **/
//char buf1[] = "abcdefghij";
//char buf2[] = "ABCDEFGHIJ";
//
//int main() {
//    int fd;
//
//    if ((fd = creat("file.hole", FILE_MODE)) < 0)
//        err_sys("creat error");
//
//    if (write(fd, buf1, 10) != 10)
//        err_sys("buf1 write error");
//
//    if (lseek(fd, 16384, SEEK_SET) == -1)
//        err_sys("lseek error");
//    if (write(fd, buf2, 10) != 10)
//        err_sys("buf2 write error");
//
//    exit(0);
//}

/*
 * 图3-11 对于指定的描述符打印文件标志
 * */
//int main(int argc, char * argv[]) {
//    int val;
//
//    if (argc != 2)
//        err_quit("usage: a.out < descriptor#>");
//
//    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
//        err_sys("fcntl error for fd %d", atoi(argv[1]));
//
//    switch (val & O_ACCMODE) {
//
//    }
//
//    exit(0);
//}


/*
 * exercise 2
 * */
int my_dup2(int oldfd, int newfd) {
    int fd;
    long t_openmax = open_max();

    if (oldfd < 0 || newfd < 0 || oldfd >= t_openmax || newfd >= t_openmax)
        err_sys("fd error");

    if (oldfd == newfd) {
        return newfd;
    }

    close(newfd);

    fd = dup(oldfd);
    while (fd < t_openmax) {
        if (fd == newfd)
            break;
        close(fd);
        if ((fd = dup(oldfd)) == -1)
            err_sys("dup error");
    }
    return fd;
}


/*
 * tee
 * */
int main() {

}
