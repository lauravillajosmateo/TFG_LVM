#include "Fichero.h"
#include <vector>
#include <iostream>
#include<Windows.h>


void Fichero::registrarstock(componente* c, int cantt)
{
			ofstream archivo1("stock.txt", std::ios::app);
			archivo1 <<"\n"<< cantt << " " << c->getnombre() << " " << c->gettipo() << " " << c->getinfo() << " ";
	
}


void Fichero::registrarretirada(int cant, string uno, string dos, string tres,string cr, int c)
{
	if (cant == 0)
	{
		return;
	}
	else
	{
		ofstream archivo1("stock.txt", std::ios::app);
		archivo1 << cant << " " << uno << " " << dos << " " << tres << " ";
		chrono::system_clock::time_point now = chrono::system_clock::now();
		// Convertir el tiempo actual a un formato de tiempo local
		time_t time = chrono::system_clock::to_time_t(now);
		// Obtener la fecha actual en formato de cadena
		fecha = std::ctime(&time);
		ofstream archivo3("registro.txt", std::ios::app);
		archivo3 << "\n" << cr << " ha retirado " << c << " " << uno << " " << dos << " " << tres << " " << fecha;
	}
}

void Fichero::registraroperacion(componente* c, string cr, int ca)
{
	chrono::system_clock::time_point now = chrono::system_clock::now();
	// Convertir el tiempo actual a un formato de tiempo local
	time_t time = chrono::system_clock::to_time_t(now);
	// Obtener la fecha actual en formato de cadena
	fecha = std::ctime(&time);
	ofstream archivo3("registro.txt", std::ios::app);
	archivo3 << "\n" << cr << " ha donado " <<ca<<" "<< c->getnombre() << " " << c->gettipo() << " " << c->getinfo() << " " << fecha;
}

int Fichero::comprobarusuario(string correo, string passw)
{
	ifstream fichero("datos.txt");
	if (!fichero)
	{
		cout << "Error al abrir el archivo datos.txt\n";
		exit(EXIT_FAILURE);
	}
	while (getline(fichero, linea) && fin == 0) { // Este bucle se repetira mientras la funcion getline pueda obtener lineas nuevas del archivo txt y la variable fin valga 0

		while ((pos = linea.find(",")) != std::string::npos) { /* Si el valor devuelto por la funcion find es distinto a la constante npos esto

		significa que si se ha encontrado lo que se busca dentro de la variable linea */

			dato = linea.substr(0, pos); // Separamos los caracteres desde la posicion 0 hasta una posicion previa al caracter separador que es la coma

			casilla[contador] = dato; // Guardamos el dato anterior dentro de la casilla 0 o la 1 dependiendo del valor de contador

			linea.erase(0, pos + 1); // Eliminamos los caracteres desde la posicion 0 hasta la posicion donde se encuentra el caracter separador coma,incluida la coma

			contador++; // Aumentamos el valor del contador

		}

		if (casilla[0].find(correo, 0) != string::npos) {

			fin = 1; /* Si el correo de alguna linea es igual al ingresado por el usuario cambiamos el valor de la variable fin para que se

		termine el bucle, sin importar que la contraseña sea incorrecta */

		}

		contador = 0;/* Regresamos el valor del contador a 0 por si en la línea previa no estuviesen el nombre y la contraseña de nuestro usuario, así

		continuamos en el bucle buscando hasta que se encuentre o se acaben los datos en el archivo de texto.*/


		if (correo == casilla[0] && passw == casilla[1]) {

			cout << "Usuario correcto." <<"\n" << endl;
			correcto = 1;
			return correcto;
		}

		else {
			correcto = 0; fin = 0;
			cout << "Usuario y contrasena no coinciden" << endl;
			failpasw++;
			if (failpasw == 3)
			{
				cout << "No es posible iniciar sesion con las credenciales indicadas. Hasta pronto." << endl;
				Sleep(2000);
				exit(0);
			}
			return correcto;
		}

		if (fichero.eof() && correcto == 0)
		{
			cout << "Los datos ingresados son incorrectos o no esta registrado en el sistema." <<"\n" << endl;
		}
	}
	
}
void Fichero::registrarusuario(usuario* us)
{
	ifstream archivo("datos.txt");
	while (getline(archivo, linea))
	{
		contenido = contenido + linea + "\n";
	}
	archivo.close();
	ofstream archivo1("datos.txt");
	archivo1 << contenido << us->getcorreo() << "," << us->getcontrasena() << ",";
}

