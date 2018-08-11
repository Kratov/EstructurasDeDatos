#pragma once

enum Ordenamiento
{
	OrdenamientoNinguno,
	OrdenamientoBurbuja,
	OrdenamientoSeleccion,
	OrdenamientoShell,
	OrdenamientoQuicksort,
	OrdenamientoQuicksort2
};

enum Busqueda
{
	BusquedaNinguno,
	BusquedaLineal,
	BusquedaBinaria
};


void mostrarIntercambios(const int nItercambio, const Ordenamiento tipoOrdenamiento);
Ordenamiento ordenarSeleccionAsc(int * vec, const int n, int * iteraciones);
Ordenamiento ordenarBurbujaAsc(int * vec, const int n, int * iteraciones);
Ordenamiento ordenarQuickSortAsc(int * vec, const int inicio, const int fin, int * iteraciones);
Ordenamiento ordenarQuickSortAsc2(int* vec, const int inicio, const int fin, int * iteraciones);
Ordenamiento ordenarShellAsc(int * vec, const int n, int * iteraciones);