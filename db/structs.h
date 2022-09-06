#ifndef STRUCTS_H
#define STRUCTS_H

#include <enums.h>

typedef struct
{
    char *buffer;
    size_t buffer_length; // return size in bytes
    ssize_t input_length; // return size in bytes or error val
} InputBuffer;

typedef struct
{
    StatementType type;
} Statement;

#endif