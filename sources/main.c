/*
** EPITECH PROJECT, 2023
** Memory Workshop
** File description:
** memory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *my_malloc(size_t size)
{
    const void *heap_start = sbrk(0);
    static size_t heap_size = 0;
    void *allocated_block = sbrk(size);

    if (allocated_block == (void *)-1) {
        printf("Segmentation fault.\n");
        return NULL;
    }

    heap_size += size;
    return allocated_block;
}

int main(int argc, char *argv[])
{
    size_t size = (size_t)strtof(argv[1], NULL);
    void *alloc_mem = my_malloc(size);
    if (alloc_mem != NULL)
        printf("memory allowed in adress: %p.\n", alloc_mem);
    return 0;
}
