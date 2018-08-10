#include "Vector.h"
#include <iostream>
#include <random>



void cargarVectorConsola(int *& vec, int & n)
{
	//Usa el espacio de nombre para la funcion
	using namespace std;

	cout << "Ingrese el tamano del arreglo: ";
	cin >> n;

	//Retorna si existe error en buffer cin
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Ingreso un valor invalido." << endl;
		return;
	}

	cout << endl;

	if (vec != NULL) {
		delete[] vec;
		vec = NULL;
	}

	//Declara el arreglo dinamico
	vec = (int *) malloc(n * sizeof(int));

	for (int  i = 0; i < n; i++)
	{
		////Motor random
		//random_device rd;									//Semilla
		//mt19937 motor(rd());								//Motor randomico
		//uniform_int_distribution<int> rand(1, 100);			//Rango del random
		//*(vec + i) = rand(motor);							//Llena elemento vector
		cout << "Ingrese el valor " << i << ": ";
		cin >> vec[i];
	}
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
