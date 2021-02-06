#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}
/*##############Nuestros TEST ###*/
TEST(densidadPoblacionTEST, toroideMuertoAreaVivaCero){
    toroide t = {
            {false,false,false},
            {false,false,false},
            {false,false,false}};

    EXPECT_NEAR(densidadPoblacion(t), 0, 0.01);
}


TEST(densidadPoblacionTEST, toroideTodoVIvo){
    toroide t = {
            {true,true,true},
            {true,true,true},
            {true,true,true}};

    EXPECT_NEAR(densidadPoblacion(t), 1, 0.01);
}

TEST(densidadPoblacionTEST, toroide3Vivos){
    toroide t = {{true,false,false},
                 {false,true,false},
                 {false,false,true}};

    EXPECT_NEAR(densidadPoblacion(t), 0.33,0.01);
}


TEST(densidadPoblacionTEST, unoSoloVivo){
    toroide t = {{false,false,false,false},
                 {false,false,false,false},
                 {false,false,true,false},
                 {false,false,false,false}};

    EXPECT_NEAR(densidadPoblacion(t), 0.062,0.001);
}
