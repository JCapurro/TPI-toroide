#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(vistaTrasladadaTEST, muevoTerceraFilaParaArriba){
    toroide t1 = { 
                  {true, false, false}, // 1
                  {false, true, false}, // 2
                  {false, false, true}};// 3
    toroide t2 = { 
                  {false, false, true}, // 3
                  {true, false, false}, // 1
                  {false, true, false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, DiagonalVsTodoTrue){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {true, true, true},
                  {true, true, true},
                  {true, true, true}}; 
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}



/*####Nuestros TEST###*/
TEST(vistaTrasladadaTEST, cruzTrasladadaUnaFilaParaAbajoYunaColumnaHaciaLaDerecha){
    toroide t1 = {
            {false, true, false}, // 1
            {true, true, true}, // 2
            {false, true, false}};// 3
    toroide t2 = {
            {false, false, true}, // 3
            {false, false, true}, // 1
            {true, true, true}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}


/*####Nuestros TEST###*/
TEST(vistaTrasladadaTEST, noEsVistaTrasladadaCruzRespectoAEsquinas){
    toroide t1 = {
            {false, true, false}, // 1
            {true, true, true}, // 2
            {false, true, false}};// 3
    toroide t2 = {
            {true, false, true}, // 3
            {false, false, false}, // 1
            {true, true, true}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

TEST(vistaTrasladadaTEST, vistaTrasladadaEsquinasOpuestasVivas){

    toroide t1 = {{false,false,false,true},
                {false,false,false,false},
                {false,false,false,false},
                {true,false,false,false}};

    toroide t2 = {{false,false,false,true},
                  {false,false,true,false},
                  {false,false,false,false},
                  {false,false,false,false}};



    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}
