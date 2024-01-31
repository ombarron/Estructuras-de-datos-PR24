# include <iostream>
# include <stdlib.h>

using namespace std;

int division (int a, int b)
{
    if ((a-b)<b)
      return 1;
    else
      return 1 + division(a-b,b);
}

int multiplicacion (int a, int b)
{
    if (a == 1)
      return b;
    else
      return b + multiplicacion(a-1,b);
}

int main()
{
    int mul1, mul2, resultado;

    cout << "Dame un numero entero ";
    cin >> mul1;
     cout << "Dame otro numero entero ";
    cin >> mul2;
    resultado = multiplicacion(mul1, mul2);
    cout << mul1 << " multiplicado por "<< mul2 << " = "<<resultado<<endl;

    cout << "Dame un numero entero ";
    cin >> mul1;
     cout << "Dame otro numero entero ";
    cin >> mul2;
    resultado = division(mul1, mul2);
    cout << mul1 << " dividido por "<< mul2 << " = "<<resultado<<endl;


    return 0;
}