#include "mundo.h"
#include <freeglut.h>
#include <iostream>
#include "ETSIDI.h"
#include <fstream>  // Para ofstream
#include <string>
#include <conio.h>


using namespace std;


mundo::mundo()
{
	x = 4.0;
	y = 4.0;
	z = 15.0;
}

mundo::~mundo()
{
}

char mundo::getrespuesta()
{
	return respuesta;
}


void mundo::inicializa()
{
	
}

void mundo::dibuja() {
	gluLookAt(x, y, z,  
		4.0, 4.0, 0.0,      
		0.0, 1.0, 0.0);    

	glDisable(GL_LIGHTING);
	glColor3ub(253, 253, 180); //amarillo
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(0,2.5,0);
	glVertex3f(8, 2.5, 0);
	glVertex3f(8, 0, 0);
	glEnd();

	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 32);
	ETSIDI::printxy("Segun lo que desees hacer,", -10, 11);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
	ETSIDI::printxy("escribe R si deseas retirar material o d si deseas donarlo.", -10, 9);
	ETSIDI::setTextColor(0,0,0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
	ETSIDI::printxy("RETIRAR / DONAR", -6, 3);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/log1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); 
	glVertex3f(14, 25, 0.1); //arriba izquierda
	glTexCoord2d(1, 1); 
	glVertex3f(24, 25, 0.1); //arriba derecha
	glTexCoord2d(1, 0); 
	glVertex3f(24, 27, 0.1); //abajo izquierda
	glTexCoord2d(0, 0); 
	glVertex3f(14, 27, 0.1); //abajo derecha
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}
	

void mundo::mueve()
{
	
	cout << "Escribe R o D segun lo que deseas hacer. Pulsa cualquier otra letra para salir." << endl;
	cin >> respuesta; cout << "\n";
	fflush;
	
	if (respuesta == 'R' || respuesta == 'r')
	{
		cout << "Has elegido retirar material" <<"\n"<< endl;
	}
	else if (respuesta == 'D' || respuesta == 'd')
	{
		cout << "Has elegido donar material" << "\n" << endl;
	}
	else
	{
		cout << "Has elegido salir" << endl;
	}
}
int mundo::iniciarsesion()
{
	cout << "Es necesario iniciar sesion en el sistema. Escriba S si ya dispone de una cuenta o N si es necesario registrarse" << endl;  cin >> sesion; cout << "\n"<<endl;
	
	if (sesion == 'S' || sesion == 's')
	{
		while (correcto == 0) {
			cout << "Bienvenido de nuevo. Introduzca su correo electronico de la UPM:" << endl; 
			cin >> correo;
			cout << "Escribe la contraseña" << endl;
			cin >> passw;
			correcto = fich.comprobarusuario(correo, passw);//comprobar correo y contraseña
		}
	}

	else if (sesion == 'N' || sesion == 'n')
	{
		while (correcto == 0)
		{
			cout << "Es necesario registrarse para proceder con la accion." << endl; cout << "Para registrarte escribe tu correo electronico UPM." << endl; cin >> correo;
			if (correo.find(dominio) != string::npos) //comprobar correo
			{
				cout << "Bien. Perteneces a la UPM" << endl;
				correcto = 1;
			}
			else
			{
				cout << "ERROR" << endl;
			}
		}

		cout << "Escribe una contraseña." << endl; cin >> passw; cout << "\n";
		cout << "--------------REGISTRO COMPLETADO CORRECTAMENTE--------------" << endl;
		usuario* us = new usuario(correo, passw);
		listausuarios.agregar(us);
		fich.registrarusuario(us);
	}
	return correcto;
}

