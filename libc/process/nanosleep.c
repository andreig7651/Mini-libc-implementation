#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    
    /* TODO: Implement nanosleep(). */
    int res = syscall(__NR_nanosleep, req, rem);
    
    if(res == 0) {
        return 0;
    }
    
    while (res == -1 && errno == EINTR) {
        res = syscall(__NR_nanosleep, req, rem);
    }
    
    return res;
}