////////////////////
//BUSQUEDA BINARIA//
////////////////////

bool buscar(tLista lista, int buscado, int& pos);

bool buscar(tLista lista, int buscado, int &pos) 
{
	int ini = 0, fin = lista.contador - 1, mitad;
	bool encontrado = false;
	while ((ini <= fin) && !encontrado) 
	{
		mitad = (ini + fin) / 2; // División entera
		if (buscado == lista.elementos[mitad])
			encontrado = true;
		else if (buscado < lista.elementos[mitad])
			fin = mitad ‐ 1;
		else
			ini = mitad + 1;
	}
	if (encontrado)
		pos = mitad;

	return encontrado;
}