int mundo::donar()
{
	cout << "¡Gracias por participar en este proyecto!" << endl;
	while (opcion == 0 || opcion > 8)
	{

		cout << "A continuacion, te mostramos algunos elementos que puedes donar." << "\n" << "Elige el numero correspondiente y si el elemento que deseas donar no se encuentra en la lista, elige la opcion OTRO." << endl;
		cout << "1-RESISTENCIAS" << "\n" << "2-CONDENSADORES" << "\n" << "3-LEDS" << "\n" << "4-PROTOBOARDS" << "\n" << "5-CABLES" << "\n" << "6-PLACAS" << "\n" << "7-OTRO" << "\n" << "8-SALIR" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 0: {
			cout << "0 no corresponde a ningún material" << endl;
			break;
		}
		case 1: {
			cout << "Cuantos resistores del mismo valor deseas donar:" << endl; cin >> cant;
			cout << "Escribe su valor:" << endl; cin >> resistencia;

			componente* aux = new Resistencia("Resistencia", resistencia, cant);
			listacomponentes.agregar(aux);
			fich.registrarstock(aux, fich.sumarcantidades(cant, "Resistencia", resistencia, "-"));
			fich.registraroperacion(aux, correo, cant);
			break;
		}
		case 2: {
			cout << "Cuantos condensadores del mismo valor deseas donar:" << endl; cin >> cant;
			cout << "Escribe su valor:" << endl; cin >> condensador;

			componente* aux = new Condensador("Condensador", condensador, cant);
			listacomponentes.agregar(aux);

			fich.registrarstock(aux, fich.sumarcantidades(cant, "Condensador", condensador, "-"));
			fich.registraroperacion(aux, correo, cant);
			break;
		}
		case 3: {
			cout << "Cuantos LEDs del mismo color deseas donar:" << endl; cin >> cant;
			cout << "Escribe el color del LED" << endl;	cin >> color;

			componente* aux = new Led("Led", color, cant);
			listacomponentes.agregar(aux);

			fich.registrarstock(aux, fich.sumarcantidades(cant, "Led", color, "-"));
			fich.registraroperacion(aux, correo, cant);
			break;
		}
		case 4: {
			cout << "Cuantas protoboards iguales deseas donar:" << endl; cin >> cant;
			cout << "Escribe la dimension de la protoboard (grande, alargada, pequeña...)" << endl; cin >> tamano;

			componente* aux = new Protoboard("Protoboard", tamano, cant);
			listacomponentes.agregar(aux);
			fich.registrarstock(aux, fich.sumarcantidades(cant, "Protoboard", tamano, "-"));
			fich.registraroperacion(aux, correo, cant);
			break;
		}
		case 5: {
			cout << "Escribe el numero de cables hembra-macho que deseas donar:" << endl; cin >> cant;
			if (cant != 0) {
				componente* aux = new Cable("Cable", "hembra-macho", cant); listacomponentes.agregar(aux); fich.registrarstock(aux, fich.sumarcantidades(cant, "Cable", "hembra-macho", "-")); fich.registraroperacion(aux, correo, cant);
			}
			cout << "Escribe el numero de cables macho-macho que deseas donar:" << endl; cin >> cant;
			if (cant != 0) {
				componente* aux1 = new Cable("Cable", "macho-macho", cant); listacomponentes.agregar(aux1); fich.registrarstock(aux1, fich.sumarcantidades(cant, "Cable", "macho-macho", "-")); fich.registraroperacion(aux1, correo, cant);
			}
			cout << "Escribe el numero de cables hembra-hembra que deseas donar:" << endl; cin >> cant;
			if (cant != 0) {
				componente* aux2 = new Cable("Cable", "hembra-hembra", cant); listacomponentes.agregar(aux2); fich.registrarstock(aux2, fich.sumarcantidades(cant, "Cable", "hembra-hembra", "-")); fich.registraroperacion(aux2, correo, cant);
			}
			break;
		}

		

		case 6:
		{
			cout << "Escribe cuantas placas iguales deseas donar:" << endl; cin >> cant;
			cout << "Escribe el nombre de la placa (por ejemplo, Arduino, STM32...):" << endl; cin >> placa;
			cout << "Escribe el modelo de la placa (por ejemplo, UNO, MEGA, F407, F411...), si no tiene introduce -:" << endl;	cin >> model;

				componente* aux1 = new Placa("Placa", placa, cant, model);
				fich.registrarstock(aux1, fich.sumarcantidades(cant, "Placa", placa, model));
				fich.registraroperacion(aux1, correo, cant);
				

			break;
		}
		case 7:
		{
			cout << "Escribe una breve descripcion del material. Maximo 3 palabras. Por ejemplo, sensor luz arduino o servomotor. Si despues del nombre, no encuentras palabras para describirlo, introduce -." << endl;
			cout << "1: " << endl; cin >> nuevo1;
			cout << "2: " << endl; cin >> nuevo2;
			cout << "3: " << endl; cin >> nuevo3;
			cout << "Escribe el numero de unidades que deseas donar:" << endl;
			cin >> cant;

			componente* aux = new Otro(nuevo1, nuevo2,cant, nuevo3);
			listacomponentes.agregar(aux);
			fich.registrarstock(aux,fich.sumarcantidades(cant, nuevo1, nuevo2, nuevo3));
			fich.registraroperacion(aux, correo,cant);
			break;
		}
		case 8:
		{
			cout << "Has elegido cerrar el programa" << endl;
			exit(0);
		}
		default:
		{
			cout << "Esta opcion no corresponde a ningun material" << endl;
			break;
		}
				}
				if (opcion != 0 && opcion < 8)
				{
					cout << "Por favor, introduce el material en su cajon correspondiente dentro del armario. Solicita ayuda del personal si es necesario." << endl;
					cout << "------------DONACION COMPLETADA. MUCHAS GRACIAS POR TU AYUDA.---------------------------------------------------" <<"\n" << endl;

				}

			}
			contenido.clear();
			cin.ignore();
			cin.clear();
			cout << "A continuacion, se muestran las siguientes opciones disponibles, elige la opcion que deseas hacer:" << "\n" << "1:Realizar otra operacion." << "\n" << "2:Salir del programa" << endl; cin >> resp2; return resp2;
		}
	

		
 int mundo::retirar()

			  {
				  cout << "¡Esperamos que el material te sea util!" << endl;
				  cout << "A continuacion, te mostramos el stock disponible." << "\n" << "--------------------------------------------------------------------------------------------------------" << endl;

				  ifstream archivo36("stock.txt");
				  while (getline(archivo36, linea))
				  {
					  contenido = contenido + linea + "\n";
				  }
				  archivo36.close();
				  cout << contenido << "--------------------------------------------------------------------------------------------------------" << endl;
				  cout << "Describe el componente que necesitas segun se ha descrito en el stock mostrado incluyendo mayusculas y caracteres especiales. Utiliza 3 palabras o caracteres para ello. Si no hay disponibilidad de lo que estas buscando, escribe salir para cerrar la sesion." << endl;
				  cout << "1: "; cin >> eleccion1; 
				  if (eleccion1 == "salir"||eleccion1=="SALIR")
				  {
					  exit(0);
				  }
				  else
				  {
					  cout << "2: "; cin >> eleccion2; cout << "3: "; cin >> eleccion3; cout << "Escribe la cantidad que deseas retirar:"; cin >> cant;
					  fich.registrarretirada(fich.restarcantidades(cant, eleccion1, eleccion2, eleccion3), eleccion1, eleccion2, eleccion3, correo, cant);
				  }
				  contenido.clear();
				  cin.ignore();
				  cin.clear();
				  cout <<"\n"<< "A continuacion, se muestran las siguientes opciones disponibles, elige la opcion que deseas hacer:" << "\n" << "1:Realizar otra operacion." << "\n" << "2:Salir del programa" << endl; cin >> resp2; return resp2;
			  }
		


