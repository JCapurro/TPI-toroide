#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(evolucionDePosicionTEST, toroideDiagonalTresPorTres){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}

TEST(evolucionDePosicionTEST, NoRevivePorCincoVecinosVivos){
    toroide t = { {false, true, true}, {false, true, false}, {false, true, true}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,0)));
}


/*###Nuestro TEST####*/

TEST(evolucionDePosicionTEST, viveGraciasADosVecinos){
    toroide t = { {true, true, true}, {false, false, false}, {false, false, false}};
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(0,1)));
}


TEST(evolucionDePosicionTEST, SigueVivaGraciasATresVecinos){
    toroide t = { {true, true, true}, {false, true, false}, {false, false, false}};
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(0,1)));
}

TEST(evolucionDePosicionTEST, estabaMuertaYReviveGraciasATresVecinos){
    toroide t = { {true, true, true}, {false, false, false}, {false, false, false}};
    EXPECT_TRUE(evolucionDePosicion(t, make_pair(1,1)));
}


TEST(evolucionDePosicionTEST, muereDeSoledad){
    toroide t = { {false, false, false}, {false, true, false}, {false, false, false}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,1)));
}


TEST(evolucionDePosicionTEST, muerenLasDosSolitas){//porque ambas tiene un solo vecino
    toroide t = { {false, false, false}, {true, true, false}, {false, false, false}};
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,0)));
    EXPECT_FALSE(evolucionDePosicion(t, make_pair(1,1)));
}


