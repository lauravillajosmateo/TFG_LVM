#include "ListaUsuarios.h"
#include "usuario.h"


using namespace std;

ListaUsuarios::ListaUsuarios()
{
	for (int i = 0; i < MAX_COMP; i++) {
		lista[i] = 0;
	}
	num = 0;
}

bool ListaUsuarios::agregar(usuario* u)
{
	for (int i = 0; i < num; i++) {
		if (lista[i] == u)
			return false;
	}

	if (num < MAX_COMP)
		lista[num++] = u;
	else
		return false;
	return true;
}