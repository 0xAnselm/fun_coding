/* https://stackoverflow.com/questions/25274312/is-it-a-good-practice-to-define-c-functions-inside-header-files
1. Compile source code files (*.c) to object files (*.o)
2. Link object files to executable
*/
#ifndef CORE_H
#define CORE_H

/* Def s.t. Project contains only 1 main. GTest also requires a main and that confuses the compilation */
#define TESTING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <unistd.h>
#include <stdint.h>

#include "structs.h"
#include "enums.h"

// Function prototypes
int run(int argc, char *argv[]);                                                  // Function def in core.c
char *meta_command(InputBuffer *input_buffer, Table *table, char *buffer);        // Function def in compiler.c
MetaCommandResult do_meta_command(InputBuffer *input_buffer, Table *table);       // Function def in compiler.c
PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement); // Function def in compiler.c
PrepareResult parse_insert(InputBuffer *input_buffer, Statement *statement);      // Function def in parse.c
ExecuteResult execute_statement(Statement *statement, Table *table);              // Function def in compiler.c
ExecuteResult execute_insert(Statement *statement, Table *table);                 // Function def in compiler.c
ExecuteResult execute_select(Statement *statement, Table *table);                 // Function def in compiler.c
void read_input(InputBuffer *input_buffer);                                       // Function def in buffer.c
void close_input_buffer(InputBuffer *input_buffer);                               // Function def in buffer.c
InputBuffer *new_input_buffer();                                                  // Function def in buffer.c
void print_prompt();                                                              // Function def in buffer.c
Table *new_table();                                                               // Function def in table.c
void free_table(Table *table);                                                    // Function def in table.c
void serialize_row(Row *source, void *destination);                               // Function def in table.c
void deserialize_row(void *source, Row *destination);                             // Function def in table.c
void *row_slot(Table *table, uint32_t row_num);                                   // Function def in table.c
char *print_row(Row *row, char *buffer);                                          // Function def in table.c

#define size_of_attribute(Struct, Attribute) sizeof(((Struct *)0)->Attribute)
// Declaration here, Definition in table.c
extern const uint32_t ID_SIZE,
    USERNAME_SIZE, EMAIL_SIZE, ID_OFFSET, USERNAME_OFFSET, EMAIL_OFFSET, ROW_SIZE;

// Declaration here, Definition in table.c
extern const uint32_t PAGE_SIZE, ROWS_PER_PAGE, TABLE_MAX_ROWS;

#endif