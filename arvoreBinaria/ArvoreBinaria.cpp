#include <iostream>
#include "ArvoreBinaria.h"
using namespace std;

No :: No () {
    this->direito = this->esquerdo = this->pai = NULL;
}
No :: No(End valor, No *pai) {
    this->valor = valor;
    this->direito = this->esquerdo = NULL;
    this->pai = pai;
}

No* ArvoreBinaria :: noMaior(No *raiz){
    No *temp=NULL;
    temp = raiz;
    if(temp->direito== NULL){
        raiz = raiz->esquerdo;
        return temp;       
    } else 
        return noMaior(raiz->direito);                
}
int ArvoreBinaria :: Nivel(No *inicio, End valor, int nivel) {
    if (!inicio)
        return -1;
    else {
        if (valor==(inicio->valor))
            return nivel;
        else {
            ++nivel;
            if (valor<(inicio->valor))
                nivel = Nivel (inicio->esquerdo, valor, nivel);
            else if (valor>(inicio->valor))
                nivel = Nivel (inicio->direito, valor, nivel);
        }
        return nivel;
    }
}
void ArvoreBinaria :: percursoEmLargura(No *inicio){
    /*No *temp = NULL;
    queue *auxFila = NULL;
    if(inicio != NULL){ // !inicio
        auxFila->push(inicio);
        while(auxFila->empty() != true){
            temp = auxFila->pop();
            if(temp->esquerdo != NULL)
                auxFila->push(temp->esquerdo);                
            if(temp->direito != NULL)
                auxFila->push(temp->direito);
            cout << temp->valor<< endl;            
        }              
    }  */  
}
void ArvoreBinaria :: percursoEmLargura() {
    return percursoEmLargura (this->raiz);
}
int ArvoreBinaria :: Nivel(End valor) {
    return Nivel (this->raiz, valor, 0);
}
int ArvoreBinaria ::Altura(No *inicio) {
    if (!inicio)
        return -1;
    else {
        int alturaesquerda, alturadireita;
        alturaesquerda = Altura (inicio->esquerdo);
        alturadireita  = Altura (inicio->direito);
      if (alturaesquerda < alturadireita)
         return alturadireita + 1;
      else 
         return alturaesquerda + 1;
    }
}
int ArvoreBinaria :: Altura() {
    return Altura (this->raiz)+1;
}
vector<End> ArvoreBinaria :: Busca (No *inicio, End valor) {
    vector<End> v;
    while (inicio != NULL) {
        if (valor==(inicio->valor)){
            v.push_back(inicio->valor);
            inicio = inicio->esquerdo;
        }
        else if (valor<(inicio->valor))
            inicio = inicio->esquerdo;
        else
            inicio = inicio->direito;
    }
    return v;
}
void ArvoreBinaria  :: PreOrdem (No *inicio) {
    if (inicio != NULL) {
        this->PreOrdem (inicio->esquerdo);
        cout << inicio->valor << endl;
        this->PreOrdem (inicio->direito);
    }
}
void ArvoreBinaria :: EmOrdem (No *inicio) {
    if (inicio != NULL) {
        cout << inicio->valor << " ";
        this->EmOrdem (inicio->esquerdo);
        this->EmOrdem (inicio->direito);
    }
}
void ArvoreBinaria :: PosOrdem (No *inicio) {
    if (inicio != NULL) {
        this->PosOrdem (inicio->esquerdo);
        this->PosOrdem (inicio->direito);
        cout << inicio->valor << " ";
    }
}
ArvoreBinaria  :: ArvoreBinaria () {
    this->raiz = NULL;
}
bool ArvoreBinaria :: Vazio () {
    return this->raiz == NULL;
}
void ArvoreBinaria::insere(End valor) {
    No *tmp = this->raiz;
    No *ant = NULL;
    while (tmp != NULL) {
        ant = tmp;
        if (tmp->valor<(valor)) {
            tmp = tmp->direito;
        }
        else {
            tmp = tmp->esquerdo;
        }
    }
    if (this->Vazio()) {
        this->raiz = new No (valor, NULL);
    }
    else if (ant->valor<(valor)) {
        ant->direito = new No (valor, ant);
    }
    else {
        ant->esquerdo = new No (valor, ant);
    }
}

