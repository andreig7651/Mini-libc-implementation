#include <time.h>
#include <unistd.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds)
{
	/* TODO: Implement sleep(). */
    struct timespec req;
    struct timespec rem;
    req.tv_nsec = 0;
    req.tv_sec = seconds;

    while (nanosleep(&req, &rem) == -1) {
        req = rem;
    }

    return 0;
}