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
		void escribir(){						
			ofstream archsalida1("archivos/temp.txt", ios::out|ios::trunc);    //Crea un archivo para escribirlo
			
			if (!archsalida1.good())
		    {	cerr << "No se pudo abrir el archivo " << endl;
		    	exit(1);
			}    
			for (int i=1; i<=partidos.getTam(); i++){
				archsalida1<<partidos.devolverDato(i).clave<<" "<<partidos.devolverDato(i).nombre;						   
				if(i<partidos.getTam()){
					archsalida1<<endl;
				}
			}												
		    archsalida1.close();
		    
		    remove("archivos/partidos.txt");
		 	rename("archivos/temp.txt", "archivos/partidos.txt");
		}
		//Función encargada de insertar un candidato
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
		
		//Función para consultar un partido específico 
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
			for(int i = 1;i<= getTam();i++){
				Lista<candidato> c = partidos.devolverDato(i).candidatos;
				for(int j =1;j<=c.getTam();j++){
					if(c.devolverDato(i).tipoCandidato == 1){
						temp.anadirFin(c.devolverDato(j));
					}
				}
			}
			return temp;
		}
		
		
		/**
		//Metodo para modificar un candidato
		void modificar(int clave, candidato c){
		//	Escritura esc;
			eliminar(clave);
			int aux = c.partido;
			can.getCandidatos().modificar(c,clave);	
			cout<<"partido nuevo: "<<aux<<endl;
			anadirC(c);
			cout<<"miembros del partido: "<<partidos[aux].candidatos.getTam()<<endl;
			//llamo el método para que me escriba el archivo
			
			Escritura esc;	
		//	esc.escrituraCandidatos(candi, clave, can.getCandidatos().getTam());
			esc.escrituraCandidatos(c, clave, can.getCandidatos().getTam());      	
		}
		*/
		void modificarP( partido parti){
			int i=1;
		//	cout<<"cantidad de partidos: "<<tam<<endl;
			while(parti.clave!=partidos.devolverDato(i).clave){
				i++;
			}
			parti.candidatos = partidos.devolverDato(i).candidatos;
			partidos.modificar(parti, i);
			escribir();
		}
		/*
		//Eliminar candidato
		void eliminar(int clave){
			int aux = can.getCandidato(clave).partido;
			partidos[aux].candidatos.eliminar(clave);
			
			Escritura esc;
			esc.eliminarCandidato(clave, can.getCandidatos().getTam());
		}
		*/			
};
#endif
