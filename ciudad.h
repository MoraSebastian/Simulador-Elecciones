#ifndef CIUDAD
#define CIUDAD
#include<string.h>
#include "plantilla.h"
#include "listas.h"
#include "candidato.h"
#include "estructura.h"
class ciudades: public plantilla{
	Lista<ciudad> mun;
	
	
	public:
		//Constructor ya esta cargando la informacion del archivo de las ciudades
		ciudades(){
			this->leido = false;
			this->cantidad  = 0;	
			leer();
			
		}
		/**Anade ciudades*/
		void anadirCiudad(ciudad c){									
			mun.anadirFin(c);
		}	
		
		void leer(){
			if(this->leido==false){
				int clave;
				string nombre;
				int departamento;		
				long long censo;
				ciudad ciuda;

				//archivo de entrada
				ifstream archEntrada("archivos/Ciudades.txt", ios::in);
				if (!archEntrada.good()){
					cerr << "No se pudo abrir el archivo ciudades" << endl;
			    	exit(1);
				}
				while(!archEntrada.eof()){
					archEntrada >> clave;
					archEntrada >> nombre;
					archEntrada >> departamento;
					archEntrada >> censo;
					ciuda.clave = clave;
					ciuda.nombre = nombre;
					ciuda.departamento = departamento;
					ciuda.censo = censo;
					this->anadirCiudad(ciuda);
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
			for (int i=1; i<=mun.getTam(); i++){
				archsalida1<<mun.devolverDato(i).clave<<" "<<mun.devolverDato(i).nombre<<" "<<mun.devolverDato(i).departamento
						   <<" "<<mun.devolverDato(i).censo ;
				if(i<mun.getTam()){
					archsalida1<<endl;
				}
			}												
		    archsalida1.close();
		    
		    remove("archivos/ciudades.txt");
		 	rename("archivos/temp.txt", "archivos/ciudades.txt");
		}
		/**Método cuyo @return es una ciudad especifica*/
		ciudad getCiudad(int i ){
			return mun.devolverDato(i);
		}
		
		void modificarC(ciudad ciu){
			int i=1;
			while(ciu.clave!=mun.devolverDato(i).clave){
				i++;
			}
			mun.modificar(ciu, i);
			escribir();
		}
		
		/**Muestra los candidatos de una ciudad*/
	/*	Lista <candidato> mostrarCandPorCiudad(int posCiudad){
			return mun[posCiudad].cabCandidatosCiudad;
		}*/
		
		/**Añade candidatos a la ciudad en la que va a a particiar*/		
		/*   POR AHORA NO
		void anadirCandidatoCiudad(candidato cand, int posCiudad){
			int auxId;
			if (mun[posCiudad].idCabezaCand == 0){						//Si la ciudad aun no tiene candidatos, este es el primero
				mun[posCiudad].idCabezaCand = cand.clave;
			} else {
				cand.antCandCiudad = mun[posCiudad].idCabezaCand;		//El candidato guarda la clave del anterior candidato d ela misma ciudad
				mun[posCiudad].idCabezaCand = cand.clave;
				
			}
		}
		*/
		
		
		//funcion para consultar todos los partidos
		Lista<ciudad> getCiudades(){
			return mun;
		}
		
				
		void anadirADept(){
			//Aun no hago esto
		}
	
		/**Método que no recibe parametros, pero su @return la cantidad de ciudades en el arreglo*/
		int getCantidad(){
			return mun.getTam();
		}
		
};
#endif
