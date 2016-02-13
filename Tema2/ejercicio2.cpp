// *** Tema02 Parte 1 Ejercicio 2 ***
//------------------------------------
//
// Calcular volumen del cono de radio de base 14.5 y altura 26.79
// usando la formula pi*(radio^2)*altura/3 = volumen
// declarando como double radio, altura y volumen

#include <iostream>
#include <cmath>
using namespace std;

main()
{
    const double Pi = 3.141592;
    double radio = 14.5, altura = 26.79, volumen; //Declarar e inicializar pi, radio, altura y volumen

    volumen = Pi * pow (radio, 2) * altura / 3 ; //Formula para calcular la salida volumen

    cout << "El volumen de un cono de radio de la base " << radio <<"u y altura " << altura <<"u es: "
         << volumen << "u^3" <<endl; //Mostrar resultado de volumen

    return 0;
}
