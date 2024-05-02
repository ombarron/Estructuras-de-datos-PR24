//  Olivia Maricela Barrón Cano
//  Creación: 24/Abril/2024
//

#include "ListaEncadenada.h"

#ifndef _NodoGrafo
#define _NodoGrafo

// Definición de la clase NodoGrafo
// Para que reconozca que la clase amiga usa template
template <typename T> class Grafo;

template <typename T>
class NodoGrafo
{ 
    friend class Grafo<T>; // clase amiga para poder acceder directo a los atributos

    
public:
    NodoGrafo(T e);                   // constructor con informacion
    NodoGrafo();                      // constructor sin informacion
    bool insertaEnLista(int valor);


private:
    T informacion;                  // datos almacenados en este  vertice
    ListaEncadenada<int> adyacencias; 
    int estado;
};

template <class T>
NodoGrafo<T>::NodoGrafo() 
{ 
    estado = 0;
}; 

template <class T>
NodoGrafo<T>::NodoGrafo(T e) 
{ 
    informacion = e; 
    estado = 0;
}; 

template <class T>
bool NodoGrafo<T>::insertaEnLista(int valor)
{
  return adyacencias.insertarElementoFinal(valor);
}

#endif