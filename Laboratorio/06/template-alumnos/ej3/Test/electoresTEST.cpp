#include "../electores.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(EleccionesTest, FechaInvalida1)
{
    // setup
    int dia = 15;
    int mes = 11;
    int ano = 2021;
    //exercise
    int result = validarVotante(ano, mes, dia);
    // check
    EXPECT_EQ(result, ERROR);
}

TEST(EleccionesTest, FechaInvalida2)
{
    // setup
    int dia = 15;
    int mes = 11;
    int ano = 1810;
    //exercise
    int result = validarVotante(ano, mes, dia);
    // check
    EXPECT_EQ(result, ERROR);
}

TEST(EleccionesTest, FechaInvalida3)
{
    // setup
    int dia = 15;
    int mes = 15;
    int ano = 2021;
    //exercise
    int result = validarVotante(ano, mes, dia);
    // check
    EXPECT_EQ(result, ERROR);
}

TEST(EleccionesTest, FechaInvalida4)
{
    // setup
    int dia = 34;
    int mes = 7;
    int ano = 2021;
    //exercise
    int result = validarVotante(ano, mes, dia);
    // check
    EXPECT_EQ(result, ERROR);
}

TEST(EleccionesTest, FechaInvalida5)
{
    // setup
    int dia = 31;
    int mes = 4;
    int ano = 2021;
    //exercise
    int result = validarVotante(ano, mes, dia);
    // check
    EXPECT_EQ(result, ERROR);
}

TEST(EleccionesTest, FechaInvalida6)
{
    // setup
    int dia = 29;
    int mes = 2;
    int ano = 2019;
    //exercise
    int result = validarVotante(ano, mes, dia);
    // check
    EXPECT_EQ(result, ERROR);
}

TEST(EleccionesTest, NoVotante)
{
    // setup
    int dia = 13;
    int mes = 2;
    int ano = 2007;
    //exercise
    int result = validarVotante(ano, mes, dia);
    // check
    EXPECT_EQ(result, NO_VOTA);
}

TEST(EleccionesTest, VotanteOpcionalMenor)
{
    // setup
    int dia = 13;
    int mes = 12;
    int ano = 2004;
    //exercise
    int result = validarVotante(ano, mes, dia);
    // check
    EXPECT_EQ(result, OPCIONAL_MENOR);
}

TEST(EleccionesTest, VotanteOpcionalMayor)
{
    // setup
    int dia = 5;
    int mes = 3;
    int ano = 1930;
    //exercise
    int result = validarVotante(ano, mes, dia);
    // check
    EXPECT_EQ(result, OPCIONAL_MAYOR);
}

TEST(EleccionesTest, Votante)
{
    // setup
    int dia = 14;
    int mes = 11;
    int ano = 1980;
    //exercise
    int result = validarVotante(ano, mes, dia);
    // check
    EXPECT_EQ(result, OBLIGATORIO);
}