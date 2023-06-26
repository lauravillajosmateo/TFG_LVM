#pragma once
#include <string>

using namespace std;

class usuario
{
protected:
	string correo, contrasena;

public:
	usuario(string c, string cc) : correo(c), contrasena(cc){}
	void setcorreo(string c);
	string getcorreo();
	void setcontrasena(string cc);
	string getcontrasena();
};