#ifndef DEPARTAMENTO
#define DEPARTAMENTO
#include "listas.h"
#include<string.h>
#include "estructura.h"
//#include "ciudad.h"


class departamentos{
	departamento * dep;
	int tam;
	
	public:
		/**Constructos de departamento*/
		departamentos(Lista<departamento> depa){
			dep = new departamento[6];
			tam = 0; 
			for(int i=1; i<=depa.getTam(); i++){
				agregarDept(depa.devolverDato(i));
			}
		}
		/** Get de arreglo de departamentos*/
		departamento* getArregloDep(){
			return dep;
		}
		//Retorna el tamaño del arreglo de departamentos, es decir el numero de ellos
		int getTam(){
			return tam;
		}
		/** Agregar departamento*/
		void agregarDept(departamento dept){			
			dep[tam+1] = dept;
			tam++;			
		}
		/** Agregar municipio a departamento*/
		/*
		void agregarMunicipio(ciudad municipio, int numDept){
			dep[numDept].municipios.anadirFin(municipio);		//Añade el municipio a el departamento correspondiente
			dept[numDept].censoPersonas=+municipio.censo;		//Va sumando la cantidad de personas al censo de el departamento
		}*/
		/** Muestra las ciudades de un departamento*/
		Lista <ciudad> mostrarCiudadesDept(int numDept){
			return dep[numDept].municipios;
		}				
};
#endif
