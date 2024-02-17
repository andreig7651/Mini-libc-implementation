// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (addr == MAP_FAILED) {
		return NULL;
	}

	if (mem_list_add(addr, size) == 0) {
		return addr;
	}

	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	// TODO: Implement calloc().
	size_t new_size = nmemb * size;
	void *addr = mmap(NULL, new_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (addr == MAP_FAILED) {
		return NULL;
	}

	if (mem_list_add(addr, new_size) == 0) {
		memset(addr, 0, new_size);
		return addr;
	}

	return NULL;
}

void free(void *ptr)
{
	// TODO: Implement free().
	struct mem_list *elem = mem_list_find(ptr);
	if (&mem_list_head != elem) {
		munmap(ptr, elem->len);
		mem_list_del(ptr);
	} else {
		struct mem_list aux = mem_list_head;
		mem_list_head = *aux.next;
		munmap(ptr, elem->len);
		mem_list_del(ptr);
	}
	return;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list *elem = mem_list_find(ptr);
	void *addr = mremap(ptr, elem->len, size, MREMAP_MAYMOVE);

	if (addr == MAP_FAILED) {
		return NULL;
	}

	if (mem_list_add(addr, size) == 0) {
		return addr;
	}

	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t new_size = nmemb * size;
	struct mem_list *elem = mem_list_find(ptr);
	void *addr = mremap(ptr, elem->len, new_size, MREMAP_MAYMOVE);

	if (addr == MAP_FAILED) {
		return NULL;
	}

	if (mem_list_add(addr, new_size) == 0) {
		return addr;
	}

	return NULL;
}