# include <iostream>
# include <queue>
//# include <stl_queue.h>
#include "../endereco/End.h"
#include <vector>
#include <fstream>
using namespace std;

class No {
    public : End valor;
             No *direito, *esquerdo, *pai;
             No ();
             No (End, No*);
};

class ArvoreBinaria {
    protected : No *raiz;
                vector<End> Busca (No*, End);
                void PreOrdem (No*);
                void EmOrdem (No*);
                void PosOrdem (No*);                
                End remove (No*,End);
                void percursoEmLargura(No *);
                int Altura (No*);
                int Nivel (No*, End, int);   
                No * maisEsquerda(No *);
                No * maisDireita(No *folha);
                No * antescessorEmOrdem(No *);
                No * get(No *, End);
                void gravarArvore(No *, ofstream&);
    public    : ArvoreBinaria ();
                int Altura ();
                int Nivel (End);
                bool Vazio ();
                vector<End> Busca (End);
                void insere (End);
                End remove (End);
                void percursoEmLargura();
                No* noMaior(No*);
                void PreOrdem ();
                void EmOrdem ();
                void PosOrdem ();
                void gravarArvore(string);
};