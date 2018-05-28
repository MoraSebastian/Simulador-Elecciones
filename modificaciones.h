//#ifndef MODIFICACIONES
//#define MODIFICACIONES
#include "estructura.h"
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "listas.h"
#include "plantilla.h"
#include "candidato.h"
#include "partido.h"

class modificacion{
	candidatos cand;
	//Partido partidito;
	public:
		modificacion(candidatos candi /*, Partido part*/){	
			cand = candi;
			//partidito = part;
		}
		void modificarCandidato(candidato structCandidato){
			cand.modificarC(structCandidato);
		}
		/*
		void modificarPartido(partido structPartido){
			partidito.modificarP(structPartido);
		}
		
		void modificarCandidatosPart(int partido, int candidato){
			bool yaEsta=false;
			int i=1;
			Lista <candidato> candidatosPartido = partidito.getPartidos().devolverDato(partido).candidatos;
			while(i<=candidatosPartido.getTam() || !yaEsta){
				if(candidatosPartido.devolverDato(i).clave == candidato){
					yaEsta=true;
				}
			}
			if(!yaEsta){
			//	for()
			}
		}*/
	
};
