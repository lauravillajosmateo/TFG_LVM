#include "componente.h"
#include "usuario.h"
#include "Fichero.h"
#include "Resistencia.h"
#include "Condensador.h"
#include "Led.h"
#include "Placa.h"
#include "Cable.h"
#include "Otro.h"
#include "Protoboard.h"
#include "ListaComponentes.h"
#include "ListaUsuarios.h"

class mundo
{
public:
	float x,y,z; //variables utilizadas para establecer la posici�n del ojeador en las pantallas
	
	/*Variables que guardan respuestas del usuario*/
	char sesion, respuesta; //sobre si desea retirar o donar (respuesta), sobre si dispone de cuenta en el sistema o no (sesion).
	int resp2; //sobre si desea realizar alguna operaci�n m�s.
	string correo, passw; // guardan datos del usuario (correo electr�nico y contrase�a)

	/*Variables necesarias para retirar material*/
	string eleccion1, eleccion2, eleccion3; // guardan los datos identificativos de cada componente para retirar material

	/*Variables necesarias para donar material*/
	int opcion;//para elegir el tipo de donacion
	string resistencia, condensador, color, placa, model, tamano, nuevo1, nuevo2 = " ", nuevo3 = " "; //especificaciones de cada componente (Valor, modelo de placa, color del led...)
	int cant;//cantidad de componentes que se donan
	

	/*Variables necesarias para leer fichero y comprobar los datos*/
	string linea; // Variable temporal donde se almacenar�n usuario y contrase�a separados por coma y obtenidos desde el archivo de texto
	string contenido; //almacena l�neas de fichero para escribirlas juntas
	string casilla[2]; // Este arreglo servir� para separar el usuario y la contrase�a guard�ndolos en una casilla distinta
	size_t pos = 0; // variable que contendr� la posici�n donde se encuentra la coma que separa el usuario de la contrase�a
	int contador = 0; // Servir� para avanzar en las casillas del arreglo
	string dato; // Contendr� temporalmente el usuario o la contrase�a mientras se identifican en la linea del fichero
	string dominio = "upm.es"; //para comprobar que el usuario pertenece a la UPM
	int fin = 0, correcto=0;

	ListaComponentes listacomponentes;
	ListaUsuarios listausuarios;
	Fichero fich;

	mundo();
	~mundo();
	char getrespuesta();

	void inicializa();
	int iniciarsesion();
	void dibuja();
	void mueve();
	int donar();
	int retirar();
	void dibujadonar();
	void dibujaretirar();
	void dibujasesion();

};