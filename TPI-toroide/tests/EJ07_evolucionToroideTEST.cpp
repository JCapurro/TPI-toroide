#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionToroideTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false}, {false, true, false}, {false, false, true} };
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {true, true, true}, {true, true, true}, {true, true, true} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

/*####Nuestros TEST####*/
TEST(evolucionToroideTEST, toroideOcilador){//ocilador:las tres celdas vivas rotan en sentido horario,
    toroide t = { {false,false, false, false,false},
                  {false,false, false, false,false},
                  {false,true, true,true,false},
                  {false,false, false,false,false},
                  {false,false, false, false,false}};

    toroide evo_t = {{false,false, false, false,false},
                     {false,false, true, false,false},
                     {false,false, true,false,false},
                     {false,false, true,false,false},
                     {false,false, false, false,false}};

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroideMuere){
    toroide t ={{true,false,false},
                {false,false,true},
                {false,false,false}};

    toroide tEvo = {{false, false,false},
                    {false,false,false},
                    {false,false,false}};

    evolucionToroide(t);
    EXPECT_EQ(t,tEvo);
}

TEST(evolucionToroideTEST, sobrepoblacion){
    toroide t ={{false,true,false},
                {true,true,false},
                {false,true,true}};
    toroide tEvo = {{false,false,false},
                    {false,false,false},
                    {false,false,false}};

    evolucionToroide(t);
    EXPECT_EQ(t,tEvo);
}

