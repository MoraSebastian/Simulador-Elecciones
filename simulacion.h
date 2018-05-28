#include "plantilla.h"
#include <iostream>
#include "estructura.h"
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <sstream>

long long randomi(int max){
	int lim=5+rand()%((8)-5);
	int y=0;
	int x;
	for(int i=1; i<=lim; i++){
		x=1+ rand()%9;
		if(10*y+x>=max){    
			break;
		}			
		y=10*y+x; 
	}
	return y;
}

using namespace std;
class simulacion: public plantilla{
	Lista<resultados> result;
	Lista<votoP> presidentes;
	Lista<voto> alcaldias;
	votoEst votosTotales;
	int cantCiudades = 0;
	int indice=0; 
	int cantcandidatos=0;
	
	public: 
		Lista<votoP> getPresidentes(){
			return presidentes;
		}
		Lista<resultados> getResult(){
			return result;
		}
		//Funciones herdadas de plantilla	
		void leer(){
				int numcandidatos;
				string nombre;
				string apellido;
				int partido;
				long long votos;
				float porcentaje;
				int departamento;
				long long censo;
				int ciudad;
				string nombreCompleto;
				//archivo de entrada
				ifstream archEntrada1("archivos/simulacion/simulation.txt", ios::in);
				ifstream archEntrada2("archivos/simulacion/simulationA.txt", ios::in);
				
				if (!archEntrada1.good()){
					cerr << "No se pudo abrir el archivo ciudades" << endl;
			    	exit(1);
				}
				if (!archEntrada2.good()){
					cerr << "No se pudo abrir el archivo ciudades" << endl;
			    	exit(1);
				}
				
				votoP v;
				
				//se carga la simulacion presidencial anterior
				archEntrada1 >> numcandidatos;
				while(!archEntrada1.eof()){					
					archEntrada1 >> nombre;
					archEntrada1 >> apellido;
					nombreCompleto = nombre +" "+apellido;
					archEntrada1 >> partido;
					archEntrada1 >> votos;
					archEntrada1 >> porcentaje;
					v.nombreCand=nombreCompleto;
					v.partido = partido;
					v.porcentaje = porcentaje;
					v.votos = votos;
					v.votoP = new votoPC[cantCiudades+1];   //supongo y aspiro que esta bien
					for (int i=1 ; i<=numcandidatos; i++){
						archEntrada1>> departamento;
						archEntrada1 >> ciudad;
						archEntrada1>>votos;
						archEntrada1>>porcentaje;
						v.votoP[i-1].ciudad = ciudad;
						v.votoP[i-1].departamento = departamento;
						v.votoP[i-1].porcentaje = porcentaje;
						v.votoP[i-1].votos = votos;
					}
					presidentes.anadirFin(v);
				}
				//se carga la simulacion de las alcaldias anterior
				string city;
				resultados r;
				voto vo;
				while(!archEntrada2.eof()){
					archEntrada2 >> city;
					r.nombreCiudad = city;
					
					for(int i=1; i<=cantCiudades; i++){
						archEntrada2 >> city;
						vo.nombreCand = city;
						archEntrada2 >> partido;
						vo.partido = partido;
						archEntrada2 >> votos;
						vo.votos = votos;
						archEntrada2 >> porcentaje;
						vo.porcentaje = porcentaje;
						r.resultado.anadirFin(vo);
					}
					result.anadirFin(r);
				}
				archEntrada1.close();
				archEntrada2.close();
		}
		void escribir(){
			ofstream archsalida1("archivos/simulacion/temp.txt", ios::out|ios::trunc);    //Crea un archivo para escribirlo
			ofstream archsalida2("archivos/simulacion/temp2.txt", ios::out|ios::trunc);    //Crea un archivo para escribir la cantidad de simulaciones actual
			ofstream archsalida3("archivos/simulacion/temp3.txt", ios::out|ios::trunc);
			if (!archsalida1.good())
		    {	cerr << "No se pudo abrir el archivo " << endl;
		    	exit(1);
			}    
			if (!archsalida2.good())
		    {	cerr << "No se pudo abrir el archivo " << endl;
		    	exit(1);
			}
			if (!archsalida3.good())
		    {	cerr << "No se pudo abrir el archivo " << endl;
		    	exit(1);
			}
			//Se escribe el archivo de la simulación actual     
			archsalida1 << presidentes.getTam()<<endl;
			for(int i=1; i<=presidentes.getTam(); i++){
				archsalida1 << presidentes.devolverDato(i).nombreCand <<" "<< presidentes.devolverDato(i).partido <<" " <<presidentes.devolverDato(i).votos 
				            <<" "<< presidentes.devolverDato(i).porcentaje << endl;
				   
				for(int j=1; j<=cantCiudades; j++){
					archsalida1 << presidentes.devolverDato(i).votoP[j].departamento<<" " << presidentes.devolverDato(i).votoP[j].ciudad 
								<<" "<< presidentes.devolverDato(i).votoP[j].votos <<" "<< presidentes.devolverDato(i).votoP[j].porcentaje;
					if(i<presidentes.getTam() && j<=cantCiudades){
						archsalida1 <<endl;
					} 
					if(i==presidentes.getTam() && j<cantCiudades){
						archsalida1 <<endl;
					}
				}
			}
			//Se escribe el archivo de la cantidad de simulaciones realizadas
			archsalida2 << ++indice;		
			
			//Se escribe el archivo con los resultados para las alcaldias
			for (int i=1; i<=result.getTam(); i++){
				archsalida3 << result.devolverDato(i).nombreCiudad<<endl;
				for (int j=1 ;j<=result.devolverDato(i).resultado.getTam(); j++){
					archsalida3 << result.devolverDato(i).resultado.devolverDato(j).nombreCand<<" " << result.devolverDato(i).resultado.devolverDato(j).partido
								<<" "<< result.devolverDato(i).resultado.devolverDato(j).votos<<" " << result.devolverDato(i).resultado.devolverDato(j).porcentaje;
					if(i<result.getTam() && j<= result.devolverDato(i).resultado.getTam()){
						archsalida3<<endl;
					} 
					if(i==result.getTam() && j<result.devolverDato(i).resultado.getTam()){
						archsalida3 <<endl;
					}
				}
			}
			
			
		    archsalida1.close();
			archsalida2.close();
			archsalida3.close();
			remove("archivos/simulacion/simulation.txt");									
		 	rename("archivos/simulacion/temp.txt", "archivos/simulacion/simulation.txt");
		 	remove("archivos/simulacion/indice.txt");
		 	rename("archivos/simulacion/temp2.txt", "archivos/simulacion/indice.txt");
		 	remove("archivos/simulacion/simulationA.txt");
		 	rename("archivos/simulacion/temp3.txt", "archivos/simulacion/simulationA.txt");
		}
		
