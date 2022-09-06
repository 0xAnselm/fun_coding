/* https://stackoverflow.com/questions/25274312/is-it-a-good-practice-to-define-c-functions-inside-header-files
1. Compile source code files (*.c) to object files (*.o)
2. Link object files to executable
*/
#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <unistd.h>

#include <structs.h>
#include <enums.h>

// Function prototypes
MetaCommandResult do_meta_command(InputBuffer *input_buffer);                     // Function def in compiler.c
PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement); // Function def in compiler.c
void execute_statement(Statement* statement);                                     // Function def in compiler.c
void read_input(InputBuffer *input_buffer);                                       // Function def in buffer.c
void close_input_buffer(InputBuffer *input_buffer);                               // Function def in buffer.c
InputBuffer *new_input_buffer();                                                  // Function def in buffer.c
void print_prompt();                                                              // Function def in buffer.c

#endif