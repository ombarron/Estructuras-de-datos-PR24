//  Olivia Maricela Barrón Cano
//  Creación: 14/marzo/2024
//  Última modificación: 14/marzo/2024
//

# include "ListaEncadenada.h"
using namespace std;

// Definición de la clase Pila

#ifndef _Pila
#define _Pila

template <typename T>
class Pila
{ 
    public:
        void mete(T valor);
        T saca();
        T tope();
        bool estaVacia();
        void desplegarPila();

    private:
        ListaEncadenada<T> info;
};

template <typename T>
void Pila<T>::mete(T valor)
{
    info.insertarElementoInicio(valor);
}

template <typename T>
T Pila<T>::saca()
{
    return info.eliminarElementoInicio();
}

template <typename T>
T Pila<T>::tope()
{
    return info.traerInformacionInicio();
}

template <typename T>
bool Pila<T>::estaVacia()
{
    return info.estaVacia();
}

template <typename T>
void Pila<T>::desplegarPila()
{
    info.desplegarLista();
}
#endif
