#pragma once
#define MAX_COMP 1000
#include <iostream>

class componente;


class ListaComponentes
{

	componente* lista[MAX_COMP];
	int num;

public:
	ListaComponentes();
	bool agregar(componente* c);

	friend class Resistencia;
	friend class Condensador;
	friend class Led;
	friend class Placa;
	friend class Cable;
	friend class Protoboard;
	friend class Otro;
};
