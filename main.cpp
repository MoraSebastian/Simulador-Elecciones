#include <iostream>
#include "simulacion.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ciudades cities;
/*	for(int i = 1;i<=cities.getCantidad();i++){
		cout<<cities.getCiudad(i).nombre<<" ";
		cout<<cities.getCiudad(i).censo<<endl;
	}

	cout<<endl<<"DEPARTAMENTOS"<<endl;
*/	departamentos deps(cities.getCiudades());
/*	for(int i = 1;i<=deps.getTam();i++){
		cout<<deps.getDept(i).nombre <<endl;
		Lista<ciudad> c = deps.mostrarCiudades(i);
		for(int  j= 1;j<= c.getTam();j++){
			cout<<c.devolverDato(j).nombre<<endl;
		}
		cout<<endl;
	}
	
	cout<<endl<<"CANDIDATOS"<<endl;
*/	candidatos can;
/*	for(int i = 1;i<=can.getTam();i++){
		cout<<can.getCandidato(i).clave <<" ";
		cout<<can.getCandidato(i).nombre <<" ";
		cout<<can.getCandidato(i).apellido<<endl;
	}
	
	cout<<endl<<"PARTIDOS"<<endl;
*/	Partido part(can.getCandidatos());
/*	for(int i = 1;i<part.getTam();i++){
		cout<<part.getPartido(i).nombre <<endl;;
		Lista<candidato> c = part.consultarC(i);
		for(int j = 1;j<= c.getTam();j++){
			cout<<c.devolverDato(j).clave <<" "<<c.devolverDato(j).ciudadRes<<endl;
		}
		cout<<endl;
	}
*/
	//Consulta de candidatos en un departamento de un partido politico
	simulacion s(part.getPartidos(),deps.getDeps());
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
	cout<<"Censo Colombia: "<<s.censo()<<endl;;
	return 0;
}
