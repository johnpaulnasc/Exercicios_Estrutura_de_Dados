/*Implementar as funções de mostrar pelo início e de mostrar pelo final
Aluno:Joao Paulo do Nascimento Borges
Matricula: 20190034839*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Lista listaDuplamenteEncadeada;

struct Lista{
    int valor;
    listaDuplamenteEncadeada *proximo;
    listaDuplamenteEncadeada *anterior;
};

//Criar duas variaveis globais.
listaDuplamenteEncadeada *inicio;
listaDuplamenteEncadeada *fim;
int tamanho;

// Prototipos de funções.
void criarLista();
listaDuplamenteEncadeada *aloca(int valor);
void inserirNoInicio(int valor);
void inserirNoFim(int valor);
void removeNoInicio();
void removeNoFinal();
void imprimeLista();
void imprimeListaContrario();

int main(void){

    criarLista();
	int i;
	for(i=0 ; i<= 10 ; i++){
		inserirNoInicio(i);
	}
	imprimeLista();
	printf("--------------\n");
	imprimeListaContrario();
}

//Criar 2 elementos nulos na Lista.
void criarLista(){
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}

//Aloca um dado.
listaDuplamenteEncadeada *aloca(int valor) {
	listaDuplamenteEncadeada *novo = (listaDuplamenteEncadeada*) malloc(sizeof(listaDuplamenteEncadeada));
	novo->valor = valor;
	novo->anterior = NULL;
	novo->proximo = NULL;
	return novo;
}

//Inserir no inicio da Lista.
void inserirNoInicio(int valor){
    listaDuplamenteEncadeada *novo = aloca(valor); //Criar novo elemento.
    //verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também.
    if(inicio == NULL){
		inicio = novo;
		fim = novo;
    }
    
    //Se a lista já tiver dado, se cria outro elemento e aponta o anterior para o dado 2 e proximo do dado 2 para o 1.
    else{
        listaDuplamenteEncadeada *atual; ////criar novo elemento caso tenha dado no inicio da lista.
        atual = inicio;
		novo->proximo = atual;
		atual->anterior = novo;
		inicio = novo;
    }
    tamanho++;
}

void inserirNoFim(int valor){
    listaDuplamenteEncadeada *novo = aloca(valor); //Criar novo elemento.
    //Verifica se o incio for nulo, se sim inicio vai receber novo e o fim vai ser novo também
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }

    //Se a lista já tiver dado, se cria outro elemento e aponta o anterior para o dado 2 e proximo do dado 2 para o 1.
    else{
        listaDuplamenteEncadeada *atual; //criar novo elemento caso tenha dado no inicio da lista.
        atual = fim;
        novo->anterior = atual;
        atual->proximo = novo;
        fim = novo;
    }
    tamanho++;
}

void removeNoInicio(){
    listaDuplamenteEncadeada *atual = inicio;
    inicio = atual->proximo;
    inicio->anterior = NULL;
    tamanho--;
}

void removeNoFinal(){
    listaDuplamenteEncadeada *atual = fim;
    fim = atual->anterior;
    fim->proximo = NULL;
    tamanho--;
}

//Mostrar pelo início.
void imprimeLista() {
	listaDuplamenteEncadeada *atual;
	atual = inicio;
	while(atual){
		printf("%d\n",atual->valor);
		atual=atual->proximo;
	}
}

//Mostrar pelo final.
void imprimeListaContrario() {
	listaDuplamenteEncadeada *atual;
	atual = fim;
	while(atual){
		printf("%d\n",atual->valor);
		atual=atual->anterior;
	}
}