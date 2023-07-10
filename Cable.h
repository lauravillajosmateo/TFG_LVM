#pragma once
#include "componente.h"


class Cable :public componente
{
	string extra="-";

public:
	Cable() :componente() {}
	Cable(string n, string t, int c) :componente(n, t, c) {}
	string getinfo();
};