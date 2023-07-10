#pragma once
#include "componente.h"
#include "Fichero.h"


class Otro :public componente
{
private:
	string extra="-";
public:
	Otro():componente() {}
	Otro(string n, string t, int c, string e) :componente(n,t,c), extra(e) {}
	Otro(string n, string t, int c) :componente(n, t,c){}
	Otro(string n, int c) :componente(n,c) {}

	string getinfo();
	

};