#include <iostream>
#include "Ordenador.h"
#include "Vector.h"

int menuPrincipal() 
{

	//Define espacio de nombre para la funci�n
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

	//Define espacio de nombre para la funci�n
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

int main(int argc, char * argv[]) 
{
	// Numero de salida
	int op = 4;

	//Arreglo dinamico
	int longitud = 0;
	int * vector = NULL;
	Ordenamiento ultimoOrdenameintoExe = Ordenamiento::ninguno;

	//Cuenta iteraciones de los ordenamientos
	int intercambios = 0;

	do
	{
		system("cls");
		//Muestra vector si este existe
		if (vector != NULL) 
			leerVectorConsola(vector, longitud);
		if (ultimoOrdenameintoExe != Ordenamiento::ninguno)
			mostrarIntercambios(intercambios, ultimoOrdenameintoExe);	

		//Muestra menu y retorna selecci�n
		op = menuPrincipal();
		switch (op)
		{
			case 1:
				cargarVectorConsola(vector, longitud);
				ultimoOrdenameintoExe = Ordenamiento::ninguno;
				intercambios = 0;
				break;
			case 2:
				if (vector != NULL) {
					system("cls");
					leerVectorConsola(vector, longitud);
					if (ultimoOrdenameintoExe != Ordenamiento::ninguno)
						mostrarIntercambios(intercambios, ultimoOrdenameintoExe);
					op = menuOrdenamiento();
					switch (op)
					{
						case 1:
							ultimoOrdenameintoExe = ordenarBurbujaAsc(vector, longitud, &intercambios);
							break;
						case 2:
							ultimoOrdenameintoExe = ordenarSeleccionAsc(vector, longitud, &intercambios);
							break;
						case 3:
							ultimoOrdenameintoExe = ordenarShellAsc(vector, longitud, &intercambios);
							break;
						case 4:
							ultimoOrdenameintoExe = ordenarQuickSortAsc(vector, 0, (longitud-1), &intercambios);
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