		//Constructor
		simulacion(int ciudadesCant){
			cantCiudades=ciudadesCant;			 				
		}	
		resultados getResultAlcaldia(string nombreC){
			int aux=1;
			for (int i=1; i<=result.getTam(); i++){
				if(nombreC.compare(result.devolverDato(i).nombreCiudad)==0){
					aux=i;
				}
			}
			return result.devolverDato(aux);
			
		}			
		//Simula las elecciones presidenciales
		void simularP(Lista<ciudad> c, Lista<candidato> can){
			//guarda el censo del pais
			long long censo = 0;	
			srand(time(0));
			votoP v;
			//LLena la lista de presidentes
			for(int i = 1;i<=can.getTam();i++){
				v.nombreCand = can.devolverDato(i).nombre+" "+can.devolverDato(i).apellido;
				v.partido = can.devolverDato(i).partido;
				v.votos = 0;
				v.porcentaje = 0;
				v.vice = can.devolverDato(i).vicepresidente;
				v.votoP = new votoPC[c.getTam()+1];
				presidentes.anadirFin(v);
			}
			// se agrega espacio para abstinencia
			v.nombreCand = "Abstinencia";
			v.partido = 0;
			v.votos = 0;
			v.porcentaje = 0;
			v.vice = 0;
			v.votoP = new votoPC[c.getTam()+1];
			presidentes.anadirFin(v);
			
			//se agrega los votos en blanco y voto nulo
			v.nombreCand = "Voto en Blanco";
			v.partido = 0;
			v.votos = 0;
			v.porcentaje = 0;
			v.vice = 0;
			v.votoP = new votoPC[c.getTam()+1];
			presidentes.anadirFin(v);
			
			v.nombreCand = "Voto Nulo";
			v.partido = 0;
			v.votos = 0;
			v.porcentaje = 0;
			v.vice = 0;
			v.votoP = new votoPC[c.getTam()+1];
			presidentes.anadirFin(v);
			//Carga el censo total del pais
			for(int i = 1;i<=c.getTam();i++){
				censo+= c.devolverDato(i).censo;
			}	
			//Recorre partidos
			for(int i = 1;i<=c.getTam();i++){
				long long aux = c.devolverDato(i).censo;//Carga el censo de la ciudad
				for(int j = 1;j<=presidentes.getTam();j++){//Recorre los candidatos, para asignar votos
					v = presidentes.devolverDato(j);
					if(j == presidentes.getTam()){//Caso especial para la abstencion 
						v.votos += aux;
						v.votoP[i].votos = aux;
						v.votoP[i].ciudad = c.devolverDato(i).clave;
						v.votoP[i].departamento = c.devolverDato(i).departamento;
						v.votoP[i].porcentaje = porcentaje(aux,c.devolverDato(i).censo);
					}else{
						long long lim =randomi(aux);
						long long temp = lim+ rand()%(aux-lim);
						v.votos += temp;
						v.votoP[i].votos = temp;
						v.votoP[i].ciudad = c.devolverDato(i).clave;
						v.votoP[i].departamento = c.devolverDato(i).departamento;
						aux-= temp;
						v.votoP[i].porcentaje = porcentaje(temp,c.devolverDato(i).censo);
					}
				
				}
			}
			for(int i =1;i<= presidentes.getTam();i++){//aca cargo el porcentaje total de los votos cargados
				v = presidentes.devolverDato(i);
				for(int j = 1;j<= c.getTam();j++){
					v.votos += v.votoP[j].votos;
				}
				v.porcentaje = porcentaje(v.votos,censo);
				presidentes.modificar(v,i);
			}
			ordenar(presidentes);//ordeno la lista de tal manera que el de mayor porcentaje quede de primeras, lo hice con seleccion :3
		}
		
