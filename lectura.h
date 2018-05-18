#ifndef LECTURA
#define LECTURA

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "estructura.h"
#include "listas.h"

using namespace std;

class Lectura{
		public:
			Lista<candidato> lecturaCandidatos(){
				long long id;
				int clave;
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
				Lista<candidato> candi;     //150  por ciudad, 10 presidenciales, 10 vicepresidenciales
				candidato c;
			 	ifstream archEntrada("archivos/candidatos.txt", ios::in);   //lee el archivo para el modo lectura	 
			
			 	if (!archEntrada.good())    //verifica que el archivo este disponible para abrir
			   		{cerr << "No se pudo abrir el archivo trios" << endl;
			    	exit(1);}                //en caso de no poder abrir se cierra el programa
			    
					 // lectura del archivo y creacion del arreglo   
					while(!archEntrada.eof()){        //mientras haya algo que leer, hagale
					   	archEntrada >> clave;
					    c.clave=clave;
					    archEntrada >> nombre;
					    c.nombre=nombre;
					    archEntrada >> apellido;
					    c.apellido=apellido;
					    archEntrada >> id;
					  	c.id=id;	    
					    archEntrada >> sexo;
					    c.sexo=sexo;
					   	archEntrada >> estado;
					    c.estadoCivil=estado;
					    archEntrada >> fecha;
					    c.fechaNac=fecha;
					    archEntrada >> ciudadn;
					    c.ciudadNac=ciudadn;
					    archEntrada >> ciudadr;
					    c.ciudadRes=ciudadr;
					    archEntrada >> partido;
					    c.partido=partido;
					    archEntrada >> tipo;
					    c.tipoCandidato=tipo;
					    archEntrada >> vice;
					    c.vicepresidente=vice;
					    candi.anadirFin(c);
					}
				   
				archEntrada.close();	
				cout<<"sale de leer candidato"<<endl;
				return candi;
			}
			
			Lista<partido> lecturaPartido(){
				int id;
				string nombre;
				partido p;
				Lista<partido> parti;

				ifstream archEntrada("archivos/partidos.txt", ios::in);   //lee el archivo para el modo lectura
												
			
				if (!archEntrada.good())    //verifica que el archivo este disponible para abrir
				   {cerr << "No se pudo abrir el archivo trios" << endl;
				    exit(1);}                //en caso de no poder abrir se cierra el programa
				    
				//cout<<"que pasa?"<<endl;									    
				 // lectura del archivo y creacion del arreglo   
				while(!archEntrada.eof()){        //mientras haya algo que leer, hagale
				   	archEntrada >> id;
				    p.clave=id;
				    archEntrada >> nombre;
				    p.nombre=nombre;
				    cout<<"clave: "<<p.clave<<"nombre: "<<p.nombre<<endl;
					parti.anadirFin(p);
					
				}
				cout<<"ultimo nombre: "<<nombre<<endl;
				for (int i=1; i<=parti.getTam(); i++){
					cout<<"nombrex2: "<<parti.devolverDato(i).nombre<<endl;
				}
				archEntrada.close();
				cout<<"sale de leer partido"<<endl;
				return parti;
			}
			Lista<ciudad> lecturaCiudad(){
				int id;
				string nombre;
				int dept;
				ciudad c;
				Lista<ciudad> ciudad;

				ifstream archEntrada("archivos/Ciudades.txt", ios::in);   //lee el archivo para el modo lectura												
			
				if (!archEntrada.good())    //verifica que el archivo este disponible para abrir
				   {cerr << "No se pudo abrir el archivo trios" << endl;
				    exit(1);}                //en caso de no poder abrir se cierra el programa
				    
				//cout<<"que pasa?"<<endl;									    
				 // lectura del archivo y creacion del arreglo   
				while(!archEntrada.eof()){        //mientras haya algo que leer, hagale
				   	archEntrada >> id;
				    c.clave=id;
				    archEntrada >> nombre;
				    c.nombre=nombre;
				    archEntrada >> dept;
				    c.departamento = dept;
				    //HACE FALTA LEER EL CENSO 
					ciudad.anadirFin(c);
				//	cout<<"nombre: "<<nombre<<endl;
				}
				
			//	for (int i=1; i<=parti.getTam(); i++){
				//	cout<<"nombrex2: "<<parti.devolverDato(10).nombre<<endl;
			//	}
				archEntrada.close();		 	   
				return ciudad;
			}
			Lista<departamento> lecturaDepartamento(){
				int id;
				string nombre;
				int dept;
				departamento c;
				Lista<departamento> depa;

				ifstream archEntrada("archivos/departamentos.txt", ios::in);   //lee el archivo para el modo lectura												
			
				if (!archEntrada.good())    //verifica que el archivo este disponible para abrir
				   {cerr << "No se pudo abrir el archivo trios" << endl;
				    exit(1);}                //en caso de no poder abrir se cierra el programa
				    
				//cout<<"que pasa?"<<endl;									    
				 // lectura del archivo y creacion del arreglo   
				while(!archEntrada.eof()){        //mientras haya algo que leer, hagale
				   	archEntrada >> id;
				    c.clave=id;
				    archEntrada >> nombre;
				    c.nombre=nombre;
				    cout<<"clave: "<<id<<" nombre: "<<nombre<<endl;
				    //HACE FALTA LEER EL CENSO
					depa.anadirFin(c);
				//	cout<<"nombre: "<<nombre<<endl;
				}
				
				for (int i=1; i<=depa.getTam(); i++){
					cout<<"nombrex2: "<<depa.devolverDato(i).nombre<<endl;
				}
				archEntrada.close();		 	   
				return depa;
			}
};
#endif
