#pragma once
#include "componente.h"

class Placa :public componente
{
private:
	string modelo;
public:
	Placa() :componente() {}
	Placa(string n, string t, int c) :componente(n,t,c) {}
	Placa(string n, string t, int c, string m) :componente(n,t,c), modelo(m){}

	string getinfo();
	
};