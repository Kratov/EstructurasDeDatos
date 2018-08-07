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
	cout << "0.Salir" << endl;
	cout << "Seleccion: ";

	//Seleccion del usuario
	int aux;
	cin >> aux;
	return aux;

}

int MenuOrdenamiento()
{

	//Define espacio de nombre para la función
	using namespace std;

	//Menu
	cout << "1.Metodo Burbuja" << endl;
	cout << "2.Metodo Seleccion" << endl;
	cout << "3.Metodo Shell" << endl;
	cout << "4.Metodo QuickSort" << endl;
	cout << "Seleccion: ";

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
				if (vector != NULL) {
					system("cls");
					LeerVectorConsola(vector, longitud);
					op = MenuOrdenamiento();
					switch (op)
					{
						case 1:
							OrdenarBurbujaAsc(vector, longitud);
							break;
						case 2:
							OrdenarSeleccionAsc(vector, longitud);
							break;
						case 3:
							OrdenarShellAsc(vector, longitud);
							break;
						case 4:
							 
							 OrdenarQuickSortAsc(vector, 0, (longitud-1));
							break;
					}
				}
				break;
		}

	} while (op != 0);

	if (vector != NULL) {
		delete[] vector;
		vector = NULL;
	}

	return 0;
}