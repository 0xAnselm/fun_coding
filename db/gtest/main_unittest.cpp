#include <iostream>
#include "gtest/gtest.h"
extern "C"
{
#include "../core.h"
}

#ifdef TESTING
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "RUNNING TESTS ..." << std::endl;
    RUN_ALL_TESTS();
    return 0;
}
#endif