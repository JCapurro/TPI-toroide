#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionMultipleTEST, toroideDiagonalTresPorTresUnPaso){
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
    toroide res = evolucionMultiple(t, 1);
    EXPECT_EQ(res, evo_t);
}

/*####Nuestros TEST####*/
TEST(evolucionMultipleTEST, toroideOciladorDespuesDeUnTick){/*las tres posciones vivas rotan en cada tick en sentido horario infinitamente*/
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
    toroide res = evolucionMultiple(t, 1);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroideOciladorDespuesDeDosTicks){/*las tres posciones vivas rotan en cada tick en sentido horario infinitamente*/
    toroide t = { {false,false, false, false,false},
                  {false,false, false, false,false},
                  {false,true, true,true,false},
                  {false,false, false,false,false},
                  {false,false, false, false,false}};

    toroide evo_t = {{false,false, false, false,false},
                     {false,false, false, false,false},
                     {false,true, true,true,false},
                     {false,false, false,false,false},
                     {false,false, false, false,false}};
    toroide res = evolucionMultiple(t, 2);
    EXPECT_EQ(res, evo_t);
}

TEST(evolucionMultipleTEST, toroideMuere){
    toroide t ={{true,false,false},
                {false,false,true},
                {false,false,false}};

    toroide tEvo = {{false, false,false},
                    {false,false,false},
                    {false,false,false}};

    toroide res= evolucionMultiple(t,1);
    EXPECT_EQ(res,tEvo);
}

TEST(evolucionMultipleTEST, sobrepoblacion){
    toroide t ={{false,true,false},
                {true,true,false},
                {false,true,true}};
    toroide tEvo = {{false,false,false},
                    {false,false,false},
                    {false,false,false}};

    toroide res= evolucionMultiple(t,1);
    EXPECT_EQ(res,tEvo);
}



