#ifndef ESTRUCTURA 
#define ESTRUCTURA 
#include <string>
#include "avl.h"


struct candidato{
	string nombre;
	string apellido;
	long long id;
	string sexo;
	string estadoCivil;
	string fechaNac;
	int ciudadNac;
	int ciudadRes;
	int partido;
	int tipoCandidato;
	int vicepresidente;
	int clave;	
};
struct ciudad{
	int clave;
	string nombre;
	int departamento;
	long long censo;
//	int idCabezaCand;		//Es el ultimo candidato que pertenece a la ciudad	
};
struct departamento{
	//El identificador del dept es la posicion en el array
	int clave;
	string nombre;
	Lista<ciudad> municipios;		//Tiene una lista de ciudades
	long long censoPersonas;	//Cantidad de personas que pueden votar en el departamento
};
struct partido{
	int clave;
	string nombre;
	AVL<int> candidatos;
};



#endif

