#pragma once
#define MAX_COMP 5000
#include <iostream>

class usuario;


class ListaUsuarios
{

	usuario* lista[MAX_COMP];
	int num;

public:
	ListaUsuarios();
	bool agregar(usuario* u);

};