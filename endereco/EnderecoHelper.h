#include <iostream>
#include <fstream>
#include <cstring>
#include "../arvoreBinaria/ArvoreBinaria.h"
#include "../listaDinamicaTemplate/ListaDT.h"
#include <stdlib.h>
#include <vector>
using namespace std;

class EnderecoHelper
{
public:
	EnderecoHelper(string);
	~EnderecoHelper();
	string pegaUltimoEndCode();
	ListaDT<End> *pegaListaEnderecos();
	ArvoreBinaria pegaArvoreEnderecos();
	void listarEnderecos();
	End buscarPorCep(string);
	void inserir(End);
	void excluirPorCep(string);
private:
	string arquivoCSV;
};