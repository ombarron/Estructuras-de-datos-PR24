//  Olivia Maricela Barrón Cano
//  Creación: 06/marzo/2024
//  Última modificación: 13/marzo/2024
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
    void insertarElementoInicio(T valor);
    void desplegarLista();
    int obtenerTamanio();
    T eliminarElementoFinal();
    int buscarPosicionElemento(T valor);
    bool estaVacia();
    void insertarElementoFinal(T valor);
    T eliminarElementoInicio();
    T traerInformacionInicio();



private:
    int tamanio;            // tamanio actual de la lista
    Nodo<T>* inicio;          // apuntador al primer elemento de la lista

};

template <typename T>
ListaEncadenada<T>::ListaEncadenada()
{
    inicio = nullptr;
    tamanio = 0;
}

template <typename T>
void ListaEncadenada<T>::insertarElementoInicio(T valor)
{
   Nodo<T>* apuntaNodo;

   apuntaNodo = new Nodo<T>(valor);

   if (tamanio == 0)
      inicio = apuntaNodo;
   else {
      apuntaNodo->guardaSiguiente(inicio);
      inicio = apuntaNodo;
   }

   tamanio = tamanio+1;
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

    if (tamanio == 1)
    {
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
        delete(ultimo);
        auxiliar->guardaSiguiente(nullptr);
        tamanio = tamanio - 1;
         
    }
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
 void ListaEncadenada<T>::insertarElementoFinal(T valor)
 {
    Nodo<T> *auxiliar, *nuevoNodo;

    nuevoNodo = new Nodo<T>(valor);

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


 template <typename T>
 T ListaEncadenada<T>::eliminarElementoInicio()
 {
    Nodo<T>* auxiliar;
    T valor;

    if (tamanio >0)
    {
        auxiliar = inicio;
        inicio = auxiliar->traeSiguiente();
        valor = auxiliar->traeInformacion();
        tamanio = tamanio -1;
        delete (auxiliar);
    }

    return valor;
 }

 template <typename T>
 T ListaEncadenada<T>::traerInformacionInicio()
 {
    T valor;

    if (tamanio > 0)
        valor = inicio->traeInformacion();

    return valor;
 }

 #endif