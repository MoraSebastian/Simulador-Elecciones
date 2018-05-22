#include <iostream>
#include "consulta.h"
#include "simulacion.h"
#include "ciudad.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Se cargan todos los datos
ciudades cities;
departamentos deps(cities.getCiudades());
candidatos can;
Partido part(can.getCandidatos());
consulta s(part.getPartidos(),deps.getDeps());
simulacion sim;

//Reemplaza el - del nombre por un espacio 
string reemplazar(string str, char original, string reemplazo) {    
		string aux = str;        
	    for (int i = 0; i < (int)aux.length(); ++i) {
	        if(aux[i]==original)
	        {
	            aux.replace(i,1,reemplazo);
	        }
	    }     
	    return aux;
}

//Tarjeton por ciudad
void tarjetonC(Lista<candidato> c){
	cout<<endl<<"0. Voto en Blanco."<<endl;
	int aux = 1;
	for(int i = 1;i<c.getTam();i++){
		
			cout<<aux<<". "<<c.devolverDato(i).nombre<<"  "<<c.devolverDato(i).apellido<<"   "<<reemplazar(s.getNombreP(c.devolverDato(i).partido),'-'," ")<<endl;
			aux++;
		
	}
}

//Tarjeton para presidencia
void tarjetonP(Lista<candidato> c){
	cout<<endl<<"0. Voto en Blanco."<<endl;
	cout<<endl;
	for(int i = 1;i<=c.getTam();i++){
		cout<<i<<". "<<c.devolverDato(i).nombre<<"  "<<c.devolverDato(i).apellido<<endl;
		cout<<"   "<<s.vice(c.devolverDato(i).vicepresidente).nombre<<" "<<s.vice(c.devolverDato(i).vicepresidente).apellido<<endl;
		cout<<"   "<<reemplazar(s.getNombreP(c.devolverDato(i).partido),'-'," ")<<endl;
		cout<<endl;
	}
}
//Mostrar censos
void censo(Lista<ciudad> c){
	for(int i = 1;i<= c.getTam();i++){
		cout<<"Ciudad: "<<c.devolverDato(i).nombre<<"  Censo: "<<c.devolverDato(i).censo<<endl;
	}
}
//Muestra el censo de todo el pais
void pais(Lista<departamento> d){
	for(int i = 1;i<= d.getTam();i++){
		cout<<"Departamento "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<"  Censo: "<<s.censoDepartamento(i)<<endl;
	}
}
//Muestra toda la información importante de un candidato
void mostrarCandidato(candidato c){
	cout<<"Nombre; "<<c.nombre<<" "<<c.apellido<<endl;
	cout<<"Cedula: "<<c. id<<endl;
	cout<<"Sexo: "<<c.sexo<<endl;
	cout<<"Estado Civil: "<<c.estadoCivil<<endl;
	cout<<"Edad: "<<can.edad(c.fechaNac)<<endl;
	cout<<"Ciudad Nacimiento: "<<s.nombreCiudad(c.ciudadNac)<<endl;
	cout<<"Ciudad Residencia: "<<s.nombreCiudad(c.ciudadRes)<<endl;
	cout<<"Partido: "<<reemplazar(s.getNombreP(c.partido),'-'," ")<<endl;
	cout<<"--------------------------------------------------------"<<endl;
}

//Muestra información importante de una ciudad
void mostrarCiudad(ciudad ci){
	cout<<"Nombre: "<<ci.nombre<<endl;
	cout<<"Departamento: "<<reemplazar(s.getNombreD(ci.departamento),'-'," ")<<endl;
	cout<<"Censo: "<<ci.censo<<endl;	
	cout<<"--------------------------------------------------------"<<endl;
}
void menuConsulta(int opcion);
void menusSimulacion(int opcion);

void menus(int opcion){
	switch(opcion){
		case 0:{
			cout<<"Bienvenido a la Registraduria General de la Nacion"<<endl<<endl;
			cout<<"1. Consultar."<<endl;
			cout<<"2. Simular Elecciones."<<endl;
			cout<<"3. Modificar."<<endl;
			cout<<"4. Salir."<< endl;
			break;
		}
		case 1:{
			menuConsulta(0);
			break;
		}
		case 2:{
			menusSimulacion(0);
			break;
		}
		case 3:{
			
			break;
		}
	}
}

