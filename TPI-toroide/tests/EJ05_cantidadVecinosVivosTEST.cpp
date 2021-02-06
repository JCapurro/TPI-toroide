#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(cantidadVecinosVivosTEST, seisVivos){
    toroide t = {
            {true, false, false, false},
            {false, false, true, true},
            {false, false, false, false},
            {true, false, true, true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 3), 6);
}

/*############Nuestros TEST######################*/

TEST(cantidadVecinosVivosTEST,todosVivosDespuesDeUnTick){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true} };
                        //1*0 0 1*0
                        //0 1 0 0 1
                        //0 0 1 0 0
                        //1 0 0 1 0
                        //0*1 0 0*1
    EXPECT_EQ(cantidadVecinosVivos(t, 0, 0), 2);
    EXPECT_EQ(cantidadVecinosVivos(t, 0, 1), 3);
    EXPECT_EQ(cantidadVecinosVivos(t, 0, 2), 3);
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 0), 3);
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 1), 2);
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 2), 3);
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 0), 3);
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 1), 3);
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 2), 2);
}

TEST(cantidadVecinosVivosTEST,toroideMuertoCuatroPorCuatro){//menos de 2 vecinos o +3 vecinos
    toroide t = { {false, false, false},
                  {false, false, false},
                  {false,false, false},
                  {false,false, false}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 0), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 0, 1), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 0, 2), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 0), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 1), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 2), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 0), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 1), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 2), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 3, 0), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 3, 1), 0);
    EXPECT_EQ(cantidadVecinosVivos(t, 3, 2), 0);
}

TEST(cantidadVecinosVivosTEST,toroideTodoVivoCuatroPorCuatro){//menos de 2 vecinos o +3 vecinos
    toroide t = { {true, true, true},
                  {true, true, true},
                  {true, true, true},
                  {true, true, true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 0), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 0, 1), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 0, 2), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 0), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 1), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 1, 2), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 0), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 1), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 2), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 3, 0), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 3, 1), 8);
    EXPECT_EQ(cantidadVecinosVivos(t, 3, 2), 8);
}
