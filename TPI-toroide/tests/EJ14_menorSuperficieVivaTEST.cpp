#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true, false, false, true},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, true, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}


/*###########Nuestros TEST################*/
TEST(menorSuperficieVivaTEST, unaSolaConVida){
    toroide t = {
            {false, false, false, false},   // 1
            {false, false, false, false}, // 2
            {false, true, false, false}, // 3
            {false, false, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 1);
}

TEST(menorSuperficieVivaTEST, lineaHorizontalViva){
    toroide t = {
            {false,false, false ,false,false},   // 1
            {false,false ,false ,false,false}, // 2
            {false,true  ,true  ,true ,false}, // 3
            {false,false ,false  ,false,false},  // 4
            {false,false ,false ,false,false}}; // 5
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 3);
}

TEST(menorSuperficieVivaTEST, lineaVerticalViva){
    toroide t = {
            {false,false, false ,false,false},   // 1
            {false,false ,true ,false,false}, // 2
            {false,false  ,true  ,false ,false}, // 3
            {false,false ,true ,false,false},  // 4
            {false,false ,false ,false,false}}; // 5
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 3);
}

TEST(menorSuperficieVivaTEST, cruzCentralViva){
    toroide t = {
            {false,false, false ,false,false},   // 1
            {false,false ,true  ,false,false}, // 2
            {false,true  ,true  ,true ,false}, // 3
            {false,false ,true  ,false,false},  // 4
            {false,false ,false ,false,false}}; // 5
     int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 9);
}


TEST(menorSuperficieVivaTEST, bordesVivos){
    toroide t = {
            {true ,true ,true ,true ,true},   // 1
            {true ,false,false,false,true}, // 2
            {true ,false,false,false ,true}, // 3
            {true ,false,false,false,true},  // 4
            {true ,true ,true ,true ,true}};  //5
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 25);
}

TEST(menorSuperficieVivaTEST, rectanguloVivoCentro){
    toroide t = {
            {false,false, false ,false,false},   // 1
            {false,true ,true  ,true,false}, // 2
            {false,true  ,true  ,true ,false}, // 3
            {false,true ,true  ,true,false},  // 4
            {false,false ,false ,false,false}}; // 5
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 9);
}

TEST(menorSuperficieVivaTEST, todasVivas){
    toroide t = {
            {true,true, true,true,true},   // 1
            {true,true ,true  ,true,true}, // 2
            {true,true  ,true  ,true ,true}, // 3
            {true,true ,true  ,true,true},  // 4
            {true,true ,true ,true,true}}; // 5
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 25);
}


TEST(menorSuperficieVivaTEST,unaDeLasVistasTrasladadasTieneMenorSuperficie){
    toroide t = {{true,true,false,false},
                 {false,false,false,false},
                 {true,false,false,false},
                 {true,true,false,false}};

    /*vista trasladada de menor superficie:
     *           {false,false,false,false},
                 {true,false,false,false},
                 {true,true,false,false},
                 {true,true,false,false}};
    */
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}



TEST(menorSuperficieVivaTEST,esquinasOpuestaVivas){
    toroide t = {{false,false,false,true},
                 {false,false,false,false},
                 {false,false,false,false},
                 {true,false,false,false}};

    /*una de las vistas trasladada de menor superficie:
     *           {false,false,false,false},
                 {false,false,false,false},
                 {false,true,false,false},
                 {true,false,false,false}};
    */
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}


TEST(menorSuperficieVivaTEST,RectanguloMinimoConTodasLasEsquinasVivas){
    toroide t = {{true,false,false,true},
                 {false,false,false,false},
                 {false,false,false,false},
                 {true ,false,false,true},
                 {false,false,false,false}};
    /* Vista trasladada de area minima: 1 hacia la izquierda y 2 hacia abajo
     *           {{true,true ,false,false},
                 {false,false,false,false},
                 {true ,true ,false,false},
                 {false,false,false,false},
                 {false,false,false,false}};*/
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

TEST(menorSuperficieVivaTEST,todasLasEsquinasVivas){
    toroide t = {{false ,false,false,false,false},
                 {false,true ,false,true ,false},
                 {false,false,false,false,false},
                 {false,true ,false,true ,false},
                 {false,false,false,false,false }};

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res,9);
}


