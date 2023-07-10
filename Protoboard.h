#pragma once
#include "componente.h"


class Protoboard :public componente
{
private:
	string extra="-";
public:
	Protoboard() :componente() {}
	Protoboard(string n, string t, int c) :componente(n, t, c){}
	Protoboard(string n,string t, int c, string e) :componente(n,t,c), extra(e) {}
	string getinfo();
};