# include <iostream>
# include <stdlib.h>

using namespace std;

void ordenEvaluacion()
{
  int a = 3, b;

  b = 5/2 + --a;
  cout <<a<<" "<< b << endl;
}

void algo(int m, int n)
{
  cout << n << endl;
}

void ciclo(int a, int b, int &sum, int &count)
{
  for (int i=0; i<a; i=i+2)
  {
    sum += i;
    count++;
  }
}

void ejercicioCiclo()
{
  int s = 3, c = 2;

  cout << "antes del ciclo "<<s<<" "<<c<<endl;
  ciclo(4,3,s,c);
  cout << "despues del ciclo "<<s<<" "<<c<<endl;

}

void ejercicioMatriz()
{
   int a[] = {2,3,4,-1,4,2,1,-1,-9}, b[10][10], c, d, e, f;
   
   e = 0; f = 0; c = 0; d = 0;
   
   while (a[e] != -9)
   {  
    if (a[e] != -1)
      b[f++][c] = a[e++];
    else
    { 
      c++;
      d = f;
      f = 0;
      e++;
    }
   } 
   
   cout << "Renglones "<<d<<", Columnas "<<c<<endl;
   cout << "Matriz"<<endl;
   for(int i= 0; i< d; i++)
   { 
    for (int j=0; j<c;j++)
      cout << b[i][j]<<" ";
    cout << endl;
  }
}

double convertir (double millas)
{
    return millas*1.60934;
}

void ejercicioConvertir()
{ 
  char respuesta;
  double millas, kilometros;
  
  do
  {
    cout << "Cantidad en millas? ";
    cin >> millas;
    kilometros = convertir(millas);
    cout << "Equivalente en kilometros " << kilometros << endl;
    cout << "Otra cantidad?";
    cin >> respuesta;
   } while (respuesta == 's');
   
}

int main()
{
  cout << "Resultado del ejercicio de orden de evaluacion"<<endl;
  ordenEvaluacion();

  cout << "Resultado del ejercicio de algo"<<endl;
  algo(5,3);

  cout << "Resultado del ejercicio del ciclo"<<endl;
  ejercicioCiclo();

  cout << "Resultado del ejericio de la Matriz"<<endl;
  ejercicioMatriz();

  cout << "Resultado del ejercicio de conversion"<<endl;
  ejercicioConvertir();
}

