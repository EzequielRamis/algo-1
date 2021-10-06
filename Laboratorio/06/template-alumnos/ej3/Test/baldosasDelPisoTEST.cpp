#include "../baldosasDelPiso.h"
#include "gtest/gtest.h"

// Escribir tests aca:

// ..|..|..
// ..|..|..
// --------
// ..|..|..
// ..|..|..
TEST(BaldosasTest, BDivideAMYN)
{
    // setup
    int M = 4;
    int N = 6;
    int B = 2;
    //exercise
    int result = baldosasDelPiso(M, N, B);
    // check
    EXPECT_EQ(result, 6);
}

// ..|..|.
// ..|..|.
// --------
// ..|..|.
// ..|..|.
TEST(BaldosasTest, BDivideAM)
{
    // setup
    int M = 4;
    int N = 5;
    int B = 2;
    //exercise
    int result = baldosasDelPiso(M, N, B);
    // check
    EXPECT_EQ(result, 5);
}

// ..|..|..
// ..|..|..
// --------
// ..|..|..
TEST(BaldosasTest, BDivideAN)
{
    // setup
    int M = 3;
    int N = 6;
    int B = 2;
    //exercise
    int result = baldosasDelPiso(M, N, B);
    // check
    EXPECT_EQ(result, 5);
}

// ..|..|.
// ..|..|.
// --------
// ..|..|.
TEST(BaldosasTest, BNoDivide)
{
    // setup
    int M = 3;
    int N = 5;
    int B = 2;
    //exercise
    int result = baldosasDelPiso(M, N, B);
    // check
    EXPECT_EQ(result, 4);
}