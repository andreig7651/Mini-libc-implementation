/* SPDX-License-Identifier: BSD-3-Clause */

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	for (; *source != '\0'; source++, destination++) {
		*destination = *source;
	}

	*destination = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t src_len = strlen(source);
	int found = 0;
	for (size_t i = 0; i < len; source++, destination++, i++) {
		*destination = *source;
		if (*source == '\0') {
			found = 1;
		}
	}

	if (len >= src_len) {
		*destination = '\0';
	} else if (len < src_len && found == 1) {
		*destination = '\0';
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int len = strlen(destination);

	for (; *source != '\0'; source++, len++) {
		*(destination + len) = *source;
	}

	*(destination + len) = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int dest_len = strlen(destination);

	for (size_t i = 0; i < len; source++, dest_len++, i++) {
		*(destination + dest_len) = *source;
	}

	*(destination + dest_len) = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	if (strlen(str1) > strlen(str2)) {
		return 1;
	}

	if (strlen(str1) < strlen(str2)) {
		return -1;
	}

	for (; (*str1 != '\0') & (*str2 != '\0'); str1++, str2++) {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		}
	}

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	for (size_t i = 0; i < len; str1++, str2++, i++) {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		}
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	for (; *str != '\0'; str++) {
		if (*str == c) {
			return (char *)str;
		}
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int len = strlen(str) - 1;
	for (; *(str + len) != '\0'; len--) {
		if (*(str + len) == c) {
			return (char *)(str + len);
		}
	}

	return NULL;
}

char *strstr(const char *str1, const char *str2)
{
	/* TODO: Implement strstr(). */
	for (; *str1 != '\0'; str1++) {
		if (*str1 == *str2) {
			char *copy1 = (char *)str1;
			char *res = (char *)str1;
			char *copy2 = (char *)str2;
			for (; *copy2 != '\0'; copy2++, copy1++) {
				if (*copy2 != *copy1) {
					break;
				}
			}

			if (*copy2 == '\0') {
				return res;
			}
		}
	}
	return NULL;
}

char *strrstr(const char *str1, const char *str2)
{
	/* TODO: Implement strrstr(). */
	int len = strlen(str1) - 1;
	for (; len >= 0; len--) {
		if (*(str1 + len) == *str2) {
			char *copy1 = (char *)(str1 + len);
			char *res = (char *)(str1 + len);
			char *copy2 = (char *)str2;
			for (; *copy2 != '\0'; copy2++, copy1++) {
				if (*copy2 != *copy1) {
					break;
				}
			}

			if (*copy2 == '\0') {
				return res;
			}
		}
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	char *src = (char *)source;
	char *dest = (char *)destination;

	for (size_t i = 0; i < num; i++) {
		dest[i] = src[i];
	}

	destination = dest;

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
	char *src = (char *)source;

	if (dest <= src) {
		for (size_t i = 0; i < num; i++) {
			*(dest + i) = *(src + i);
		}
	} else {
		for (int i = num; i > 0; i--) {
			*(dest + (i - 1)) = *(src + (i - 1));
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *str1 = (char *)ptr1;
	char *str2 = (char *)ptr2;
	int ok = 0;

	for (size_t i = 0; i < num; i++) {
		if ((*str1 + i) > (*str2 + i)) {
			return 1;
		}

		if ((*str1 + i) < (*str2 + i)) {
			ok = 1;
		}

		if ((*str1 + i) == (*str2 + i)) {
			continue;
		}
	}

	if (ok == 0) {
		return 0;
	}

	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *)source;
	for (size_t i = 0; i < num; i++) {
		*(src + i) = value;
	}

	return source;
}