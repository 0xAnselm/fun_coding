#include <core.h>

PrepareResult parse_insert(InputBuffer *input_buffer, Statement *statement)
{
    int args_assigned = sscanf(input_buffer->buffer, "insert %d %s %s", &(statement->row_to_insert.id), statement->row_to_insert.username, statement->row_to_insert.email);
    if (args_assigned < 3)
    {
        return PREPARE_SYNTAX_ERROR;
    }
    return PREPARE_SUCCESS;
}