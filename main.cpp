#include <iostream>
#include "consulta.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Se cargan todos los datos
ciudades cities;
departamentos deps(cities.getCiudades());
candidatos can;
Partido part(can.getCandidatos());
consulta s(part.getPartidos(),deps.getDeps());


//Tarjeton por ciudad
void tarjetonC(Lista<candidato> c){
	cout<<endl<<"0. Voto en Blanco."<<endl;
	for(int i = 1;i<c.getTam();i++){
		cout<<i<<". "<<c.devolverDato(i).nombre<<"  "<<c.devolverDato(i).apellido<<"   "<<s.getNombreP(c.devolverDato(i).partido)<<endl;
	}
}

//Tarjeton para presidencia
void tarjetonP(Lista<candidato> c){
	cout<<endl<<"0. Voto en Blanco."<<endl;
	cout<<endl;
	for(int i = 1;i<c.getTam();i++){
		cout<<i<<". "<<c.devolverDato(i).nombre<<"  "<<c.devolverDato(i).apellido<<endl;
		cout<<"   "<<s.vice(c.devolverDato(i).vicepresidente).nombre<<" "<<s.vice(c.devolverDato(i).vicepresidente).apellido<<endl;
		cout<<"   "<<s.getNombreP(c.devolverDato(i).partido)<<endl;
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
		cout<<"Departamento "<<d.devolverDato(i).nombre<<"  Censo: "<<s.censoDepartamento(i)<<endl;
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
	cout<<"Partido: "<<part.getNombre(c.partido)<<endl;
	cout<<"--------------------------------------------------------"<<endl;
}

//Muestra información importante de una ciudad
void mostrarCiudad(ciudad ci){
	cout<<"Nombre: "<<ci.nombre<<endl;
	cout<<"Departamento: "<<s.getNombreD(ci.departamento)<<endl;
	cout<<"Censo: "<<ci.censo<<endl;	
	cout<<"--------------------------------------------------------"<<endl;
}
void menuConsulta(int opcion);
void menus(int opcion){
	switch(opcion){
		case 0:{
			int decision;
			cout<<"Bienvenido a la Registraduria General de la Nacion"<<endl<<endl;
			cout<<"1. Consultar."<<endl;
			cout<<"2. Simular Elecciones."<<endl;
			cin>>decision;
			system("cls");
			menus(decision);
			break;
		}
		case 1:{
			menuConsulta(0);
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
				cout<<i<<". "<<deps.getDeps().devolverDato(i).nombre<<endl;
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
				cout<<i<<". "<<deps.getDeps().devolverDato(i).nombre<<endl;
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
				cout<<i<<". "<<deps.getDeps().devolverDato(i).nombre<<endl;
			}
			cin>>departamento;
			system("cls");
			cout<<"Que partido desea consultar?"<<endl;
			for(int i = 1;i< part.getTam();i++){
				cout<<i<<". "<<part.getPartidos().devolverDato(i).nombre<<endl;
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
				cout<<"Partido: "<<s.getNombreP(c.devolverDato(i).partido)<<endl;
				cout<<"Presidente"<<endl;
				mostrarCandidato(c.devolverDato(i));
				candidato aux = s.vice(c.devolverDato(i).vicepresidente);
				cout<<"Vicepresidente"<<endl;
				mostrarCandidato(aux);
			}
			break;
		}
		case 5:{
			int departamento,ci,aux;
			cout<<"Que departamento desea consultar?"<<endl;
			for(int i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<deps.getDeps().devolverDato(i).nombre<<endl;
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
				cout<<i<<". "<<deps.getDeps().devolverDato(i).nombre<<endl;
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
			for(int i = 1;i< part.getTam();i++){
				cout<<i<<". "<<part.getPartidos().devolverDato(i).nombre<<endl;
			}cin>>p;
			cout<<endl<<"Representante Legal de "<<s.getNombreP(p)<<endl<<endl;
			mostrarCandidato(part.representante(p));
			break;
		}
	}
}
int main(int argc, char** argv) {
	
	
/*	for(int i = 1;i<=cities.getCantidad();i++){
		cout<<cities.getCiudad(i).nombre<<" ";
		cout<<cities.getCiudad(i).censo<<endl;
	}

	cout<<endl<<"DEPARTAMENTOS"<<endl;
*/	
/*	for(int i = 1;i<=deps.getTam();i++){
		cout<<deps.getDept(i).nombre <<endl;
		Lista<ciudad> c = deps.mostrarCiudades(i);
		for(int  j= 1;j<= c.getTam();j++){
			cout<<c.devolverDato(j).nombre<<endl;
		}
		cout<<endl;
	}
	
	cout<<endl<<"CANDIDATOS"<<endl;
*/	
/*	for(int i = 1;i<=can.getTam();i++){
		cout<<can.getCandidato(i).clave <<" ";
		cout<<can.getCandidato(i).nombre <<" ";
		cout<<can.getCandidato(i).apellido<<endl;
	}
	
	cout<<endl<<"PARTIDOS"<<endl;
*/	
/*	for(int i = 1;i<part.getTam();i++){
		cout<<part.getPartido(i).nombre <<endl;;
		Lista<candidato> c = part.consultarC(i);
		for(int j = 1;j<= c.getTam();j++){
			cout<<c.devolverDato(j).clave <<" "<<c.devolverDato(j).ciudadRes<<endl;
		}
		cout<<endl;
	}

	//Consulta de candidatos en un departamento de un partido politico
	Lista<candidato> c = s.consultaDepartamento(3,2);
	cout<<s.getNombreD(3)<<"  "<<s.getNombreP(3)<<endl;
	for(int i =1;i<=c.getTam();i++ ){
		cout<<s.nombreCiudad(c.devolverDato(i).ciudadRes)<<" ";
		cout<<c.devolverDato(i).nombre<<" "<<c.devolverDato(i).apellido<<" ";
		cout<<can.edad(c.devolverDato(i).fechaNac)<<" ";
		cout<<c.devolverDato(i).sexo<<endl;
	}
	cout<<endl;
	
	//Consulta de los candidatos a alcaldía de un partido político 
	c = part.consultarC(6);
	cout<<part.getNombre(6)<<endl;
	for(int i = 1;i<= c.getTam();i++){
		cout<<s.nombreCiudad(c.devolverDato(i).ciudadRes)<<" ";
		cout<<c.devolverDato(i).nombre<<" "<<c.devolverDato(i).apellido<<" ";
		cout<<can.edad(c.devolverDato(i).fechaNac)<<" ";
		cout<<c.devolverDato(i).sexo<<endl;
	}
	cout<<endl;
	
	//Consulta formulas presidenciales
	c = part.candidatosPresidencia();
	
	for(int i =1;i<=c.getTam();i++){
		cout<<"Presidente: ";
		cout<<c.devolverDato(i).nombre<<" "<<c.devolverDato(i).apellido<<" ";
		cout<<can.edad(c.devolverDato(i).fechaNac)<<" ";
		cout<<s.nombreCiudad(c.devolverDato(i).ciudadNac)<<" ";
		cout<<c.devolverDato(i).estadoCivil<<endl;
		candidato cani = s.vice(c.devolverDato(i).vicepresidente,can.getCandidatos());
		cout<<"Vicepresidente: ";
		cout<<cani.nombre<<" "<<cani.apellido<<" ";
		cout<<can.edad(cani.fechaNac)<<" ";
		cout<<s.nombreCiudad(cani.ciudadNac)<<" ";
		cout<<cani.estadoCivil<<endl;
		cout<<endl;
	}
	
	
	//Candidatos a la alcaldia de una ciudad
	c = s.alcaldia(1);
	cout<<"Alcaldia: "<<s.nombreCiudad(1)<<endl;
	for(int i= 1;i< c.getTam();i++){
		cout<<c.devolverDato(i).nombre<<" "<<c.devolverDato(i).apellido<<" ";
		cout<<can.edad(c.devolverDato(i).fechaNac)<<" ";
		cout<<part.getNombre(c.devolverDato(i).partido)<<endl;
	}
	
	//Censo de Antioquia
	cout<<endl<<"Censo: "<<deps.getDept(2).nombre<<" "<<s.censoDepartamento(2)<<endl;
	cout<<"Censo Colombia: "<<s.censo()<<endl;*/
	menus(0);
	return 0;
}
