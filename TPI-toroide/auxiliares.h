//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
float superficieTotal(toroide t);
float cantidadVivas(toroide t);
bool debeVivir(toroide t, int f, int c);
int cantidadAMorir(toroide t);
bool enRangoToroide(int f, int c, toroide t);
toroide interseccionVivas(toroide t1,toroide t2);
bool esRectangulo(toroide r,int ncol,int nfil);
int modulo(int a,int b);
bool vivaToroide(int h,int k,toroide t);
int vecinosVivos(toroide t,int f,int c);
int cotaMaximoPeriodo(toroide t,toroide u);
toroide traslacion(toroide const &t,int i,int j);
vector<posicion> minimoSubRecQueCubreLosVivos(vector<posicion> vivos);
int menorSuperficieRec(toroide t);
int calcularAreaRec(posicion a,posicion b);
#endif //REUNIONESREMOTAS_AUXILIARES_H
