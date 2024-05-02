//  Olivia Maricela Barrón Cano
//  Creación: 02/Noviembre/2023
//

#include "NodoGrafo.h"

#ifndef _Grafo
#define _Grafo

// Definición de la clase Grafo

template <typename T>
class Grafo
{ 
    
public:
    bool insertaNodo(T info);
    bool insertaArco(int origen, int destino);
    bool borraVertice(int posicion);
    bool borraArco(int origen, int posicion);
    void recorridoAnchura();
    void recorridoProfundidad();
    void despliegaInformacion();

private:
    ListaEncadenada<NodoGrafo<T>> vertices; 
};

template <class T>
bool Grafo<T>::insertaNodo(T info)
{
    bool bandera;
    NodoGrafo<T> auxiliar(info);

    bandera = vertices.insertarElementoFinal(auxiliar);
    return bandera;

}

template <class T>
bool Grafo<T>::insertaArco(int origen, int destino)
{
    NodoGrafo<T> *auxiliar;
    bool bandera;
    int tamanio;
  

    tamanio = vertices.obtenerTamanio();

    if ((origen <= tamanio) and (destino <= tamanio) and (tamanio != 0))
    {
        auxiliar = vertices.traerDatosPosicion(origen);
        bandera = (auxiliar->adyacencias).insertarElementoFinal(destino);
    }
    else
        bandera = false;

    return bandera;
}

template <class T>
bool Grafo<T>::borraVertice(int posicion)
{
    bool bandera;
    int tamanio;

    tamanio = vertices.obtenerTamanio();
    if (posicion <= tamanio)
    {
        bandera = true;
        vertices.borrarElemento(posicion);
    }
    else
        bandera = false;

    return bandera;
}

template <class T>
bool Grafo<T>::borraArco(int origen, int posicion)
{
    NodoGrafo<T>* auxiliar;
    bool bandera = true;
    int tamanio;

    tamanio = vertices.obtenerTamanio();
    if ((origen <= tamanio) and (posicion <= tamanio) and (tamanio != 0))
    {
        auxiliar = vertices.traerDatosPosicion(origen);
        (auxiliar->adyacencias).borrarElemento(posicion);
    }
    else
        bandera = false;

    return bandera;
}

template <class T>
void Grafo<T>::despliegaInformacion()
{
    NodoGrafo<T>* auxiliar;
    int tamanio;
    int tamAdy;

    tamanio = vertices.obtenerTamanio();
    for (int i=1; i<= tamanio; i++)
    {
        auxiliar = vertices.traerDatosPosicion(i);
        cout << "Informacion del vertice "<<i<<endl;
        cout << auxiliar->informacion<<endl;

        tamAdy = (auxiliar->adyacencias).obtenerTamanio();
        for (int j=1; j<=tamAdy; j++)
        {
            cout << "Arco con vertice no. "<<*((auxiliar->adyacencias).traerDatosPosicion(j))<<endl;
        }
    }
}

template <class T>
void Grafo<T>::recorridoAnchura()
{
    NodoGrafo<T> *auxiliar;
    int tamanio;
    int tamAdy;
    ListaEncadenada<NodoGrafo<T>*> fila;
    NodoGrafo<T> *auxiliar2;
    int indice;

    tamanio = vertices.obtenerTamanio();
    for (int i=1; i<=tamanio; i++)
    {
        auxiliar = vertices.traerDatosPosicion(i);
        auxiliar->estado = 0;
    }
    for (int i=1; i<=tamanio; i++)
    {
         auxiliar = vertices.traerDatosPosicion(i);
         if (auxiliar->estado == 0)
         {
            fila.insertarElementoFinal(auxiliar);
            while (!fila.estaVacia())
            {
                auxiliar = fila.traerInformacionInicio2();
                auxiliar->estado = 2;
                cout << auxiliar->informacion<<" - ";
                tamAdy = (auxiliar->adyacencias).obtenerTamanio();
                for (int j=1; j<=tamAdy; j++)
                {
                    indice = *((auxiliar->adyacencias).traerDatosPosicion(j));
                    auxiliar2 = vertices.traerDatosPosicion(indice);
                    if (auxiliar2->estado == 0)
                    {
                        auxiliar2->estado = 1;
                        fila.insertarElementoFinal(auxiliar2);
                    }
                }
                fila.eliminarElementoInicio();
            }
         }
    }
}

template <class T>
void Grafo<T>::recorridoProfundidad()
{
    NodoGrafo<T> *auxiliar;
    int tamanio;
    int tamAdy;
    ListaEncadenada<NodoGrafo<T>*> pila;
    NodoGrafo<T> *auxiliar2;
    int indice;

    tamanio = vertices.obtenerTamanio();
    for (int i=1; i<=tamanio; i++)
    {
        auxiliar = vertices.traerDatosPosicion(i);
        auxiliar->estado = 0;
    }
    for (int i=1; i<=tamanio; i++)
    {
         auxiliar = vertices.traerDatosPosicion(i);
         if (auxiliar->estado == 0)
         {
            pila.insertarElementoInicio(auxiliar);
            while (!pila.estaVacia())
            {
                auxiliar = pila.traerInformacionInicio2();
                pila.eliminarElementoInicio();
                if (auxiliar->estado == 0)
                {
                    auxiliar->estado = 1;
                    cout << auxiliar->informacion<<" - ";
                    tamAdy = (auxiliar->adyacencias).obtenerTamanio();
                    for (int j=1; j<=tamAdy; j++)
                    {
                        indice = *((auxiliar->adyacencias).traerDatosPosicion(j));
                        auxiliar2 = vertices.traerDatosPosicion(indice);
                        if (auxiliar2->estado == 0)
                        {
                            pila.insertarElementoInicio(auxiliar2);
                        }
                    }
                }
            }
         }
    } 
}


#endif