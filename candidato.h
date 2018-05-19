#ifndef CANDIDATO
#define CANDIDATO
#include "estructura.h"
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "listas.h"
#include "plantilla.h"

class candidatos: public plantilla{
	Lista<candidato> cand;
	public:
	candidatos(){
		this->leido = false;
		this->cantidad  = 0;	
		leer();
	}
	void leer(){
		int clave;
			string nombre;
			string apellido;
			long long id;
			string sexo;
			string estadoCivil;
			string fechaNac;
			int ciudadNac;
			int ciudadRes;
			int partido;
			int vice;
			int tipo;
			candidato can;
			this->cantidad = 0;
			//archivo de entrada
			ifstream archEntrada("Archivos/candidatos.txt", ios::in);
			if(!archEntrada.good()){
			 	cerr << "No se pudo abrir el archivo candidatos.txt" << endl;
    			exit(1);
			}
			//se leen los registros
			while(!archEntrada.eof()){
				archEntrada >> clave;
				archEntrada >> nombre;
				archEntrada >> apellido;
				archEntrada >> id;
				archEntrada >> sexo;
				archEntrada >> estadoCivil;
				archEntrada >> fechaNac;
				archEntrada >> ciudadNac;
				archEntrada >> ciudadRes;
				archEntrada >> partido;
				archEntrada >> tipo;
				archEntrada >> vice;
				
				can.clave = clave;
				can.nombre = nombre;
				can.apellido = apellido;
				can.id = id;
				can.sexo = sexo;
				can.estadoCivil = estadoCivil;
				can.fechaNac= fechaNac;
				can.ciudadNac = ciudadNac;
				can.ciudadRes = ciudadRes;
				can.partido = partido;
				can.vicepresidente = vice;
				can.tipoCandidato= tipo;
				anadir(can);
			}
			archEntrada.close();
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
		
		/*Muestra la cantidad de candidatos registrados*/
		int getTam(){
			return cand.getTam();
		}
		
};
#endif
