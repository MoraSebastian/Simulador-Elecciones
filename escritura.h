#ifndef _ESCRITURAH_
#define _ESCRITURAH_
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "estructura.h"

using namespace std;

class Escritura{
		public:
			void escrituraCandidatos(candidato Ncandidato, int clave, int numcandidatos){
				long long id,j,i=0;
				int clave1;				//variable para comparar en la busqueda del candidato
				string sexo;
				string apellido;
			    string nombre;
				string estado;
				string fecha;
				int ciudadn;
				int ciudadr;
				int partido;
				int tipo;
				int vice;
				 
				ifstream archEntrada("archivos/candidatos.txt", ios::in);   //lee el archivo para el modo lectura
				ofstream archsalida1("archivos/temp.txt", ios::out|ios::trunc);    //Crea un archivo para escribirlo
				if (!archEntrada.good())
			    {	cerr << "No se pudo abrir el archivo " << endl;
			    	exit(1);
				}
				if (!archsalida1.good())
			    {	cerr << "No se pudo abrir el archivo " << endl;
			    	exit(1);
				}    
				//se recorre el archivo, y se va sobreescribiendo el temporal                  
				while(!archEntrada.eof()){
					archEntrada>>clave1;
					archEntrada>>nombre;
					archEntrada>>apellido;
					archEntrada>>id;
					archEntrada>>sexo;
					archEntrada>>estado;
					archEntrada>>fecha;
					archEntrada>>ciudadn;
					archEntrada>>ciudadr;
					archEntrada>>partido;
					archEntrada>>tipo;
					archEntrada>>vice;
					//cuando se cumple esta condicion se sobreescriben los datos del anterior candidato por los actuales
					if(clave1 == clave){
						archsalida1<<clave1<<" "<<Ncandidato.nombre<<" "<<Ncandidato.apellido<<" "<<Ncandidato.id<<" "
						<<Ncandidato.sexo<<" "<<Ncandidato.estadoCivil<<" "<<Ncandidato.fechaNac<<" "<<Ncandidato.ciudadNac<<" "
						<<Ncandidato.ciudadRes<<" "<<Ncandidato.partido<<" "<<Ncandidato.tipoCandidato<<" "<<Ncandidato.vicepresidente;			
						
					}else{
						archsalida1<<clave1<<" "<<nombre<<" "<<apellido<<" "<<id<<" "<<sexo<<" "<<estado<<" "<<fecha<<" "<<ciudadn<<" "
							  	  <<ciudadr<<" "<<partido<<" "<<tipo<<" "<<vice;
					
					}
					// i< tamanoarreglo-1  
					if(i<numcandidatos-1){
						archsalida1<<endl;
					}
					i++;				
				}
				archEntrada.close();   
			    archsalida1.close();
			    
			    remove("archivos/candidatos.txt");
			 	rename("archivos/temp.txt", "archivos/candidatos.txt");
			}
			void eliminarCandidato(int clave, int numcandidatos){
				long long id,j,i=0;
				int clave1;				//variable para comparar en la busqueda del candidato
				string sexo;
				string apellido;
			    string nombre;
				string estado;
				string fecha;
				int ciudadn;
				int ciudadr;
				int partido;
				int tipo;
				int vice;
				 
				ifstream archEntrada("archivos/candidatos.txt", ios::in);   //lee el archivo para el modo lectura
				ofstream archsalida1("archivos/temp.txt", ios::out|ios::trunc);    //Crea un archivo para escribirlo
				if (!archEntrada.good())
			    {	cerr << "No se pudo abrir el archivo " << endl;
			    	exit(1);
				}
				if (!archsalida1.good())
			    {	cerr << "No se pudo abrir el archivo " << endl;
			    	exit(1);
				}    
				//se recorre el archivo, y se va sobreescribiendo el temporal                  
				while(!archEntrada.eof()){
					archEntrada>>clave1;
					archEntrada>>nombre;
					archEntrada>>apellido;
					archEntrada>>id;
					archEntrada>>sexo;
					archEntrada>>estado;
					archEntrada>>fecha;
					archEntrada>>ciudadn;
					archEntrada>>ciudadr;
					archEntrada>>partido;
					archEntrada>>tipo;
					archEntrada>>vice;
					//cuando se cumple esta condicion se sobreescriben los datos del anterior candidato por los actuales
					if(clave1 != clave){
						archsalida1<<clave1<<" "<<nombre<<" "<<apellido<<" "<<id<<" "<<sexo<<" "<<estado<<" "<<fecha<<" "<<ciudadn<<" "
							  	  <<ciudadr<<" "<<partido<<" "<<tipo<<" "<<vice;		
						
					}											
					// i< tamanoarreglo-1  
					if(i<numcandidatos-1){
						archsalida1<<endl;
					}
					i++;				
				}
				archEntrada.close();   
			    archsalida1.close();
			    
			    remove("archivos/candidatos.txt");
			 	rename("archivos/temp.txt", "archivos/candidatos.txt");
			}
			void escrituraPartido(string nombre, int clave, int numpartidos){
				int clave1;
				int i=0;
				string nombre1;
				
				ifstream archEntrada("archivos/partidos.txt", ios::in);   //lee el archivo para el modo lectura
				ofstream archsalida1("archivos/temp.txt", ios::out|ios::trunc);    //Crea un archivo para escribirlo
				if (!archEntrada.good())
			    {	cerr << "No se pudo abrir el archivo " << endl;
			    	exit(1);
				}
				if (!archsalida1.good())
			    {	cerr << "No se pudo abrir el archivo " << endl;
			    	exit(1);
				}    
				//se recorre el archivo, y se va sobreescribiendo el temporal                  
				while(!archEntrada.eof()){
					archEntrada>>clave1;
					archEntrada>>nombre1;
					
					//cuando se cumple esta condicion se sobreescriben los datos del anterior candidato por los actuales
					if(clave1 == clave){
						cout<<"nombre: "<<nombre<<endl;
						archsalida1<<clave<<" "<<nombre;			
						
					}else{
						cout<<"nombre1: "<<nombre1<<endl;
						archsalida1<<clave1<<" "<<nombre1;		
					}		
					// i< tamanoarreglo-1  
					if(i<numpartidos-1){
						archsalida1<<endl;
					}	
					i++;
				}
				archEntrada.close();   
			    archsalida1.close();
			    
			    remove("archivos/partidos.txt");
			 	rename("archivos/temp.txt", "archivos/partidos.txt");	 	   				
			}
};
#endif