		//Simula las elecciones a la alcaldia de una ciudad
		void simularA(Lista<candidato> c, long long censo, string nombre, int departamento){			
			long long votosfinal=0 ;    //AL FINAL DEBE SER IGUAL AL CENSO
			resultados r;
			long long votosAnt = 0;
			Lista<voto> temp; //Lista con los resultados. la que se devuelve
			long long aux = censo;
			voto v;//Se va a ir llenado con la información de los candidatos
			srand(time(0));
			
			for(int i = 1;i<= c.getTam();i++){
				v.nombreCand = c.devolverDato(i).nombre+" "+c.devolverDato(i).apellido;
				v.partido = c.devolverDato(i).partido;				
				long long lim =randomi(aux);		
				v.votos =lim+ rand()%(aux-lim);				
				votosfinal = votosfinal + v.votos;				
				if(aux-v.votos>=0){
					aux -= v.votos;	
				}else{
					while(!(aux-v.votos>=0)){
						v.votos = lim+ rand()%(aux-lim);
					}					
				}				
				v.porcentaje = porcentaje(v.votos,censo);
				temp = ordenar(v,temp);
				v.porcentaje = porcentaje(v.votos,censo);
				if (votosAnt < v.votos){
						r.ganador = c.devolverDato(i).clave;
						votosAnt = v.votos;
				}
				
			}
			
			v.nombreCand = "Voto en Blanco";
			v.votos = rand()%aux;
			aux -= v.votos;
			votosfinal = votosfinal + v.votos;			
			v.partido = 0;
			v.porcentaje = porcentaje(v.votos,censo);
			temp = ordenar(v,temp);
			
			v.nombreCand = "Votos Nulos";
			v.votos = rand()%aux;
			aux -= v.votos;
			votosfinal = votosfinal + v.votos;			
			v.partido = 0;
			v.porcentaje = porcentaje(v.votos,censo);
			temp = ordenar(v,temp);
			
			v.nombreCand = "Abstinencia";
			v.votos = aux;
			aux -= v.votos;				
			votosfinal = votosfinal + v.votos;			
			v.partido = 0;
			v.porcentaje = porcentaje(v.votos,censo);
			temp = ordenar(v,temp);
			r.nombreCiudad=nombre;
			r.departamento=departamento;
			r.resultado = temp;
			result.anadirFin(r);
		}
		/*Obtiene el porcentaje de los votos originales*/
		float porcentaje(long long dato, long long original){
			return((float)dato*100)/(float)original;
		}
		
