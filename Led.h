#pragma once
#include "componente.h"


class Led :public componente
{
private:
	string extra="-";
public:
	Led() :componente() {}
	Led(string n, string t, int cc) :componente(n, t, cc){}
	Led(string n,string t, int cc, string e) :componente(n,t,cc), extra(e) {}
	string getinfo();
};