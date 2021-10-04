#include "../llenarTaxis.h"
#include "gtest/gtest.h"

// Escribir tests aca:

/*  Disclaimer:
 -  Se asume en la Pre que g1,g2,g3 >= 0,
    por lo que se ignora casos contrarios.

 -  Para representar un taxi con sus pasajeros,
    se escribe [x_i,...,x_n] con x_i ∈ {1,2,3};
    la suma de los elementos tiene que ser <= 4,
    que es la capacidad máxima del taxi.
*/

/*
    1_NingunTaxi: Si no hay grupos, no hace falta
    llenar ningún taxi.
*/

TEST(TaxisTest, Dominio1_NingunTaxi_Implementacion1)
{
    // setup
    int g1 = 0;
    int g2 = 0;
    int g3 = 0;
    //exercise
    int result = llenarTaxis1(g1, g2, g3);
    // check
    EXPECT_EQ(result, 0);
}

TEST(TaxisTest, Dominio1_NingunTaxi_Implementacion2)
{
    // setup
    int g1 = 0;
    int g2 = 0;
    int g3 = 0;
    //exercise
    int result = llenarTaxis2(g1, g2, g3);
    // check
    EXPECT_EQ(result, 0);
}

TEST(TaxisTest, Dominio1_NingunTaxi_Implementacion3)
{
    // setup
    int g1 = 0;
    int g2 = 0;
    int g3 = 0;
    //exercise
    int result = llenarTaxis3(g1, g2, g3);
    // check
    EXPECT_EQ(result, 0);
}

/*
    1_Uno: con g1 = g2 = g3 = 1, se puede
    llenar mínimamente 2 taxis de esta manera:

    [3,1]
    [2]

*/

TEST(TaxisTest, Dominio1_Uno_Implementacion1)
{
    // setup
    int g1 = 1;
    int g2 = 1;
    int g3 = 1;
    //exercise
    int result = llenarTaxis1(g1, g2, g3);
    // check
    EXPECT_EQ(result, 2);
}

TEST(TaxisTest, Dominio1_Uno_Implementacion2)
{
    // setup
    int g1 = 1;
    int g2 = 1;
    int g3 = 1;
    //exercise
    int result = llenarTaxis2(g1, g2, g3);
    // check
    EXPECT_EQ(result, 2);
}

TEST(TaxisTest, Dominio1_Uno_Implementacion3)
{
    // setup
    int g1 = 1;
    int g2 = 1;
    int g3 = 1;
    //exercise
    int result = llenarTaxis3(g1, g2, g3);
    // check
    EXPECT_EQ(result, 2);
}

/*
    1_Dos: con g1 = g2 = g3 = 2, se puede
    llenar mínimamente 3 taxis de esta manera:

    [3,1]
    [3,1]
    [2,2]

*/

TEST(TaxisTest, Dominio1_Dos_Implementacion1)
{
    // setup
    int g1 = 2;
    int g2 = 2;
    int g3 = 2;
    //exercise
    int result = llenarTaxis1(g1, g2, g3);
    // check
    EXPECT_EQ(result, 3);
}

TEST(TaxisTest, Dominio1_Dos_Implementacion2)
{
    // setup
    int g1 = 2;
    int g2 = 2;
    int g3 = 2;
    //exercise
    int result = llenarTaxis2(g1, g2, g3);
    // check
    EXPECT_EQ(result, 3);
}

TEST(TaxisTest, Dominio1_Dos_Implementacion3)
{
    // setup
    int g1 = 2;
    int g2 = 2;
    int g3 = 2;
    //exercise
    int result = llenarTaxis3(g1, g2, g3);
    // check
    EXPECT_EQ(result, 3);
}

/*
    1_Tres: con g1 = g2 = g3 = 3, se puede
    llenar mínimamente 5 taxis de esta manera:

    [3,1]
    [3,1]
    [3,1]
    [2,2]
    [2]

*/

TEST(TaxisTest, Dominio1_Tres_Implementacion1)
{
    // setup
    int g1 = 3;
    int g2 = 3;
    int g3 = 3;
    //exercise
    int result = llenarTaxis1(g1, g2, g3);
    // check
    EXPECT_EQ(result, 5);
}

TEST(TaxisTest, Dominio1_Tres_Implementacion2)
{
    // setup
    int g1 = 3;
    int g2 = 3;
    int g3 = 3;
    //exercise
    int result = llenarTaxis2(g1, g2, g3);
    // check
    EXPECT_EQ(result, 5);
}

TEST(TaxisTest, Dominio1_Tres_Implementacion3)
{
    // setup
    int g1 = 3;
    int g2 = 3;
    int g3 = 3;
    //exercise
    int result = llenarTaxis3(g1, g2, g3);
    // check
    EXPECT_EQ(result, 5);
}