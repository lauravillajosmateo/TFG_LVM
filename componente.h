#pragma once
#include <string>

using namespace std;

class componente
{
protected:
	
	string nombre, tipo;
	int cantidad;

public:
	componente(string n,int c) :nombre(n), cantidad(c) { tipo = ""; }
	componente(string n, string t, int c):nombre(n), tipo(t), cantidad(c){}
	componente() :nombre("0"), tipo("0"),cantidad(0) {}


	void setnombre(string n);
	string getnombre();
	string gettipo();
	void setcantidad(int c);
	int getcantidad();
	virtual string getinfo()=0;

	
};