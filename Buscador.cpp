#include "Buscador.h"
#include <iostream>

const char * TiposBusqueda[] = {
	"",
	"Lineal",
	"Binaria"
};

void leerElementoBuscar(int & elementoBuscar)
{
	using namespace std;
	cout << "Ingrese numero a buscar: " << endl;;
	cout << "Numero: ";
	cin >> elementoBuscar;

	if (cin.fail())
	{
		cin.ignore();
		cin.clear();
		leerElementoBuscar(elementoBuscar);
	}
}

void leerElementoBsucar(int & elementoBuscar)
{
}

void mostrarIndiceEncontrado(const int indiceEncontrado, const Busqueda tipoBusqueda)
{
	using namespace std;
	if (indiceEncontrado >= 0)
		cout << "(" << TiposBusqueda[tipoBusqueda] << ")" << " Encontrado en el indice: " << indiceEncontrado << endl << endl;
	else
		cout << "(" << TiposBusqueda[tipoBusqueda] << ")" << " Elemento no encontrado" << endl << endl;
}

void mostrarNumeroComparaciones(const int nComparaciones, const Busqueda tipoBusqueda)
{
	using namespace std;
	cout << "(" << TiposBusqueda[tipoBusqueda] << ")" << " Numero de comparaciones: " << nComparaciones << endl << endl;
}

Busqueda busquedaLineal(const int * vec, const int longitud, const int nBuscar, int & nComparaciones, int & indiceEncontrado)
{

	for (int i = 0; i <= longitud; i++)	
		if (vec[i] == nBuscar) 		 
			indiceEncontrado = i;
	

	 
		
	return Busqueda::BusquedaLineal;
}

Busqueda busquedaBinaria(const int * vec, const int inicio, const int fin, const int nBuscar, int & nComparaciones, int & indiceEncontrado)
{
	//Divide longitud 2
	int indiceMedio = (inicio + fin) / 2;
	if (inicio <= fin)
	{
		nComparaciones++;
		int puntoMedio = vec[indiceMedio];
		if (nBuscar == puntoMedio)
			indiceEncontrado = indiceMedio;
		if (nBuscar > puntoMedio)
			busquedaBinaria(vec, indiceMedio + 1, fin, nBuscar, nComparaciones, indiceEncontrado);
		else if (nBuscar < puntoMedio)
			busquedaBinaria(vec, inicio, indiceMedio - 1, nBuscar, nComparaciones, indiceEncontrado);
	}
	return Busqueda::BusquedaBinaria;
}
