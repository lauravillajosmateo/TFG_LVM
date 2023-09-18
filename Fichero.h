#pragma once
#include <string>
#include "componente.h"
#include <fstream>
#include <sstream>
#include <map>
#include "usuario.h"
#include <chrono>
#include <ctime>

using namespace std;

class Fichero
{
protected:

	string contenido,linea; // Variables temporals donde se almacenar� informaci�n del archivo de texto
	string fecha; // se utiliza para registrar las operaciones con la fecha del d�a en que se realizan dentro del fichero registro


public:

	/*Variables necesarias para leer fichero y comprobar los datos del usuario al iniciar sesion*/
	string casilla[4]; // Este arreglo servir� para separar el usuario y la contrase�a guard�ndolos en una casilla distinta
	size_t pos = 0; // variable que contendr� la posici�n donde se encuentra la coma que separa el usuario de la contrase�a
	int contador = 0; // Servir� para avanzar en las casillas de casilla
	string dato; // Contendr� temporalmente el usuario o la contrase�a mientras se separan
	string dominio = "upm.es";//para comprobar que el usuario pertenece a la UPM
	int fin = 0, correcto=0;
	Fichero(string c, string l, string f) :contenido(c),linea(l), fecha (f) {}
	Fichero() :contenido(""), linea(""),fecha("") {}

	int failpasw = 0; //flag en caso de que se introduzca la contrase�a err�nea

	void registrarstock(componente* c, int cantt);
	void registrarretirada(int cant, string uno, string dos, string tres, string cr,int c);
	void registraroperacion(componente*c, string cr, int cant);
	int comprobarusuario(string correo, string passw);
	void registrarusuario(usuario* us);
	int sumarcantidades(int cant, string nbusc, string tbusc, string ebusc);
	int restarcantidades(int cant, string nbusc, string tbusc, string ebusc);

	int sumarintstring(int entero, const string& cadena); 
	int restarintstring(int entero, const string& cadena);
}; 