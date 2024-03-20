//  Olivia Maricela Barrón Cano
//  Creación: 14/marzo/2024
//  Última modificación: 14/marzo/2024
//

# include "ListaEncadenada.h"
using namespace std;

// Definición de la clase Fila

#ifndef _Fila
#define _Fila

template <typename T>
class Fila
{ 
    public:
        void mete(T valor);
        T saca();
        T siguiente();
        bool estaVacia();
        void desplegarFila();

    private:
        ListaEncadenada<T> info;
};

template <typename T>
void Fila<T>::mete(T valor)
{
    info.insertarElementoFinal(valor);
}

template <typename T>
T Fila<T>::saca()
{
    return info.eliminarElementoInicio();
}

template <typename T>
T Fila<T>::siguiente()
{
    return info.traerInformacionInicio();
}

template <typename T>
bool Fila<T>::estaVacia()
{
    return info.estaVacia();
}

template <typename T>
void Fila<T>::desplegarFila()
{
    info.desplegarLista();
}

#endif
