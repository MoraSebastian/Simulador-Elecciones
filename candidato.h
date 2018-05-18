#ifndef CANDIDATO
#define CANDIDATO
#include "estructura.h"
#include <cstring>
#include <time.h>
#include "listas.h"

class candidatos{
	Lista<candidato> cand;
	public:
	candidatos(Lista<candidato> can){
		cand = can;
	}
	candidatos(){
	}
	
	//agregar un nuevo candidato
	void anadir(candidato c){
		cand.anadirFin(c);
	}
	
	//Devuelve la lista de candidatos
	Lista<candidato> getCandidatos(){
		return cand;
	}
	//Para obtener un candidato
	candidato getCandidato(int clave){
		return cand.devolverDato(clave);
	}
	
	//Función para calcular edad 
	int edad(string fecha){
			char *nuevafecha=strdup(fecha.c_str());
			int dia,mes,ano,diaa,mesa,anoa;
			char *ptr;
			ptr=strtok(nuevafecha,"/");
			dia=atoi(ptr);
			ptr=strtok(NULL,"/");
			mes=atoi(ptr);
			ptr=strtok(NULL,"/");
			ano=atoi(ptr);
		
			//SE obtiene la fecha actual del sistema
			time_t tiempo = time(NULL);//variables donde guardo el valor de la funcion time. 
		    struct tm *tlocal = localtime(&tiempo); //estructura donde obtengo el tiempo 
		    char output[10]; //array donde guardo la fecha
		    strftime(output,10,"%d/%m/%y",tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
		    
		    ptr=strtok(output,"/");
			diaa=atoi(ptr);
			ptr=strtok(NULL,"/");
			mesa=atoi(ptr);
			ptr=strtok(NULL,"/");
			anoa=atoi(ptr)+2000;
			int dias,meses,anos;
			anos=anoa-ano;
			meses=mesa-mes;
			dias=diaa-dia;
	
			if (dias<0){
				meses--;
			}
	
			if(meses<0){
				anos--;
			}
			return anos;
		}
		
};
#endif
