#include <stdio.h>

int main(int argc, char* argv[]) {

	int vector[7] = {30,23,67,12,65,12,43};

	{
		int min;
		for (int i = 0; i < 7; i++)
		{
			min = i;
			//Se Seleccion el menor numero del arreglo y se guarda
			for (int j = i + 1; j < 7; j++)			
				if (vector[j] < vector[min])
					min = j;

			//Se intercambia el indice i con el min
			{
				int aux = vector[i];
				vector[i] = vector[min];
				vector[min] = aux;
			}
		}
	}

	//Se imprime el arreglo
	for (int i = 0; i < 7; i++)
		printf("%d \n", vector[i]);

	getchar();

	return 0;
}