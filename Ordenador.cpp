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

void OrdenarBurbujaAsc(int * vec, int n)
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
				existeIntercambio = true;
			}
		}
	}
}

void OrdenarShellAsc(int * vec, int n)
{
																			// Arreglo de ejemplo int a[10] = {54,4,78,47,6,7,45,74,15,35}
	for (int salto = n / 2; salto > 0; salto /= 2)							// Crea saltos de la mitad de la longitud del arreglo  ej. 10 / 2 = 5 (Saltos) y divide el salto para iteracion en 2
	{
		for (int i = salto; i < n; i++)										// i = salto;  i = 5 ; a[i] = 7
		{
			int j = 0;														// Variable que mantiene la posicion hacia atras de i
			int aux = vec[i];												// Guarda aux = a[i]; aux = 7
			for (j = i; j >= salto && vec[j - salto] > aux ; j -= salto)	// j = i ; j = 5;  j >= salto ; 5 >= 5; a[5 - 5 = 0] > 7; 54 > 7; Verifica
			{
				vec[j] = vec[j - salto];									// Intercambia a[5] = a[5 - 5]; a[10] = {54,4,78,47,6,54,45,74,15,35}; j -= salto; j = 5 - 5 = 0
			}

			vec[j] = aux;													// Asigna a[j] = aux;  a[0] = 7; a[10] = {7,4,78,47,6,54,45,74,15,35};
		}
	}
}
