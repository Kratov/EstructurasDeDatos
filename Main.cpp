#include <iostream>
#include "Ordenador.h"
#include "Vector.h"

int menuPrincipal() 
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

int menuOrdenamiento()
{

	//Define espacio de nombre para la función
	using namespace std;

	//Menu
	cout << "1.Metodo Burbuja" << endl;
	cout << "2.Metodo Seleccion" << endl;
	cout << "3.Metodo Shell" << endl;
	cout << "4.Metodo QuickSort" << endl;
	cout << "5.Metodo QuickSort 2" << endl;
	cout << "Seleccion: ";

	//Seleccion del usuario
	int aux;
	cin >> aux;
	return aux;

}

int main(int argc, char * argv[]) 
{
	// Numero de salida
	int op = 4;

	//Arreglo dinamico
	int longitud = 0;
	int * vector = NULL;
	int * cVector = NULL;
	Ordenamiento ultimoOrdenameintoExe = Ordenamiento::ninguno;

	//Cuenta iteraciones de los ordenamientos
	int intercambios = 0;

	do
	{
		system("cls");
		//Muestra vector si este existe
		if (vector != NULL) {
			leerVectorConsola(vector, longitud);
		}
		//Muestra numero de intercambios Y y copia del vector ordenada
		if (ultimoOrdenameintoExe != Ordenamiento::ninguno) {
			leerVectorConsola(cVector, longitud);
			mostrarIntercambios(intercambios, ultimoOrdenameintoExe);
			copiarVector(vector, cVector, longitud);
		}

		//Muestra menu y retorna selección
		op = menuPrincipal();
		switch (op)
		{
			case 1:
				cargarVectorConsola(vector, longitud);
				copiarVector(vector, cVector, longitud);
				ultimoOrdenameintoExe = Ordenamiento::ninguno;
				intercambios = 0;
				break;
			case 2:
				if (vector != NULL) {
					system("cls");
					leerVectorConsola(vector, longitud);
					intercambios = 0;
					op = menuOrdenamiento();
					switch (op)
					{
						case 1:
							ultimoOrdenameintoExe = ordenarBurbujaAsc(cVector, longitud, &intercambios);
							break;
						case 2:
							ultimoOrdenameintoExe = ordenarSeleccionAsc(cVector, longitud, &intercambios);
							break;
						case 3:
							ultimoOrdenameintoExe = ordenarShellAsc(cVector, longitud, &intercambios);
							break;
						case 4:
							ultimoOrdenameintoExe = ordenarQuickSortAsc(cVector, 0, (longitud-1), &intercambios);
							break;
						case 5:
							ultimoOrdenameintoExe = ordenarQuickSortAsc2(cVector, 0, (longitud - 1), &intercambios);
							break;
					}
				}
				break;
		}

	} while (op != 0);

	if (vector != NULL) {
		delete[] vector;
		delete[] cVector;
		vector = NULL;
		cVector = NULL;
	}

	return 0;
}