void menuConsulta(int opcion){
	switch(opcion){
		case 0:{
			int decision;
			cout<<"CONSULTAS"<<endl;
			cout<<"1. Ciudades de un departamento."<<endl;
			cout<<"2. Candidatos a la alcaldia de una ciudad."<<endl;
			cout<<"3. Candidatos a las alcaldias en un departamento de un partido."<<endl;
			cout<<"4. Formulas presidenciales."<<endl;
			cout<<"5. Tarjetones de una ciudad."<<endl;
			cout<<"6. Tarjeton de la presidendcia."<<endl;
			cout<<"7. Censo de un departamento."<<endl;
			cout<<"8. Censo total del pais."<<endl;
			cout<<"9. Mostrar el representante legal de un partido."<<endl;
			cin>>decision;
			system("cls");
			menuConsulta(decision);
			break;
		}
		case 1:{
			int departamento;
			cout<<"Que departamento desea consultar?"<<endl;
			for(int i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin>>departamento;
			Lista<ciudad> cd = deps.mostrarCiudades(departamento);
			for(int i = 1;i<=cd.getTam();i++){
				mostrarCiudad(cd.devolverDato(i));
				cout<<endl;
			}
			break;
		}
		case 2:{
			int departamento,ci,aux;
			cout<<"Que departamento desea consultar?"<<endl;
			for(int i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin>>departamento;
			cout<<endl<<"Que ciudad desea cosultar?"<<endl;
			Lista<ciudad> cd = deps.mostrarCiudades(departamento);
			for(int i = 1;i<=cd.getTam();i++){
				cout<<i<<". "<<cd.devolverDato(i).nombre<<endl;
			}cin>>ci;
			for(int i = 1;i<=cd.getTam();i++){
				if(i == ci){
					aux = cd.devolverDato(i).clave;
				}
			}
			cout<<endl;
			Lista<candidato> cn = s.alcaldia(aux);
			system("cls");
			cout<<"Candidatos a la alcaldia de: " <<s.nombreCiudad(ci)<<endl;
			cout<<endl;
			for(int i = 1;i<= cn.getTam();i++){
				mostrarCandidato(cn.devolverDato(i));
			}
			break;
		}
		case 3:{
			int departamento, p;
			cout<<"Que departamento desea consultar?"<<endl;
			for(int i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin>>departamento;
			system("cls");
			cout<<"Que partido desea consultar?"<<endl;
			for(int i = 1;i< part.getTam();i++){
				cout<<i<<". "<<reemplazar(part.getNombre(i),'-'," ")<<endl;
			}cin>>p;
			system("cls");
			cout<<"Candidatos a la alcaldia en "<<s.getNombreD(departamento)<<endl;
			cout<<endl;
			Lista<candidato> c = s.consultaDepartamento(p,departamento);
			for(int i = 1;i<=c.getTam();i++){
				mostrarCandidato(c.devolverDato(i));
			}
			break;
		}
		case 4:{
			Lista<candidato> c = part.candidatosPresidencia();
			for(int i = 1;i<= c.getTam();i++){
				cout<<"Partido: "<<reemplazar(s.getNombreP(c.devolverDato(i).partido),'-'," ")<<endl;
				cout<<"Presidente"<<endl;
				mostrarCandidato(c.devolverDato(i));
				candidato aux = s.vice(c.devolverDato(i).vicepresidente);
				cout<<"Vicepresidente"<<endl;
				mostrarCandidato(aux);
				cout<<"--------------------------------------------------------"<<endl;
			}
			break;
		}
		case 5:{
			int departamento,ci,aux;
			cout<<"Que departamento desea consultar?"<<endl;
			for(int i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin>>departamento;
			cout<<endl<<"Que ciudad desea cosultar?"<<endl;
			Lista<ciudad> cd = deps.mostrarCiudades(departamento);
			for(int i = 1;i<=cd.getTam();i++){
				cout<<i<<". "<<cd.devolverDato(i).nombre<<endl;
			}cin>>ci;
			for(int i = 1;i<=cd.getTam();i++){
				if(i == ci){
					aux = cd.devolverDato(i).clave;
				}
			}
			cout<<endl;
			Lista<candidato> cn = s.alcaldia(aux);
			system("cls");
			cout<<"Tarjeton de votacion de "<<s.nombreCiudad(aux)<<endl;
			tarjetonC(cn);
			break;
		}
		case 6:{
			Lista<candidato> c = part.candidatosPresidencia();
			cout<<"Tarjeton Presidencial."<<endl;
			tarjetonP(c);
			break;
		}
		case 7:{
			int departamento, p;
			cout<<"Que departamento desea consultar?"<<endl;
			for(int i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin>>departamento;
			system("cls");
			cout<<"Censo por ciudad de: "<<s.getNombreD(departamento)<<endl;
			Lista<ciudad> c = deps.mostrarCiudades(departamento);
			censo(c);
			cout<<"Censo Total: "<<s.censoDepartamento(departamento)<<endl;
			break;
			break;
		}
		case 8:{
			cout<<"CENSO TOTAL DE COLOMBIA"<<endl;
			pais(deps.getDeps());
			cout<<"Censo total: "<<s.censo()<<endl;
			
			break;
		}
		case 9:{
			int p;
			cout<<"Que partido desea consultar?"<<endl;
			for(int i = 1;i<= part.getTam();i++){
				cout<<i<<". "<<reemplazar(part.getNombre(i),'-'," ")<<endl;
			}cin>>p;
			cout<<endl<<"Representante Legal de "<<s.getNombreP(p)<<endl<<endl;
			mostrarCandidato(part.representante(p));
			break;
		}
	}
}

//Menus de simulacion
void menusSimulacion(int opcion){
	switch(opcion){
		case 0:{
			int decision;
			cout<<"Que simulacion desea realizar?"<<endl;
			cout<<"1. Simulacion presidencial."<<endl;
			cout<<"2. Simulacion elecciones para las alcaldias."<<endl;
			cin>>decision;
			system("cls");
			menusSimulacion(decision);
			break;
		}
		case 1:{
			sim.simularP(part.candidatosPresidencia(),s.censo() );

			break;
		}
		case 2:{								
			int departamento,ci,aux, i, aux2;			
			cout<<"Que departamento ?"<<endl;
			for(i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin>>departamento;
			cout<<endl<<"A que ciudad desea hacer la simulacion?"<<endl;
			Lista<ciudad> cd = deps.mostrarCiudades(departamento);
			for(i = 1;i<=cd.getTam();i++){
				cout<<i<<". "<<cd.devolverDato(i).nombre<<endl;
			}cin>>ci;
			i=1;
			while(i!=ci){				
				i++;
			}
			aux = cd.devolverDato(i).clave;			
			sim.simularA(s.alcaldia(aux), cd.devolverDato(i).censo, cd.devolverDato(i).nombre);							
			break;
		}
	}
}
int main(int argc, char** argv) {
		int decision;
		do{
			menus(0);
			cin>>decision;
			system("cls");
			if(decision != 4){
				menus(decision);
				system("pause");
				system("cls");
			}
		}while(decision!= 4);
		cout<<"!GRACIAS!"<<endl;
	return 0;
}
