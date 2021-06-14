/*
Programa implementar as funções de árvore, incluindo uma que conte a quantidade de nós da árvore.
Aluno:Joao Paulo do Nascimento Borges
Matricula: 20190034839
*/


#include<stdio.h>
#include<stdlib.h>

struct arvore{
    char info;
    struct arvore *esquerda;     //raiz pela esqueda
    struct arvore *direita;      //raiz pela direita
};

typedef struct arvore Arvore;

Arvore* criaArvoreVazia(void);
Arvore* arvoreCria(int c, Arvore* e, Arvore* d);
void arvoreImprime(Arvore* a);
int contaNos(Arvore* a);


int main(){
    Arvore *arvore;                  //ponteiro da raiz da arvore
    arvore = arvoreCria(4, 0, 0);    //raiz da Arvore

    //Filhos a esqerda da raiz principal
    arvore->esquerda = arvoreCria(2, 0, 0);
    arvore->esquerda->esquerda = arvoreCria(1, 0, 0);
    arvore->esquerda->direita = arvoreCria(3, 0, 0);

    //Filhos a direita da raiz principal
    arvore->direita = arvoreCria(6, 0, 0);
    arvore->direita->esquerda = arvoreCria(5, 0, 0);
    arvore->direita->direita = arvoreCria(7, 0, 0); 

    contaNos(arvore);
    arvoreImprime(arvore);
    return 0;
}


Arvore* criaArvoreVazia(void){
    return NULL;
}

Arvore* arvoreCria(int aux, Arvore* sae, Arvore* sad){
    Arvore* p = (Arvore*)malloc(sizeof(Arvore));
    if (!p){
        return 0;
    }
    p->info = aux;       
    p->esquerda = sae;   //sub-arvore da esquerda
    p->direita = sad;    //sub-arvore da direita
    return p;  
}

void arvoreImprime(Arvore* a){
    if(a){
        printf("%d\n", a->info);      //mostra a raiz
        arvoreImprime(a->esquerda);   //mostra sae
        arvoreImprime(a->direita);    //mostra sad
    }
    return;
}

int contaNos (Arvore *a) { 
    if (a == NULL) return 0;
    else{          
        int contE = contaNos (a->esquerda);   //Contando nós pela esqueda      
        int contD = contaNos (a->direita);    //Contando nós pela direita
        return contE + contD + 1;   
    }
} 