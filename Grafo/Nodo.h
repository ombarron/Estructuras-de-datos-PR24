//  Olivia Maricela Barrón Cano
//  Creación: 06/marzo/2024
//  Última modificación: 13/marzo/2024
//

// Definición de la clase nodo
#ifndef _Nodo
#define _Nodo

template <typename T>
class Nodo
{ 
    
public:
    Nodo(T valor);                    // constructor
    T* traeInformacion();              // Permite el acceso a la informacion
    T  traeInformacion2();
    Nodo<T>* traeSiguiente();         // Permite el acceso al apuntador al siguiente nodo
    void guardaInformacion(T valor);  // Para poder cambiar la informacion
    void guardaSiguiente(Nodo<T>* sig);    // Para poder cambiar el apuntador al siguiente nodo

private:
    T informacion;                // datos almacenados en este nodo
    Nodo<T>* siguiente;           // ptr a otro objeto del mismo tipo
};

template <typename T>
Nodo<T>::Nodo(T valor) 
{ 
    informacion=valor; 
    siguiente = nullptr;
}; 

template <typename T>
T* Nodo<T>::traeInformacion()
{
    return &informacion;
}

template <typename T>
T Nodo<T>::traeInformacion2()
{
    return informacion;
}

template <typename T>
Nodo<T>* Nodo<T>::traeSiguiente()
{
    return siguiente;
}

template <typename T>
void Nodo<T>::guardaInformacion(T valor)
{
    informacion = valor;
}

template <typename T>
void Nodo<T>::guardaSiguiente(Nodo<T>* sig)
{
    siguiente = sig;
}

#endif