#include <iostream>
#include "EnderecoHelper.h"
using namespace std;

string pegaColunaDeString(int *, string, char, char);

EnderecoHelper::EnderecoHelper(string arquivoCSV){
	this->arquivoCSV = arquivoCSV;
};
EnderecoHelper::~EnderecoHelper(){};

string EnderecoHelper::pegaUltimoEndCode(){
	ifstream arq_;
	string linha, endCod;
	arq_.open(this->arquivoCSV);
	int i=0;
	char c;
	while(c != '\n'){
		i++;
		arq_.seekg(-i, ios::end);
		arq_.get(c);
	}
	getline(arq_, linha);
	arq_.close();
	i=0;
	endCod = pegaColunaDeString(&i, linha, ';', '\0');
	return endCod;
};

ListaDT<End> *EnderecoHelper::pegaListaEnderecos(){
	ifstream arq_end;
	string linha;

	End ende;
	ListaDT<End> *lista = new ListaDT<End>();

	arq_end.open(this->arquivoCSV);
	if (!arq_end.is_open())
	{
		cout << "Arquivo já aberto";
		exit(-1);
	}

	while(getline(arq_end, linha)){
		int i=0;
		ende.setEndereco_codigo(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_cep(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_logradouro(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_complemento(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setBairro_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setCidade_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setUf_sigla(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setUf_descricao(pegaColunaDeString(&i, linha, ';', '\0'));

		lista->adicionaNoFim(ende);
	}
	arq_end.close();
	return lista;
};

ArvoreBinaria EnderecoHelper::pegaArvoreEnderecos(){
	ifstream arq_end;
	string linha;

	End ende;
	ArvoreBinaria arvBin;

	arq_end.open(this->arquivoCSV);
	if (!arq_end.is_open())
	{
		cout << "Arquivo já aberto";
		exit(-1);
	}
	while(getline(arq_end, linha)){
		int i=0;
		ende.setEndereco_codigo(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_cep(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_logradouro(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_complemento(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setBairro_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setCidade_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setUf_sigla(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setUf_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		
		arvBin.insere(ende);
	}
	arq_end.close();
	return arvBin;
};

void EnderecoHelper::listarEnderecos(){
	ifstream arq_end;
	string linha;

	End ende;

	arq_end.open(this->arquivoCSV);
	if (!arq_end.is_open())
	{
		cout << "Arquivo já aberto";
		exit(-1);
	}

	while(getline(arq_end, linha)){
		int i=0;
		ende.setEndereco_codigo(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_cep(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_logradouro(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_complemento(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setBairro_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setCidade_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setUf_sigla(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setUf_descricao(pegaColunaDeString(&i, linha, ';', '\0'));

		cout << ende.getEndereco_codigo() << ";";
		cout << ende.getEndereco_cep() << ";";
		cout << ende.getEndereco_logradouro() << ";";
		cout << ende.getEndereco_complemento() << ";";
		cout << ende.getBairro_descricao() << ";";
		cout << ende.getCidade_descricao() << ";";
		cout << ende.getUf_sigla() << ";";
		cout << ende.getUf_descricao() << endl;
	}
	arq_end.close();
};

string pegaColunaDeString(int *cont, string linha, char delimitador_1, char delimitador_2){
	
	string str;
	while(linha[*cont] != delimitador_1 && linha[*cont] != delimitador_2){
		str += linha[*cont];
		(*cont)++;
	}
	(*cont)++;
	return str;
}

End EnderecoHelper::buscarPorCep(string cep){
	ifstream arq_end;
	string linha;

	End ende;

	arq_end.open(this->arquivoCSV);
	if (!arq_end.is_open())
	{
		cout << "Arquivo já aberto";
		exit(-1);
	}

	while(getline(arq_end, linha)){
		int i=0;
		ende.setEndereco_codigo(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_cep(pegaColunaDeString(&i, linha, ';', '\0'));
		
		if (ende.getEndereco_cep() == cep){

			ende.setEndereco_logradouro(pegaColunaDeString(&i, linha, ';', '\0'));
			ende.setEndereco_complemento(pegaColunaDeString(&i, linha, ';', '\0'));
			ende.setBairro_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
			ende.setCidade_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
			ende.setUf_sigla(pegaColunaDeString(&i, linha, ';', '\0'));
			ende.setUf_descricao(pegaColunaDeString(&i, linha, ';', '\0'));

			arq_end.close();
			return ende;
		}
	}
	ende.setEndereco_codigo("");
	ende.setEndereco_cep("");
	ende.setEndereco_logradouro("");
	ende.setEndereco_complemento("");
	ende.setBairro_descricao("");
	ende.setCidade_descricao("");
	ende.setUf_sigla("");
	ende.setUf_descricao("");
	arq_end.close();
	return ende;

};

void EnderecoHelper::inserir(End endereco){

	int i=0;
	char c = '0';
	string linha, endCod;
	ifstream arq_;
	arq_.open(this->arquivoCSV);
	while(c != '\n'){
		i++;
		arq_.seekg(-i, ios::end);
		arq_.get(c);
	}
	getline(arq_, linha);
	i=0;
	endCod = pegaColunaDeString(&i, linha, ';', '\0');
	i = atoi(endCod.c_str());
	i++;
	arq_.close();


	ofstream arq_end;

	arq_end.open(this->arquivoCSV, ios::app);

	arq_end << endl << i << ";" 
	<< endereco.getEndereco_cep() << ";" 
	<< endereco.getEndereco_logradouro() << ";" 
	<< endereco.getEndereco_complemento() << ";" 
	<< endereco.getBairro_descricao() << ";" 
	<< endereco.getCidade_descricao() << ";"
	<< endereco.getUf_sigla() << ";"
	<< endereco.getUf_descricao();

	arq_end.close();
};

void EnderecoHelper::excluirPorCep(string cep){
	ifstream arq_end;
	ofstream arq_aux;
	string linha;

	End ende;

	arq_end.open(this->arquivoCSV);
	arq_aux.open("aux.csv");
	if (!arq_end.is_open())
	{
		cout << "Arquivo já aberto";
		exit(-1);
	}

	bool achou = false;
	getline(arq_end, linha);
	int i=0;
	ende.setEndereco_codigo(pegaColunaDeString(&i, linha, ';', '\0'));
	ende.setEndereco_cep(pegaColunaDeString(&i, linha, ';', '\0'));
	
	if (ende.getEndereco_cep() == cep){
		achou = true;
	}else{
		ende.setEndereco_logradouro(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_complemento(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setBairro_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setCidade_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setUf_sigla(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setUf_descricao(pegaColunaDeString(&i, linha, ';', '\0'));

		arq_aux << ende.getEndereco_codigo() << ";" 
		<< ende.getEndereco_cep() << ";" 
		<< ende.getEndereco_logradouro() << ";" 
		<< ende.getEndereco_complemento() << ";" 
		<< ende.getBairro_descricao() << ";" 
		<< ende.getCidade_descricao() << ";"
		<< ende.getUf_sigla() << ";"
		<< ende.getUf_descricao();	
	}
	while(getline(arq_end, linha)){
		i=0;
		ende.setEndereco_codigo(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_cep(pegaColunaDeString(&i, linha, ';', '\0'));
		
		if (ende.getEndereco_cep() == cep){
			achou = true;
			continue;
		}
		
		ende.setEndereco_logradouro(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setEndereco_complemento(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setBairro_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setCidade_descricao(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setUf_sigla(pegaColunaDeString(&i, linha, ';', '\0'));
		ende.setUf_descricao(pegaColunaDeString(&i, linha, ';', '\0'));

		arq_aux << endl << ende.getEndereco_codigo() << ";" 
		<< ende.getEndereco_cep() << ";" 
		<< ende.getEndereco_logradouro() << ";" 
		<< ende.getEndereco_complemento() << ";" 
		<< ende.getBairro_descricao() << ";" 
		<< ende.getCidade_descricao() << ";"
		<< ende.getUf_sigla() << ";"
		<< ende.getUf_descricao();		

	}
	arq_end.close();
	arq_aux.close();

	if (achou == true){
		string cmd = "rm " + this->arquivoCSV;
		system(cmd.data());
		cmd = "mv aux.csv " + this->arquivoCSV;
		system(cmd.data());
	}else{
		system("rm aux.csv");
	}
};