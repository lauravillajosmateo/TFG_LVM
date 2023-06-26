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
	float x,y,z; //variables para establecer la posición del ojeador
	
	char respuesta, sesion;
	string eleccion1, eleccion2, eleccion3;
	int machomacho, hembrahembra,hembramacho, opcion,cant, resp2;
	string correo, passw, contenido, contenido2, contenido3, contenido4, conteniddo, contenidddo, resistencia, condensador, color, placa,nuevo1, nuevo2=" ", nuevo3=" ", model,tamano;
	string linea; // Variable temporal donde se almacenarán usuario y contraseña separados por coma y obtenidos desde el archivo de texto
	string casilla[2]; // Este arreglo servirá para separar el usuario y la contraseña guardándolos en una casilla distinta
	size_t pos = 0; // variable que contendrá la posición donde se encuentra la coma que separa el usuario de la contraseña
	int contador = 0; // Servirá para avanzar en las casillas del arreglo
	string dato; // Contendrá temporalmente el usuario o la contraseña mientras se separan
	string dominio = "upm.es";
	int fin = 0, correcto=0;

	ListaComponentes listacomponentes;
	ListaUsuarios listausuarios;
	Fichero fich;


	mundo();
	~mundo();
	char getrespuesta();

	void inicializa();
	void dibuja();
	void mueve();
	int donar();
	int retirar();
	void dibujadonar();
	void dibujaretirar();
	void dibujasesion();
	int iniciarsesion();


};