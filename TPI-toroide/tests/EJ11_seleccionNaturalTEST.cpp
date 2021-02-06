#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;


TEST(seleccionNaturalTEST, toroideDiagonalVsUnoVivo){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, false, false}, 
                  {false, false, false}, 
                  {false, true, false},
                  {false, false, false}, 
                  {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

/*Por intruccion de la catedra este TEST fue comentado,no cumple con la Precondicion*/
/*TEST(seleccionNaturalTEST, DiagonalVsHorizontal){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}*/

/*########TEST NUESTROS############*/

TEST(seleccionNaturalTEST,t1ViveMasQuet2) {
   toroide t1 = {{false,false,false,false,false},
                {false,false,true ,false,false},
                {false,true ,false, true,false},
                {false,false,false,false,false}};

   toroide t2 = {{false,false,false,false,false},
                 {false,false,true,false,false},
                 {false,false,true,false,false},
                 {false,false,false,false,false}};

    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}


TEST(seleccionNaturalTEST,t1Yt2MuerenAlMismoTiempo) {
//t1 muere en 2 ticks
    toroide t1 = {{false,false,false,false,false},
                  {false,false,true ,false,false},
                  {false,true ,false, true,false},
                  {false,false,false,false,false}};
//t2 muere en 2 ticks
    toroide t2 = {{false,false,false,true,false},
                  {false,false,true,false,false},
                  {false,true,false,false,false},
                  {false,false,false,false,false}};

    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);//el indice del mas longevo tiene que dejar a la izquierda(en ts) a los que mueren antes stricto
                           // y a la derecha a los que mueren en tiempos iguales o menores.
}


TEST(seleccionNaturalTEST,t3MuereEnUnTickYt1Yt2MuerenEnDosTicks) {
    //Muere en 2 ticks
    toroide t1 = {{false,false,false,false,false},
                  {false,false,true ,false,false},
                  {false,true ,false, true,false},
                  {false,false,false,false,false}};
    //Muere en 2 ticks
    toroide t2 = {{false,false,false,true,false},
                  {false,false,true,false,false},
                  {false,true,false,false,false},
                  {false,false,false,false,false}};
    //Muere en 1 tick
    toroide t3 = {{false, false, false},
                  {false, false, false},
                  {false, true, false},
                  {false, false, false},
                  {false, false, false}};
    vector<toroide> ts;
    ts.push_back(t3);
    ts.push_back(t3);
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);

    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 2);//el indice del mas longevo tiene que dejar a la izquierda(en ts) a los que mueren antes
                           // estricto y a la derecha(en ts) a los que mueren en tiempos iguales o menores.
}