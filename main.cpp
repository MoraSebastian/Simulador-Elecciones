#include <iostream>
#include "lectura.h"
#include "candidato.h"
#include "partido.h"
#include "ciudad.h"
#include "departamento.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main(int argc, char** argv) {
	
	Lectura lee;
	candidatos can(lee.lecturaCandidatos());
	candidato candi;
	//creo partido
	
//	cout<< lee.lecturaPartido().devolverDato(1).nombre;
	
	cout<<"Prueba para mostrar los candidatos de un partido en este caso 6: "<<endl;	
	
	Partido part(can,lee.lecturaPartido());
	

	Lista<candidato> cani = part.consultarC(6);
	cout<<part.getPartido(6).nombre<<endl;
	cout<<endl;
	
	for(int i = 1; i<= cani.getTam();i++){
		candi = cani.devolverDato(i);
		cout<<"Clave: "<<candi.clave <<endl;
		cout<<"Nombre: "<<candi.nombre<<" "<<candi.apellido<<endl;
		cout<<"CC: "<<candi.id<<endl;
		cout<<"Sexo: "<<candi.sexo<<endl;
		cout<<"Estado: "<<candi.estadoCivil <<endl;
		cout<<"NAcimiento: "<<candi.fechaNac<<endl;
		cout<<"ciudadNac "<<candi.ciudadNac<<endl;
		cout<<"ciudadRes: "<<candi.ciudadRes<<endl;
		cout<<"partido: "<<part.getNombre(candi.partido)<<endl;
		cout<<"Tipo: "<<candi.tipoCandidato <<endl;
		cout<<"Vice: "<<candi.vicepresidente <<endl;
		cout<<"-------------------------------------------------"<<endl;
	}
	
	part.vaciar();            //se vacian las listas
	
	cani = part.candidatosPresidencia();
	cout<<endl<<"Presidencia"<<endl;
	cout<<endl;
	for(int i = 1; i<= cani.getTam();i++){
		candi = cani.devolverDato(i);
		cout<<"Clave: "<<candi.clave <<endl;
		cout<<"Nombre: "<<candi.nombre<<" "<<candi.apellido<<endl;
		cout<<"CC: "<<candi.id<<endl;
		cout<<"Sexo: "<<candi.sexo<<endl;
		cout<<"Estado: "<<candi.estadoCivil <<endl;
		cout<<"NAcimiento: "<<candi.fechaNac<<endl;
		cout<<"ciudadNac "<<candi.ciudadNac<<endl;
		cout<<"ciudadRes: "<<candi.ciudadRes<<endl;
		cout<<"partido: "<<part.getNombre(candi.partido)<<endl;
		cout<<"Tipo: "<<candi.tipoCandidato <<endl;
		cout<<"Vice: "<<candi.vicepresidente <<endl;
		cout<<"-------------------------------------------------"<<endl;
	}
	
	part.vaciar();
	
	cout<<endl<<"Ciudades del archivo: "<<endl;
	ciudades ciu(lee.lecturaCiudad());	
	ciudad* ciud;
	ciud = ciu.getCiudades();
	cout<<"cantidad de ciudades: "<<ciu.getTam()<<endl;
	//vamos a mostrar las ciudades
	for (int i=1; i<=ciu.getTam(); i++){
		cout<<"clave: "<<ciud[i].clave<<" nombre: "<<ciud[i].nombre<<endl;
	}
	
	
	cout<<endl<<"Departamentos del archivo: "<<endl;
	departamentos depa(lee.lecturaDepartamento());
	departamento* depar;
	depar = depa.getArregloDep();
	cout<<"cantidad de departamentos: "<<depa.getTam()<<endl;
	//vamos a mostrar los departamentos
	for (int i=1; i<=depa.getTam(); i++){
		cout<<"clave: "<<depar[i].clave<<" nombre: "<<depar[i].nombre<<endl;
	}
	return 0;
}