		/*Ordena la lista con tal de que siempre el de mayor cantidad de votos quede de primero*/
		Lista<voto> ordenar(voto v, Lista<voto> datos){
			voto aux;
			voto temp = v;
			for(int i = 1;i<= datos.getTam();i++){
				aux = datos.devolverDato(i);
				if(temp.votos>aux.votos){
					datos.modificar(temp,i);
					temp = aux;
				}
			}
			datos.anadirFin(temp);
			return datos;
		}
		
		Lista<votoP> ordenar(Lista<votoP> datos){
			int aux;
			votoP temp;
			for(int i = 1;i< datos.getTam();i++){
				aux = i;
				for(int j = i+1;j<=datos.getTam();j++){
					if(datos.devolverDato(j).votos < datos.devolverDato(i).votos){
						aux = j;
					}
					temp = datos.devolverDato(j);
					datos.modificar(datos.devolverDato(aux),j);
					datos.modificar(temp,aux);
				}
			}
			return datos;
		}
		
		votoEst informeGeneralDep(int departamento){
			votoEst resultadosFinalesDept;
			resultadosFinalesDept.votos = 0;
			resultadosFinalesDept.votosBlanco = 0;
			resultadosFinalesDept.votosAbstencion = 0;
			resultadosFinalesDept.votosNulos = 0;
			resultadosFinalesDept.porcentajeBlanco = 0;
			resultadosFinalesDept.porcentajeAbst = 0;
			resultadosFinalesDept.porcentajeNulos = 0;
			
			for (int i=1; i<=result.getTam(); i++){
				if(departamento==result.devolverDato(i).departamento){
					resultados resCiudad = result.devolverDato(i);
					for(int j=1; j<=resCiudad.resultado.getTam(); j++){
						voto votoCiudad = resCiudad.resultado.devolverDato(j);	
						resultadosFinalesDept.votos = resultadosFinalesDept.votos + votoCiudad.votos;
						if(votoCiudad.nombreCand.compare("Voto en Blanco")==0){
							resultadosFinalesDept.votosBlanco += votoCiudad.votos;
							
						}
						if(votoCiudad.nombreCand.compare("Abstinencia")==0){
							resultadosFinalesDept.votosAbstencion += votoCiudad.votos;
						}
						if(votoCiudad.nombreCand.compare("Votos Nulos")==0){
							resultadosFinalesDept.votosNulos += votoCiudad.votos;
							resultadosFinalesDept.votos = resultadosFinalesDept.votos - votoCiudad.votos;
						}
					}
				}
				resultadosFinalesDept.porcentajeBlanco = porcentaje(resultadosFinalesDept.votosBlanco, resultadosFinalesDept.votos);
				resultadosFinalesDept.porcentajeAbst = porcentaje(resultadosFinalesDept.votosAbstencion, resultadosFinalesDept.votos);
				resultadosFinalesDept.porcentajeNulos = porcentaje(resultadosFinalesDept.votosNulos, resultadosFinalesDept.votos);
			}
			return resultadosFinalesDept;	
		}
		/*Metodo que genera el reporte detallado de un partido, ya sea en un departamento o a nivel nacional*/
		estadisticas reporteDetallado(Lista<candidato> candidatosPartido){
			estadisticas estDepartamento;
			estDepartamento.cantidadHombres = 0;
			estDepartamento.cantidadMujeres = 0;
			estDepartamento.totalCandidatos = 0;
			estDepartamento.porcentajeHombres = 0;
			estDepartamento.porcentajeMujeres = 0;
			estDepartamento.partido = candidatosPartido.devolverDato(1).partido;
			candidato persona;
			for (int i=1; i<=candidatosPartido.getTam(); i++){
				persona = candidatosPartido.devolverDato(i);
				for (int j=1 ; j<=result.getTam(); j++){
					if (result.devolverDato(j).ganador == persona.clave){
						estDepartamento.totalCandidatos+=1;
						if (persona.sexo.compare("Mujer")){
							estDepartamento.cantidadMujeres+=1;
						}
						if(persona.sexo.compare("Hombre")){
							estDepartamento.cantidadHombres+=1;
						}
					}
				}
			}
			estDepartamento.porcentajeHombres = porcentaje(estDepartamento.cantidadHombres, estDepartamento.totalCandidatos);
			estDepartamento.porcentajeMujeres = porcentaje(estDepartamento.cantidadMujeres, estDepartamento.totalCandidatos);
			estDepartamento.porcentajeTotal = porcentaje(estDepartamento.totalCandidatos, 30);									//Esto es solo para el reporte nacional
			return estDepartamento;
		}
		
