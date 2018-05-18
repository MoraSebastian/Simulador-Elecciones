#ifndef PILA1_H     
#define PILA1_H    

template<class T>
struct nodo{T dato;
        nodo <T> *sig;
       };
template<class T>
class pila{nodo<T> *cab;
      public: pila(){cab= new nodo<T>;
                     cab->dato=' ';
                     cab->sig=NULL;}
             void Push( T v);
             T Pop();
             T Top();
             bool PilaVacia();
             ~pila();
      };
template<class T>
void pila<T>::Push(T v){
     nodo<T> *t = new nodo<T>;
     t->dato=v; 
     t->sig=cab->sig;
     cab->sig= t;
     }
template<class T>
T pila<T>::Pop(){
     T x;
     nodo<T> *t= cab->sig;
     cab->sig= t->sig; 
     x=t->dato;
     delete t;
     return x;
     }
template<class T>
T pila<T>::Top(){
	T x;
	nodo<T> *t= cab->sig;
	x=t->dato;
	delete t;
	return x;
}
template<class T>
bool pila<T>::PilaVacia(){
      return cab->sig== NULL;
      }
template<class T>
 pila<T>::~pila(){
      nodo<T> *t=cab;
     while (t!=NULL){
           cab=t;
           t=t->sig;
           delete cab;
           }
     }
 
     
#endif
