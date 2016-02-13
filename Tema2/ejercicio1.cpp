// *** Tema02 Parte 1 Ejercicio 1 ***
//------------------------------------
//
// Calcular volumen del cono de radio de base 14.5 y altura 26.79
// usando la formula pi*(radio^2)*altura/3

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double Pi = 3.141592; //Declarar e inicializar pi con valor aproximado

    cout << "El volumen de un cono de radio de la base 14,5u y altura 26,79u es: "
         << Pi * pow(14.5, 2) * 26.79 / 3 << "u^3" <<endl; //Salida del resultado

         return 0;
}
