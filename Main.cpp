#include <iostream>
#include "Ordenador.h"
#include "Vector.h"

int MenuPrincipal() 
{

	//Define espacio de nombre para la función
	using namespace std;

	//Menu
	cout << "MENU DE METODOS DE ORDENAMIENTO" << endl;
	cout << "1.Cargar Vector Random" << endl;
	cout << "2.Metodos de ordenamiento" << endl;
	cout << "4.Salir" << endl;
	cout << "Selección: ";

	//Seleccion del usuario
	int aux;
	cin >> aux;
	return aux;

}

int main(int argc, char* argv[]) 
{
	// Numero de salida
	int op = 4;

	//Arreglo dinamico
	int longitud = 0;
	int * vector = NULL;

	do
	{
		system("cls");
		//Muestra vector si este existe
		if (vector != NULL)
			LeerVectorConsola(vector, longitud);

		//Muestra menu y retorna selección
		op = MenuPrincipal();
		switch (op)
		{
			case 1:
				CargarVectorConsola(vector, longitud);
				break;
			case 2:

				break;
		}

	} while (op != 4);

	return 0;
}