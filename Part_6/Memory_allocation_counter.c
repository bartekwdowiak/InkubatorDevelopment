#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static unsigned long long allocated_memory = 0;

void *mem_alloc(size_t size)
{
    size_t *ret_ptr = malloc(sizeof(size_t) + size);

    *ret_ptr = size;
    allocated_memory += size;

    return &ret_ptr[1];
}

void mem_free(void *ptr)
{
    allocated_memory -= ((size_t*)ptr)[-1];
    free ((size_t*)ptr - 1);
}

unsigned long long get_currently_allocated_size()
{
    return allocated_memory;
}

void test_cases()
{
    char * x = (char*)mem_alloc(20);
    int * z = (int*)mem_alloc(50);
    long * y = (long*)mem_alloc(21);

    int received = get_currently_allocated_size();
    assert(received == 91);
    mem_free(z);

    received = get_currently_allocated_size();
    assert(received == 41);
    mem_free(x);

    received = get_currently_allocated_size();
    assert(received == 21);
    mem_free(y);

    received = get_currently_allocated_size();
    assert(received == 0);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}