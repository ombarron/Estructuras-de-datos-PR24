//  Olivia Maricela Barrón Cano
//  Creación: 06/marzo/2024
//  Última modificación: 24/marzo/2024
//

# include <iostream>
# include "Nodo.h"

using namespace std;
// Definición de la clase ListaEncadenada

#ifndef _ListaEncadenada
#define _ListaEncadenada

template <typename T>
class ListaEncadenada
{ 
    
public:
    ListaEncadenada();
    bool insertarElementoInicio(T valor);
    bool insertarElementoFinal(T valor);
    T eliminarElementoFinal();
    T eliminarElementoInicio();
    int buscarPosicionElemento(T valor);
    bool estaVacia();
    void desplegarLista();
    int obtenerTamanio();
    T* traerInformacionInicio();
    T traerInformacionInicio2();
    void borrarElemento(int posicion);
    T* traerDatosPosicion(int posicion);
  

private:
    int tamanio;              // tamanio actual de la lista
    Nodo<T>* inicio;          // apuntador al primer elemento de la lista

};

template <typename T>
ListaEncadenada<T>::ListaEncadenada()
{
    inicio = nullptr;
    tamanio = 0;
}

template <typename T>
bool ListaEncadenada<T>::insertarElementoInicio(T valor)
{
   Nodo<T>* apuntaNodo;
   bool bandera;

   apuntaNodo = new Nodo<T>(valor);
   bandera = apuntaNodo != nullptr;

  if (bandera)
  {
    if (tamanio == 0)
          inicio = apuntaNodo;
    else {
          apuntaNodo->guardaSiguiente(inicio);
          inicio = apuntaNodo;
   }

   tamanio = tamanio+1;
  }

}

template <typename T>
void ListaEncadenada<T>::desplegarLista()
{
    Nodo<T>* auxiliar;

    auxiliar = inicio;
    for (int indice = 1; indice<=tamanio;indice++)
    {
        cout << auxiliar->traeInformacion() << " ";
        auxiliar = auxiliar->traeSiguiente();
    }
}

template <typename T>
int ListaEncadenada<T>::obtenerTamanio()
{
    return tamanio;
}

template <typename T>
T ListaEncadenada<T>::eliminarElementoFinal()
{
    Nodo<T> *auxiliar, *ultimo;
    T valor;

    if (tamanio == 1)
    {
        valor = inicio->traeInformacion();
        delete(inicio);
        inicio = nullptr;
        tamanio = 0;
    }
    else if (tamanio >1)
    {
       auxiliar = inicio;
        for (int indice = 1; indice<tamanio-1;indice++)
          auxiliar = auxiliar->traeSiguiente();
        ultimo = auxiliar->traeSiguiente();
        valor = ultimo->traeInformacion();
        delete(ultimo);
        auxiliar->guardaSiguiente(nullptr);
        tamanio = tamanio - 1;     
    }

    return valor;
}

template <typename T>
int ListaEncadenada<T>::buscarPosicionElemento(T valor)
{
    int posicion = 0;
    Nodo<T>* auxiliar = inicio;
    bool bandera = false;

    for(int indice = 1; indice<=tamanio && !bandera; indice++)
    {
        posicion = posicion + 1;
        if (auxiliar->traeInformacion() == valor)
         bandera = true;
        auxiliar = auxiliar->traeSiguiente();
    }

    if (!bandera)
      posicion = 0;

    return posicion;
}

template <typename T>
bool ListaEncadenada<T>::estaVacia()
{
    bool bandera = false;

    if (tamanio == 0)
      bandera = true;

    return bandera;
}

 template <typename T>
 bool ListaEncadenada<T>::insertarElementoFinal(T valor)
 {
    Nodo<T> *auxiliar, *nuevoNodo;
    bool bandera;

    nuevoNodo = new Nodo<T>(valor);
    bandera = nuevoNodo!=nullptr;

    if (bandera)
    {
        if (inicio == nullptr)
        {
            tamanio = 1;
            inicio = nuevoNodo;
        }
        else
        { 
            auxiliar = inicio;
            for (int indice = 1; indice<tamanio;indice++)
                auxiliar = auxiliar->traeSiguiente();
            auxiliar->guardaSiguiente(nuevoNodo);
            tamanio = tamanio+1;
        }
    }

    return bandera;

 }


 template <typename T>
 T ListaEncadenada<T>::eliminarElementoInicio()
 {
    Nodo<T>* auxiliar;
    T valor;

    if (tamanio >0)
    {
        auxiliar = inicio;
        inicio = auxiliar->traeSiguiente();
        valor = *(auxiliar->traeInformacion());
        tamanio = tamanio -1;
        delete (auxiliar);
    }

    return valor;
 }

 template <typename T>
 T* ListaEncadenada<T>::traerInformacionInicio()
 {
    T* valor = nullptr;

    if (tamanio > 0)
        valor = inicio->traeInformacion();

    return valor;
 }

template <typename T>
 T ListaEncadenada<T>::traerInformacionInicio2()
 {
    T valor;

    if (tamanio > 0)
        valor = inicio->traeInformacion2();

    return valor;
 }

template <class T>     
void ListaEncadenada<T>::borrarElemento(int posicion)
{
  Nodo<T>* auxiliar  = inicio;
  Nodo<T>* anterior = nullptr;
  int tamanio = this->tamanio;

  if (posicion == 1)
  {
    inicio = auxiliar->traeSiguiente();
    delete auxiliar;
  }
  else if (posicion <= tamanio)
  {
    for (int i=1; i<posicion; i++)
    {  
        anterior = auxiliar;
        auxiliar = auxiliar->traeSiguiente();
    }
    anterior->guardaSiguiente(auxiliar->traeSiguiente());
    delete auxiliar;
  }     
}


template <class T>     
T* ListaEncadenada<T>::traerDatosPosicion(int posicion)
{
  Nodo<T>* auxiliar  = inicio;
  int tamanio = this->tamanio;

  if (posicion == 1)
    return inicio->traeInformacion();
  else if (posicion <= tamanio)
  {
    for (int i=1; i<posicion; i++)
        auxiliar = auxiliar->traeSiguiente();
    return auxiliar->traeInformacion();

  }
  else
    return nullptr;
      
}

 #endif