#ifndef _PARTIDOH_
#define _PARTIDOH_
#include "avl.h"
#include "escritura.h"
#include "estructura.h"

class Partido{
	partido* partidos;
	candidatos can;
	int tam;
	
	public:
		Partido(candidatos candid, Lista<partido>  nombres){
			can = candid;
			tam = 0;
			partidos = new partido[100];
			for(int i = 1;i<=nombres.getTam();i++){
				agregar(nombres.devolverDato(i));
			}
			for(int i = 1;i<=can.getCandidatos().getTam();i++){
				anadirC(can.getCandidato(i));
			}
		}
				
		//anadir partido
		void agregar(partido p){
			partidos[tam+1] = p;
			tam++;
		}
		//Función encargada de insertar un candidato
		void anadirC( candidato cani){
			if(partidos[cani.partido].candidatos.getTam() == 0){
				partidos[cani.partido].candidatos.insertarRaiz(cani.clave);
			}else{
				partidos[cani.partido].candidatos.insertarElemento(cani.clave);
			}	
		}
		
		//Devuelve la cantidad de partidos
		int getTam(){
			return tam;
		}
		//funcion para consultar todos los partidos
		partido* getPartidos(){
			return partidos;
		}
		
		//Función para consultar un partido específico 
		partido getPartido(int partido){
			return partidos[partido];
		}
		
		
		//obtener el nombre de un partido
		string getNombre(int partido){
			return partidos[partido].nombre;
		}
		
		//Obtiene los candidatos  de un partido
		Lista<candidato> consultarC(int partido){
			Lista<int> aux;
			int auxp = 0;
			Lista<candidato> temp;
			for(int i =1;i<= tam;i++){
				if(partido == partidos[i].clave)
					auxp = i;
			}
			aux = partidos[auxp].candidatos.getin();
			for(int i =1;i<= aux.getTam();i++){
				temp.anadirFin(can.getCandidato(aux.devolverDato(i)));
			}
			return temp;
		}
		
		//Obtiene todos los candidatos a presidencia
		Lista<candidato> candidatosPresidencia(){
			Lista<int> aux;
			Lista<candidato> temp;
			cout<<"cantidad de partidos: "<<getTam()<<endl;
			
			for(int i = 1;i<= getTam();i++){
				cout<<"partido: "<<partidos[i].clave<<endl;
				aux = partidos[i].candidatos.getin();
				for(int j =1;j<= aux.getTam();j++){
					cout<<"clave: "<<can.getCandidato(aux.devolverDato(j)).clave<<"  tipo candidato: "<<can.getCandidato(aux.devolverDato(j)).tipoCandidato<<endl;
					if(can.getCandidato(aux.devolverDato(j)).tipoCandidato == 1){
						cout<<"clave: "<<can.getCandidato(aux.devolverDato(j)).clave<<endl;
						temp.anadirFin(can.getCandidato(aux.devolverDato(j)));
					}
				}
			}
			return temp;
		}
		//Vacia las listas
		void vaciar(){
			for(int i = 0;i<=getTam();i++){
				partidos[i].candidatos.vaciarListas();
			}
		}
		
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
		void modificarP(int clave, partido parti){
			
			cout<<"cantidad de partidos: "<<tam<<endl;
			Escritura esc;
			esc.escrituraPartido(parti.nombre, clave, tam);
		}
		
		//Eliminar candidato
		void eliminar(int clave){
			int aux = can.getCandidato(clave).partido;
			partidos[aux].candidatos.eliminar(clave);
			
			Escritura esc;
			esc.eliminarCandidato(clave, can.getCandidatos().getTam());
		}			
};
#endif
