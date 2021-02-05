#include <iostream>
#include "ListaDT.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ListaDT<string> *minhaLista = new ListaDT<string>();
	minhaLista->adicionaNoComeco("Isaac");
	minhaLista->adicionaNoComeco("Allison");
	minhaLista->adicionaNoComeco("Cuba_Livre");
	
	minhaLista->printTudo();
	cout << endl;

	minhaLista->adicionaNoFim("Kaycote");
	minhaLista->adicionaNoFim("Higór_sem_freio");
	minhaLista->adicionaNoFim("Marciola");

	minhaLista->printTudo();
	cout << endl;
;

	lista<string> *a = minhaLista->getCelula(3);
	cout << a->valor << endl;

	minhaLista->adicionaPorPosicao(3, "Mateuzin");
	minhaLista->printTudo();
	cout << endl;

	a = minhaLista->getCelula(3);
	cout << a->valor << endl;

	minhaLista->deletaPorPosicao(3);
	minhaLista->printTudo();
	cout << endl;

	return 0;
}