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
		
		//Regresa la lista de ciudades
		Lista<ciudad> getMun(){
			return mun;
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
		/*Metodo que devuelve el nombre de una ciudad*/
		string getNombre(int ciudad){
			int aux;
			for(int i = 1;i<= getCantidad();i++){
				if(mun.devolverDato(i).clave == ciudad){
					aux = i;
				}
			}
			return mun.devolverDato(aux).nombre;
		}
		/**Método cuyo @return es una ciudad especifica*/
		ciudad getCiudad(int ciudad ){
			int aux;
			for(int i = 1;i<= getCantidad();i++){
				if(mun.devolverDato(i).clave == ciudad){
					aux = i;
				}
			}
			return mun.devolverDato(aux);
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
