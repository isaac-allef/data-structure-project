#include <iostream>
#include "End.h"
using namespace std;

End::End(){};
End::~End(){};

bool End::isIgual(End lhs){
    	return this->endereco_cep == lhs.getEndereco_cep() && this->endereco_codigo == lhs.endereco_codigo;
};
bool End::isMaior(End lhs){
    	return this->endereco_cep > lhs.getEndereco_cep();
};
bool End::isMenor(End lhs){
    	return this->endereco_cep < lhs.getEndereco_cep();
};
bool End::isMaiorOuIgual(End lhs){
    	return this->endereco_cep >= lhs.getEndereco_cep();
};
bool End::isMenorOuIgual(End lhs){
    	return this->endereco_cep <= lhs.getEndereco_cep();
};
string End::toString(){
	return this->endereco_codigo + ";" + this->endereco_cep + ";" + this->endereco_logradouro + ";" + this->endereco_complemento + ";" + this->bairro_descricao + ";" + this->cidade_descricao + ";" + this->uf_sigla + ";" + uf_descricao;
};

void End::zerar(){
	this->endereco_codigo = "";
	this->endereco_cep  = "";
	this->endereco_logradouro = "";
	this->endereco_complemento = "";
	this->bairro_descricao = "";
	this-> cidade_descricao = "";
	this->uf_sigla = "";
	this->uf_descricao = "";
}

string End::getEndereco_codigo(){
	return this->endereco_codigo;
};
void End::setEndereco_codigo(string ec){
	this->endereco_codigo = ec;
};


string End::getEndereco_cep(){
	return this->endereco_cep;
};
void End::setEndereco_cep(string ec){
	this->endereco_cep = ec;
};


string End::getEndereco_logradouro(){
	return this->endereco_logradouro;
};
void End::setEndereco_logradouro(string ec){
	this->endereco_logradouro = ec;
};


string End::getEndereco_complemento(){
	return this->endereco_complemento;
};
void End::setEndereco_complemento(string ec){
	this->endereco_complemento = ec;
};


string End::getBairro_descricao(){
	return this->bairro_descricao;
};
void End::setBairro_descricao(string ec){
	this->bairro_descricao = ec;
};


string End::getCidade_descricao(){
	return this-> cidade_descricao;
};
void End::setCidade_descricao(string ec){
	this->cidade_descricao = ec;
};


string End::getUf_sigla(){
	return this->uf_sigla;
};
void End::setUf_sigla(string ec){
	this->uf_sigla = ec;
};


string End::getUf_descricao(){
	return this->uf_descricao;
};
void End::setUf_descricao(string ec){
	this->uf_descricao = ec;
};