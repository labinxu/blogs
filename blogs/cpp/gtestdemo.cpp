#include "gtest/gtest.h"
int test(int a, int b)
{
return a + b;
}

TEST(test, AddTest) {
EXPECT_EQ(4, test(2, 2));
}

//int _main(int argc, char **argv) {
//::testing::InitGoogleTest(&argc, argv);
//return RUN_ALL_TESTS();
//}
