//  Olivia Maricela Barrón Cano
//  Creación: 16/abril/2024
//  Última modificación: 16/abril/2024
//

// Definición de la clase nodoArbol

template <typename T>
class NodoArbol
{ 

public:
    NodoArbol(T valor);            // constructor
    void guardaInformacion(T valor);
    void guardaHijoIzq(NodoArbol<T>* hizq);
    void guardaHijoDer(NodoArbol<T>* hder);
    void guardaCantHijos(int cuantos);
    T traeInformacion();
    NodoArbol<T>* traeHijoIzq();
    NodoArbol<T>* traeHijoDer();
    int traeCantHijos();


private:
    T informacion;             // datos almacenados en este NodoArbol
    NodoArbol<T>* izq;         // ptr al hijo izquierdo
    NodoArbol<T>* der;         // ptr al hijo derecho
    int numHijos;              // cantidad de hijos
};

template <class T>
NodoArbol<T>::NodoArbol(T valor) 
{ 
    informacion=valor; 
    izq = nullptr;
    der = nullptr;
    numHijos = 0;
}; 

template <class T>
void NodoArbol<T>::guardaInformacion(T valor)
{
    informacion = valor;
}
    
template <class T>
void NodoArbol<T>::guardaHijoIzq(NodoArbol* hizq)
{
    izq = hizq;
}
    
template <class T>
void NodoArbol<T>::guardaHijoDer(NodoArbol* hder)
{
    der = hder;
}
   
template <class T>
void NodoArbol<T>::guardaCantHijos(int cuantos)
{
  numHijos = cuantos;
}

template <class T>
 T NodoArbol<T>::traeInformacion()
 {
    return informacion;
 }
    
template <class T>
NodoArbol<T>* NodoArbol<T>::traeHijoIzq()
{
    return izq;
}
   
template <class T>
 NodoArbol<T>* NodoArbol<T>::traeHijoDer()
 {
    return der;
 }

 template <class T>
 int NodoArbol<T>::traeCantHijos()
 {
    return numHijos;
 }