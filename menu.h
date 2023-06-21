#pragma once
#include "mundo.h"
#include "ETSIDI.h"

enum Estado { INICIO, SESION, JUEGO, RETIRAR, DONAR };

class menu
{
public:
	menu();
	~menu();
	void tecla(unsigned char key);
	void dibuja();
	void mueve();
	char resp;
	float x;
	float y;
	float z;
	

protected:
	mundo mundo1;
	Estado estado;
	float tiempo;
	bool audio;

};

