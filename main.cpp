#include <iostream>
#include "departamento.h"
#include "partido.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ciudades cities;
	cout<<endl<<"CIUDADES"<<endl;
	for(int i = 1;i<=cities.getCantidad();i++){
		cout<<cities.getCiudad(i).nombre<<" ";
		cout<<cities.getCiudad(i).censo<<endl;
	}

	cout<<endl<<"DEPARTAMENTOS"<<endl;
	departamentos deps(cities.getCiudades());
	for(int i = 1;i<=deps.getTam();i++){
		cout<<deps.getDept(i).nombre <<endl;
		Lista<ciudad> c = deps.mostrarCiudades(i);
		for(int  j= 1;j<= c.getTam();j++){
			cout<<c.devolverDato(j).nombre<<endl;
		}
		cout<<endl;
	}
	

	Lista<candidato> c ;
	
	cout<<endl<<"CANDIDATOS"<<endl;
	candidatos can;
	for(int i = 1;i<=can.getTam();i++){
		cout<<can.getCandidato(i).clave <<" ";
		cout<<can.getCandidato(i).nombre <<" ";
		cout<<can.getCandidato(i).apellido<<endl;
	}
	
	cout<<endl<<"PARTIDOS"<<endl;
	Partido part(can.getCandidatos());
	for(int i = 1;i<part.getTam();i++){
		cout<<part.getPartido(i).nombre <<endl;;
		c = part.consultarC(i);
		for(int j = 1;j<= c.getTam();j++){
			cout<<c.devolverDato(j).clave<<endl;
		}
		cout<<endl;
	}
	
	//ejemplo para modificar candidato 
	candidato cand;
	cand.clave=162;
	cand.nombre="Sebista";
	cand.apellido="Morita";
	cand.estadoCivil="Soltero";
	cand.sexo = "Hombre";
	cand.fechaNac="26/02/99";
	cand.ciudadNac=1;
	cand.ciudadRes= 1;
	cand.id = 1018509802;
	cand.tipoCandidato=1; 
	cand.vicepresidente= 152;
	cand.partido=6;
	
	can.modificarC(cand);
	
	cout<<endl<<"CANDIDATOS"<<endl;
	
	for(int i = 1;i<=can.getTam();i++){
		cout<<can.getCandidato(i).clave <<" ";
		cout<<can.getCandidato(i).nombre <<" ";
		cout<<can.getCandidato(i).apellido<<endl;
	}
	
	//ejemplo para modificar partido
	partido parti;
	parti.clave = 6;
	parti.nombre = "LosHijosDeLosDias";
	
	part.modificarP(parti);
	
	cout<<endl<<"PARTIDOS"<<endl;

	for(int i = 1;i<=part.getTam();i++){
		cout<<part.getPartido(i).nombre <<endl;;
		c = part.consultarC(i);
		for(int j = 1;j<= c.getTam();j++){
			cout<<c.devolverDato(j).clave<<endl;
		}
		cout<<endl;
	}
	
	//ejemplo para modificar ciudad
	ciudad ciu;
	ciu.nombre="Villeta";
	ciu.clave = 2;
	ciu.censo=10000;
	ciu.departamento = 1;
	
	cities.modificarC(ciu);
	cout<<endl<<"CIUDADES"<<endl;
	for(int i = 1;i<=cities.getCantidad();i++){
		cout<<cities.getCiudad(i).nombre<<" ";
		cout<<cities.getCiudad(i).censo<<endl;
	}
	
	cout<<endl<<"DEPARTAMENTOS"<<endl;
	for(int i = 1;i<=deps.getTam();i++){
		cout<<deps.getDept(i).nombre <<endl;
		Lista<ciudad> c = deps.mostrarCiudades(i);
		for(int  j= 1;j<= c.getTam();j++){
			cout<<c.devolverDato(j).nombre<<endl;
		}
		cout<<endl;
	}		
	return 0;
}
