#include "plantilla.h"
#include <iostream>
#include "estructura.h"
#include<stdlib.h>
#include <cstdlib>
#include<time.h>
#include <ctime>


long long randomi(int max){
	int lim=5+rand()%((8)-5);
	int y=0;
	int x;
	for(int i=1; i<=lim; i++){
		x=1+ rand()%9;
		if(10*y+x>=max){   //MACHETE 
			break;
		}			
		y=10*y+x; 
	}
	return y;
}

using namespace std;
class simulacion: public plantilla{
	Lista<resultados> result;
	Lista<votoP> presidentes;
	public: 
		Lista<votoP> getPresidentes(){
			return presidentes;
		}
		//Funciones herdadas de plantilla	
		void leer(){
			int i ;
		}
		void escribir(){cout<<"escribe";}
		
		//Constructor
		simulacion(){		
		}				
		//Simula las elecciones presidenciales
		void simularP(Lista<ciudad> c, Lista<candidato> can){
			//guarda el censo del pais
			long long censo = 0;	
			srand(time(0));
			votoP v;
			//LLena la lista de presidentes
			//se agrega los votos en blanco y voto nulo
			v.nombreCand = "Voto en Blanco";
			v.partido = 0;
			v.votos = 0;
			v.porcentaje = 0;
			v.vice = 0;
			v.votoP = new votoPC[c.getTam()+1];
			presidentes.anadirFin(v);
			v.nombreCand = "Voto Nulo";
			v.partido = 0;
			v.votos = 0;
			v.porcentaje = 0;
			v.vice = 0;
			v.votoP = new votoPC[c.getTam()+1];
			presidentes.anadirFin(v);
			for(int i = 1;i<=can.getTam();i++){
				v.nombreCand = can.devolverDato(i).nombre+" "+can.devolverDato(i).apellido;
				v.partido = can.devolverDato(i).partido;
				v.votos = 0;
				v.porcentaje = 0;
				v.vice = can.devolverDato(i).vicepresidente;
				v.votoP = new votoPC[c.getTam()+1];
				presidentes.anadirFin(v);
			}
			// se agrega espacio para abstinencia
			v.nombreCand = "Abstinencia";
			v.partido = 0;
			v.votos = 0;
			v.porcentaje = 0;
			v.vice = 0;
			v.votoP = new votoPC[c.getTam()+1];
			presidentes.anadirFin(v);
			//Carga el censo total del pais
			for(int i = 1;i<=c.getTam();i++){
				censo+= c.devolverDato(i).censo;
			}	
			//Recorre partidos
			for(int i = 1;i<=c.getTam();i++){
				long long aux = c.devolverDato(i).censo;//Carga el censo de la ciudad
				for(int j = 1;j<=presidentes.getTam();j++){//Recorre los candidatos, para asignar votos
					v = presidentes.devolverDato(j);
					if(j == presidentes.getTam()){//Caso especial para la abstencion 
						v.votos += aux;
						v.votoP[i].votos = aux;
						v.votoP[i].ciudad = c.devolverDato(i).clave;
						v.votoP[i].porcentaje = porcentaje(aux,c.devolverDato(i).censo);
					}else{
						long long lim =randomi(aux);
						long long temp = lim+ rand()%(aux-lim);
						v.votos += temp;
						v.votoP[i].votos = temp;
						v.votoP[i].ciudad = c.devolverDato(i).clave;
						aux-= temp;
						v.votoP[i].porcentaje = porcentaje(temp,c.devolverDato(i).censo);
					}
				
				}
			}
			for(int i =1;i<= presidentes.getTam();i++){//aca cargo el porcentaje total de los votos cargados
				v = presidentes.devolverDato(i);
				for(int j = 1;j<= c.getTam();j++){
					v.votos += v.votoP[j].votos;
				}
				v.porcentaje = porcentaje(v.votos,censo);
				presidentes.modificar(v,i);
			}
			ordenar(presidentes);//ordeno la lista de tal manera que el de mayor porcentaje quede de primeras, lo hice con seleccion :3
		}
		
		//Simula las elecciones a la alcaldia de una ciudad
		void simularA(Lista<candidato> c, long long censo, string nombre){			
			long long votosfinal=0 ;    //AL FINAL DEBE SER IGUAL AL CENSO
			resultados r;
			Lista<voto> temp; //Lista con los resultaos. la que se devuelve
			long long aux = censo;
		
			voto v;//Se va a ir llenado con la información de los candidatos
			srand(time(0));
			
			v.nombreCand = "Voto en Blanco";
			v.partido = 0;
			v.votos = rand()%aux;
			
			votosfinal = votosfinal + v.votos;
			
			aux -= v.votos;
			v.porcentaje = porcentaje(v.votos,censo);
			temp  = ordenar(v,temp);
			v.nombreCand = "Votos Nulos";
			v.votos = rand()%aux;
			aux -= v.votos;
			votosfinal = votosfinal + v.votos;			
			v.partido = 0;
			temp = ordenar(v,temp);
			
			for(int i = 1;i<= c.getTam();i++){
				v.nombreCand = c.devolverDato(i).nombre+" "+c.devolverDato(i).apellido;
				v.partido = c.devolverDato(i).partido;				
				long long lim =randomi(aux);		
				v.votos =lim+ rand()%(aux-lim);				
				votosfinal = votosfinal + v.votos;				
				if(aux-v.votos>=0){
					aux -= v.votos;	
				}else{
					while(!(aux-v.votos>=0)){
						v.votos = lim+ rand()%(aux-lim);
					}					
				}				
				v.porcentaje = porcentaje(v.votos,censo);
				temp = ordenar(v,temp);
			v.porcentaje = porcentaje(v.votos,censo);
			}
			v.nombreCand = "Abstinencia";
		
			v.votos = aux;
			aux -= v.votos;				
			votosfinal = votosfinal + v.votos;			
			v.partido = 0;
			v.porcentaje = porcentaje(v.votos,censo);
			temp = ordenar(v,temp);
			r.nombreCiudad=nombre;
			r.resultado = temp;
			result.anadirFin(r);
			for(int i = 1;i<=temp.getTam();i++){
				cout<<i<<" "<<temp.devolverDato(i).nombreCand<<" "<<temp.devolverDato(i).votos<<" "<< fixed << setprecision(1) << temp.devolverDato(i).porcentaje<<"%"<<endl;
			}
			
		//	cout<<"final de votos: "<<votosfinal<<endl;
			cout<<"diferencia: "<<votosfinal-censo<<endl;			
		}
		//Obtiene el porcentaje de los votos originales
		float porcentaje(long long dato, long long original){
		//	cout<<"porcentaje: "<<((float)dato*100)/(float)original<<"%"<<endl;
			return((float)dato*100)/(float)original;
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
		
		Lista<votoP> ordenar(Lista<votoP> datos){
			int aux;
			votoP temp;
			for(int i = 1;i< datos.getTam();i++){
				aux = i;
				for(int j = i+1;j<=datos.getTam();j++){
					if(datos.devolverDato(j).votos < datos.devolverDato(i).votos){
						aux = j;
					}
					temp = datos.devolverDato(j);
					datos.modificar(datos.devolverDato(aux),j);
					datos.modificar(temp,aux);
				}
			}
			return datos;
		}
};
