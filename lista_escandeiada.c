/*Código da implementação das primeiras funções de lista encadeada: criar, inserir no inicio e remover 
Aluno:Joao Paulo do Nascimento Borges 
Matricula: 20190034839*/ 

#include<stdio.h> 
#include<stdlib.h> 
struct Lista{ 
    int ocupacao; 
    struct Lista* prox; 
};

typedef struct Lista listaEncadeada; 

listaEncadeada* criarLista(); 
listaEncadeada* insereNoInicio(listaEncadeada*, int); 
void excluiLista(listaEncadeada* ); 

void main(){ 
    listaEncadeada* exLista; 

    exLista = criarLista(); 
    exLista = insereNoInicio(exLista, 1); 
    exLista = insereNoInicio(exLista, 2); 
    exLista = insereNoInicio(exLista, 3); 
    exLista = insereNoInicio(exLista, 4); 

    excluiLista(exLista); 
} 

listaEncadeada* criarLista(){ 
    return NULL; 
} 

listaEncadeada* insereNoInicio(listaEncadeada* exLista, int valor){ 
    listaEncadeada* novaLista = (listaEncadeada*) malloc(sizeof(listaEncadeada)); 
    novaLista -> ocupacao = valor; 
    novaLista -> prox = exLista; 

    return novaLista; 
} 

void excluiLista(listaEncadeada* exLista){ 
    listaEncadeada* listaAuxiliar = exLista; 

    while(listaAuxiliar != NULL){ 
        exLista = exLista -> prox; 
        free(listaAuxiliar); 
        listaAuxiliar = exLista; 
    } 
}