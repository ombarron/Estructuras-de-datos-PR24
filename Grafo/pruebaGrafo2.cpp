# include <iostream>  // Librería para utilizar cin y cout
# include <stdlib.h>  // Libreria para poder usar comandos del sistema y funciones de conversion de datos
# include "Grafo.h"

using namespace std; // Para no tener que usar el prefijo std 

int main()
{

    Grafo<string> grafoEjemplo;

    grafoEjemplo.insertaNodo("Monterrey");
    grafoEjemplo.insertaNodo("Saltillo");
    grafoEjemplo.insertaNodo("Torreón");
   
    grafoEjemplo.insertaArco(1,2);
    grafoEjemplo.insertaArco(1,3);
    grafoEjemplo.insertaArco(2,1);
    grafoEjemplo.insertaArco(2,3);
    grafoEjemplo.insertaArco(3,1);
    grafoEjemplo.insertaArco(3,2);
   

    grafoEjemplo.recorridoAnchura();
    cout<< endl;
    grafoEjemplo.recorridoProfundidad();

    for (int i=0; i<3; i++)
    {
        grafoEjemplo.borraVertice(i+1);
    
    }

return 0;
}
    