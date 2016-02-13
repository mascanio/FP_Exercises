// Grupo01
// Miguel Ascanio G�mez y Javier Ortiz Iniesta
//
// *** Tema02 Parte 1 Ejercicio 8 ***
//------------------------------------
// 
// Calculo de nomina

#include <iostream>
using namespace std;

int main()
{
    cout << "*** CALCULO DE N�MINAS ***" << endl << endl
         << "Introduzca los datos solicitados para calcular la n�mina" << endl
         << "--------------------------------------------------------" << endl ;
    //Declaraciones
    double  sueldoBase,     //Variable sueldo base
            complDestino,   //Variable complemento de destino
            complAcademico, //Variable complemento de cargo acadamico 
			horasExtra ;    //Variable horas extra
          
	int		numHijos,       //Variable numero de hijos
            numMayores ;    //Variable numero de mayores

                    //Variables de salida
     double	sueldoBruto,    //Variable sueldo bruto
            irpfAplicado,   //Variable IRPF aplicado
            retenIRPF,      //Variable retencion por IRPF
            sueldoNeto ;    //Variable sueldo neto

    const int IRPF = 24 ;   //IRPF al 24%

    //Entrada de datos
    
        cout << "Sueldo Base: \t\t" ;
        cin >> sueldoBase ;

        cout << "Complemento de destino: " ;
        cin >> complDestino ;

        cout << "Complemento academico: \t" ;
        cin >> complAcademico ;

        cout << "Horas extra: \t\t" ;
        cin >> horasExtra ;

        cout << "N�mero de hijos: \t" ;
        cin >> numHijos ;
        

        cout << "Mayores a cargo: \t" ;
        cin >> numMayores ;
        
    
    //Calculo de la nomina

    sueldoBruto = sueldoBase + complAcademico + complDestino + horasExtra * 23 ;
    irpfAplicado = IRPF - numHijos * 2 - numMayores ;
    retenIRPF =  irpfAplicado * sueldoBruto / 100 ;
    sueldoNeto = sueldoBruto + retenIRPF ;

    //Salida
    cout << endl
         << "----------------------------------------" << endl
         << "C�lculo de la n�mina" << endl
         << "----------------------------------------" << endl << endl
         << "Sueldo bruto: \t\t\t" << sueldoBruto << endl
         << "Porcentaje de IRPF: \t\t" << irpfAplicado << endl
         << "Retenci�n por IRPF: \t\t" << retenIRPF << endl
         << "****************************************" << endl
         << "SUELDO NETO: \t\t\t" << sueldoNeto << endl
         << "****************************************" << endl;

    return 0;

}
