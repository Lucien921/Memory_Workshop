/*
** EPITECH PROJECT, 2023
** Memory Workshop
** File description:
** memory
*/

#include "../includes/malloc.h"

metadata_t *insert_metadata_to_ll(metadata_t *current_block, metadata_t *block_metadata)
{
    while (current_block->next != NULL) {
        current_block = current_block->next;
    }
    current_block->next = block_metadata;
    return current_block;
}

void *my_malloc(size_t size)
{
    metadata_t *current_block = sbrk(0);
    void *allocated_block = sbrk(size);
    metadata_t *block_metadata = (metadata_t *)allocated_block;

    block_metadata->size = size;
    block_metadata->next = NULL;
    block_metadata->is_free = 0;
    if (block_metadata == (void *)-1) {
        printf("Segmentation fault.\n");
        return NULL;
    }
    if (current_block != NULL) {
        insert_metadata_to_ll(current_block, block_metadata);
    } else
        current_block = block_metadata;
    return (void *)(block_metadata + 1);
}

int main(int argc, char *argv[])
{
    size_t size = (size_t)strtof(argv[1], NULL);
    void *alloc_mem = my_malloc(size);
    if (alloc_mem != NULL) {
        printf("Memory allocated at address: %p.\n", alloc_mem);
    }
    return 0;
}
