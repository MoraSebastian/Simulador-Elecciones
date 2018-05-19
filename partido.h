#ifndef _PARTIDOH_
#define _PARTIDOH_
#include "avl.h"
#include "estructura.h"
#include "candidato.h"
class Partido: public plantilla{
	Lista<partido> partidos;
	int tam;
	
	public:
		Partido(Lista<candidato> c){
			leer();
			for(int i =1;i<= c.getTam();i++){
				anadirC(c.devolverDato(i));
			}
		}
		//anadir partido
		int anadirPar(partido par){
			partidos.anadirFin(par);
			return 0;
		}		
		//Lee el archivo
		 void leer(){
		 	if(leido==false){
				int clave;
				string nombre;
				partido par;
				//archivo de entrada
				ifstream archEntrada("archivos/partidos.txt", ios::in);
				if (!archEntrada.good()){
				 	cerr<< "No se pudo abrir el archivo partidos" << endl;
			    	exit(1);
				}
				while(!archEntrada.eof()) {
					archEntrada >> clave;
					archEntrada >> nombre;
					par.clave = clave;
					par.nombre = nombre;
					anadirPar(par);
				}
				archEntrada.close();
				this->leido = true;
}
		 }
		
		//Funci�n encargada de insertar un candidato
		void anadirC( candidato cani){
			partido p;
			for(int i =1;i<=partidos.getTam();i++){
				if(partidos.devolverDato(i).clave == cani.partido){
					p =  partidos.devolverDato(i);
					p.candidatos.anadirFin(cani);
					partidos.modificar(p,i);
				}
			}	
		}
		
		//Devuelve la cantidad de partidos
		int getTam(){
			return partidos.getTam();
		}
		//funcion para consultar todos los partidos
		Lista<partido> getPartidos(){
			return partidos;
		}
		
		//Funci�n para consultar un partido espec�fico 
		partido getPartido(int partido){
			int aux;
			for(int i =1;i<=getTam();i++){
				if(partidos.devolverDato(i).clave == partido){
					aux = i;
				}
			}
			return partidos.devolverDato(aux);
		}
		
		
		//obtener el nombre de un partido
		string getNombre(int partido){
			int aux;
			for(int i =1;i<=getTam();i++){
				if(partidos.devolverDato(i).clave == partido){
					aux = i;
				}
			}
			return partidos.devolverDato(aux).nombre;
		}
		
		//Obtiene los candidatos  de un partido
		Lista<candidato> consultarC(int partido){
			int aux;
			for(int i = 1;i<=partidos.getTam();i++){
				if(partido == partidos.devolverDato(i).clave){
					aux = i;
				}
			}
			return partidos.devolverDato(aux).candidatos;
		}
		
		//Obtiene todos los candidatos a presidencia
		Lista<candidato> candidatosPresidencia(){
			Lista<candidato> temp;
			for(int i = 1;i<getTam();i++){
				Lista<candidato> c = partidos.devolverDato(i).candidatos;
				for(int j =1;j<=c.getTam();j++){	
					if(c.devolverDato(j).tipoCandidato == 1){
						temp.anadirFin(c.devolverDato(j));
					}
				}
			}
			return temp;
		}
		
		//Obtiene el representante legal del partido
		candidato representante(int partido){
			int aux;
			for(int i = 1;i<partidos.getTam();i++){
				if(partidos.devolverDato(i).clave == partido){
					aux = i;
				}
			}
			Lista<candidato> temp = partidos.devolverDato(aux).candidatos;
			candidato c;
			for(int i = 1;i<=temp.getTam();i++){
				if(temp.devolverDato(i).tipoCandidato == 0){
					c = temp.devolverDato(i);
				}
			}
			return c;
		}	
};
#endif
