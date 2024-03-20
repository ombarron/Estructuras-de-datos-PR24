# include <iostream>
# include <string.h>
# include "Fila.h"

using namespace std;

int main()
{
    Fila<string> pila;
    string etiqueta;
 
    cout << "Ejemplo de manejo de pila"<<endl;

    if (pila.estaVacia())
      cout << "Todavia no le ponemos datos"<<endl;

    for (int i = 1; i < 5; i++)
     {   
        etiqueta = "Turno "+ to_string(i);
        pila.mete(etiqueta);
     }

    pila.desplegarFila();
    pila.saca();
    pila.desplegarFila();


 }