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
	posini.x, posini.y, posfin.x, posfin.y = 0;
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
	cin >> respuesta;
	fflush;

	if (respuesta == 'R' || respuesta == 'r')
	{
		cout << "Has elegido retirar material" << endl;
	
	}
	else if (respuesta == 'D' || respuesta == 'd')
	{
		cout << "Has elegido donar material" << endl;

	}
	else
	{
		cout << "Has elegido salir" << endl;
		exit(0);
	}
}

void mundo::donar()
{
	cout << "¡Gracias por participar en este proyecto!" << endl;
	while (opcion == 0 || opcion > 8)
	{

		cout << "A continuacion, te mostramos algunos elementos que puedes donar." << "\n" << "Elige el numero correspondiente y si el elemento que deseas donar no se encuentra en la lista, elige la opcion OTRO." << endl;
		cout << "1-RESISTENCIAS" << "\n" << "2-CONDENSADORES" << "\n" << "3-LEDS" << "\n" << "4-PROTOBOARDS" << "\n" << "5-CABLES" << "\n" << "6-PLACAS" << "\n" << "7-OTRO" << "\n" <<"8-SALIR" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 0: {
			cout << "0 no corresponde a ningún material" << endl;
			break;
		}
		case 1: {
			cout << "Escribe el valor de la resistencia:" << endl;
			cin >> resistencia;
			ifstream archivo("stock.txt");
			while (getline(archivo, linea))
			{
				contenido = contenido + linea + "\n";
			}
			archivo.close();

			ofstream archivo1("stock.txt");
			archivo1 << contenido << "Resistencia " << resistencia;
			ifstream archivo2("registro.txt");
			while (getline(archivo2, linea))
			{
				contenido2 = contenido2 + linea + "\n";
			}
			archivo2.close();

			ofstream archivo3("registro.txt");
			archivo3 << contenido2 << correo <<" ha donado una resistencia de "<< resistencia;
			break;
		}
		case 2: {
			cout << "Escribe el valor del condensador:" << endl;
			cin >> condensador;
			ifstream archivo4("stock.txt");
			while (getline(archivo4, linea))
			{
				contenido = contenido + linea + "\n";
			}
			archivo4.close();

			ofstream archivo5("stock.txt");
			archivo5 << contenido << "Condensador " << condensador;
			ifstream archivo6("registro.txt");
			while (getline(archivo6, linea))
			{
				contenido2 = contenido2 + linea + "\n";
			}
			archivo6.close();

			ofstream archivo7("registro.txt");
			archivo7 << contenido2 << correo << " ha donado un condensador de " << condensador;
			break;
		}
		case 3: {
			cout << "Escribe el color del LED" << endl;
			cin >> color;
			ifstream archivo8("stock.txt");
			while (getline(archivo8, linea))
			{
				contenido = contenido + linea + "\n";
			}
			archivo8.close();

			ofstream archivo9("stock.txt");
			archivo9 << contenido << "LED " << color;
			ifstream archivo10("registro.txt");
			while (getline(archivo10, linea))
			{
				contenido2 = contenido2 + linea + "\n";
			}
			archivo10.close();

			ofstream archivo11("registro.txt");
			archivo11 << contenido2 << correo << " ha donado un LED de color " << color;
			break;
		}
		case 4: {
			ifstream archivo12("stock.txt");
			while (getline(archivo12, linea))
			{
				contenido = contenido + linea + "\n";
			}
			archivo12.close();

			ofstream archivo13("stock.txt");
			archivo13 << contenido << "Protoboard";
			ifstream archivo14("registro.txt");
			while (getline(archivo14, linea))
			{
				contenido2 = contenido2 + linea + "\n";
			}
			archivo14.close();

			ofstream archivo15("registro.txt");
			archivo15 << contenido2 << correo << " ha donado una protoboard";
			break;
		}
		case 5: {
			cout << "Escribe el numero de cables hembra-macho que deseas donar:" << endl;
			cin >> hembramacho;
			cout << "Escribe el numero de cables macho-macho que deseas donar:" << endl;
			cin >> machomacho;
			cout << "Escribe el numero de cables hembra-hembra que deseas donar:" << endl;
			cin >> hembrahembra;

			if (hembramacho != 0)
			{
				ifstream archivo16("stock.txt");
				while (getline(archivo16, linea))
				{
					contenido = contenido + linea + "\n";
				}
				archivo16.close();

				ofstream archivo17("stock.txt");
				archivo17 << contenido << hembramacho<<" cables hembra-macho";
				ifstream archivo18("registro.txt");
				while (getline(archivo18, linea))
				{
					contenido2 = contenido2 + linea + "\n";
				}
				archivo18.close();

				ofstream archivo19("registro.txt");
				archivo19 << contenido2 << correo << " ha donado "<<hembramacho<<" cables hembra-macho";
			}
			if (machomacho != 0)
			{
				ifstream archivo20("stock.txt");
				while (getline(archivo20, linea))
				{
					conteniddo = conteniddo + linea + "\n";
				}
				archivo20.close();

				ofstream archivo21("stock.txt");
				archivo21 << conteniddo << machomacho<<" cables macho-macho";
				ifstream archivo22("registro.txt");
				while (getline(archivo22, linea))
				{
					contenido3 = contenido3 + linea + "\n";
				}
				archivo22.close();

				ofstream archivo23("registro.txt");
				archivo23 << contenido3 << correo << " ha donado " << machomacho<<" cables macho-macho";
			}
			if (hembrahembra != 0)
			{
				ifstream archivo24("stock.txt");
				while (getline(archivo24, linea))
				{
					contenidddo = contenidddo + linea + "\n";
				}
				archivo24.close();

				ofstream archivo25("stock.txt");
				archivo25 << contenidddo << hembrahembra<< " cables hembra-hembra";
				ifstream archivo26("registro.txt");
				while (getline(archivo26, linea))
				{
					contenido4 = contenido4 + linea + "\n";
				}
				archivo26.close();

				ofstream archivo27("registro.txt");
				archivo27 << contenido4 << correo << " ha donado "<<hembrahembra<<" cables hembra-hembra";
			}
			break;
		}
		case 6:
		{
			cout << "Escribe el nombre de la placa (por ejemplo, arduinouno, arduinomega, stm32...):" << endl;
			cin >> placa;
			ifstream archivo28("stock.txt");
			while (getline(archivo28, linea))
			{
				contenido = contenido + linea + "\n";
			}
			archivo28.close();

			ofstream archivo29("stock.txt");
			archivo29 << contenido << "Placa " << placa;
			ifstream archivo30("registro.txt");
			while (getline(archivo30, linea))
			{
				contenido2 = contenido2 + linea + "\n";
			}
			archivo30.close();

			ofstream archivo31("registro.txt");
			archivo31 << contenido2 << correo << " ha donado una placa " << placa;
			break;
		}
		case 7:
		{
			cout << "Escribe una breve descripcion del material. Maximo 3 palabras. Por ejemplo, sensor luz arduino o servomotor:" << endl;
			cin >> nuevo1>>nuevo2>>nuevo3;
			ifstream archivo32("stock.txt");
			while (getline(archivo32, linea))
			{
				contenido = contenido + linea + "\n";
			}
			archivo32.close();

			ofstream archivo33("stock.txt");
			archivo33 << contenido << nuevo1<<" "<<nuevo2<<" "<<nuevo3;
			ifstream archivo34("registro.txt");
			while (getline(archivo34, linea))
			{
				contenido2 = contenido2 + linea + "\n";
			}
			archivo34.close();

			ofstream archivo35("registro.txt");
			archivo35 << contenido2 << correo << " ha donado "<< nuevo1<<" "<<nuevo2<<" "<<nuevo3;
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
			cout << "------------DONACION COMPLETADA. MUCHAS GRACIAS POR TU AYUDA.---------------------------------------------------" << endl;
			

		}
	}
}

