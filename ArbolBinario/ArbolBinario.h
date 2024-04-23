//  Olivia Maricela Barrón Cano
//  Creación: 16/abril/2024
//  Última modificación: 16/abril/2024
//
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "NodoArbol.h"

using namespace std;
// Definición de la clase Arbol Binario

template <typename T>
class ArbolBinario
{ 

public:
    ArbolBinario();  
    bool estaVacio();                               // constructor
    void agregarNodo(T valor);
    void agregarNodo(NodoArbol<T>* padre, NodoArbol<T>* nuevoNodo);
    void eliminarNodo(T valor);
    NodoArbol<T>* encontrarPapaNodo(T valor);
    NodoArbol<T>* encontrarPapaNodo(NodoArbol<T>* padre, T valor);
    NodoArbol<T>* encontrarHoja(NodoArbol<T>* padre);
    void recorridoPreOrden();
    void recorridoPreOrden(NodoArbol<T>* padre);
    void recorridoInOrden();
    void recorridoInOrden(NodoArbol<T>* padre);
    void recorridoPostOrden();
    void recorridoPostOrden(NodoArbol<T>* padre);
    void visitaNodo(NodoArbol<T>* nodo);

private:
    NodoArbol<T>* raiz;         // ptr a la raiz del árbol
              
};

template <typename T>
ArbolBinario<T>::ArbolBinario()
{
    raiz = nullptr;

}

template <typename T>
bool ArbolBinario<T>::estaVacio()
{
    return raiz==nullptr;
}

template <typename T>
void ArbolBinario<T>::agregarNodo(T valor)
{
    NodoArbol<T>* nuevoNodo;

    nuevoNodo = new NodoArbol<T>(valor);

    if (raiz == nullptr)
      raiz = nuevoNodo;
    else
       agregarNodo(raiz, nuevoNodo);
}

template <typename T>
void ArbolBinario<T>::agregarNodo(NodoArbol<T> *padre, NodoArbol<T> *nuevoNodo)
{
   int cantidadHijos, valorAleatorio;
   NodoArbol<T> *auxiliar;

   cantidadHijos = padre->traeCantHijos();
   if (cantidadHijos == 0) 
   { padre->guardaHijoIzq(nuevoNodo);
     padre->guardaCantHijos(1);
   }
   else if (cantidadHijos == 1)
   {  auxiliar = padre->traeHijoDer();
      if (auxiliar == nullptr)
        padre->guardaHijoDer(nuevoNodo);
      else
        padre->guardaHijoIzq(nuevoNodo);
      padre->guardaCantHijos(2);
   }
   else
   {  srand (time(0));
      valorAleatorio = rand()%2+1;
      if (valorAleatorio == 1)
        auxiliar = padre->traeHijoDer();
      else
        auxiliar = padre->traeHijoIzq();
      agregarNodo(auxiliar, nuevoNodo);
   }
}

template <typename T>
NodoArbol<T>*  ArbolBinario<T>::encontrarPapaNodo(T valor)
{
    NodoArbol<T> *auxiliar;
    int cantHijos;

    auxiliar = nullptr;
    cantHijos = 0;

    if (raiz != nullptr)
    {
        cantHijos = raiz->traeCantHijos();
        if (cantHijos != 0)
          auxiliar = encontrarPapaNodo(raiz, valor);
    }

    return auxiliar;
}

template <typename T>
NodoArbol<T>*  ArbolBinario<T>::encontrarPapaNodo(NodoArbol<T>* padre, T valor)
{
    NodoArbol<T>* auxiliar;
    int cantHijos;
    NodoArbol<T>* hijo;

    auxiliar = nullptr;
    cantHijos = padre->traeCantHijos();

    switch (cantHijos)
    {
        case 1: hijo = padre->traeHijoDer();
                if (hijo == nullptr)
                    hijo = padre->traeHijoIzq();
                if (hijo->traeInformacion() == valor)
                   auxiliar = padre;
                else
                   auxiliar = encontrarPapaNodo(hijo, valor);
                break;
        case 2: hijo = padre->traeHijoDer();
                if (hijo->traeInformacion() == valor)
                   auxiliar = padre;
                else
                {
                    hijo = padre->traeHijoIzq();
                    if (hijo->traeInformacion() == valor)
                       auxiliar = padre;
                    else
                    {  auxiliar = encontrarPapaNodo(hijo, valor);
                       if (auxiliar = nullptr)
                       {
                        hijo = padre->traeHijoDer();
                        auxiliar = encontrarPapaNodo(hijo, valor);
                       }
                    }
                }
                break;
        default: auxiliar = nullptr;
    }
    return auxiliar;
}

template <typename T>
NodoArbol<T>* ArbolBinario<T>::encontrarHoja(NodoArbol<T>* padre)
{
    NodoArbol<T>* auxiliar;
    int cantidadHijos;

    cantidadHijos = padre->traeCantHijos();
    switch (cantidadHijos)
    { case 0: auxiliar = padre;
              break;
      case 1: if (padre->traeHijoDer()!= nullptr)
                auxiliar = encontrarHoja(padre->traeHijoDer());
              else
                auxiliar = encontrarHoja(padre->traeHijoIzq());
              break;
      case 2: auxiliar = encontrarHoja(padre->traeHijoIzq());
              break;
     default: auxiliar = nullptr;
    }
    return auxiliar;
}

