#include "Vector.h"
#include <iostream>
#include <random>



void crearVectorConsola(int *& vec, int & n)
{
	//Usa el espacio de nombre para la funcion
	using namespace std;

	cout << endl << "Ingrese el tamano del arreglo: " << endl;
	cout << endl << "Tamano: ";
	cin >> n;

	//Retorna si existe error en buffer cin
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Ingreso un valor invalido." << endl;
		crearVectorConsola(vec, n);
	}

	cout << endl;

	if (vec != NULL) {
		delete[] vec;
		vec = NULL;
	}

	//Declara el arreglo dinamico
	if (vec == NULL)
		vec = (int *)malloc(n * sizeof(int));

}

void leerVectorConsola(const int * vec, const int n)
{
	//Usa el espacio de nombre para la funcion
	using namespace std;
	
	cout << endl << "Arreglo {";
	for (int i = 0; i < n; i++){
		cout << " " << *(vec + i);
	}
	cout << " }" << endl << endl;
}

void copiarVector(const int * origen, int *& destino, const int longitud)
{
	if (destino != NULL) {
		delete[] destino;
		destino = NULL;
	}

	if (destino	== NULL)
		destino = (int *)malloc(longitud * sizeof(int));

	for (int i = 0; i < longitud; i++)
		*(destino + i) = *(origen + i);
	
}

void cargarVectorManual(int * vec, const int longitud)
{
	//Usa el espacio de nombre para la funcion
	using namespace std;

	for (int i = 0; i < longitud; i++)
	{
		cout << "Ingrese el valor " << i << ": ";
		cin >> vec[i];
	}
}

void cargarVectorAutomatico(int * vec, const int longitud)
{
	//Usa el espacio de nombre para la funcion
	using namespace std;

	for (int i = 0; i < longitud; i++)
	{
		//Motor random
		random_device rd;									//Semilla
		mt19937 motor(rd());								//Motor randomico
		uniform_int_distribution<int> rand(1, 100);			//Rango del random
		*(vec + i) = rand(motor);							//Llena elemento vector
	}
}
