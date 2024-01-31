# include <iostream>  // Librería para utilizar cin y cout
# include <stdlib.h>  // Libreria para poder usar comandos del sistema y funciones de conversion de datos
# include <vector>

using namespace std; // Para no tener que usar el prefijo std 

// Este programa es un ejemplo de uso de std:vector
// Permite capturar calificaciones, sacar su promedio, y encontrar la calificación más alta
// No declara clases nuevas


void pideCalificaciones(vector<int> &calificaciones)
{  int calificacion, indice = 0;
   char respuesta; 

   calificaciones.clear();

   do
   { cout << "Ingrese la calificacion del alumno "<<indice+1<<endl;
     cin >> calificacion;
     calificaciones.push_back(calificacion);
     indice++;
     cout << "¿Quiere capturar otra calificacion (s/n)?"<<endl;
     cin>> respuesta;
   } while (respuesta == 's');

}

 
double calculaPromedio(vector<int> calificaciones)
{   
   double promedio = 0.0;

   for (auto& calificacion: calificaciones)
     promedio += calificacion;
 
   promedio = promedio / calificaciones.size();
   return promedio;
}

int encontrarMejor(int &mejor, vector<int> calificaciones)
{
    int contador = -1;
    int indice = 0;
    mejor = calificaciones[0];

    for (auto& calificacion: calificaciones)
    {    
        contador++;
        if (calificacion> mejor)
        { mejor = calificacion;
          indice = contador;
         }
    }
    return indice;
}
    
    
// Esta rutina despliega el menu principal
void despliegaMenu()
{
    // Primero limpiamos la pantalla
    system("cls");

    // Desplegamos las opciones
    cout << "      01 Pedir calificaciones      " << endl;
    cout << "      02 Calcular promedio         " << endl;
    cout << "      03 Encontrar mejor           " << endl;
    cout << "      04 Salir del programa        " << endl;
    cout << "                            Opcion ";

}


int main()
{
    // Declaramos variables de entrada
    string opcionStr;
    int opcion, mejor,indice;
    double promedio;
    vector <int> calificaciones;
    

    // Todo el código se va a repetir hasta que el usuario indique que quiere terminar
    do
    {
  
        // Llamamos a la función que dibuja el menu
        despliegaMenu(); 
        //Pedimos la opción al usuario, la capturamos como string para no tener problemas si el usurio se equivoca
        cin >> opcionStr;

        // Cambiamos de string a entero
        opcion = atoi(opcionStr.c_str());

        // Y utilizamos un switch para ejecutar las diferentes opciones
        switch (opcion)
        {
        case 1:
            cout << "Pedir calificaciones"<<endl;
            pideCalificaciones(calificaciones);
            system("pause");
            break;
        case 2:
            cout << "Calcular promedio"<<endl;
            promedio = calculaPromedio(calificaciones);
            if (promedio <0)
                cout << "Hubo un error en la captura de las calificaciones"<< endl;
            else
                cout << "El promedio de las calificaciones es "<<promedio<<endl;
            system("pause");
            break;
        case 3:
            cout << "Encontrar mejor"<<endl;
            indice = encontrarMejor(mejor, calificaciones);
            cout << "El alumno # "<<indice+1<<" obtuvo la mejor calificacion que es "<<mejor<<endl;
            system("pause");
            break;
        case 4:
            cout << "Vamos a salir"<<endl;
            system("pause");
            break;
        default:
            cout << "Por favor da una opcion valida (1, 2, 3 o 4)"<<endl;
            system("pause");
            break;
        }
    } while (opcion != 4);
    
    return 0;
}