No * ArvoreBinaria::maisEsquerda(No *folha){
    while(folha->esquerdo) {
        folha = folha -> esquerdo;
    }
    return folha;
}
No * ArvoreBinaria::maisDireita(No *folha){
    while(folha->direito) {
        folha = folha -> direito;
    }
    return folha;
}

No * ArvoreBinaria::antescessorEmOrdem(No *folha){
    if(folha->esquerdo != NULL) {
        return maisDireita(folha);
    }

    No *p = folha->pai;
    
    while(p != NULL && folha == p->esquerdo) {
        folha = p;
        p = p->pai;
    }
    return p;
}

No * ArvoreBinaria::get(No *folha, End n){
    if(folha == NULL){ 
        return folha;
    }
    if (n.isIgual(folha->valor))
        return folha;
    else if(n<(folha->valor)){ 
        return get(folha->esquerdo,n);
    }else if( n>(folha->valor)){
        return get(folha->direito, n);
    }else{
        return get(folha->esquerdo, n);
    }
}

End ArvoreBinaria :: remove (No *raizAux, End n){
    No *node, *p, *filho, *ant;

    node = get(raizAux, n);

    if(node == raiz){
        No *paraDeletar = node; 
        No *aux = maisEsquerda(node->direito);
        aux->esquerdo = node->esquerdo;
        raiz = node->direito;

        paraDeletar->pai=NULL;
        paraDeletar->esquerdo=NULL;
        paraDeletar->direito=NULL;

        delete paraDeletar;
        return n;
    }

    if(node->esquerdo == NULL && node->direito == NULL) {
        if(node->pai) p = node->pai;
        if(node == p->esquerdo) {
            p->esquerdo = NULL;
        }else{
            p->direito = NULL;
        }
        delete node;
        return n;
    }

    if(node->esquerdo && node->direito) {
        End n_pred = antescessorEmOrdem(node)->valor;
        ant = get(raizAux, n_pred);
        if(ant->pai->esquerdo == ant){ 
            ant->pai->esquerdo = NULL;
        }else if(ant->pai->direito == ant){ 
            ant->pai->direito = NULL;
        }
        node->valor = ant->valor;
        delete ant;
        return n;
    }
    if(node->esquerdo) {
        filho = node->esquerdo;
    }else if(node->direito){
        filho = node->direito;
    }
    p = node->pai;
    if(p->esquerdo && p->esquerdo == node) {
        p->esquerdo = filho;
    }else if (p->direito && p->direito == node) {
        p->direito = filho;
    }
    filho->pai = p;
    delete node;
    return n;   
}
End ArvoreBinaria :: remove (End valor){
    return remove (this->raiz, valor);
}
vector<End> ArvoreBinaria :: Busca (End valor){
    return Busca (this->raiz, valor);
}
void ArvoreBinaria :: PreOrdem () {
    PreOrdem (this->raiz);
}
void ArvoreBinaria :: EmOrdem () {
    EmOrdem (this->raiz);
}
void ArvoreBinaria :: PosOrdem () {
    PosOrdem (this->raiz);
}

void ArvoreBinaria::gravarArvore(string arqArvore){
    ofstream arq_arvore;
    arq_arvore.open(arqArvore);
    gravarArvore(this->raiz, arq_arvore);
    arq_arvore.close();
}

void ArvoreBinaria::gravarArvore(No *inicio, ofstream& arq_arvore){

    if (inicio != NULL) {
        this->gravarArvore(inicio->esquerdo, arq_arvore);
        arq_arvore << inicio->valor << endl;
        this->gravarArvore(inicio->direito, arq_arvore);
    }

}