void mundo::dibujadonar()
{
	gluLookAt(x, y, z,
		4.0, 4.0, 0.0,
		0.0, 1.0, 0.0);
	glDisable(GL_LIGHTING);
	glColor3ub(255, 0, 0); //rojo
	glBegin(GL_POLYGON);
	glVertex3f(0, 4, 0);
	glVertex3f(0, 6, 0);
	glVertex3f(8, 6, 0);
	glVertex3f(8, 4, 0);
	glEnd();

	ETSIDI::setTextColor(0,0,0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
	ETSIDI::printxy("Gracias por donar", 1, 5);
	ETSIDI::setTextColor(255,255,255);
	ETSIDI::printxy("SecondLife ETSIDI", -2, 8);


}


void mundo::dibujaretirar()
{
	gluLookAt(x, y, z,
		4.0, 4.0, 0.0,
		0.0, 1.0, 0.0);
	glDisable(GL_LIGHTING);
	glColor3ub(255, 0, 0); //rojo
	glBegin(GL_POLYGON);
	glVertex3f(-2, 4, 0);
	glVertex3f(-2, 6, 0);
	glVertex3f(9, 6, 0);
	glVertex3f(9, 4, 0);
	glEnd();

	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
	ETSIDI::printxy("Esperamos que te sea util", -1, 5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::printxy("SecondLife ETSIDI", -2, 8);


}

void mundo::dibujasesion()
{
	gluLookAt(x, y, z,
		4.0, 4.0, 0.0,
		0.0, 1.0, 0.0);
	glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 255); //blanco
	glBegin(GL_POLYGON);
	glVertex3f(-2.5, 4, 0);
	glVertex3f(-2.5, 6, 0);
	glVertex3f(9, 6, 0);
	glVertex3f(9, 4, 0);
	glEnd();

	ETSIDI::setTextColor(0, 255, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
	ETSIDI::printxy("INICIA SESION O REGISTRATE", -2, 5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::printxy("SecondLife ETSIDI", -2, 8);
}


