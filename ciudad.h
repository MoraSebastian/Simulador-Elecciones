#ifndef CIUDAD
#define CIUDAD
#include<string.h>
#include "listas.h"
#include "candidato.h"
#include "estructura.h"
class ciudades{
	ciudad *mun;
	int tam;
	
	public:
		//Constructor ya esta cargando la informacion del archivo de las ciudades
		ciudades(Lista<ciudad> ciu){	
			mun = new ciudad[31];
			tam=0;
			for (int i=1; i<=ciu.getTam(); i++){
				anadirCiudad(ciu.devolverDato(i));
			}	
		}
		/**Anade ciudades*/
		void anadirCiudad(ciudad c){									
			mun[tam+1] = c;
			tam++;
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
		
		//Devuelve la cantidad de ciudades
		int getTam(){
			return tam;
		}
		//funcion para consultar todos los partidos
		ciudad* getCiudades(){
			return mun;
		}
		
				
		void anadirADept(){
			//Aun no hago esto
		}
	
	
};
#endif