		votoEst reportePresidenciaDep(int departamento){
			string nombreC;
			votoPC votoAux;
			votoEst votosTotales2;
			votosTotales2.votos = 0;
			votosTotales2.votosBlanco = 0;
			votosTotales2.votosNulos = 0;
			votosTotales2.votosAbstencion = 0;
			votosTotales2.porcentajeBlanco = 0;
			votosTotales2.porcentajeNulos = 0;
			votosTotales2.porcentajeAbst = 0;
			for (int i=1; i<=presidentes.getTam(); i++){
				nombreC = presidentes.devolverDato(i).nombreCand;
				for (int j=1; j<=cantCiudades+1; j++){
					votoAux = presidentes.devolverDato(i).votoP[j];
					if(votoAux.departamento==departamento){
						votosTotales2.votos+=votoAux.votos;
						if(nombreC.compare("Voto en Blanco")==0){
							votosTotales2.votosBlanco+=votoAux.votos;
						}
						if(nombreC.compare("Abstinencia")==0){
							votosTotales2.votosAbstencion+=votoAux.votos;
							votosTotales2.votos-=votoAux.votos;
						}
						if(nombreC.compare("Voto Nulo")==0){
							votosTotales2.votosNulos+=votoAux.votos;
						}	
					}
				}
			}
			votosTotales2.porcentajeBlanco = porcentaje(votosTotales2.votosBlanco, votosTotales2.votos);
			votosTotales2.porcentajeAbst = porcentaje(votosTotales2.votosAbstencion, votosTotales2.votos);
			votosTotales2.porcentajeNulos = porcentaje(votosTotales2.votosNulos, votosTotales2.votos);
	
			return votosTotales2;
		}
		
		votoEst reportePresidenciaGeneral(){
			string nombreC;
			votosTotales.votos = 0;
			votosTotales.votosBlanco = 0;
			votosTotales.votosNulos = 0;
			votosTotales.votosAbstencion = 0;
			votosTotales.porcentajeBlanco = 0;
			votosTotales.porcentajeNulos = 0;
			votosTotales.porcentajeAbst = 0;
			votosTotales.departamento = 0;
			for(int i=1; i<=presidentes.getTam(); i++){
				nombreC = presidentes.devolverDato(i).nombreCand;
				votosTotales.votos+=presidentes.devolverDato(i).votos;
				if(nombreC.compare("Abstinencia")==0){
					votosTotales.votosAbstencion+=presidentes.devolverDato(i).votos;
					votosTotales.votos-=votosTotales.votosAbstencion;
				}
				if(nombreC.compare("Voto en Blanco")==0){
					votosTotales.votosBlanco+=presidentes.devolverDato(i).votos;
				}
				if(nombreC.compare("Voto Nulo")==0){
					votosTotales.votosNulos+=presidentes.devolverDato(i).votos;
				}
			}
			votosTotales.porcentajeBlanco = porcentaje(votosTotales.votosBlanco, votosTotales.votos);
			votosTotales.porcentajeAbst = porcentaje(votosTotales.votosAbstencion, votosTotales.votos);
			votosTotales.porcentajeNulos = porcentaje(votosTotales.votosNulos, votosTotales.votos);
			
			return votosTotales;
		}
		
		
		Lista <votoP> segundaVuelta(){
			int i=1;
			Lista <votoP> candSeg;
			votosTotales = reportePresidenciaGeneral();
			long long auxCant = abs((votosTotales.votos/2)+1);
			bool segundVuelta = true;
			while(i<= presidentes.getTam() && segundVuelta == true){
				if(presidentes.devolverDato(i).votos>=auxCant && (presidentes.devolverDato(i).nombreCand).compare("Abstinencia")==1 
					&& (presidentes.devolverDato(i).nombreCand).compare("Voto en Blanco")==1 && (presidentes.devolverDato(i).nombreCand).compare("Voto Nulo")==1 ){
					segundVuelta = false;
				}	
				i++;
			}
			if(segundVuelta){
				candSeg.anadirFin(presidentes.devolverDato(1));
				candSeg.anadirFin(presidentes.devolverDato(2));
			}
			return candSeg;
		}
		
