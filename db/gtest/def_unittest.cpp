/*
Definition of unit test. Note this file is cpp, main project is in c.
*/
#include "gtest/gtest.h"
extern "C"
{
#include "../core.h"
}
namespace
{
    TEST(RowTest, regular)
    {
        // This test is named "regular", and belongs to the "SelectTest"
        // test case.
        std::string s1 = "(0, abc, c@d.e)";
        Row r{0, "abc", "c@d.e"};
        char *buffer = (char *)malloc(sizeof(char) * 1024);
        
        EXPECT_EQ(s1, print_row(&r, buffer));
        free(buffer);
    }
    TEST(InputTest, UnrecognizedCommand)
    {
        InputBuffer *input_buffer = new_input_buffer();
        Table *table = new_table();
        char *buffer = (char *)malloc(sizeof(char) * 1024);
        
        std::string s1 = "Unrecognized command 'ab'\n";
        input_buffer->buffer = strdup("ab");
        std::string i1 = meta_command(input_buffer, table, buffer);
        EXPECT_EQ(s1, i1);
        input_buffer->buffer = NULL;

        std::string s2 = "Unrecognized command '.'\n";
        input_buffer->buffer = strdup(".");
        std::string i2 = meta_command(input_buffer, table, buffer);
        EXPECT_EQ(s2, i2);
        
        std::string s3 = "Hello World - A friendly greeting\n";
        input_buffer->buffer = strdup(".hello");
        std::string i3 = meta_command(input_buffer, table, buffer);
        EXPECT_EQ(s3, i3);
        input_buffer->buffer = NULL;


        free(buffer);
        close_input_buffer(input_buffer);
    }
}