//Ejercicio 16

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numero = 1; //Declaraci�n

    cout << "*****************************" << endl
         << "DIFERENCIADOR PARES E IMPARES" << endl
         << "*****************************" << endl ;

    while(1) //Bucle
    {
            //Entrada
        cout << endl << "Introduzca un n�mero para diferenciar entre par o impar" << endl
             << "   + N�meros negativos ignorados" << endl
             << "   + Parar ejecuci�n introduciendo un 0" << endl << endl
             << "Introduzca numero: " ;
        cin  >> numero ;

        if(numero == 0) //Si 0, detener
            return 0;

        if(numero > 0) //Si negativo, ignorar
        {
            if(numero % 2 == 0) //Si par
                cout << endl
                     << "----------" << endl
                     << numero << " es par" << endl
                     << "----------" << endl;
            else                //Si impar
                cout << endl
                     << "------------" << endl
                     << numero << " es impar" << endl
                     << "------------" << endl;
        }
    }
}
