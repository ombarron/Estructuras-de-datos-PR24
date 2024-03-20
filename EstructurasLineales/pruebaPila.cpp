# include <iostream>
# include <string.h>
# include "Pila.h"

using namespace std;

int main()
{
    Pila<int> pila;

    cout << "Ejemplo de manejo de pila"<<endl;

    if (pila.estaVacia())
      cout << "Todavia no le ponemos datos"<<endl;

    for (int i = 1; i < 5; i++)
        pila.mete(i);

   pila.desplegarPila();

   pila.saca();
   cout << pila.tope() <<endl;
   pila.desplegarPila();


 }