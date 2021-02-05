#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
template<class Type>
struct lista
{
	Type valor;
	struct lista *proximo;
	struct lista *anterior;
};

template<class Type>
class ListaDT
{
public:
	
	int tam;
	struct lista<Type> *lD;
	struct lista<Type> *primeiro;
	struct lista<Type> *ultimo;
	struct lista<Type> *pAnterior;
	struct lista<Type> *pProximo;
	struct lista<Type> *pAtual;
	ListaDT();
	~ListaDT();
	void adicionaNoComeco(Type);
	void adicionaNoFim(Type);
	struct lista<Type>* getCelula(int);
	Type getValorPorPosicao(int);
	void adicionaPorPosicao(int, Type);
	void deletaPorPosicao(int);
	void printTudo();
	vector<Type> busca(Type);
	void deleta(Type);
	void gravarLista(string);

};

template<class Type>
Type ListaDT<Type>::getValorPorPosicao(int posicao){
	if (posicao >= 0 && posicao <= this->tam)
	{
		this->lD = new struct lista<Type>;
		this->lD = this->primeiro;
		for (int i = 0; i < posicao; i++)
		{
			this->lD = this->lD->proximo;
		}
		return this->lD->valor;
	}
	//return NULL; //Essa função está com um erro, é preciso criar uma exeption
};

template<class Type>
ListaDT<Type>::ListaDT(){
	this->tam = 0;
	this->primeiro = NULL;
	this->ultimo = NULL;
};
template<class Type>
ListaDT<Type>::~ListaDT(){
	delete this->lD;
	delete this->primeiro;
	delete this->ultimo;
	delete this->pAnterior;
	delete this->pAtual;
	delete this->pProximo;
};
template<class Type>
void ListaDT<Type>::adicionaNoComeco(Type v){
	this->lD = new  struct lista<Type>;
	this->lD->valor = v;
	this->lD->proximo = this->primeiro;
	this->lD->anterior = NULL;
	this->primeiro = this->lD;
	if(this->tam == 0){
		this->ultimo = this->primeiro;
	}
	this->tam++;
};
template<class Type>
void ListaDT<Type>::adicionaNoFim(Type v){
	if(this->tam == 0){
		this->adicionaNoComeco(v);
	}
	else{
		this->lD = new struct lista<Type>;
		this->lD->valor = v;
		this->lD->proximo = NULL;
		this->lD->anterior = this->ultimo;
		this->ultimo->proximo = this->lD;
		this->ultimo = this->lD;
		this->tam++;
	}
};
template<class Type>
struct lista<Type>* ListaDT<Type>::getCelula(int posicao){
	if (posicao >= 0 && posicao <= this->tam)
	{
		//this->lD = new struct lista<Type>;
		this->lD = this->primeiro;
		for (int i = 0; i < posicao; i++)
		{
			this->lD = this->lD->proximo;
		}
		return this->lD;
	}
	return NULL;
};
template<class Type>
void ListaDT<Type>::adicionaPorPosicao(int posicao, Type v){
	if (posicao == 0)
	{
		this->adicionaNoComeco(v);
	}
	else if(posicao == this->tam)
	{
		this->adicionaNoFim(v);
	}
	else if(posicao >= 0 && posicao <= this->tam)
	{
		this->pAnterior = new struct lista<Type>;
		this->pAnterior = this->getCelula(posicao-1);
		this->lD = new struct lista<Type>;
		this->lD->valor = v;
		this->lD->proximo = this->pAnterior->proximo;
		this->pAnterior->proximo = this->lD;
	}
};

template<class Type>
void ListaDT<Type>::deletaPorPosicao(int posicao){
	//this->pAnterior = new struct lista<Type>;
	this->pAnterior = this->getCelula(posicao-1);
	//this->pAtual = new struct lista<Type>;
	this->pAtual = this->getCelula(posicao);
	//this->pProximo = new struct lista<Type>;
	this->pProximo = this->getCelula(posicao+1);

	this->pAnterior->proximo = this->pAtual->proximo;
	this->pProximo->anterior = this->pAtual->anterior;;
};

template<class Type>
void ListaDT<Type>::printTudo(){
	struct lista<Type> *p = this->primeiro;
	while(p != NULL){
		cout << p->valor << endl;
		p = p->proximo;
	}
};

template<class Type>
vector<Type> ListaDT<Type>::busca(Type v){
	vector<Type> vt;
	struct lista<Type> *p = this->primeiro;
	while(p != NULL){
		if(p->valor == v)
			vt.push_back(p->valor);
		p = p->proximo;
	}
	return vt;
};

template<class Type>
void ListaDT<Type>::deleta(Type v){
	int posicao = atoi((v.getEndereco_codigo()).c_str());
	this->pAnterior = this->getCelula(posicao-1);
	this->pAtual = this->pAnterior->proximo;
	if (pAtual->proximo != NULL){
		this->pProximo = this->pAtual->proximo;
		this->pProximo->anterior = this->pAtual->anterior;;
	}

	this->pAnterior->proximo = this->pAtual->proximo;
};

template<class Type>
void ListaDT<Type>::gravarLista(string arqLista){
	ofstream arq_lista;
	arq_lista.open(arqLista);

	this->lD = primeiro;
	while(this->lD != NULL){
		arq_lista << this->lD->valor << endl;
		this->lD = this->lD->proximo;
	}
	arq_lista.close();
}