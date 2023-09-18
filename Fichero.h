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

	string contenido,linea; // Variables temporals donde se almacenará información del archivo de texto
	string fecha; // se utiliza para registrar las operaciones con la fecha del día en que se realizan dentro del fichero registro


public:

	/*Variables necesarias para leer fichero y comprobar los datos del usuario al iniciar sesion*/
	string casilla[4]; // Este arreglo servirá para separar el usuario y la contraseña guardándolos en una casilla distinta
	size_t pos = 0; // variable que contendrá la posición donde se encuentra la coma que separa el usuario de la contraseña
	int contador = 0; // Servirá para avanzar en las casillas de casilla
	string dato; // Contendrá temporalmente el usuario o la contraseña mientras se separan
	string dominio = "upm.es";//para comprobar que el usuario pertenece a la UPM
	int fin = 0, correcto=0;
	Fichero(string c, string l, string f) :contenido(c),linea(l), fecha (f) {}
	Fichero() :contenido(""), linea(""),fecha("") {}

	int failpasw = 0; //flag en caso de que se introduzca la contraseña errónea

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