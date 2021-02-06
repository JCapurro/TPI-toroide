#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

/******************************/
/** Autores:                 **/
/**  *Juan Capurro           **/
/**  *Humberto Carlos Sanchez**/
/******************************/
using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}
//No pueden usar esta función para resolver el TPI.
//Tampoco pueden usar iteradores, como usa esta función.
vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}


bool esRectangulo(toroide t,int ncol,int nfil){
    int resp=true;
    for(int i=0;i<nfil;i++){
        resp&=t[i].size()==ncol;
    }
    return resp;
}

int modulo(int a, int b){
    int r = a % b;
    return r < 0 ? r + b : r;
}


int vecinosVivos( toroide t,int f, int c){
    int vecinosVivos = 0;
    for(int i =-1; i <=1;i++) {
        for(int j=-1;j<=1;j++){
            if(vivaToroide(f+i,c+j,t)&&(i!=0||j!=0)){
                vecinosVivos+=1;
            }
        }
    }
    return vecinosVivos;
}


bool vivaToroide(int f,int c,toroide t){
    return t[modulo(f,t.size())][modulo(c,t[0].size())];
}


float cantidadVivas(toroide t){
    float vivas = 0;
    for (int i=0; i <t.size(); i++){
        for (int j=0; j<t[i].size(); j++){
            if(t[i][j]){
                vivas += 1;
            }
        }
    }
    return vivas;
}


float superficieTotal(toroide t){
    return t.size() * t[0].size();
}


bool estaViva(toroide t, int f, int c){
    return enRangoToroide(f,c,t) && t[f][c];
}


bool enRangoToroide(int f, int c, toroide t){
    return (0<=f && f<t.size()) && (0<=c && c<t[0].size());
}


bool debeVivir(toroide t, int f, int c){
    bool reproduccion=!estaViva(t,f,c) && vecinosVivos(t,f,c)==3;
    bool sobrevive=estaViva(t,f,c) && vecinosVivos(t,f,c)>=2 && vecinosVivos(t,f,c)<=3;
    return reproduccion||sobrevive;
}

int cantidadAMorir(toroide t){
    int ticks=0;
    while(cantidadVivas(t) != 0){
        evolucionToroide(t);
        ticks++;
    }
    return ticks;
}

toroide interseccionVivas(toroide t1,toroide t2){
    for(int i = 0; i < t1.size(); i++){
        for(int j = 0;j < t1[i].size(); j++){
            t2[i][j]=t1[i][j]&&t2[i][j];
        }
    }
    return t2;
}

int cotaMaximoPeriodo(toroide t,toroide u) {
    int pt;
    int pu;
    esPeriodico(t, pt);
    esPeriodico(u, pu);
    if (pu > pt)
        return pu;
    else
        return pt;
}

/**********/

toroide traslacion(toroide const &t,int i,int j){
    toroide tf=t;
    for(int k=0;k<t.size();k++){
        for(int m=0;m<t[k].size();m++){
            tf[k][m]=t[modulo(k+i,t.size())][modulo(m+j,t[k].size())];
        }
    }
    return tf;
}


int menorSuperficieRec(toroide t) {
    vector<posicion> vivas=posicionesVivas(t);
    posicion esquinaSupIzq=minimoSubRecQueCubreLosVivos(vivas)[0];//esquina superior izq. de minimo sub-rectangulo.
    posicion esquinaInfDer=minimoSubRecQueCubreLosVivos(vivas)[1];//esquina inferior der. de minimo sub-rectangulo.
    return calcularAreaRec(esquinaSupIzq,esquinaInfDer);
}

vector<posicion> minimoSubRecQueCubreLosVivos(vector<posicion> vivas) {
    int minimaFila = vivas[vivas.size() - 1].first;;
    int minimaCol = vivas[vivas.size() - 1].second;
    int maximaFila = 0;
    int maximaCol = 0;

    for (int i = 0; i < vivas.size(); i++) {
        if (minimaFila > vivas[i].first) {
            minimaFila = vivas[i].first;
        }
        if (minimaCol > vivas[i].second) {
            minimaCol = vivas[i].second;
        }
        if (maximaFila < vivas[i].first) {
            maximaFila = vivas[i].first;
        }
        if (maximaCol < vivas[i].second) {
            maximaCol = vivas[i].second;
        }
    }
    posicion esquinaSupIzq = make_pair(minimaFila, minimaCol);//esquina superior izquierda de rectangulo
    posicion esquinaInfDer = make_pair(maximaFila, maximaCol);//esquina inferior derecha de rectangulo

    return {esquinaSupIzq, esquinaInfDer};
}



int calcularAreaRec(posicion esquinaSupIzq,posicion esquinaInfDer){
    int altura = esquinaInfDer.first - esquinaSupIzq.first +1;
    int base = esquinaInfDer.second - esquinaSupIzq.second +1;
    return base * altura;
}
