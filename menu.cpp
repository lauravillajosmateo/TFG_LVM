#include "menu.h"
#include <iostream>
#include<Windows.h>

using namespace std;

menu::menu()
{
	estado = INICIO;
	tiempo = 0.000f;
	audio = true;
	x = 4.0;
	y = 4.0;
	z = 15.0;
}

menu::~menu()
{

}

void menu::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e' || key == 'E')
		{
			mundo1.inicializa();
			audio = true;
			tiempo = 0;
			ETSIDI::stopMusica();
			estado = SESION;
		
		}
		if (key == 's' || key == 'S')
			exit(0);
	}


}

void menu::dibuja()
{
	if (estado == INICIO)
	{
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(255, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 32);
		ETSIDI::printxy("Bienvenido a", -4, 11);
		ETSIDI::printxy("SecondLife ETSIDI", -9, 9);
		ETSIDI::setTextColor(255, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -6, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -6, 6);
		ETSIDI::printxy("Trabajo Fin de Grado", 2, 3);
		ETSIDI::printxy("Universidad Politecnica de Madrid", 2, 2);
		ETSIDI::printxy("", 2, 1);
		ETSIDI::printxy("Laura Villajos Mateo", 2, 4);
		ETSIDI::printxy("", 2, 5);
		if (audio) {
			ETSIDI::play("sonidos/inicio.mp3");
			audio = false;
			tiempo = 0;
		}

	}
	else if (estado == SESION)
	{
		mundo1.dibujasesion();
		
	}
	else if (estado == JUEGO)
	{
	
		//mundo1.dibuja();
		mundo1.dibujadonar();
	}
		
	else if (estado == RETIRAR)
	{
		mundo1.dibujaretirar();
		
	}
	else if (estado == DONAR)
	{
		mundo1.dibujadonar();
	
	}
}

void menu::mueve()
{
	if (estado == SESION)
	{
		if (mundo1.iniciarsesion() == 1)
		{
			estado = JUEGO;
		}
	}
	else if (estado == JUEGO) {
		ETSIDI::playMusica("sonidos/ambiente.mp3", true);
		
		mundo1.mueve();
		resp = mundo1.getrespuesta();
		if (resp == 'r' || resp == 'R')
		{
			estado = RETIRAR;
			system("cls");
			if (mundo1.retirar() == 1)
			{
				estado = JUEGO;
			}
			else
			{
				cout << "GRACIAS por utilizar SecondLife ETSIDI, hasta la proxima." << "\n";
				Sleep(2000);
				exit(0);
			}
		}

		else if (resp == 'd' || resp == 'D')
		{
			estado = DONAR;
			system("cls");
			if (mundo1.donar() == 1)
			{
				estado = JUEGO;
			}
			else
			{
				cout << "GRACIAS por utilizar SecondLife ETSIDI, hasta la proxima." << "\n";
				Sleep(2000);
				exit(0);
			}
		}

		else
		{
			ETSIDI::playMusica("sonidos/ambiente.mp3", false);
			ETSIDI::playMusica("sonidos/windows.mp3", true);
			Sleep(2000);
			exit(0);
			
		}
		
	}

}

