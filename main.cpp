#include <iostream>
#include "departamento.h"
#include "partido.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ciudades cities;
/*	for(int i = 1;i<=cities.getCantidad();i++){
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
*/	
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
		Lista<candidato> c = part.consultarC(i);
		for(int j = 1;j<= c.getTam();j++){
			cout<<c.devolverDato(j).clave<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}
