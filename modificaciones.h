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
#include "ciudad.h"

class modificacion{
	public:
		void modificarCandidato(candidato structCandidato, candidatos cand){	
			cand.modificarC(structCandidato);
		}
		void modificarPartido(partido structPartido, Partido partidito){
			partidito.modificarP(structPartido);
		}
		void modificarCiudad(ciudad c, ciudades ci){
			ci.modificarC(c);
			
		}
		void eliminarCandidato(int structCandidato, candidatos cand){
			cand.eliminarC(cand.getCandidato(structCandidato));
		}

		/*
		void modificarCandidatosPart(int partidote, int cand, Partido partidito, candidatos candi){
			bool yaEsta=false;
			int i=1;
			partido p;
			Lista<candidato> candidatosPartido = partidito.getPartidos().devolverDato(partidote).candidatos;	//Lista de los candidatos del partido
			while(i<=candidatosPartido.getTam() || !yaEsta){		//Verifica que yno este en la lista ya
				if(candidatosPartido.devolverDato(i).clave == cand){
					yaEsta=true;
				}
			}
			if(!yaEsta){	//Si no esta, borra el candidato de el anterior partido y lo añade al nuevo partido;
				partidito.eliminarCandidato(cand, candi.getCandidato(cand).partido);
				p = partidito.getPartido(partidote);
				p.candidatos.anadirFin(candi.getCandidato(cand));
				partidito.modificarP(p);
			}
		}*/
	
};
