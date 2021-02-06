#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

/******************************/
/** Autores:                 **/
/**  *Juan Capurro           **/
/**  *Humberto Carlos Sanchez**/
/******************************/
// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    int nfil=t.size();//numero de filas
    int ncol=t[0].size();//numero de columnas
    return esRectangulo(t,ncol,nfil)&&nfil>=3&&ncol>=3;
}

// EJERCICIO 2
bool toroideMuerto(toroide const &t) {
    bool estaMuerta = true;
    int f = 0;
    while(f < t.size() && estaMuerta){
        int c=0;
        while (c < t[f].size() && estaMuerta){
            estaMuerta= !t[f][c];
            c++;
        }
        f++;
    }
    return estaMuerta;
}

// EJERCICIO 3
vector<posicion> posicionesVivas(toroide const &t) {
	vector<posicion> vivos={};
    for(int i=0;i<t.size();i++){
        for(int j=0;j<t[i].size();j++){
            if(t[i][j]){
                vivos.push_back(make_pair(i,j));
            }
        }
    }
    return vivos;
}

// EJERCICIO 4
float densidadPoblacion(toroide const &t) {
    return cantidadVivas(t) / superficieTotal(t);
}

// EJERCICIO 5
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    return vecinosVivos(t,f,c);
}

// EJERCICIO 6
bool evolucionDePosicion(toroide const &t, posicion x) {
	return debeVivir(t,x.first, x.second);
}

// EJERCICIO 7
void evolucionToroide(toroide &t){
    toroide t0=t;//guardo en t0 estado inicial del toroide
    for(int i = 0;i<t.size();i++) {
        for (int j = 0; j < t[i].size(); j++) {
            t[i][j] = debeVivir(t0, i, j);
        }
    }
}

//EJERCICIO 8
toroide evolucionMultiple(toroide const &t, int K) {
    toroide t0=t;
    for(int i=1;i<=K;i++){
        evolucionToroide(t0);//toroide t0 despues de i ticks.
    }
    return t0;
}

// EJERCICIO 9
bool esPeriodico(toroide const &t, int &p){
    toroide tf=t;
    evolucionToroide(tf);//primer tick
    int ticks=1;
    while(t!=tf && !toroideMuerto(tf)){
        evolucionToroide(tf);
        ticks++;
    }

    if(t==tf && !toroideMuerto(tf)){//se modifica p solo si es periodico.
        p=ticks;
    }

    return t==tf && !toroideMuerto(tf);//el toroide se repite despues de k tiks y no muere.
}



// EJERCICIO 10
bool primosLejanos(toroide const &t, toroide const &u) {
	int p=cotaMaximoPeriodo(t,u);//para acotar iteraciones en caso de que sea periodico t o u.
	bool sonPrimos=false;
	int k=0;
	while(k<=p && !sonPrimos){
	    k++;
        sonPrimos=(t==evolucionMultiple(u,k)||u==evolucionMultiple(t,k));
	}
    return sonPrimos;
}


// EJERCICIO 11
int seleccionNatural(vector <toroide> ts) {
    int resp = 0;
	for (int i=1;i<ts.size();i++){
	    if(cantidadAMorir(ts[i]) > cantidadAMorir(ts[resp])){
	        resp = i;
	    }
	}
    return resp;
}



// EJERCICIO 12
toroide fusionar(toroide const &t, toroide const &u) {
    return interseccionVivas(t,u);
}

// EJERCICIO 13
bool vistaTrasladada(toroide const &t, toroide const &u){
    bool esTrasladada=false;
	for(int i=1;i<t.size();i++){
	    for(int j=1;j<t[i].size();j++){
	        esTrasladada|=traslacion(u,i,j)==t;
	    }
	}
	return  esTrasladada;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t){
    int minSupViva=t.size()*t[0].size();//inicializo con el mayor area posible.
	for(int i=0;i<t.size();i++){
	    for(int j=0;j<t[i].size();j++){
	        int supVivaDeTrasladada=menorSuperficieRec(traslacion(t,i,j));//menor superficie viva de trasladada
	        if(supVivaDeTrasladada<minSupViva){
	            minSupViva=supVivaDeTrasladada;
	        }
	    }
	}
	return minSupViva;
}

