/* All interface functions and buffering*/

#include <core.h>

InputBuffer *new_input_buffer()
{
    InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

void close_input_buffer(InputBuffer *input_buffer)
{
    free(input_buffer->buffer);
    free(input_buffer);
}

void read_input(InputBuffer *input_buffer)
{
    // getline returns # chars read + delim char
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if (bytes_read <= 0)
    {
        printf("Error reading input. Exiting\n");
        exit(EXIT_FAILURE);
    }
    // Ignore trailing newline char '\n'
    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
    printf("[DEBUG] char: '%s', buffer_length: %d, input_length: %d\n", input_buffer->buffer, input_buffer->buffer_length, input_buffer->input_length);
}

void print_prompt()
{
    printf("db > ");
}