//  Olivia Maricela Barrón Cano
//  Creación: 22 de abril de 2024

# include <iostream>
# include <string.h>
# include "ArbolBinario.h"

using namespace std;

int main()
{
    ArbolBinario<int> arbol;
    ArbolBinario<string> arbolDos;
    int valores[10] = {23,12,11,43,15,54,35,40,32,30};
    string val[5] = {"uno","dos","tres","cuatro","cinco"};

   for (int i=0; i<10; i++)
    {
         /*cout << "Dame un numero entero";
        cin >> valores[i]; */
        arbol.agregarNodo(valores[i]);
        if (i<5)
            arbolDos.agregarNodo(val[i]);
    }
    

    cout << "Recorrido preorden" << endl;
    arbol.recorridoPreOrden();

    cout << "Recorrido postorden" << endl;
    arbol.recorridoPostOrden();

    cout << "Recorrido inorden" << endl;
    arbol.recorridoInOrden();

    cout << "Recorrido preorden" << endl;
    arbolDos.recorridoPreOrden();

    cout << "Recorrido postorden" << endl;
    arbolDos.recorridoPostOrden();

    cout << "Recorrido inorden" << endl;
    arbolDos.recorridoInOrden();


    for (int i=0; i<10; i++)
    {

        arbol.eliminarNodo(valores[i]);
        if (i<5)
         arbolDos.eliminarNodo(val[i]);
    }

    return 0;
}