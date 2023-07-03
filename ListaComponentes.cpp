#include "ListaComponentes.h"
#include "componente.h"


using namespace std;

ListaComponentes::ListaComponentes()
{
	for (int i = 0; i < MAX_COMP; i++) {
		lista[i] = 0;
	}
	num = 0;
}

bool ListaComponentes::agregar(componente* c)
{
	for (int i = 0; i < num; i++) {
		if (lista[i] == c)
			return false;
	}

	if (num < MAX_COMP)
		lista[num++] = c;
	else
		return false;
	return true;
}
