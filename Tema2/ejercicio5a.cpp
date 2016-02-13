// *** Tema02 Parte 1 Ejercicio 5 ***
//------------------------------------
//
// Calcular nota de fin de curso

#include <iostream>
using namespace std;

double inNotaPractica(int contador) //Funcion ingreso de notas practicas
{
    double nota = 0;

    cout << "Ingrese nota de la practica " << contador + 1 << ": " ; //Muestra numero de la pract. pedida
    cin >> nota ;

    return nota;
}

int main()
{
    cout << "*** CALCULADOR DE NOTA FUNDAMENTOS DE PROGRAMACION ***"
         << "\n\nCalculada teniendo en cuenta:"
         << "\n\t * Practicas:            20% "
         << "\n\t * Examen de diciembre:   5% "
         << "\n\t * Examen de enero:      10% "
         << "\n\t * Examen de abril:      10% "
         << "\n\t * Examen final:         45% "
         << "\n\t * Actividad adiciobnal: 10% "
         << "\n\nIntroduzca las notas segun se solicite a continuacion: " << endl;

    //double practica, practicaIn ;
    int numPracticas;

    cout << "\nIntroduzca numero de practicas: " ; // Solicitar numero de practicas para usar en bucle
    cin >> numPracticas ;
    cout << endl;

    double sumPractica = 0;
    int i = 0; //Variable para el contador del bucle, usada en formula final

    for (; i < numPracticas; i++){ // Bucle acumular nota de las practicas

            sumPractica = sumPractica + inNotaPractica(i) ;
        }

    double eDic, eEne, eAbr, eFin, adicional; //Declaracion variables notas de los examenes y act.adicional
    //Entada de notas restantes
    {
    cout << "\nIntroduzca nota del examen de Diciembre: " ;
    cin  >> eDic ;

    cout << "Introduzca nota del examen de Enero: " ;
    cin  >> eEne ;

    cout << "Introduzca nota del examen de Abril: " ;
    cin  >> eAbr ;

    cout << "Introduzca nota del examen final: " ;
    cin  >> eFin ;

    cout << "Introduzca nota de actividad adicional: " ;
    cin  >> adicional ;
    }
     //Nota final
    double notaFinal = ((sumPractica / i) * 0.2 ) + eDic * 0.05 + eEne * 0.1 + eAbr * 0.1 + eFin * 0.45 + adicional * 0.1 ;

    cout << "\nLa nota final es: " << notaFinal ;

    return 0;
}