template <typename T>
void ArbolBinario<T>::eliminarNodo(T valor)
{
  NodoArbol<T>* padre;  
  NodoArbol<T>* hoja;
  NodoArbol<T>* hijo;
  NodoArbol<T>* nietoIzq;
  NodoArbol<T>* nietoDer;
  NodoArbol<T>* auxiliar;
  int cantHijos, cantNietos;
  T valorAux;
  bool izquierdo;

  izquierdo = true;
  
  if (raiz != nullptr)
  {
   padre = encontrarPapaNodo(valor);
   if (padre == nullptr)
   {
      if (raiz->traeInformacion()== valor)
      {
         cantHijos = raiz->traeCantHijos();
         if (cantHijos == 0)
         {
            delete(raiz);
            raiz = nullptr;
            
         }
         if (cantHijos == 1)
         {
            auxiliar = raiz->traeHijoDer();
            if (auxiliar == nullptr)
            {
               auxiliar = raiz->traeHijoIzq();
            }
            delete (raiz);
            raiz = auxiliar;
         }
         if (cantHijos == 2)
         {
            hoja = encontrarHoja(raiz);
            valorAux = hoja->traeInformacion();
            padre = encontrarPapaNodo(valorAux);
            cantHijos = padre->traeCantHijos();
            hijo = padre->traeHijoIzq();
            if (hijo!= nullptr and hijo->traeInformacion() == valorAux)
            {
                padre->guardaHijoIzq(nullptr);
            }
            else{
               padre->guardaHijoDer(nullptr);
            }
            delete(hoja);
            raiz->guardaInformacion(valorAux);
            padre->guardaCantHijos(cantHijos-1);
         }
      }
   }
   else{
      cantHijos = padre->traeCantHijos();
      hijo = padre->traeHijoIzq();
      if (hijo==nullptr or hijo->traeInformacion()!=valor)
      {
         hijo = padre->traeHijoDer();
         izquierdo = false;
      }
      cantNietos = hijo->traeCantHijos();
      switch (cantNietos)
      {
         case 0: if (izquierdo)
                   {
                     padre->guardaHijoIzq(nullptr);
                  }
                  else {
                     padre->guardaHijoDer(nullptr);
                  }
                  delete (hijo);
                  padre->guardaCantHijos(cantHijos-1);
             break;
         case 1: nietoIzq = hijo->traeHijoIzq();
                 nietoDer = hijo->traeHijoDer();
                 if (nietoIzq == nullptr)
                 {
                  if (izquierdo)
                  {
                     padre->guardaHijoIzq(nietoDer);
                  }
                  else 
                  {
                     padre->guardaHijoDer(nietoDer);
                  }
                 }
                 else
                 {
                  if (izquierdo)
                  {
                     padre->guardaHijoIzq(nietoIzq);
                  }
                  else
                  {
                     padre->guardaHijoDer(nietoIzq);
                  }
                 }
                 delete(hijo);
               break;
         case 2: hoja = encontrarHoja(hijo);
                 valorAux = hoja->traeInformacion();
                 padre = encontrarPapaNodo(valorAux);
                 hijo->guardaInformacion(valorAux);
                 cantHijos = padre->traeCantHijos();
                 hijo = padre->traeHijoIzq();
                 if (hijo!= nullptr and hijo->traeInformacion() == valorAux)
                 {
                     padre->guardaHijoIzq(nullptr);
                 }
                 else
                 {
                      padre->guardaHijoDer(nullptr);
                 }
                 delete(hoja);
                 padre->guardaCantHijos(cantHijos-1);
               break;           
         default:
               break;
      }
   }
  }
}

template <typename T>
void ArbolBinario<T>::recorridoPreOrden()
{
   recorridoPreOrden(raiz);
   cout << endl;
}

template <typename T>
void ArbolBinario<T>:: recorridoPreOrden(NodoArbol<T>* padre)
{
   if (padre != nullptr)
   {
      visitaNodo(padre);
      recorridoPreOrden(padre->traeHijoIzq());
      recorridoPreOrden(padre->traeHijoDer());
      
   }
}

template <typename T>
void ArbolBinario<T>::recorridoInOrden()
{
  recorridoInOrden(raiz);
  cout << endl;
}

template <typename T>
void ArbolBinario<T>::recorridoInOrden(NodoArbol<T>* padre)
{
   if (padre != nullptr)
   {
      recorridoInOrden(padre->traeHijoIzq());
      visitaNodo(padre);
      recorridoInOrden(padre->traeHijoDer());
      
   }
}

template <typename T>
void ArbolBinario<T>::recorridoPostOrden()
{
   recorridoPostOrden(raiz);
   cout << endl;
}
    
template <typename T>
void ArbolBinario<T>:: recorridoPostOrden(NodoArbol<T>* padre)
{
   if (padre != nullptr)
   {
      recorridoPostOrden(padre->traeHijoIzq());
      recorridoPostOrden(padre->traeHijoDer());
      visitaNodo(padre);
   }

}
    
template <typename T>
void ArbolBinario<T>::visitaNodo(NodoArbol<T>* nodo)
{
   if (nodo != nullptr)
      cout << nodo->traeInformacion() << " ";
}