		estadisticasP reporteDetalladoPres(Lista<candidato> candPresidentesPart, int departamento){
			estadisticasP informe;
			votoPC auxVotos;
			string nombreComp;
			informe.partido = candPresidentesPart.devolverDato(1).partido;
			informe.totalVotos = 0;
			informe.votosPorHombres = 0;
			informe.votosPorMujeres = 0;
			
			for(int i=1; i<=candPresidentesPart.getTam(); i++){
				for (int j=1; j<=presidentes.getTam(); j++){
					nombreComp = candPresidentesPart.devolverDato(i).nombre + " " + candPresidentesPart.devolverDato(i).apellido;
					if(nombreComp.compare(presidentes.devolverDato(j).nombreCand)==0){	
						for (int k=1; k<=cantCiudades+1 ; k++){
							auxVotos = presidentes.devolverDato(j).votoP[k];
							if(auxVotos.departamento == departamento){
							//	cout << "contador " << auxVotos.votos; 
								if((candPresidentesPart.devolverDato(i).sexo).compare("Mujer")==0){
									informe.votosPorMujeres+=auxVotos.votos;
								} 
								if((candPresidentesPart.devolverDato(i).sexo).compare("Hombre")==0){
									informe.votosPorHombres+=auxVotos.votos;
								}
								informe.totalVotos+=auxVotos.votos;
	
							}
						}
					}
				}			
			}
			return informe;
		}
		estadisticasP reporteDetalladoPresGeneral(Lista<candidato> candPresidentesPart){
			estadisticasP informe;
			votoPC auxVotos;
			string nombreComp;
			informe.partido = candPresidentesPart.devolverDato(1).partido;
			informe.totalVotos = 0;
			informe.votosPorHombres = 0;
			informe.votosPorMujeres = 0;
			informe.porcentajeHombres = 0;
			informe.porcentajeMujeres = 0;
			
			for(int i=1; i<=candPresidentesPart.getTam(); i++){
				for(int j=1; j<=presidentes.getTam(); j++){
					nombreComp = candPresidentesPart.devolverDato(i).nombre + " " + candPresidentesPart.devolverDato(i).apellido;
					if(nombreComp.compare(presidentes.devolverDato(j).nombreCand)==0){	
						for (int k=1; k<=cantCiudades ; k++){
								auxVotos = presidentes.devolverDato(j).votoP[k];
								if((candPresidentesPart.devolverDato(i).sexo).compare("Mujer")==0){
								//	cout << "entra M" << endl;
									informe.votosPorMujeres+=auxVotos.votos;
								} 
								if((candPresidentesPart.devolverDato(i).sexo).compare("Hombre")==0){
								//	cout << "entra H" << endl;
									informe.votosPorHombres+=auxVotos.votos;
								}
								informe.totalVotos+=auxVotos.votos;
						}
					}
				}
				//informe.porcentajeHombres = porcentaje(informe.votosPorHombres, censoVotos());			
				//informe.porcentajeMujeres = porcentaje(informe.votosPorMujeres, censoVotos());
				//informe.porcentajeTotal = porcentaje(informe.totalVotos, censoVotos());
			}
			return informe;
		}
		long long censoVotos(){
			long long totalVotosC;
			for(int l=1; l<=presidentes.getTam(); l++){
				if(presidentes.devolverDato(l).nombreCand.compare("Abstinencia")==1){
					totalVotosC+=presidentes.devolverDato(l).votos;
				}
			}
			return totalVotosC;
		}
};

