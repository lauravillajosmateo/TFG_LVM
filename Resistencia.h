#pragma once
#include "componente.h"
#include <fstream>
#include <iostream>

class Resistencia : public componente
{
private:
	string extra="-";
public:
	Resistencia() :componente() {}
	Resistencia(string n, string t, int c) :componente(n,t,c) {}
	Resistencia(string n, string t, int c, string e) :componente(n, t, c), extra(e) {}

	string getinfo();
};