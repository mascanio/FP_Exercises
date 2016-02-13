// Grupo01
// Miguel Ascanio Gómez y Javier Ortiz Iniesta
//
// *** Ejercicio 11-06 ***
//------------------------

#include <iostream>
#include <string>
using namespace std;

#include <iomanip>
#include <cctype>

int main()
{
   // Declaraciones
   const int IVA = 21 , //Constantes, enteros para mostrarlos y para aplicarlos en las constates reales Porcentaje, usadas en las operaciones 
      Descuento = 15 ;
   const double PorcentIVA = double(IVA) / 100 ,
      PorcentDescuento = double(Descuento) / 100 ;
   int opcion = 10 ,
      unidades ;
   double precio, total, totalDescontado, descuentoAplicado, precioFinal,
      acumuladorPrecioFinal = 0, acumuladorIVAFinal = 0;
   char aplicarDescuento ;
   string nombre, NIF, direccion, nombreProducto ;
   bool opcionOK = false ,
      datosClienteOK = false, datosVentaOK = false,
      facturaOK = false ;

   while(opcion != 0)
   {
      opcionOK = false ; //Volver a pedir opcion al acaba la anterior

      while(!opcionOK)  //Pedir numero (opcion) entre 0 y 5 (mientras opcionOK false)
      {
         opcionOK = true ;

         cout << endl
            << "*****************" << endl
            << "SELECCIONE OPCIÓN" << endl
            << "*****************" << endl
            << "1: Datos del cliente" << endl
            << "2: Datos de venta" << endl
            << "3: Factura" << endl
            << "4: Total" << endl
            << "5: Reiniciar" << endl
            << "0: Salir" << endl ;
         cin >> opcion ;

         if(5 < opcion)          //
            opcionOK = false ;   //
         if(0 > opcion)          // Opcion OK (false) si numero no esta entre las opciones 0 - 5
            opcionOK = false ;   //
      }

      if(1 == opcion) //Datos cliente: introducir datos de cliente
      {
         cout << "Nombre del cliente: " ;
         cin.sync() ;
         getline(cin, nombre) ;
         cout << "NIF del cliente: " ;
         getline(cin, NIF) ;
         cout << "Dirección del cliente: " ;
         getline(cin, direccion) ;
         datosClienteOK = true ;
      }

      if(2 == opcion) //Datos venta: introducir datos de venta, calcular datos y acumular (para (4))
      {
         cout << "Nombre del producto: " ;
         cin.sync() ;
         getline(cin, nombreProducto) ;
         cout << "Precio del producto: " ;
         cin >> precio ;
         cout << "Unidades: " ;
         cin >> unidades ;
         cout << "Descuento (s/n)? " ;
         cin >> aplicarDescuento ;
         aplicarDescuento = toupper(aplicarDescuento);

         //Cálculo de Total, Descuento, Total con descuento...
         total = precio * unidades ;

         //Si tenemos descuento, calcularlo, si no, descuento 0
         if('S' == aplicarDescuento)
            descuentoAplicado = total * PorcentDescuento ;
         else
            descuentoAplicado = 0 ;

         totalDescontado = total - descuentoAplicado ;
         precioFinal = totalDescontado + totalDescontado * PorcentIVA ;
         //Acumulamos los datos para mostrarlos en opción 4
         acumuladorPrecioFinal += precioFinal ; 
         acumuladorIVAFinal += totalDescontado * PorcentIVA ;

         datosVentaOK = true ;
      }

      if(3 == opcion) //Mostrar factura: comprobar si se han indroducido datos necesarios; y mostrar factura si procede
      {
         if (opcion != 0)
         {
            facturaOK = true ;		 
            //  facturaOK = true si datosCliente == true && datosVenta == true 
            if(!datosClienteOK)      
            {
               cout << "¡No hay datos de cliente!" << endl ;
               facturaOK = false ;  
            }

            if(!datosVentaOK)   
            {
               cout << "¡No hay datos de venta!" ;
               facturaOK = false ; 
            }
         }

         if(facturaOK) //Si factura OK (tenemos datos venta y datos cliente) mostrar factura, si no ignorar (se mostro lo que falta anteriormente)
         {
            //Cálculo de Total, Descuento, Total con descuento...
            total = precio * unidades ;

            //Si tenemso descuento, calcularlo, si no, desceunto 0
            if('S' == aplicarDescuento)
               descuentoAplicado = total * PorcentDescuento ;
            else
               descuentoAplicado = 0 ;

            //Precio final calculado anteriormente

            // Salida
            cout << endl
               << "Factura: " << endl
               << setw(50) << nombre << endl
               << setw(50) << direccion << endl
               << setw(50) << NIF << endl
               << endl
               << "Producto: " << nombreProducto << endl
               << setw(40) << left << "Precio unitario"
               << setw(10) << right << fixed 
               << setprecision(2) << precio << " €" << endl
               << setw(40) << left << "Unidades"
               << setw(7) << right << unidades << endl
               << setw(40) << left << "Total"
               << setw(10) << right << fixed 
               << setprecision(2) << total << " €" << endl << endl 

               << setw(40) << left << "Descuento"
               << setw(7) << right << fixed 
               << setprecision(2) << Descuento  << " %" << endl
               << setw(50) << right << -descuentoAplicado << " €" << endl
               << setw(40) << left << "Total tras descuento" 
               << setw(10) << right << fixed 
               << setprecision(2) << total - descuentoAplicado << " €" << endl << endl

               << setw(40) << left << "I.V.A." 
               << setw(7) << right << fixed 
               << setprecision(2) << IVA << " %" << endl
               << setw(50) << right << fixed 
               << setprecision(2) << totalDescontado * PorcentIVA  << " €" << endl << endl
               << setw(40) << left << "Precio final"
               << setw(10) << right << fixed 
               << setprecision(2) << precioFinal << " €" ;
         }
      }

      if (4 == opcion)	//Totales: mostrar acumulados
      {
         cout << "Total facturado: " << acumuladorPrecioFinal << " €" << endl 
            << "Total I.V.A.: " << acumuladorIVAFinal << " €" << endl; 
      }

      if (5 == opcion)  //Reiniciar: acumuladores 0; no permitir entrada a (3) sin meter datos
      {
         acumuladorIVAFinal = 0;
         acumuladorPrecioFinal = 0;
         datosClienteOK = false ;
         datosVentaOK = false ;
         cout << "Reiniciado" ;
      }
   }
   return 0;
}