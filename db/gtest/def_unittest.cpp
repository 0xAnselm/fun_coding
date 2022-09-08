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
        EXPECT_EQ(s1, print_row(&r));
    }
    TEST(InputTest, regular)
    {
        std::string s1 = "db >";
        // EXPECT_EQ(s1, run());
    }
}