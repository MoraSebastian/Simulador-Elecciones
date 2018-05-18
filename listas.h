#ifndef _LISTH_
#define _LISTH_
#include <string>
#include <iostream>

using namespace std;
template<class T>
struct Nodo{
	T x;
	Nodo<T> *sig;
};
template<class T>
class Lista{
	Nodo<T> *cab,*fin;
	int tam;
	
	public:
		Lista(){
			cab=fin=NULL;
			tam=0;
		}
		bool estaVacia(){
			if(tam ==0)
				return true;
			else
				return false;
		}
		
		void anadirFin(T a){
			Nodo<T> *b = new Nodo<T>;
			b->x = a;
			b-> sig = NULL;
			if(estaVacia()){
				cab = b;
				fin = b;
			}
			else{
				fin->sig = b;
				fin = b;
			}
			tam++;
		}
		int getTam(){
			return tam;
		}
		void anadirCabeza(T a){
			Nodo<T> *b = new Nodo<T>;
			b->x = a;
			b-> sig = NULL;
			if(estaVacia()){
				cab = b;
				fin = b;
			}
			else{
				b->sig = cab;
				cab=b;
			}
			tam++;
		}
		
		void anadirPos(T a, int Pos){
			Nodo<T> *b = new Nodo<T>;
			b->x = a;
			b-> sig = NULL;
			if(estaVacia()){
				anadirCabeza(a);
			}
			else{
				if(Pos>tam)
					anadirFin(a);
				else{
					Nodo<T> *aux = new Nodo<T>;
					aux=cab;
					for(int i=2;i<Pos;i++){
						aux=aux->sig;
					}
					b->sig=aux->sig;
					aux->sig=b;
					tam++;
				}	
			}
		}
		
		void modificar(T a,int Pos){
			if(estaVacia()){
				anadirCabeza(a);
			}
			else{
				if(Pos>tam)
					anadirFin(a);
				else{
					Nodo<T> *aux = new Nodo<T>;
					aux=cab;
					for(int i=2;i<=Pos;i++){
						aux=aux->sig;
					}
					aux->x=a;
				}	
			}
		}
		
		void eliminarFinal(){
			if(!estaVacia()){
				Nodo<T> *aux = new Nodo<T>;
				aux=cab;
				for(int i=2;i<getTam();i++){
					aux = aux->sig;
				}
				fin = aux;
				aux= aux->sig;
				fin->sig=NULL;
				delete aux;
				tam--;				
			}
		}
		
		void eliminarInicio(){
			if(!estaVacia()){	
				Nodo<T> *aux = new Nodo<T>;							
				aux = cab->sig;
				cab = aux;
				tam--;
			}
		}
		
		void eliminarPos(int pos){
			if(pos>tam || pos==tam){
				eliminarFinal();
			}else{
				Nodo<T> *aux = new Nodo<T>;
				Nodo<T> *temp = new Nodo<T>;
				aux=cab;
				for(int i=2;i<pos;i++){
					aux=aux->sig;
				}
				temp=aux->sig;
				aux->sig=temp->sig;
				delete temp;
				tam--;
			}
						
		}
		
		
		
		T devolverDato(int Pos){
		//	cout<<"hjkl"<<endl;
			int contador = 1;
			Nodo<T> *aux = new Nodo<T>;
			aux = cab;
			while(contador<= Pos){
				if(contador == Pos){
					return aux->x;
				}
				else{
					aux = aux->sig;
					contador++;
				}
			}
		}
		
		void vaciar(){
			while(tam != 0){
				eliminarFinal();
			}
		}
};
#endif
