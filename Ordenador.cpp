#include "Ordenador.h"
#include <iostream>
#include <utility>

const char * TiposOrden[] = {
	"",
	"Burbuja",
	"Seleccion",
	"Shell",
	"QuickSort",
	"QuickSort2"
};

const char * TiposBusqueda[] = {
	"",
	"Lineal",
	"Binaria"
};


void mostrarIntercambios(const int nItercambio, const Ordenamiento tipoOrdenamiento)
{
	using namespace std;
	cout << "Iteraciones de ordenamiento " << TiposOrden[tipoOrdenamiento] << ": " << nItercambio << endl << endl;
}

Ordenamiento ordenarSeleccionAsc(int * vec, const int n, int * iteraciones)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		//Se Seleccion el menor numero del arreglo y se guarda
		for (int j = i + 1; j < n; j++)
			if (vec[j] < vec[min]) {
				min = j;
				*iteraciones += 1;
			}

		//Se intercambia el indice i con el min
		{
			int aux = vec[i];
			vec[i] = vec[min];
			vec[min] = aux;
		}
	}

	return Ordenamiento::OrdenamientoSeleccion;
}

Ordenamiento ordenarBurbujaAsc(int * vec, const int n, int * iteraciones)
{
	//Continua si existe un intercambio
	for (bool existeIntercambio = true; existeIntercambio;)
	{
		existeIntercambio = false;
		//Recorre todo el arreglo menos el ultimo item
		for (int i = 0; i < n - 1; i++)
		{
			//Si el elemento actual es mayor al siguiente
			if (vec[i] > vec[i + 1])
			{
				//Intercambia
				int aux = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = aux;
				*iteraciones += 1;
				existeIntercambio = true;
			}
		}
	}

	return Ordenamiento::OrdenamientoBurbuja;
}

Ordenamiento ordenarShellAsc(int * vec, const int n, int * iteraciones)
{
	// Arreglo de ejemplo int a[10] = {54,4,78,47,6,7,45,74,15,35}

	//1.

	for (int salto = n / 2; salto > 0; salto /= 2)							// Crea saltos de la mitad de la longitud del arreglo  ej. 10 / 2 = 5 (Saltos) y divide el salto para iteracion en 2
	{
		for (int i = salto; i < n; i++)										// i = salto;  i = 5 ; a[i] = 7
		{
			int j = 0;														// Variable que mantiene la posicion hacia atras de i
			int aux = vec[i];												// Guarda aux = a[i]; aux = 7
			for (j = i; j >= salto && vec[j - salto] > aux; j -= salto)	// j = i ; j = 5;  j >= salto ; 5 >= 5; a[5 - 5 = 0] > 7; 54 > 7
			{
				vec[j] = vec[j - salto];	
				*iteraciones += 1;												// Intercambia a[5] = a[5 - 5]; a[10] = {54,4,78,47,6,54,45,74,15,35}; j -= salto; j = 5 - 5 = 0
			}

			vec[j] = aux;													// Asigna a[j] = aux;  a[0] = 7; a[10] = {7,4,78,47,6,54,45,74,15,35};
		}
	}

	return Ordenamiento::OrdenamientoShell;
}

Ordenamiento ordenarQuickSortAsc(int * vec, const int inicio, const int fin, int * iteraciones)
{
	if (inicio < fin) {
		int pIndice = inicio;
		int pivote = vec[fin];

		for (int i = inicio; i < fin; i++)
		{
			if (vec[i] <= pivote)
			{
				int aux = vec[i];
				vec[i] = vec[pIndice];
				vec[pIndice] = aux;
				pIndice++;
				*iteraciones += 1;
			}
		}

		int aux = vec[fin];
		vec[fin] = vec[pIndice];
		vec[pIndice] = aux;

		/*Usamos recursividad para que el ordenamiento se efectue mientras sea necesario*/
		ordenarQuickSortAsc(vec, inicio, pIndice - 1, iteraciones);
		ordenarQuickSortAsc(vec, pIndice + 1, fin, iteraciones);
		
	}
	return Ordenamiento::OrdenamientoQuicksort;
}

Ordenamiento ordenarQuickSortAsc2(int* vec, const int inicio, const int fin, int * iteraciones)
{
	//menores parte izq, mayores parte derecha
	int i = inicio, j = fin; //variable aux, variables i y j de recorrido
	int pivote = vec[(inicio + fin) / 2]; // pivote = al numero de la mitad del arreglo
	while (i <= j)
	{
		while (vec[i] < pivote)
			i++; // mientras vec[izq] < al pivote, i aumenta de recorrido sin hacer cambio

		while (vec[j] > pivote)
			j--; // mientras vec[derech] > al pivote, j aumenta de recorrido sin hacer cambio

		if (i <= j)
		{
			int aux = vec[i]; // guardamos al mayor
			vec[i] = vec[j]; // lo cambiamos a la derecha
			vec[j] = aux;// el menor lo movemos a la izquierda
			i++;	// aumentamos el recorrido de las variables
			j--;
			*iteraciones += 1;
		}
	}
	/*Usamos recursividad para que el ordenamiento se efectue mientras sea necesario*/
	if (inicio < j)
		ordenarQuickSortAsc2(vec, inicio, j, iteraciones);
	if (i < fin)
		ordenarQuickSortAsc2(vec, i, fin, iteraciones);

	return Ordenamiento::OrdenamientoQuicksort2;
}

