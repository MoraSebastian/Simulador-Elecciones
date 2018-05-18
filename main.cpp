#include <iostream>
#include "ciudad.h"
#include "departamento.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ciudades cities;
	for(int i = 1;i<=cities.getCantidad();i++){
		cout<<cities.getCiudad(i).nombre<<" ";
		cout<<cities.getCiudad(i).censo<<endl;
	}
	cout<<endl<<"DEPARTAMENTOS"<<endl;
	departamentos deps;
	for(int i = 1;i<=deps.getTam();i++){
		cout<<deps.getDept(i).nombre <<endl;
	}
	return 0;
}
