#include <iostream>
#include "consulta.h"
#include "simulacion.h"
#include "ciudad.h"
#include "string.h"
#include <string>
#include "modificaciones.h"

//Se cargan todos los datos
ciudades cities;
departamentos deps(cities.getCiudades());
candidatos can;
Partido part(can.getCandidatos());
consulta s(part.getPartidos(),deps.getDeps());
simulacion sim(cities.getMun().getTam());
modificacion modificar(can, /*part*/);
bool simulacion = false;

string reemplazar(string str, char original, string reemplazo);
void tarjetonC(Lista<candidato> c);
void tarjetonP(Lista<candidato> c);
void censo(Lista<ciudad> c);
void pais(Lista<departamento> d);
void mostrarCandidato(candidato c);
void mostrarCiudad(ciudad ci);
void menus(int opcion);
void menuCambios(int opcion);
void menuModCand(int opcion);
void menuModificaciones(int opcion);
void menuConsulta(int opcion);
void menuReportes(int opcion);
void menusSimulacion(int opcion);

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

/*Reemplaza el - del nombre por un espacio */
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
/*Tarjeton por ciudad*/
void tarjetonC(Lista<candidato> c){
	cout<<endl<<"0. Voto en Blanco."<<endl;
	int aux = 1;
	for(int i = 1;i<c.getTam();i++){
		
			cout<<aux<<". "<<c.devolverDato(i).nombre<<"  "<<c.devolverDato(i).apellido<<"   "<<reemplazar(s.getNombreP(c.devolverDato(i).partido),'-'," ")<<endl;
			aux++;
		
	}
}
/*Tarjeton para presidencia*/
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
/*Mostrar censos por ciudad*/
void censo(Lista<ciudad> c){
	for(int i = 1;i<= c.getTam();i++){
		cout<<"Ciudad: "<<c.devolverDato(i).nombre<<"  Censo: "<<c.devolverDato(i).censo<<endl;
	}
}
/*Muestra el censo de todo el pais*/
void pais(Lista<departamento> d){
	for(int i = 1;i<= d.getTam();i++){
		cout<<"Departamento "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<"  Censo: "<<s.censoDepartamento(i)<<endl;
	}
}
/*Muestra toda la información importante de un candidato*/
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
/*Muestra información importante de una ciudad*/
void mostrarCiudad(ciudad ci){
	cout<<"Nombre: "<<ci.nombre<<endl;
	cout<<"Departamento: "<<reemplazar(s.getNombreD(ci.departamento),'-'," ")<<endl;
	cout<<"Censo: "<<ci.censo<<endl;	
	cout<<"--------------------------------------------------------"<<endl;
}
/**Menus generales*/
void menus(int opcion){
	switch(opcion){
		case 0:{
			cout<<"Bienvenido a la Registraduria General de la Nacion"<<endl<<endl;
			cout<<"1. Consultar."<<endl;
			cout<<"2. Simular Elecciones."<<endl;
			cout<<"3. Modificar, crear o eliminar registros."<<endl;
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
			menuCambios(0);
			break;
		}
	}
}
/*Menu para los cambios en el registro*/
void menuCambios(int opcion){
	int decision;
	switch(opcion){
		case 0:{
			cout << "1. Modificar registro. " << endl;
			cout << "2. Eliminar registro. " << endl;
			cout << "3. Crear registro." << endl;
			cin >> decision;
			menuCambios(decision);
			break;
		}
		case 1:{
			cout << "1. Modificar informacion de candidato." << endl;
			cout << "2. Modificar informacion de partido." << endl;
			cout << "3. Modificar informacion de ciudad." << endl;
			cout << "4. Modificar informacion de departamento" << endl;
			cin >> decision;
			menuModificaciones(decision);
			break;
		}
		case 2:{
			
			break;
		}
		default:{
	
			break;
		}
	}
}
/*Menu modificaciones candidato*/
void menuModCand(int opcion, candidato auxCand){
	string texto, texto2, texto3;
	int decision;
	switch(opcion){
		case 1:{
			cout << "Nombre actual: " << auxCand.nombre << endl;
			cout << "Escriba el nuevo nombre:" << endl;
			cin >> texto;
			auxCand.nombre = texto;
			break;
		}
		case 2:{
			cout << "Apellido actual: " << auxCand.apellido << endl;
			cout << "Escriba el nuevo apellido:" << endl;
			cin >> texto;
			auxCand.apellido = texto;
			break;
		}
		case 3:{
			cout << "Sexo actual: " << auxCand.sexo << endl;
			cout << "1. Mujer" << endl;
			cout << "2. Hombre" << endl;
			cin >> decision;
			if(decision==1){
				auxCand.sexo = "Mujer";
			} else if(decision==2){
				auxCand.sexo = "Hombre";
			} else {
				cout << "Numero no valido, no se modifico el sexo del candidato" << endl;
			}
			
			break;
		}
		case 4:{
			cout << "Estado Civil actual: " << auxCand.estadoCivil << endl;
			cout << "Escriba el nuevo estado civil:" << endl;
			cin >> texto;
			auxCand.estadoCivil = texto;
			break;
		}
		case 5:{
			cout << "Fecha nacimiento actual: " << auxCand.fechaNac << endl;
			cout << "Escriba el dia de nacimiento (numero)" << endl;
			cin >> texto;
			cout << "Escriba el mes de nacimiento (numero)" << endl;
			cin >> texto2;
			cout << "Escriba el año de nacimiento " << endl;
			cin >> texto3;
			auxCand.fechaNac = texto+"/"+texto2+"/"+texto3;
			break;
		}
		case 6:{
			cout << "Ciudad de nacimiento actual: " << s.nombreCiudad(auxCand.ciudadNac) << endl;
			cout << "Ciudades disponibles: " << endl;
			Lista<ciudad> ciud = cities.getMun();
			for(int i=1; i<=ciud.getTam(); i++){
				cout << i << ". " << ciud.devolverDato(i).nombre << endl;
			} 
			cout << "Escriba el numero de la ciudad" << endl;
			cin >> decision;
			auxCand.ciudadNac;
			break;
		}
		case 7:{
			cout << "Ciudad de residencia actual: " << s.nombreCiudad(auxCand.ciudadRes) << endl;
			cout << "Ciudades disponibles: " << endl;
			Lista<ciudad> ciud = cities.getMun();
			for(int i=1; i<=ciud.getTam(); i++){
				cout << i << ". " << ciud.devolverDato(i).nombre << endl;
			}
			cout << "Escriba el numero de la ciudad" << endl;
			cin >> decision;
			auxCand.ciudadRes;
			break;
		}
		case 8:{
			cout << "Partido actual: " << s.getNombreP(auxCand.partido) << endl << endl; 
			for(int i=1; i<=part.getPartidos().getTam(); i++){
				cout << i << ". " << part.getPartidos().devolverDato(i).nombre << endl;
			}
			cin >> decision;
			auxCand.partido;
			break;
		}
		default:{
			break;
		}
	}
	modificar.modificarCandidato(auxCand);
}
/*Menu modificaciones de registros*/
void menuModificaciones(int opcion){
	string texto;
	int decision;
	switch(opcion){
			case 1:{
			candidato auxCand;
			cout << "Lista de candidatos" << endl;
			Lista <candidato> aux = can.getCandidatos();
			for (int i=1; i<=can.getTam(); i++){
				cout << i << ". " << aux.devolverDato(i).nombre << " " << aux.devolverDato(i).apellido <<  endl;
			}
			cout << "Escriba el numero del candidato el cual desea modificar" << endl;
			cin >> decision;
			system("cls");
			auxCand = can.getCandidato(decision);
			cout << "1. Nombre: " << auxCand.nombre << endl;
			cout << "2. Apellido: " << auxCand.apellido << endl;
			cout << "3. Sexo: " << auxCand.sexo << endl;
			cout << "4. Estado Civil: " << auxCand.estadoCivil << endl;
			cout << "5. Fecha nacimiento: " << auxCand.fechaNac << endl;
			cout << "6. Ciudad de nacimiento: " << s.nombreCiudad(auxCand.ciudadNac) << endl;
			cout << "7. Ciudad de residencia: " << s.nombreCiudad(auxCand.ciudadRes) << endl;
			cout << "8. Partido: " << s.getNombreP(auxCand.partido) << endl << endl;
			cout << "Seleccione el elemento que desea modificar del candidato" << endl;
			cin >> decision;
			menuModCand(decision, auxCand);
			break;
		}
		case 2:{
			cout >> "Lista de partidos: " << endl;
			partido partidito;
			for(int i=1; i<=part.getPartidos().getTam(); i++){
				cout << i << ". " << part.getPartidos().devolverDato(i).nombre << endl;
			}
			cout << "Escriba el numero del partido que desea modificar"<< endl;
			cin >> decision;
			system("cls");
			partidito = part.getPartido(decision);
			cout << "1. Modificar nombre" << endl;
			cout << "2. Anadir un candidato" << endl;
			cin >> decision;
			switch(decision){
				case 1:{
					cout << "Nombre actual: " << partidito.nombre << endl;
					cout << "Escriba el nuevo nombre: (Usar guiones en lugar de espacios) " << emdl;
					cin >> texto;
					partidito.nombre = texto;
					modificar.modificarPartido(partidito);
					break;
				}
				case 2:{
					cout << "Lista de candidatos" << endl;
					Lista <candidato> aux = can.getCandidatos();
					for (int i=1; i<=can.getTam(); i++){
						cout << i << ". " << aux.devolverDato(i).nombre << " " << aux.devolverDato(i).apellido <<  endl;
					}
					cout << "Escriba el numero del candidato el cual desea añadir al nuevo partido" << endl;
					cin >> decision;
					modificar.modificarCandidatosPart(partidito.clave, decision);
					break;
				}
				default:{
					break;
				}
			}
			break;
		}
		case 3:{
			
			break;
		}
		case 4:{
			
			break;
		}
		default:{
			break;
		}
	}
}
/*Menus para consulta*/
void menuConsulta(int opcion){
	int i;
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
			cout <<"10. Mostrar todos los partidos legalmente reconocidos." << endl;
			cin>>decision;
			system("cls");
			menuConsulta(decision);
			break;
		}
		case 1:{
			int departamento;
			cout<<"Que departamento desea consultar?"<<endl;
			for(i =1;i<= deps.getTam();i++){
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
			for(i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin>>departamento;
			cout<<endl<<"Que ciudad desea cosultar?"<<endl;
			Lista<ciudad> cd = deps.mostrarCiudades(departamento);
			for(i = 1;i<=cd.getTam();i++){
				cout<<i<<". "<<cd.devolverDato(i).nombre<<endl;
			}cin>>ci;
			for(i = 1;i<=cd.getTam();i++){
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
			for(i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin>>departamento;
			system("cls");
			cout<<"Que partido desea consultar?"<<endl;
			for(i = 1;i< part.getTam();i++){
				cout<<i<<". "<<reemplazar(part.getNombre(i),'-'," ")<<endl;
			}cin>>p;
			system("cls");
			cout<<"Candidatos a la alcaldia en "<<s.getNombreD(departamento)<<endl;
			cout<<endl;
			Lista<candidato> c = s.consultaDepartamento(p,departamento);
			for(i = 1;i<=c.getTam();i++){
				mostrarCandidato(c.devolverDato(i));
			}
			break;
		}
		case 4:{
			Lista<candidato> c = part.candidatosPresidencia();
			for(i = 1;i<= c.getTam();i++){
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
			for(i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin>>departamento;
			cout<<endl<<"Que ciudad desea cosultar?"<<endl;
			Lista<ciudad> cd = deps.mostrarCiudades(departamento);
			for(i = 1;i<=cd.getTam();i++){
				cout<<i<<". "<<cd.devolverDato(i).nombre<<endl;
			}cin>>ci;
			for(i = 1;i<=cd.getTam();i++){
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
			for(i =1;i<= deps.getTam();i++){
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
			for(i = 1;i<= part.getTam();i++){
				cout<<i<<". "<<reemplazar(part.getNombre(i),'-'," ")<<endl;
			}cin>>p;
			cout<<endl<<"Representante Legal de "<<s.getNombreP(p)<<endl<<endl;
			mostrarCandidato(part.representante(p));
			break;
		}
		case 10:{
			cout << "Partidos legalmente reconocidos" << endl;
			for(i = 1; i<=part.getTam() ; i++){
				cout << i <<". " << reemplazar(part.getNombre(i), '-', " ") << endl;
			}
			break;
		}
	}
} 
/*Menus para reportes*/
void menuReportes(int opcion){
	int decision, i, departamento;
	switch(opcion){
		case 1:{
			cout << "De cual departamento desea ver el reporte general?" << endl;
			for(i = 1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin >> decision;
			votoEst informe = sim.informeGeneralDep(decision);
			cout << "Total votos:" << informe.votos << endl;
			cout << "Votos en blanco:" << informe.votosBlanco << " "<< informe.porcentajeBlanco << "%" << endl;
			cout << "Votos nulos:" << informe.votosNulos << " "<< informe.porcentajeNulos <<"%" << endl;
			cout << "Abstencion:" << informe.votosAbstencion << " "<< informe.porcentajeAbst <<"%" << endl;
			
			break;
		}
		case 2:{
			Lista<candidato> c;
			estadisticas est;
			cout << "De cual departamento desea ver el reporte detallado?" << endl;
			for(i = 1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin >> departamento;
			system("cls");
			for (i = 1; i<= part.getTam(); i++){
				c = s.consultaDepartamento(i,departamento);
				est = sim.reporteDetallado(c);
				if(est.totalCandidatos!=0){
					cout << "Partido: " << s.getNombreP(i) << endl;
					cout << "Cantidad de hombres del partido ganadores para alcalde en el departamento: " << est.cantidadHombres << " "<< est.porcentajeHombres << "%" << endl;
					cout << "Cantidad de mujeres del partido ganadores para alcalde en el departamento: " << est.cantidadMujeres << " "<< est.porcentajeMujeres << "%" << endl;
					cout << "Total candidatos del partido ganadores en el departamento: " << est.totalCandidatos << endl << endl;		
				}		
			}
			break;
			
		}
		case 3:{
			Lista<candidato> c;
			estadisticas est;
			for (i = 1; i<= part.getTam(); i++){
				c = s.consultaNacional(i);
				est = sim.reporteDetallado(c);
				cout << "Partido: " << s.getNombreP(i) << endl;
				cout << "Cantidad de hombres del partido ganadores para alcalde en el departamento: " << est.cantidadHombres << " "<< est.porcentajeHombres << "%" << endl;
				cout << "Cantidad de mujeres del partido ganadores para alcalde en el departamento: " << est.cantidadMujeres << " "<< est.porcentajeMujeres << "%" << endl;
				cout << "Total candidatos del partido ganadores en el departamento: " << est.totalCandidatos <<" " <<  est.porcentajeTotal << "%" <<   endl << endl;				
			}
			break;
		}
		case 4:{
			cout << "De cual departamento desea ver el reporte general?" << endl;
			for(i = 1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin >> decision;
			votoEst informe = sim.reportePresidenciaDep(decision);
			cout << "Estadisticas por departamento." << endl;
			cout << "Total votos:" << informe.votos << endl;
			cout << "Votos en blanco:" << informe.votosBlanco << " "<< informe.porcentajeBlanco << "%" << endl;
			cout << "Votos nulos:" << informe.votosNulos << " "<< informe.porcentajeNulos <<"%" << endl;
			cout << "Abstencion:" << informe.votosAbstencion << " "<< informe.porcentajeAbst <<"%" << endl;
			
			break;
		}
		case 5:{
			votoEst informe = sim.reportePresidenciaGeneral();
			cout << "Informe general elecciones presidenciales" << endl;
			cout << "Total votos:" << informe.votos << endl;
			cout << "Votos en blanco:" << informe.votosBlanco << " "<< informe.porcentajeBlanco << "%" << endl;
			cout << "Votos nulos:" << informe.votosNulos << " "<< informe.porcentajeNulos <<"%" << endl;
			cout << "Abstencion:" << informe.votosAbstencion << " "<< informe.porcentajeAbst <<"%" << endl;
			break;
		}
		case 6:{
			Lista<candidato> c;
			estadisticasP est;
			long long mujeres=0, hombres=0, censoVotos= sim.censoVotos();
			cout << "De cual departamento desea ver el reporte detallado?" << endl;
			for(i = 1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin >> departamento;
			system("cls");
			cout << "censo: " << censoVotos << endl;
			for (i = 1; i<= part.getTam(); i++){
				c = s.consultaPresidenciaPartido(i);
				if(c.getTam()>0){
					est = sim.reporteDetalladoPres(c, departamento);
					cout << "Partido: " << s.getNombreP(i) << endl;
					cout << "Total votos al partido: " << est.totalVotos << " "<< sim.porcentaje(est.totalVotos, censoVotos) << "%" << endl << endl;		
					mujeres+=est.votosPorMujeres;
					hombres+=est.votosPorHombres;		
				}	
			}
			cout << "Total votos hacia mujeres por departamento: " << mujeres << " "<< sim.porcentaje(mujeres, censoVotos) << "%" << endl;
			cout << "Total votos hacia hombres por departamento: " << hombres << " "<< sim.porcentaje(hombres, censoVotos) << "%" << endl;
			break;
		}
		case 7:{
			Lista<candidato> c;
			estadisticasP est;
			long long mujeres=0, hombres=0, censoVotos= sim.censoVotos();
			cout << "censo: " << sim.censoVotos() << endl;
			for (i = 1; i<= part.getTam(); i++){
				c = s.consultaPresidenciaPartido(i);
				if(c.getTam()>0){
					est = sim.reporteDetalladoPresGeneral(c);
					cout << "Partido: " << s.getNombreP(i) << endl;
					cout << "Total votos al partido: " << est.totalVotos << " "<< sim.porcentaje(est.totalVotos, censoVotos) << "%" << endl << endl;
					mujeres+=est.votosPorMujeres;
					hombres+=est.votosPorHombres;				
				}	
			}
			cout << "Total votos hacia mujeres nacional: " << mujeres << " "<< sim.porcentaje(mujeres, censoVotos) << "%" << endl;
			cout << "Total votos hacia hombres nacional: " << hombres << " "<< sim.porcentaje(hombres, censoVotos) << "%" << endl;
			break;
		}
		case 8:{
		Lista <votoP> segV = sim.segundaVuelta();
			if (segV.getTam()!=0){
				cout << "Es necesaria una segunda vuelta presidencial entre los siguientes candidatos: " << endl;
				cout << "Candidato 1: " << segV.devolverDato(1).nombreCand << endl;
				cout << "Candidato 2: " << segV.devolverDato(2).nombreCand << endl;
			} else {
				cout << "No es necesaria una segunda vuelta presidencial" << endl;
				
			}
			break;
			
		}
		default:{break;
		}
	}
}
/*Menus de simulacion*/
void menusSimulacion(int opcion){
	int aux;
	if (!simulacion){														//Se realiza la simulacion para todo el pais
		sim.simularP(cities.getMun(),part.candidatosPresidencia());			//Simulacion de las elecciones presidenciales
		int departamento,ci,aux, i, j, aux2;				
			for(i =1;i<= deps.getTam();i++){								//Simulacion de las eleccions de alcaldia para cada ciudad
				Lista<ciudad> cd = deps.mostrarCiudades(i);
				for (j=1; j<= cd.getTam(); j++){
					aux = cd.devolverDato(j).clave;			
					sim.simularA(s.alcaldia(aux), cd.devolverDato(j).censo, cd.devolverDato(j).nombre, cd.devolverDato(j).departamento);
				}
			}
		simulacion=true;
	}	
	switch(opcion){
		int decision;
		case 0:{
			cout<<"De cual simulacion desea mostrar los resultados?"<<endl;
			cout<<"1. Simulacion presidencial."<<endl;
			cout<<"2. Simulacion elecciones para las alcaldias."<<endl;
			cout<<"3. Reporte elecciones." << endl;
			cin>>decision;
			system("cls");
			menusSimulacion(decision);	
			break;
		}
		case 1:{
			int candidato;
			for(int i = 1;i<=sim.getPresidentes().getTam();i++){
				string nombreV;
				nombreV = s.vice(sim.getPresidentes().devolverDato(i).vice).nombre +" "+ s.vice(sim.getPresidentes().devolverDato(i).vice).apellido;
				cout<<"Presidente: "<<sim.getPresidentes().devolverDato(i).nombreCand<<endl;
				cout<<"Vicepresidente: "<<nombreV<<endl;
				cout<<"-----------------------------------------------------------------------------------------"<<endl;
				for(int j = 1;j<= cities.getMun().getTam();j++){
					cout<<s.nombreCiudad(sim.getPresidentes().devolverDato(i).votoP[j].ciudad)<<"    ";
					cout<<sim.getPresidentes().devolverDato(i).votoP[j].votos<<"   ";
					cout<<sim.getPresidentes().devolverDato(i).votoP[j].porcentaje<<"%"<<endl;
				}
				cout<<"VOTOS TOTALES: "<<sim.getPresidentes().devolverDato(i).votos<<"    "<<sim.getPresidentes().devolverDato(i).porcentaje<<"%"<<endl;
				cout<<"-----------------------------------------------------------------------------------------"<<endl;
			}
			break;
		}
		case 2:{
			int departamento,ci,aux, i, aux2;			
			cout<<"De cual departamento desea ver las ciudades ?"<<endl;
			for(i =1;i<= deps.getTam();i++){
				cout<<i<<". "<<reemplazar(deps.getDeps().devolverDato(i).nombre,'-'," ")<<endl;
			}
			cin>>departamento;
			cout<<endl<<"De cual ciudad desea ver los resultados de la simulacion?"<<endl;
			Lista<ciudad> cd = deps.mostrarCiudades(departamento);
			for(i = 1;i<=cd.getTam();i++){
				cout<<i<<". "<<cd.devolverDato(i).nombre<<endl;
			}cin>>ci;
			i=1;
			while(i!=ci){				
				i++;
			}
			aux = cd.devolverDato(i).clave;			
			Lista <voto> listaCand = sim.getResultAlcaldia(s.nombreCiudad(aux)).resultado;
			for (i=1; i<=listaCand.getTam(); i++){
				cout << i <<". " << listaCand.devolverDato(i).nombreCand << "\t" << listaCand.devolverDato(i).votos << "\t" << listaCand.devolverDato(i).porcentaje << "%"<<endl;
			}		
			break;
		}
		case 3:{
			cout << "1. Reporte general de alcaldias por departamento " << endl;
			cout << "2. Reporte detallado de alcaldias por departamento " << endl;
			cout << "3. Reporte total nacional de alcaldias" << endl;
			cout << "4. Reporte general de presidencia por departamento " << endl;
			cout << "5. Reporte general nacional de presidencia" << endl;
			cout << "6. Reporte detallado de presidencia por departamento " << endl;
			cout << "7. Reporte detallado nacional de presidencia" << endl;
			cout << "8. Consulta segunda vuelta" << endl;
			cin >>decision;
			menuReportes(decision);
			break;
		}
		
	}
}


