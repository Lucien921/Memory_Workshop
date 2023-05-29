/*
** EPITECH PROJECT, 2023
** Memory_Workshop
** File description:
** malloc
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MALLOC_H_
    #define MALLOC_H_

typedef struct metadata {
    void *adress;
    size_t size;
    struct metadata* next;
    int is_free;
} metadata_t;

#endif /* !MALLOC_H_ */
