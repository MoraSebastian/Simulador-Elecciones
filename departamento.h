#ifndef DEPARTAMENTO
#define DEPARTAMENTO
#include "listas.h"
#include<string.h>
#include "estructura.h"
#include "ciudad.h"
//#include "ciudad.h"


class departamentos: public plantilla{
	Lista<departamento> dep;
	
	public:
		/**Constructos de departamento*/
		departamentos(Lista<ciudad> c){
			this->leido = false;	
			leer();
			for(int i = 1; i<= c.getTam();i++){
				agregarMunicipio(c.devolverDato(i));
			}
			cout<<dep.devolverDato(1).municipios.getTam();
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
			departamento d;
			for(int i = 1;i<= dep.getTam();i++){
				if(dep.devolverDato(i).clave == municipio.departamento){
					d =dep.devolverDato(i);
					d.municipios.anadirFin(municipio);
					dep.modificar(d,i);
				}
			}
			
		}
		/** Muestra las ciudades de un departamento*/
		Lista <ciudad> mostrarCiudades(int numDept){
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
