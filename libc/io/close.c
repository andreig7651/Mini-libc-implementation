/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
    //fac un apel de sistem apoi il verific
	int res = syscall(__NR_close, fd);

    if (res >= 0) {
        return 0;
    }

    //am descoperit ca errno e mereu -res
    errno = -res;
	return -1;
}
