# include <iostream>  // Librería para utilizar cin y cout
# include <stdlib.h>  // Libreria para poder usar comandos del sistema y funciones de conversion de datos
# include "Grafo.h"

using namespace std; // Para no tener que usar el prefijo std 

int main()
{

    Grafo<char> grafoEjemplo;
    char A = 'A';
    
    for (int i=0; i<10; i++)
    {
        grafoEjemplo.insertaNodo(A+i);
    
    }
   
    grafoEjemplo.insertaArco(1,2);
    grafoEjemplo.insertaArco(1,5);
    grafoEjemplo.insertaArco(1,8);
    grafoEjemplo.insertaArco(2,1);
    grafoEjemplo.insertaArco(2,3);
    grafoEjemplo.insertaArco(2,5);
    grafoEjemplo.insertaArco(3,2);
    grafoEjemplo.insertaArco(3,4);
    grafoEjemplo.insertaArco(3,5);
    grafoEjemplo.insertaArco(3,6);
    grafoEjemplo.insertaArco(4,3);
    grafoEjemplo.insertaArco(5,2);
    grafoEjemplo.insertaArco(5,3);
    grafoEjemplo.insertaArco(5,7);
    grafoEjemplo.insertaArco(5,8);
    grafoEjemplo.insertaArco(6,3);
    grafoEjemplo.insertaArco(6,10);
    grafoEjemplo.insertaArco(7,5);
    grafoEjemplo.insertaArco(7,10);
    grafoEjemplo.insertaArco(8,1);
    grafoEjemplo.insertaArco(8,5);
    grafoEjemplo.insertaArco(8,9);
    grafoEjemplo.insertaArco(8,10);
    grafoEjemplo.insertaArco(9,8);
    grafoEjemplo.insertaArco(10,6);
    grafoEjemplo.insertaArco(10,7);
    grafoEjemplo.insertaArco(10,8);

    grafoEjemplo.despliegaInformacion();

    cout << "Recorrido en Anchura"<<endl;
    grafoEjemplo.recorridoAnchura();
    cout<< endl;
    cout << "Recorrido en Profundidad"<<endl;
    grafoEjemplo.recorridoProfundidad();

    for (int i=0; i<10; i++)
    {
        grafoEjemplo.borraVertice(i+1);
    
    }

return 0;
}
    