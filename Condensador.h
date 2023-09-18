#pragma once
#include "componente.h"


class Condensador :public componente
{
private:
	string extra="-";
public:
	Condensador() :componente() {}
	Condensador(string n, string t, int c) :componente(n, t, c) {}
	Condensador(string n, string t, int c, string e) :componente(n,t,c), extra(e) {}
	string getinfo();
};