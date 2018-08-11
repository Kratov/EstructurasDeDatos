#pragma once

enum Busqueda
{
	BusquedaNinguno,
	BusquedaLineal,
	BusquedaBinaria
};

void leerElementoBuscar(int & elementoBuscar);
void mostrarIndiceEncontrado(const int indiceEncontrado, const Busqueda tipoBusqueda);
void mostrarNumeroComparaciones(const int nComparaciones, const Busqueda tipoBusqueda);
Busqueda busquedaLineal(const int * vec, const int longitud, const int nBuscar, int & nComparaciones, int & indiceEncontrado);
Busqueda busquedaBinaria(const int * vec, const int longitud, const int nBuscar, int & nComparaciones, int & indiceEncontrado);