void mundo::retirar()
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
	cout << "Describe el componente que necesitas. Si no hay disponibilidad de lo que estás buscando, escribe salir para cerrar del programa." << endl;
	cin >> eleccion;
	
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

int mundo::iniciarsesion()
{
	
	cout << "Es necesario iniciar sesion en el sistema. Escriba S si ya dispone de una cuenta o N si es necesario registrarse" << endl;
	cin >> sesion;

	if (sesion == 'S' || sesion == 's')
	{
		cout << "Bienvenido de nuevo. Introduzca su correo electronico de la UPM:" << endl;
		cin >> correo;

		cout << "Escribe la contraseña" << endl;
		cin >> passw;
		//comprobar correo y contraseña

		ifstream fichero("datos.txt");
		if (!fichero)
		{
			cout << "Error al crear el archivo datos.txt\n";
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

		}

		if (correo == casilla[0] && passw == casilla[1]) {

			cout << "Usuario correcto." << endl;
			correcto = 1;

		}

		else {

			cout << "Los datos ingresados son incorrectos o no esta registrado en el sistema." << endl;
			correcto = 0;

		}
		}
			
		
	
	else if (sesion == 'N' || sesion == 'n')
	{
		while (correcto == 0)
		{
			cout << "Es necesario registrarse para proceder con la accion." << endl;
			cout << "Para registrarte escribe tu correo electronico UPM." << endl;
			cin >> correo;
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

		cout << "Escribe una contraseña." << endl;
		cin >> passw;
		cout << "--------------REGISTRO COMPLETADO CORRECTAMENTE--------------" << endl;

		ifstream archivo("datos.txt");
		while (getline(archivo, linea))
		{
			contenido = contenido + linea + "\n";
		}
		archivo.close();

		ofstream archivo1("datos.txt");
		archivo1 << contenido << correo << "," << passw << ",";
		
	}
	return correcto;
}
