#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

typedef struct
{
    char *buffer;
    size_t buffer_length; // return size in bytes
    ssize_t input_length; // return size in bytes or error val
} InputBuffer;

typedef enum
{
    META_COMMAND_SUCCESS,
    META_COMMAND_FAILURE,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum
{
    PREPARE_SUCCESS,
    PREPARE_FAILURE,
    PREPARE_UNRECOGNIZRED_STATEMENT
} PrepareResult;

#endif