#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(primosLejanosTEST, toroideHorizontalPeriodico2){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {false, false, false, false, false}, 
                  {false, false, true, false, false}, 
                  {false, false, true, false, false},
                  {false, false, true, false, false}, 
                  {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

/*###############Nuestros TEST#####################*/
TEST(primosLejanosTEST,sonPrimos_t2_EsEvolucionDe_t1_DespuesDeUnTick){
    toroide t1 = {{false,false,false,false,false},
                  {false,false,true ,false,false},
                  {false,true ,false, true,false},
                  {false,false,false,false,false}};

    toroide t2 = {{false,false, false, false,false},
                  {false,false, true, false,false},
                  {false,false, true, false,false},
                  {false,false, false, false,false}};

    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}


TEST(primosLejanosTEST,noSonPrimosYAmbosMueren){
    toroide t1 = {{false,false,false,false,false},
                  {false,false,true ,false,false},
                  {false,true ,false, true,false},
                  {false,false,false,false,false}};

    toroide t2 = {{false,false, false, true,false},
                  {false,false, true, false,false},
                  {false,true,false, false,false},
                  {false,false, false, false,false}};

    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST,noSonPrimosUnoMuereYelOtroEsPeriodico){
    toroide t1 = {{false,false,false,false,false,false},
                  {false,false,true ,false,false,false},
                  {false,true ,false, true,false,false},
                  {false,false,false,false,false,false},
                  {false,false,false,false,false,false},
                  {false,false,false,false,false,false}};

    toroide t2 = {{false,false,false,false,false,false},
                  {false,false,false,true ,true ,false},
                  {false,false,false,true ,true ,false},
                  {false,true ,true ,false,false,false},
                  {false,true ,true ,false,false,false},
                  {false,false,false,false,false,false}};

    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST,noSonPrimosYLosDosSonPeriodicos){
    toroide t1 = {{false,false,false,false,false,false,false},
                  {false,false,false,true ,false,false,false},
                  {false,false,false,true,false,false,false},
                  {false,false,false,true,false,false,false},
                  {false,false,false,true,false,false,false},
                  {false,false,false,true ,false,false,false},
                  {false,false,false,false,false,false,false}};

    toroide t2 = {{false,false,false,false,false,false,false},
                  {false,false,false,false,true ,true ,false},
                  {false,false,false,false,true ,true ,false},
                  {false,false,true ,true ,false,false,false},
                  {false,false,true ,true ,false,false,false},
                  {false,false,false,false,false,false,false},
                  {false,false,false,false,false,false,false}};

    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}



TEST(primosLejanosTEST,sonPrimosYestanAmbosMuertos){
    toroide t1 = {{false,false,false,false},
                  {false,false,false,false},
                  {false,false,false,false},
                  {false,false,false,false}};

    toroide t2 ={{false,false,false,false},
                 {false,false,false,false},
                 {false,false,false,false},
                 {false,false,false,false}};

    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST,sonPrimosYAmbosSonIgualesPeriodicosQueSeRepiten){
    toroide t1 = {{false,false,false,false},
                  {false,true,true,false},
                  {false,true,true,false},
                  {false,false,false,false}};

    toroide t2 ={{false,false,false,false},
                 {false,true,true,false},
                 {false,true,true,false},
                 {false,false,false,false}};

    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}


TEST(primosLejanosTEST,noSonPrimosSonIgualesPeroEventualmenteMueren){
    toroide t1 = {{false,false,false,true},
                  {false,false,true,false},
                  {false,true,false,false},
                  {false,false,false,false}};

    toroide t2 = {{false,false,false,true},
                  {false,false,true,false},
                  {false,true,false,false},
                  {false,false,false,false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

