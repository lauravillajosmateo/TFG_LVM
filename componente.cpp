#include "componente.h"
#include <string>

using namespace std;

void componente::setnombre(string n)
{
	nombre = n;
}

string componente::getnombre()
{
	return nombre;
}

string componente::gettipo()
{
	return tipo;
}

void componente::setcantidad(int c)
{
	cantidad = c;
}

int componente::getcantidad()
{
	return cantidad;
}


