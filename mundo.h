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
	float x,y,z; //variables utilizadas para establecer la posición del ojeador en las pantallas
	
	/*Variables que guardan respuestas del usuario*/
	char sesion, respuesta; //sobre si desea retirar o donar (respuesta), sobre si dispone de cuenta en el sistema o no (sesion).
	int resp2; //sobre si desea realizar alguna operación más.
	string correo, passw; // guardan datos del usuario (correo electrónico y contraseña)

	/*Variables necesarias para retirar material*/
	string eleccion1, eleccion2, eleccion3; // guardan los datos identificativos de cada componente para retirar material

	/*Variables necesarias para donar material*/
	int opcion;//para elegir el tipo de donacion
	string resistencia, condensador, color, placa, model, tamano, nuevo1, nuevo2 = " ", nuevo3 = " "; //especificaciones de cada componente (Valor, modelo de placa, color del led...)
	int cant;//cantidad de componentes que se donan
	

	/*Variables necesarias para leer fichero y comprobar los datos*/
	string linea; // Variable temporal donde se almacenarán usuario y contraseña separados por coma y obtenidos desde el archivo de texto
	string contenido; //almacena líneas de fichero para escribirlas juntas
	string casilla[2]; // Este arreglo servirá para separar el usuario y la contraseña guardándolos en una casilla distinta
	size_t pos = 0; // variable que contendrá la posición donde se encuentra la coma que separa el usuario de la contraseña
	int contador = 0; // Servirá para avanzar en las casillas del arreglo
	string dato; // Contendrá temporalmente el usuario o la contraseña mientras se identifican en la linea del fichero
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