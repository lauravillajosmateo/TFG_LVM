#include "ListaPiezas.h"
#include "Pieza.h"
#include "peon.h"
#include "Vector.h"
#include "componente.h"
#include "usuario.h"



class mundo
{
public:
	float x,y,z; //variables para establecer la posición del ojeador
	Vector posini, posfin;
	char respuesta, sesion;
	string eleccion;
	int machomacho, hembrahembra,hembramacho, opcion;
	string correo, passw, contenido, contenido2, contenido3, contenido4, conteniddo, contenidddo, resistencia, condensador, color, placa,nuevo1, nuevo2=" ", nuevo3=" ";
	string linea; // Variable temporal donde se almacenarán usuario y contraseña separados por coma y obtenidos desde el archivo de texto
	string casilla[2]; // Este arreglo servirá para separar el usuario y la contraseña guardándolos en una casilla distinta
	size_t pos = 0; // variable que contendrá la posición donde se encuentra la coma que separa el usuario de la contraseña
	int contador = 0; // Servirá para avanzar en las casillas del arreglo
	string dato; // Contendrá temporalmente el usuario o la contraseña mientras se separan
	string dominio = "upm.es";
	int fin = 0, correcto=0;

	
	ListaPiezas listapiezas;


	mundo();
	~mundo();
	char getrespuesta();

	void inicializa();
	void dibuja();
	void mueve();
	void donar();
	void retirar();
	void dibujadonar();
	void dibujaretirar();
	VOID dibujasesion();
	int iniciarsesion();

	void dibujatblancas();
	void dibujatnegras();

	
	

};