#ifndef FACADE_H
#define FACADE_H
#include <fstream>
#include <iomanip>
//interfaz (patron de diseño FACADE)
class plantilla{
	protected:
		int cantidad;
		bool leido;
	virtual void leer() = 0; //funcion abstracta
	//virtual void guardar() = 0;
};
#endif
