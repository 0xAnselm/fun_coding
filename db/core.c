/* Core Functions, i.e. main*/
#include <core.h>

int main(int argc, char *argv[])
{
    puts("Welcome to superMongoDB");
    Table* table = new_table();
    // new input buffer for repl
    InputBuffer *input_buffer = new_input_buffer();
    printf("Buffer size. %d\n", input_buffer->buffer_length);
    while (true)
    {
        print_prompt();
        read_input(input_buffer);
        if (input_buffer->buffer[0] == '.')
        {
            // Starts with '.'? -> meta_command -> switch base on do_meta_command
            meta_command(input_buffer, table);
            continue;
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
            case (PREPARE_SUCCESS):
                break;
            case (PREPARE_SYNTAX_ERROR):
                printf("Syntax error. Could not parse statement\n");
                continue;
            case (PREPARE_UNRECOGNIZRED_STATEMENT):
                printf("Unrecognized keyword at start of '%s'\n", input_buffer->buffer);
                continue;
        }

        switch (execute_statement(&statement, table)) {
            case (EXECUTE_SUCCESS):
                printf("Executed\n");
                break;
            case (EXECUTE_TABLE_FULL):
                printf("Error: Table full\n");
                break;
        } 
    }
}
