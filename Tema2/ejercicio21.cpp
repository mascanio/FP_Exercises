#include <iostream>
#include <string>

using namespace std;
#include <iomanip>
#include <cctype>

int main()
{
	const int IVA = 21 ,
		Descuento = 15 ;
	int unidades ;
	double precio, total , descuentoAplicado , precioFinal  ;
	char aplicarDescuento ;

	string nombre, NIF, direccion, nombreProducto ;

	cout << "Precio del producto: " ;
	cin >> precio ;
	cout << "Unidades: " ;
	cin >> unidades ;
	cout << "Descuento (s/n)? " ;
	cin >> aplicarDescuento ;
	aplicarDescuento = toupper(aplicarDescuento);
	cout << "Nombre del cliente: " ;
	cin.sync() ;
	getline(cin, nombre) ;
	cout << "NIF del cliente: " ;
	getline(cin, NIF) ;
	cout << "Dirección del cliente: " ;
	getline(cin, direccion) ;
	cout << "Nombre del producto: " ;
	getline(cin, nombreProducto) ;

	//Cálculo de Total, Descuento, Total con descuento...
	total = precio * unidades ;

	//Si tenemso descuento, calcularlo, si no, desceunto 0
	if('S' == aplicarDescuento)
		descuentoAplicado = total * Descuento / 100 ;
	else
		descuentoAplicado = 0 ;

	precioFinal = (total - descuentoAplicado) * (IVA / 100 + 1) ;

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
		<< setw(50) << right << - descuentoAplicado << " €" << endl
		<< setw(40) << left << "Total tras descuento" 
		<< setw(10) << right << fixed 
		<< setprecision(2) << total - descuentoAplicado << " €" << endl

		<< setw(40) << left << "I.V.A." 
		<< setw(7)  << right << IVA  << " %" << endl
		<< setw(50) << right << fixed 
		<< setprecision(2) << (total - descuentoAplicado) * IVA << endl
		<< setw(40) << left << "Precio final"
		<< setw(10) << right << fixed 
		<< setprecision(2) << precioFinal << " €" ;

	return 0;
}