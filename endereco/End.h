#include <iostream>
using namespace std;

class End
{
public:
	End();
	~End();
	bool isIgual(End);
	bool isMaior(End);
	bool isMenor(End);
	bool isMaiorOuIgual(End);
	bool isMenorOuIgual(End);
	string toString();
	//bool recebe(End);
	void zerar();
	string getEndereco_codigo();
	void setEndereco_codigo(string);
	string getEndereco_cep();
	void setEndereco_cep(string);
	string getEndereco_logradouro();
	void setEndereco_logradouro(string);
	string getEndereco_complemento();
	void setEndereco_complemento(string);
	string getBairro_descricao();
	void setBairro_descricao(string);
	string getCidade_descricao();
	void setCidade_descricao(string);
	string getUf_sigla();
	void setUf_sigla(string);
	string getUf_descricao();
	void setUf_descricao(string);

	bool operator==(const End& e){
		return this->endereco_cep == e.endereco_cep;
	};
	bool operator>(const End& e){
		return this->endereco_cep > e.endereco_cep;
	};
	bool operator<(const End& e){
		return this->endereco_cep < e.endereco_cep;
	};
	bool operator>=(const End& e){
		return this->endereco_cep >= e.endereco_cep;
	};
	bool operator<=(const End& e){
		return this->endereco_cep <= e.endereco_cep;
	};
	friend ostream& operator<<(ostream& os, const End& e){
		os << e.endereco_codigo << ";" << e.endereco_cep << ";" << e.endereco_logradouro << ";" << e.endereco_complemento << ";" << e.bairro_descricao << ";" << e.cidade_descricao << ";" << e.uf_sigla << ";" << e.uf_descricao << ";";
		return os;
	};

//private:
	string endereco_codigo;
	string endereco_cep;
	string endereco_logradouro;
	string endereco_complemento;
	string bairro_descricao;
	string cidade_descricao;
	string uf_sigla;
	string uf_descricao;
};