/*
Programa que usa pilha e verifica correção de abertura e fechamento de chaves, parênteses e colchetes em uma expressão matemática.
Aluno:Joao Paulo do Nascimento Borges
Matricula: 20190034839
*/

#include<stdio.h>
#include<stdlib.h>

#define TAM 100

struct pilha{
    int topo;
    int vetor[100];
}p;


//Escopo das funções.
void push(struct pilha *p, int item);  //Insere item recebido como argumento no topo da pilha.
int empty(struct pilha *p);  //Verifica se a pilha está vazia.
int pop(struct pilha *p);    //Extrai e retorna item no topo da pilha.
int top(struct pilha *p);    //Retorna o item do topo da pilha, sem extraí-lo.

void main(){

    struct pilha arquivo;
    int abre, fecha;
    int id, i;
    char expressao[TAM];
    i = abre = fecha = arquivo.topo = 0;

    printf("Informe a expressao matemática contendo parenteses, chaves e/ou colchetes: ");
    fgets(expressao, TAM, stdin);

    for(i; expressao[i] != '\n'; i++){

        //Condição que verifica as aberturas de parenteses, chaves e/ou colchetes.
        if((expressao[i] == '(') || (expressao[i] == '[') || (expressao[i] == '{')){ 
            abre++;
            if(expressao[i] == '(') id = 1;
            else if(expressao[i] == '[') id = 2;
            else id = 3;
            push(&arquivo, id);
        }

        ////Condição que verifica se tem fechamento de parenteses, chaves e/ou colchetes.
        else if((expressao[i] == ')') || (expressao[i] == ']') || (expressao[i] == '}')){
            fecha++;
            if(expressao[i] == ')') id = 1;
            else if(expressao[i] == ']') id = 2;
            else id = 3;
            if(id == top(&arquivo)) pop(&arquivo);
        }
    }
    if(empty(&arquivo)){
        if(abre == fecha) 
            printf("\nExpressão foi escrita corretamente!\n");
        else 
            printf("\nHá parenteses, colchetes e/ou chaves fechando nada.\n");
    }
    else{
        printf("\nA expressão esta desordenada.\n");
        if(abre < fecha) 
            printf("Além disso, há parenteses, colchetes e/ou chaves abertos sem fechar.\n");
        else if(abre > fecha) 
            printf("Além disso, há mais parenteses, colchetes e/ou chaves de fechamento do que de abertura.\n");
    }
}

void push(struct pilha *p, int item){
    
    //item = Parâmetro da função que recebe um item para ser inserido na pilha.

    //Controle de erro que verifica se o tamanho da pilha será ultrapassado.
    if(p->topo == TAM){
        fputs("Erro: Transbordo!\n", stderr);
    }
    //Implementa a pilha
    else{
        p->vetor[p->topo++] = item;
    }
}

int empty(struct pilha *p){
    if(p->topo == 0)
        return -1;
    else   
        return 0;
}

int pop(struct pilha *p){  //Função somente poed ser utilizada se a pilha não estiver vazia
    if(empty(p)){
        fputs("Nenhum elemento na pilha.\n", stdout);
    }
    else
        return p->vetor[--p->topo];
}

int top(struct pilha *p){
    
    if(empty(p)){
            fputs("Nenhum elemento na pilha.\n", stdout);
    }else{ 
        return p->vetor[p->topo-1];
    }
}