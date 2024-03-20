# include <iostream>
# include <string.h>
# include "ListaEncadenada.h"

using namespace std;

int main()
{
    ListaEncadenada<int> lista;
    ListaEncadenada<string> etiquetas;
    int tamanio, posicion;

    cout << "Ejemplo de manejo de lista encadenada"<<endl;

    if (lista.estaVacia())
      cout << "Todavia no le ponemos datos"<<endl;

    lista.desplegarLista();
    etiquetas.desplegarLista();

    for (int i = 1; i < 5; i++)
    {
       lista.insertarElementoInicio(i*10);
       etiquetas.insertarElementoInicio("Elemento "+ to_string(i));
       etiquetas.desplegarLista();
       cout<<" - ";
       lista.desplegarLista();
       cout << endl;
       
    }
    tamanio = lista.obtenerTamanio();
    cout << "El tamanio de la lista es "<<tamanio<<endl;
    lista.eliminarElementoFinal();
    lista.desplegarLista();
    cout << endl;
    tamanio = lista.obtenerTamanio();
    cout << "El tamanio de la lista es "<<tamanio<<endl;
    posicion = lista.buscarPosicionElemento(10);
    if (posicion > 0) 
       cout << "La posicion del elemento 10 en la lista es " << posicion <<endl;
   else 
       cout << "El elemento 10 no se encuentra en la lista"<<endl;
    return 0;
 }