#include "Ordenador.h"

void OrdenarSeleccionAsc(int * vec, int n)
{
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		//Se Seleccion el menor numero del arreglo y se guarda
		for (int j = i + 1; j < n; j++)
			if (vec[j] < vec[min])
				min = j;

		//Se intercambia el indice i con el min
		{
			int aux = vec[i];
			vec[i] = vec[min];
			vec[min] = aux;
		}
	}
}
