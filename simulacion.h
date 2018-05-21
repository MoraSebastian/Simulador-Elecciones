#include "plantilla.h"
#include <iostream>
#include "estructura.h"
#include<stdlib.h>
#include<time.h>

using namespace std;
class simulacion: public plantilla{
	public: 
		//Funciones herdadas de plantilla	
		void leer(){
			int i ;
		}
		void escribir(){cout<<"escribe";}
		
		//Constructor
		simulacion(){		
		}
		
		
		//Simula las elecciones presidenciales
		void simularP(Lista<candidato> c, long long censo){
			Lista<voto> temp; //Lista con los resultaos. la que se devuelve
			long long aux = censo;
			voto v;//Se va a ir llenado con la información de los candidatos
			
			
			v.nombreCand = "Voto en Blanco";
			v.partido = 0;
			v.votos = rand()%aux;
			aux -= v.votos;
			v.porcentaje = porcentaje(v.votos,censo);
			temp  = ordenar(v,temp);
			v.nombreCand = "Votos Nulos";
			v.votos = rand()%aux;
			v.partido = 0;
			temp = ordenar(v,temp);
			for(int i = 1;i<= c.getTam();i++){
				v.nombreCand = c.devolverDato(i).nombre+" "+c.devolverDato(i).apellido;
				v.partido = c.devolverDato(i).partido;
				long long lim =1000000 +rand()%(1200000-1000000);
				v.votos =lim+ rand()%(aux-lim);
				aux -= v.votos;
				v.porcentaje = porcentaje(v.votos,censo);
				temp = ordenar(v,temp);
			v.porcentaje = porcentaje(v.votos,censo);
			}
			v.nombreCand = "Abstinencia";
			v.votos = aux;
			v.partido = 0;
			v.porcentaje = porcentaje(v.votos,censo);
			temp = ordenar(v,temp);
			for(int i = 1;i<=temp.getTam();i++){
				cout<<i<<" "<<temp.devolverDato(i).nombreCand<<" "<<temp.devolverDato(i).votos<<" "<<temp.devolverDato(i).porcentaje<<endl;
			}			
		}
		
		//Obtiene el porcentaje de los votos originales
		float porcentaje(long long dato, long long original){
			return(dato*100)/original;
		}
		
		//Ordena la lista con tal de que siempre el de mayor cantidad de votos quede de primero
		Lista<voto> ordenar(voto v, Lista<voto> datos){
			voto aux;
			voto temp = v;
			for(int i = 1;i<= datos.getTam();i++){
				aux = datos.devolverDato(i);
				if(temp.votos>aux.votos){
					datos.modificar(temp,i);
					temp = aux;
				}
			}
			datos.anadirFin(temp);
			return datos;
		}
};
