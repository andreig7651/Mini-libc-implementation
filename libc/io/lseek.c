/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	if(fd < 0 || whence < 0 || offset < 0) {
		int res = syscall(__NR_lseek, fd, offset, whence);
		errno = -res;
		return -1;
	}
	
	int res = syscall(__NR_lseek, fd, offset, whence);
	return res;
}
