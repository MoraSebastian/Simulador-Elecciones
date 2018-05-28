#ifndef ESTRUCTURA 
#define ESTRUCTURA 
#include <string>
#include "avl.h"


struct candidato{
	string nombre;
	string apellido;
	string id;
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
	int habilitada;	
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
	Lista<candidato> candidatos;
};
struct votoPC{
	long long votos;
	float porcentaje;
	int ciudad;
	int departamento;
};

struct votoEst{
	long long votos;
	long long votosBlanco;
	long long votosAbstencion;
	long long votosNulos;
	float porcentajeBlanco;
	float porcentajeAbst;
	float porcentajeNulos;
	int departamento;
};
struct estadisticas{
	int partido;
	int cantidadHombres;
	int cantidadMujeres;
	int totalCandidatos;
	float porcentajeHombres;
	float porcentajeMujeres;
	float porcentajeTotal;	
};
struct estadisticasP{
	int partido;
	long long votosPorHombres;
	long long votosPorMujeres;
	long long totalVotos;
	float porcentajeTotal;	
	float porcentajeHombres;	
	float porcentajeMujeres;	
};

struct voto{
	string nombreCand;
	int partido;
	long long votos;
	float porcentaje;
};

struct votoP{
	string nombreCand;
	int partido;
	int vice;
	long long votos;
	float porcentaje;
	votoPC *votoP;
};

struct resultados{
	string nombreCiudad;
	int departamento;
	int ganador;
	Lista<voto> resultado;
};

#endif

