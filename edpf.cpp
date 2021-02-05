#include <iostream>
#include "endereco/EnderecoHelper.h"
//#include "listaDinamicaTemplate/ListaDT.h"

using namespace std;

void console();
string pegaColunaDeString(int *, string, char, char);

int main(int argc, char const *argv[])
{
	double timeResult = 0.0;
	double startTime = 0.0;
	double endTime = 0.0;
	const int nCycles = 100000000;

	//essa classe manipula o arquivo de endereços / Ex: pega as linhas e separa cada coluna
	EnderecoHelper EndH("arq_endereco.csv");
	
	//pega o ultimo codigo do arquio e soma mais um
	string codigo = EndH.pegaUltimoEndCode();
	int ultimoEndCode = atoi(codigo.c_str());
	ultimoEndCode++;
	codigo = to_string(ultimoEndCode);
	
	//essa é a classe de endereço
	End ende;
	ende.setEndereco_codigo(codigo);
	ende.setEndereco_cep("45750000");
	ende.setEndereco_logradouro("Rua Agnaldo Severo, 32");
	ende.setEndereco_complemento("");
	ende.setBairro_descricao("Centro");
	ende.setCidade_descricao("Itapé");
	ende.setUf_sigla("BA");
	ende.setUf_descricao("Bahia");

	cout << "Lista" << endl;
	//---------------------------------------------------------------------

	startTime = clock();
	cout << "Carregando lista de endereços..." << endl;

	//pega o arquivo de endereços e coloca em uma lista duplamente encadeada
	ListaDT<End> *listaEnd = EndH.pegaListaEnderecos();
	
	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;

	//---------------------------------------------------------------------
	
	startTime = clock();
	cout << "Adicionando na lista..." << endl;
	
	//adiciona um endereço na lista
	listaEnd->adicionaNoFim(ende);

	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;
	
	//---------------------------------------------------------------------
	
	startTime = clock();
	cout << "Buscando na lista..." << endl;

	//pesquisa pelo CEP e retorna um vetor de todos os endereços com esse CEP, só precisa de um End com apenas o CEP
	vector<End> vetorEndLista = listaEnd->busca(ende);

	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;
	
	//---------------------------------------------------------------------
	
	startTime = clock();
	cout << "Deletando da lista..." << endl;

	//deleta pelo codigo, precisa de um End com apenas o codigo
	listaEnd->deleta(ende);

	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;
	
	//---------------------------------------------------------------------

	startTime = clock();
	cout << "Gravando a lista..." << endl;

	//grava a lista
	listaEnd->gravarLista("gravado/listaEnderecos.csv");

	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;
	

	cout << endl << "Arvore" << endl;

	//---------------------------------------------------------------------
	
	startTime = clock();
	cout << "Carregando arvore de endereços..." << endl;

	//pega o arquivo de endereços e coloca em uma arvore binária
	ArvoreBinaria arvBin = EndH.pegaArvoreEnderecos();

	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;

	//---------------------------------------------------------------------

	startTime = clock();
	cout << "Inserindo na arvore..." << endl;

	//insere um endereço na arvore	
	arvBin.insere(ende);

	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;

	//---------------------------------------------------------------------

	startTime = clock();
	cout << "Buscando na arvore..." << endl;

	//pesquisa pelo cep e retorna um vetor com todos os endereços que tem esse cep, só precisa de End com apenas o CEP
	vector<End> vetorEnd = arvBin.Busca(ende);

	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;

	//---------------------------------------------------------------------

	startTime = clock();
	cout << "Removendo da arvore..." << endl;

	//remove pelo cep e código juntos, pois ele pesquisa pelo cep mas só exclui pelo código
	arvBin.remove(ende);

	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;

	//---------------------------------------------------------------------
	
	startTime = clock();
	cout << "Gravando a arvore..." << endl;

	//grava a arvore
	arvBin.gravarArvore("gravado/arvoreEnderecos.csv");

	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;

	//---------------------------------------------------------------------

	int h;
	cout << "Deseja alterar a lista ou a arvore? | 0 -> não | 1 -> sim" << endl;
	cin >> h;
	if (h){
		//chama um menu para manipular os endereços
		console();
	}


	return 0;
}

