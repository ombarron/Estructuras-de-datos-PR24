# include <iostream>
using namespace std;

int valorDisperso(string llave, int tamanio)
{
    int valor = 0;
    int longitudCadena = 0;

    longitudCadena = llave.length();

    for(int i=0; i<longitudCadena; i++)
    {
        valor = valor + llave[i];
    }

    valor = valor % tamanio;

    return valor;
}

string codifica(string llave, int tamanio)
{
    string nuevo = "";

    int valor = 0;
    int longitudCadena = 0;

    longitudCadena = llave.length();
    valor = valorDisperso(llave, tamanio);

    for(int i=0; i<longitudCadena; i++)
    {
        nuevo = nuevo + char(llave[i] + valor);
    }

    return nuevo;
}

string decodifica(string texto, int tamanio, int valorDisperso)
{
    string nuevo = "";
    int longitudCadena = 0;

    longitudCadena = texto.length();


    for(int i=0; i<longitudCadena; i++)
    {
        nuevo = nuevo + char (texto[i]-valorDisperso);
    }

    return nuevo;
}

int main()
{
    string llave = "", llaveCodificada = "", llaveReconstruida = "";
    int tamanio = 0;
    int valorD = 0;
    char respuesta = 'S';

    while (respuesta == 'S')
    {
        cout << "Dame una llave a codificar ";
        cin >> llave;
        cout << "Dame un tamanio para el valor disperso ";
        cin >> tamanio;
        valorD = valorDisperso(llave, tamanio);
        llaveCodificada = codifica(llave, tamanio);
        llaveReconstruida = decodifica(llaveCodificada, tamanio, valorD);
        cout << "Llave original "<<llave<<endl;
        cout << "Valor disperso "<<valorD<<endl;
        cout << "Llave codificada "<<llaveCodificada<<endl;
        cout << "Llave reconstruida "<<llaveReconstruida<<endl;
        cout << "Desea continuar?";
        cin >> respuesta;
    }

    return 0;
}
