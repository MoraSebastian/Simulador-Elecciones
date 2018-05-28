#ifndef CONSULTA
#define CONSULTA
#include "plantilla.h"
#include "estructura.h"
#include "partido.h"
#include "departamento.h"
class consulta{
	Lista<departamento> dpts;
	Lista<partido> pts;
	
	public: 
	consulta(Lista<partido> p, Lista<departamento> d){
		this->dpts = d;
		this->pts = p;
	}
	Lista<departamento> getDpts(){
		return dpts;
	}
	
	string getNombreD(int departamento){
		int aux;
		for(int i= 1;i<= dpts.getTam();i++){
			if(dpts.devolverDato(i).clave == departamento){
				aux = i;
			}
		}
		return dpts.devolverDato(aux).nombre;
	}
	
	string getNombreP(int partido){
		int aux;
		for(int i= 1;i<= pts.getTam();i++){
			if(pts.devolverDato(i).clave == partido){
				aux = i;
			}
		}
		return pts.devolverDato(aux).nombre;
	}
	/*Metodo que recibe un partido y retorna una lista con los candidatos */
	Lista<candidato> consultaNacional(int partido){
		return pts.devolverDato(partido).candidatos;
	}
	
	Lista<candidato> consultaPresidenciaPartido(int partido){
		Lista<candidato> temp, temp2;
		temp = consultaNacional(partido);
		for (int i=1; i<=temp.getTam(); i++){
			if(temp.devolverDato(i).tipoCandidato==1){
				temp2.anadirFin(temp.devolverDato(i));
			}
		}
	
		return temp2;
	}
	/* Metodo que recibe un @param partido y @param departamento
	los cuales se utilizaran para retornar una lista con todos los candidatos
	que se presentan a alcaldia de el partido en dicha ciudad
	*/
	Lista<candidato> consultaDepartamento(int partido, int departamento){
		int auxp,auxd;
		Lista<candidato> temp;
		
		//Se busca el departamento al que se hace referencia
		for(int i = 1; i<=dpts.getTam();i++){
			if(dpts.devolverDato(i).clave == departamento){
				auxd = i;
			}
		}
		//Se busca el partido al que se hace referencia
		for(int i = 1; i<=pts.getTam();i++){
			if(pts.devolverDato(i).clave == partido){
				auxp = i;
			}
		}
		Lista<ciudad> ci = dpts.devolverDato(auxd).municipios;
		Lista<candidato> c= pts.devolverDato(auxp).candidatos;
		
		//Compara las listas de ciuddes y candidatos para encontrar los candidadtos a alcaldia a dicha ciudad
		for(int i = 1;i<= ci.getTam();i++){
			for(int j = 1;j<=c.getTam();j++){
				if(c.devolverDato(j).ciudadRes == ci.devolverDato(i).clave && c.devolverDato(j).tipoCandidato != 1 && c.devolverDato(j).tipoCandidato!=3){
					temp.anadirFin(c.devolverDato(j));
				}
			}
		}
		
		return temp;
	}
	
	/*Metodo que recibe el entero de una ciudad y devuelve el nombre de la misma.*/
	string nombreCiudad(int cd){
		string nombre;
		for(int i = 1;i<= dpts.getTam();i++){
			Lista<ciudad> city = dpts.devolverDato(i).municipios;
			for(int j = 1;j<= city.getTam();j++){
				if(city.devolverDato(j).clave ==cd){
					nombre = city.devolverDato(j).nombre;
				}
			}
		}
		
		return nombre;
	}
	
	//realiza la conversión del indice del vicepresidente a candidato
	candidato vice(int vice){
		candidato ca;
		for(int i = 1;i<= pts.getTam();i++){
			Lista<candidato> c = pts.devolverDato(i).candidatos;
			for(int j = 1;j<= c.getTam();j++){
				if(c.devolverDato(j).clave == vice){
					ca = c.devolverDato(j);
				}
			}
		}
		return ca;
	}
	
	//Dada una ciudad se muestra por partido los candidatos a dicha alcaldia
	Lista<candidato> alcaldia(int cd){
		int aux;
		Lista<candidato> temp;
		for(int i = 1;i<= dpts.getTam();i++){
			Lista<ciudad> city = dpts.devolverDato(i).municipios;
			for(int j = 1;j<= city.getTam();j++){
				if(city.devolverDato(j).clave ==cd){
					aux =city.devolverDato(j).clave;
				}
			}
		}
		for(int i = 1;i<= pts.getTam();i++){
			Lista<candidato> c = pts.devolverDato(i).candidatos;
			for(int j = 1;j<= c.getTam();j++){
				if(c.devolverDato(j).ciudadRes == aux && c.devolverDato(j).tipoCandidato!=1 && c.devolverDato(j).tipoCandidato!=0 && c.devolverDato(j).tipoCandidato!=3){
					temp.anadirFin(c.devolverDato(j));
				}
			}
		}
		return temp;
	}
	
	//Censo electoral por departamento
	long long censoDepartamento(int departamento){
		long long suma = 0;
		int aux;
		for(int i = 1;i<=dpts.getTam();i++){
			if(dpts.devolverDato(i).clave == departamento){
				aux = i;
			}
		}
		
		Lista<ciudad> c  = dpts.devolverDato(aux).municipios;
		for(int i= 1;i<=c.getTam();i++){
			suma+= c.devolverDato(i).censo;
		}
		return suma;
	}
	
	//Censo total del pais
	long long censo(){
		long long suma = 0;
		for(int i =1;i<= dpts.getTam();i++){
			suma += censoDepartamento(i);
		}
		return suma;
	}
};
#endif
