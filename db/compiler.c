#include <core.h>

char *meta_command(InputBuffer *input_buffer, Table *table, char *buffer)
{
    switch (do_meta_command(input_buffer, table))
    {
    case (META_COMMAND_SUCCESS):
        return buffer;
    case (META_COMMAND_UNRECOGNIZED_COMMAND):
        snprintf(buffer, sizeof(buffer) * 1024, "Unrecognized command '%s'\n", input_buffer->buffer);
        puts(buffer);
        return buffer;
    }
}

MetaCommandResult do_meta_command(InputBuffer *input_buffer, Table *table)
{
    if (strcmp(input_buffer->buffer, ".exit") == 0)
    {
        close_input_buffer(input_buffer);
        free_table(table);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(input_buffer->buffer, ".clear") == 0)
    {
        printf("\e[1;1H\e[2J");
        return META_COMMAND_SUCCESS;
    }
    else if (strcmp(input_buffer->buffer, ".hello") == 0)
    {
        puts("Hello World - A friendly greeting");
        return META_COMMAND_SUCCESS;
    }
    else
    {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement)
{
    if (strncmp(input_buffer->buffer, "insert", 6) == 0)
    {
        statement->type = STATEMENT_INSERT;
        return parse_insert(input_buffer, statement);
    }
    if (strcmp(input_buffer->buffer, "select") == 0)
    {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZRED_STATEMENT;
}

ExecuteResult execute_statement(Statement *statement, Table *table)
{
    switch (statement->type)
    {
    case (STATEMENT_INSERT):
        return execute_insert(statement, table);
    case (STATEMENT_SELECT):
        return execute_select(statement, table);
    }
}

ExecuteResult execute_insert(Statement *statement, Table *table)
{
    if (table->num_rows >= TABLE_MAX_ROWS)
    {
        return EXECUTE_TABLE_FULL;
    }

    Row *row_to_insert = &(statement->row_to_insert);

    serialize_row(row_to_insert, row_slot(table, table->num_rows));
    table->num_rows += 1;

    return EXECUTE_SUCCESS;
}
ExecuteResult execute_select(Statement *statement, Table *table)
{
    Row row;
    for (uint32_t i = 0; i < table->num_rows; ++i)
    {
        deserialize_row(row_slot(table, i), &row);
        char *buffer = (char *)malloc(sizeof(char) * 1024);
        print_row(&row, buffer);
        free(buffer);
    }

    return EXECUTE_SUCCESS;
}