/* Core Functions, i.e. main*/
#include <core.h>

int main(int argc, char *argv[])
{
    puts("Welcome to superMongoDB");

    // new input buffer for repl
    InputBuffer *input_buffer = new_input_buffer();
    printf("Buffer size. %d\n", input_buffer->buffer_length);
    while (true)
    {
        print_prompt();
        read_input(input_buffer);
        if (input_buffer->buffer[0] == '.')
        {
            switch (do_meta_command(input_buffer))
            {
            case (META_COMMAND_SUCCESS):
                continue;
            case (META_COMMAND_UNRECOGNIZED_COMMAND):
                printf("Unrecognized command '%s'\n", input_buffer->buffer);
                continue;
            }
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
            case (PREPARE_SUCCESS):
                break;
            case (PREPARE_UNRECOGNIZRED_STATEMENT):
                printf("Unrecognized keyword at start of '%s'\n", input_buffer->buffer);
                continue;
        }

        execute_statement(&statement);
        puts("Executed");
    }
}
