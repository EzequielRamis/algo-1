#include "../puntaje.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(PuntajeTest, MenorADiezYMultiploDeTres)
{
    // setup
    int n = 9;
    //exercise
    int result = puntaje(n);
    // check
    EXPECT_EQ(result, 28);
}

TEST(PuntajeTest, MayorIgualADiezYNoMultiploDeTres)
{
    // setup
    int n = 11;
    //exercise
    int result = puntaje(n);
    // check
    EXPECT_EQ(result, 1);
}