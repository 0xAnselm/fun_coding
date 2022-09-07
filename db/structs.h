#ifndef STRUCTS_H
#define STRUCTS_H

#include <enums.h>

typedef struct
{
    char *buffer;
    size_t buffer_length; // return size in bytes
    ssize_t input_length; // return size in bytes or error val
} InputBuffer;

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
typedef struct
{
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
} Row;

typedef struct
{
    StatementType type;
    Row row_to_insert;
} Statement;

#define TABLE_MAX_PAGES 100
typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
} Table;

#endif