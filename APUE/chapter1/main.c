//#include "apue.h"
#include "my_err.h"
#include <dirent.h>
#include <sys/wait.h>

#define BUFFSIZE 4096

/*
 * 图1-3 列出一个目录中所有文件
 * */
//int main(int argc, char * argv[]) {
//    DIR *dp;
//    struct dirent *dirp;
//
//    if (argc != 2) {
//        err_quit("usage: ls directory_name");
//    }
//    if ((dp = opendir(argv[1])) == NULL)
//        err_sys("cannot open %s", argv[1]);
//
//    while ((dirp = readdir(dp)) != NULL)
//        printf("%s\n", dirp->d_name);
//
//    closedir(dp);
//
//
//    exit(0);
//}


/*
 * 图1-4 将标准输入复制到标准输出
 * */
//int main() {
//    int n;
//    char buf[BUFFSIZE];
//
//    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
//        if (write(STDOUT_FILENO, buf, n) != n)
//            err_sys("write error");
//    }
//
//    if (n < 0)
//        err_sys("read error");
//
//    exit(0);
//}

/*
 * 图1-5 用标准I/O将标准输入复制到标准输出
 * */
//int main() {
//    int c;
//
//    while ((c = getc(stdin)) != EOF) {
//        if (putc(c, stdout) == EOF)
//            err_sys("output error");
//    }
//    if (ferror(stdin))
//        err_sys("input error");
//
//    exit(0);
//}

/*
 * 图1-6 打印进程ID
 * */
//int main() {
//    printf("hello world from process ID %ld\n", (long)getpid());
//    exit(0);
//}


/*
 * 图1-7 从标准输入读取命令并执行
 * */
//int main() {
//    char buf[MAXLINE];
//    pid_t pid;
//    int status;
//
//    printf("%% ");
//    while (fgets(buf, MAXLINE, stdin) != NULL) {
//        if (buf[strlen(buf) - 1] == '\n')
//            buf[strlen(buf) - 1] = 0;
//
//        if ((pid = fork()) < 0)
//            err_sys("fork error");
//
//
//        else if (pid==0) {
//            execlp(buf, buf, (char *) 0);
//            err_ret("could not execute: %s", buf);
//            exit(127);
//        }
//
//        if ((pid = waitpid(pid, &status, 0)) < 0)
//            err_sys("waitpid error");
//
//        printf("%% ");
//    }
//
//    exit(0);
//}



///*
// * 图1-8 例示strerror和perror
// * */
//int main(int argc, char * argv[]){
//    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
//    errno = ENOENT;
//    perror(argv[0]);
//    exit(0);
//}



/*
 * 图1-9 打印用户ID和组ID
 * */
//int main(int argc, char * argv[]){
//    printf("uid = %d, gid = %d\n", getuid(), getgid());
//    exit(0);
//}




/*
 * 图1-7 从标准输入读取命令并执行
 * */
static void sig_int(int);

int main() {
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;

        if ((pid = fork()) < 0)
            err_sys("fork error");


        else if (pid==0) {
            execlp(buf, buf, (char *) 0);
            err_ret("could not execute: %s", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");

        printf("%% ");
    }

    exit(0);
}

void sig_int(int signo) {
    printf("interrupt\n %%");
}
