#include <iostream>
#include "Ordenador.h"
#include "Vector.h"

int menuPrincipal() 
{

	//Define espacio de nombre para la función
	using namespace std;

	//Menu
	cout << "PROGRAMA DE ESTRUCTURA DE DATOS" << endl;
	cout << "1.Cargar Vector" << endl;
	cout << "2.Metodos de ordenamiento" << endl;
	cout << "3.Metodos de busqueda" << endl;
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
	cout << "Metodos de ordenamiento: " << endl;
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

int menuIngresoVector()
{

	//Define espacio de nombre para la función
	using namespace std;

	//Menu
	cout << "Carga del vector: " << endl;
	cout << "1.Automatico" << endl;
	cout << "2.Manual" << endl;
	cout << "Seleccion: ";

	//Seleccion del usuario
	int aux;
	cin >> aux;
	return aux;

}

int menuBusqueda()
{

	//Define espacio de nombre para la función
	using namespace std;

	//Menu
	cout << "Metodos de busqueda: " << endl;
	cout << "1.Lineal" << endl;
	cout << "2.Binaria" << endl;
	cout << "Seleccion: ";

	//Seleccion del usuario
	int aux;
	cin >> aux;
	return aux;

}

int main(int argc, char * argv[]) 
{
	// Numero de salida
	int op;

	//Arreglo dinamico
	int longitud = 0;
	int * vector = NULL;
	int * cVector = NULL;
	Ordenamiento ultimoOrdenameintoExe = Ordenamiento::OrdenamientoNinguno;
	Busqueda ultimaBusquedaExe = Busqueda::BusquedaNinguno;
	//Cuenta iteraciones de los ordenamientos
	int intercambios = 0;

	do
	{
		system("cls");
		//Muestra vector si este existe
		if (vector != NULL) {
			using namespace std;
			cout << endl << "Vector original:" << endl;
			leerVectorConsola(vector, longitud);
		}
		//Muestra numero de intercambios Y y copia del vector ordenada
		if (ultimoOrdenameintoExe != Ordenamiento::OrdenamientoNinguno) {
			using namespace std;
			cout << "------------------------------------------------" << endl;
			cout << "Resultados ordenamiento: " << endl;
			leerVectorConsola(cVector, longitud);
			mostrarIntercambios(intercambios, ultimoOrdenameintoExe);
			copiarVector(vector, cVector, longitud);
			cout << "------------------------------------------------" << endl;
		}

		//Muestra numero de intercambios Y y copia del vector ordenada
		if (ultimaBusquedaExe != Busqueda::BusquedaNinguno) {
			using namespace std;
			cout << "------------------------------------------------" << endl;
			cout << "Resultados busqueda: " << endl;
			
			cout << "------------------------------------------------" << endl;
		}

		//Muestra menu y retorna selección
		switch (op = menuPrincipal())
		{
			case 1:
				system("cls");
				crearVectorConsola(vector, longitud);
				ultimoOrdenameintoExe = Ordenamiento::OrdenamientoNinguno;
				ultimaBusquedaExe = Busqueda::BusquedaNinguno;
				intercambios = 0;
				switch (menuIngresoVector())
				{
					case 1:
						cargarVectorAutomatico(vector, longitud);
						break;
					case 2:
						cargarVectorManual(vector, longitud);
						break;			
				}
				copiarVector(vector, cVector, longitud);
				break;
			case 2:
				if (vector != NULL) {
					system("cls");
					{
						using namespace std;
						cout << endl << "Vector original:" << endl;
					}
					leerVectorConsola(vector, longitud);
					intercambios = 0;
					
					switch (menuOrdenamiento())
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
			case 3:
				if (vector != NULL) {
					system("cls");
					{
						using namespace std;
						cout << endl << "Vector original:" << endl;
					}

					switch (menuBusqueda())
					{
						case 1:
							
							break;
						case 2:
						
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