int Fichero::sumarcantidades(int cant, string nbusc, string tbusc, string ebusc)
{
	fin = 0;
	ifstream fichero("stock.txt");
	if (!fichero)
	{
		cout << "Error al abrir el archivo datos.txt\n";
		exit(EXIT_FAILURE);
	}
	while (getline(fichero, linea) && fin == 0) { // Este bucle se repetira mientras la funcion getline pueda obtener lineas nuevas del archivo txt y la variable fin valga 0

		while ((pos = linea.find(" ")) != std::string::npos) { /* Si el valor devuelto por la funcion find es distinto a la constante npos esto

		significa que si se ha encontrado lo que se busca dentro de la variable linea */
			
			dato = linea.substr(0, pos); // Separamos los caracteres desde la posicion 0 hasta una posicion previa al caracter separador que es el espacio

			casilla[contador] = dato; // Guardamos el dato anterior dentro de la casilla 0 o la 1 dependiendo del valor de contador

			linea.erase(0, pos + 1); // Eliminamos los caracteres desde la posicion 0 hasta la posicion donde se encuentra el caracter separador espacio,incluida el espacio

			contador++; // Aumentamos el valor del contador

		}

		if (casilla[1].find(nbusc, 0) != string::npos && casilla[2].find(tbusc, 0) != string::npos && casilla[3].find(ebusc, 0) != string::npos) {
			fichero.close();
			fin = 1; /* Si alguna linea es igual a lo ingresado por el usuario cambiamos el valor de la variable fin para que se termine el bucle*/
			vector<string> lineas; //guardo las lineas que sean distintas de lo que busco en este vector para volver a imprimirlas
			ifstream f("stock.txt");
			if (!f)
			{
				cout << "Error al abrir el archivo datos.txt\n";
				exit(EXIT_FAILURE);
			}
			while (getline(f, linea)) {
				size_t nencont = linea.find(nbusc);
				size_t tencont = linea.find(tbusc);
				if (nencont == std::string::npos || tencont == std::string::npos) {
					lineas.push_back(linea);
				}
			}

			f.close();
			cant = sumarintstring(cant,casilla[0]);
			ofstream fi("stock.txt");
				if (!fi)
				{
					cout << "Error al abrir el archivo datos.txt\n";
					exit(EXIT_FAILURE);
				}
				for (const string& linea : lineas) {
					fi << linea << '\n';
				}

				fi.close();

		}
		if (fichero.eof())
		{
			fichero.close();
		}
	
		contador = 0;/* Regresamos el valor del contador a 0 por si en la línea previa no estuviesen el nombre y la contraseña de nuestro usuario, así

				continuamos en el bucle buscando hasta que se encuentre o se acaben los datos en el archivo de texto.*/			
			
		}

	return cant;

	
}
int Fichero::restarcantidades(int cant, string nbusc, string tbusc, string ebusc)
{
	fin = 0;
	ifstream fichero("stock.txt");
	if (!fichero)
	{
		cout << "Error al abrir el archivo datos.txt\n";
		exit(EXIT_FAILURE);
	}
	while (getline(fichero, linea) && fin == 0) { // Este bucle se repetira mientras la funcion getline pueda obtener lineas nuevas del archivo txt y la variable fin valga 0

		while ((pos = linea.find(" ")) != std::string::npos) { /* Si el valor devuelto por la funcion find es distinto a la constante npos esto

		significa que si se ha encontrado lo que se busca dentro de la variable linea */

			dato = linea.substr(0, pos); // Separamos los caracteres desde la posicion 0 hasta una posicion previa al caracter separador que es el espacio

			casilla[contador] = dato; // Guardamos el dato anterior dentro de la casilla 0 o la 1 dependiendo del valor de contador

			linea.erase(0, pos + 1); // Eliminamos los caracteres desde la posicion 0 hasta la posicion donde se encuentra el caracter separador espacio,incluida el espacio

			contador++; // Aumentamos el valor del contador

		}

		if (casilla[1].find(nbusc, 0) != string::npos && casilla[2].find(tbusc, 0) != string::npos && casilla[3].find(ebusc, 0) != string::npos) {
			fichero.close();
			fin = 1; /* Si alguna linea es igual a lo ingresado por el usuario cambiamos el valor de la variable fin para que se termine el bucle*/
			vector<string> lineas; //guardo las lineas que sean distintas de lo que busco en este vector para volver a imprimirlas
			ifstream f("stock.txt");
			if (!f)
			{
				cout << "Error al abrir el archivo datos.txt\n";
				exit(EXIT_FAILURE);
			}
			while (getline(f, linea)) {
				size_t nencont = linea.find(nbusc);
				size_t tencont = linea.find(tbusc);
				if (nencont == std::string::npos || tencont == std::string::npos) {
					lineas.push_back(linea);
				}
			}

			f.close();
			int c;
			c = restarintstring(cant, casilla[0]);
			if (c < 0)
			{
				cout << "No hay suficiente cantidad del elemento que deseas retirar." << endl;
				ofstream fic("stock.txt");
				if (!fic)
				{
					cout << "Error al abrir el archivo datos.txt\n";
					exit(EXIT_FAILURE);
				}
				for (const string& linea : lineas) {
					fic << linea << '\n';
				}
				return stoi(casilla[0]);
			}
			else
			{
				ofstream fi("stock.txt");
				if (!fi)
				{
					cout << "Error al abrir el archivo datos.txt\n";
					exit(EXIT_FAILURE);
				}
				for (const string& linea : lineas) {
					fi << linea << '\n';
				}

				fi.close();
				cout << "MATERIAL DISPONIBLE PARA RETIRAR" << endl;
				cout << "Por favor, RETIRA el material de su cajon correspondiente en el armario. Solicita ayuda del personal si es necesario." << endl;
				cout << "------------RETIRADA DE MATERIAL COMPLETADA. GRACIAS POR ALARGAR LA VIDA UTIL DE ESTE MATERIAL.-------------------------" << endl;
				return c;
			}

		}
		

		contador = 0;/* Regresamos el valor del contador a 0 por si en la línea previa no estuviesen el nombre y la contraseña de nuestro usuario, así

				continuamos en el bucle buscando hasta que se encuentre o se acaben los datos en el archivo de texto.*/

	}
	if (fichero.eof() && fin == 0)
	{
		fichero.close();
		cout << "El componente que deseas no esta disponible." << endl;
		return 0;
	}

}
int Fichero::sumarintstring(int entero, const string& cadena)
{
	
		int enteroVector = stoi(cadena); //el valor de la cantidad disponible
		return entero + enteroVector;
	
}

int Fichero::restarintstring(int entero, const string& cadena)
{
	int enteroVector = stoi(cadena); //el valor de la cantidad disponible
	return enteroVector-entero;
}