void console(){

	double timeResult = 0.0;
	double startTime = 0.0;
	double endTime = 0.0;
	const int nCycles = 100000000;

	EnderecoHelper EndH("arq_endereco.csv");
	End ende;
	string codigo, cep, logradouro, complemento, bairro, cidade, siglaUF, UF;
	int opc, ord;
	int ultimoEndCode;
	
	ListaDT<End> *listaEnd;
	vector<End> vetorEndLista;
	ArvoreBinaria arvBin;
	vector<End> vetorEnd;
	
	//---------------------------------------------------------------------
	cout << "Carregando lista de endereços..." << endl;
	startTime = clock();
	listaEnd = EndH.pegaListaEnderecos();
	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;
	//---------------------------------------------------------------------

	opc = 1;
	codigo = EndH.pegaUltimoEndCode();
	ultimoEndCode = atoi(codigo.c_str());
	while(opc){
		cout << "Lista::" << endl << "0 -> Sair | 1 -> Adicionar | 2 -> Buscar | 3 -> Excluir | 4 -> listar | 5 -> gravar" << endl;
		cout << ">> ";
		cin >> opc;
		switch(opc){
			case 1:
				cout << "Informe o CEP" << endl;
				cout << ">> ";
				cin >> cep;
				cout << "Informe o logradouro" << endl;
				cout << ">> ";
				cin >> logradouro;
				cout << "Informe o complemento do endereço" << endl;
				cout << ">> ";
				cin >> complemento;
				cout << "Informe o bairro" << endl;
				cout << ">> ";
				cin >> bairro;
				cout << "Informe a cidade" << endl;
				cout << ">> ";
				cin >> cidade;
				cout << "Informe a sigla UF" << endl;
				cout << ">> ";
				cin >> siglaUF;
				cout << "Informe o UF" << endl;
				cout << ">> ";
				cin >> UF;
				
				
				ultimoEndCode++;
				codigo = to_string(ultimoEndCode);

				ende.setEndereco_codigo(codigo);
				ende.setEndereco_cep(cep);
				ende.setEndereco_logradouro(logradouro);
				ende.setEndereco_complemento(complemento);
				ende.setBairro_descricao(bairro);
				ende.setCidade_descricao(cidade);
				ende.setUf_sigla(siglaUF);
				ende.setUf_descricao(UF);
				
				//---------------------------------------------------------------------
				cout << "Adicionando..." << endl;
				startTime = clock();
				listaEnd->adicionaNoFim(ende);
				endTime = clock();
				timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
				cout << "Concluido -> time: " << timeResult << endl;
				//---------------------------------------------------------------------

				ende.zerar();
				break;
			case 2:
				cout << "Informe o CEP" << endl;
				cout << ">> ";
				cin >> cep;
				ende.setEndereco_cep(cep);

				//---------------------------------------------------------------------
				cout << "Buscando..." << endl;
				startTime = clock();
				vetorEndLista = listaEnd->busca(ende);
				endTime = clock();
				timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
				cout << "Concluido -> time: " << timeResult << endl;
				//---------------------------------------------------------------------
				
				for (int i = 0; i < vetorEndLista.size(); ++i){
					cout << vetorEndLista[i] << endl;
				}
				ende.zerar();
				break;
			case 3:
				cout << "Informe o codigo" << endl;
				cout << ">> ";
				cin >> codigo;
				ende.setEndereco_codigo(codigo);
				if(codigo <= to_string(ultimoEndCode)){

					//---------------------------------------------------------------------
					cout << "Deletando..." << endl;
					startTime = clock();
					listaEnd->deleta(ende);
					endTime = clock();
					timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
					cout << "Concluido -> time: " << timeResult << endl;
					//---------------------------------------------------------------------
				
				}else
					cout << "Codigo inválido!" << endl;

				ende.zerar();
				break;
			case 4:
				startTime = clock();
				listaEnd->printTudo();
				endTime = clock();
				timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
				cout << "Concluido -> time: " << timeResult << endl;
				break;
			case 5:
				cout << "Gravando..." << endl;
				startTime = clock();
				listaEnd->gravarLista("gravado/listaEnderecos.csv");
				endTime = clock();
				timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
				cout << "Concluido -> time: " << timeResult << endl;
				break;
		}
	}

	//---------------------------------------------------------------------
	cout << "Carregando arvore de endereços..." << endl;
	startTime = clock();
	arvBin = EndH.pegaArvoreEnderecos();
	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Concluido -> time: " << timeResult << endl;
	//---------------------------------------------------------------------

	opc = 1;
	codigo = EndH.pegaUltimoEndCode();
	ultimoEndCode = atoi(codigo.c_str());
	while(opc){
		cout << "Arvore" << endl << "0 -> Sair | 1 -> Adicionar | 2 -> Buscar | 3 -> Excluir | 4 listar | 5 -> gravar" << endl;
		cout << ">> ";
		cin >> opc;
		switch(opc){
			case 1:
				cout << "Informe o CEP" << endl;
				cout << ">> ";
				cin >> cep;
				cout << "Informe o logradouro" << endl;
				cout << ">> ";
				cin >> logradouro;
				cout << "Informe o complemento do endereço" << endl;
				cout << ">> ";
				cin >> complemento;
				cout << "Informe o bairro" << endl;
				cout << ">> ";
				cin >> bairro;
				cout << "Informe a cidade" << endl;
				cout << ">> ";
				cin >> cidade;
				cout << "Informe a sigla UF" << endl;
				cout << ">> ";
				cin >> siglaUF;
				cout << "Informe o UF" << endl;
				cout << ">> ";
				cin >> UF;
				
				
				ultimoEndCode++;
				codigo = to_string(ultimoEndCode);

				ende.setEndereco_codigo(codigo);
				ende.setEndereco_cep(cep);
				ende.setEndereco_logradouro(logradouro);
				ende.setEndereco_complemento(complemento);
				ende.setBairro_descricao(bairro);
				ende.setCidade_descricao(cidade);
				ende.setUf_sigla(siglaUF);
				ende.setUf_descricao(UF);

				//---------------------------------------------------------------------
				cout << "Inserindo..." << endl;
				startTime = clock();
				arvBin.insere(ende);
				endTime = clock();
				timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
				cout << "Concluido -> time: " << timeResult << endl;
				//---------------------------------------------------------------------
				
				ende.zerar();
				break;
			case 2:
				cout << "Informe o CEP" << endl;
				cout << ">> ";
				cin >> cep;
				ende.setEndereco_cep(cep);

				//---------------------------------------------------------------------
				cout << "Buscando..." << endl;
				startTime = clock();
				vetorEnd = arvBin.Busca(ende);
				endTime = clock();
				timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
				cout << "Concluido -> time: " << timeResult << endl;
				//---------------------------------------------------------------------
				
				for (int i = 0; i < vetorEnd.size(); ++i){
					cout << vetorEnd[i] << endl;
				}
				ende.zerar();
				break;
			case 3:
				cout << "Informe o codigo" << endl;
				cout << ">> ";
				cin >> codigo;
				cout << "Informe o cep" << endl;
				cout << ">> ";
				cin >> cep;
				ende.setEndereco_codigo(codigo);
				ende.setEndereco_cep(cep);

				//---------------------------------------------------------------------
				cout << "Removendo..." << endl;
				startTime = clock();
				arvBin.remove(ende);
				endTime = clock();
				timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
				cout << "Concluido -> time: " << timeResult << endl;
				//---------------------------------------------------------------------

				ende.zerar();
				break;
			case 4:
				cout << "0 -> Sair | 1 -> Pre Ordem | 2 -> Em Ordem | 3 -> Pos Ordem" << endl;
				cout << ">> ";
				cin >> ord;
				switch(ord){
					case 0:
						break;
					case 1:

						//---------------------------------------------------------------------
						startTime = clock();
						arvBin.PreOrdem();
						endTime = clock();
						timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
						cout << "Concluido -> time: " << timeResult << endl;
						break;
						//---------------------------------------------------------------------

					case 2:

						//---------------------------------------------------------------------
						startTime = clock();
						arvBin.EmOrdem();
						endTime = clock();
						timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
						cout << "Concluido -> time: " << timeResult << endl;
						break;
						//---------------------------------------------------------------------
					
					case 3:

						//---------------------------------------------------------------------
						startTime = clock();
						arvBin.PosOrdem();
						endTime = clock();
						timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
						cout << "Concluido -> time: " << timeResult << endl;
						break;
						//---------------------------------------------------------------------
				}
				break;
			case 5:
				cout << "Gravando..." << endl;
				startTime = clock();
				arvBin.gravarArvore("gravado/arvoreEnderecos.csv");
				endTime = clock();
				timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
				cout << "Concluido -> time: " << timeResult << endl;
				break;
		}
	}
};