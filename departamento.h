#ifndef DEPARTAMENTO
#define DEPARTAMENTO
#include "listas.h"
#include "plantilla.h"
#include<string.h>
#include "estructura.h"
//#include "ciudad.h"


class departamentos: public plantilla{
	Lista<departamento> dep;
	
	public:
		/**Constructos de departamento*/
		departamentos(){
			this->leido = false;
			this->cantidad  = 0;	
			leer();
		}
		/** Get de arreglo de departamentos*/
		Lista<departamento> getArregloDep(){
			return dep;
		}
		
		/** Agregar departamento*/
		void agregarDept(departamento dept){			
			dep.anadirFin(dept);			
		}
		/** Agregar municipio a departamento*/
		void agregarMunicipio(ciudad municipio){
			for(int i = 1;i<= dep.getTam();i++){
				if(dep.devolverDato(i).clave == municipio.departamento){
					dep.devolverDato(i).municipios.anadirFin(municipio);
				}
			}
		}
		/** Muestra las ciudades de un departamento*/
		Lista <ciudad> mostrarCiudadesDept(int numDept){
			return dep.devolverDato(numDept).municipios;
		}	
		
		/**Lee los datos que se tienen en el archivo*/
		void leer(){
			if(leido==false){
				int clave;
				string nombre;
				departamento dep;
				//archivo de entrada
				ifstream archEntrada("archivos/departamentos.txt", ios::in);
				if (!archEntrada.good()){
				 	cerr << "No se pudo abrir el archivo departamentos" << endl;
			    	exit(1);
				}
				while(!archEntrada.eof()) {
					archEntrada >> clave;
					archEntrada >> nombre;
					dep.clave = clave;
					dep.nombre = nombre;
					agregarDept(dep);
					this->cantidad++;
				}
				archEntrada.close();
				this->leido = true;
}
		}			
		int getTam(){
			return dep.getTam();
		}
		departamento getDept(int i){
			return dep.devolverDato(i);
		}
};
#endif
