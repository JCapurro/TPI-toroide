#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(esPeriodicoTEST, toroideHorizontalPeriodico2){
    toroide t = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

/*##########Nuestros TEST#######*/
TEST(esPeriodicoTEST, cuadradoDeDosPorDosViveParaSiempre){
    toroide t = {
            {false, false, false, false, false},
            {false, false, true,true, false},
            {false, false, true, true, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p,1);
}



TEST(esPeriodicoTEST,muereDespuesDeUnSoloTick){
    toroide t = {{false,false,false,false,false},
                 {false,false, true,false,false},
                 {false,false, true,false,false},
                 {false,false,false,false,false}};
    int p;
    int p0=p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p,p0);
}



TEST(esPeriodicoTEST,muereDespuesDeDosTicks){
    toroide t = {
            {false, false, false, false, false},
            {false, false, true,false, false},
            {false, true, false,true, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    int p;
    int p0=p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p,p0);
}

