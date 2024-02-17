#include <fcntl.h>
#include <internal/syscall.h>
#include <errno.h>

#define EOF -1

int puts(const char *str) {

    int n = 0;

    while (*str != '\0') {
        n += syscall(__NR_write, 1, str, 1);
        str++;
    }

    if (n < 0) {
        return EOF;
    }

    n += syscall(__NR_write, 1, "\n",1);

    if (n < 0) {
        return EOF;
    }

    return n;

}