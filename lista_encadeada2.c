/*Código completo de lista encadeada FUNCIONANDO: criar, inserir ni inicio e fim, remover no inicio e fim, mostrar
Aluno:Joao Paulo do Nascimento Borges
Matricula: 20190034839
*/


#include<stdio.h>
#include<stdlib.h>

struct Node{
    int conteudo;
    struct Node *prox;
};

typedef struct Node node;


//prototipos das funcoes
void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
node* criarLista();
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);

int main(void){
    
    node *LISTA = (node *) malloc(sizeof(node));
    if(!LISTA){
        printf("Sem memória disponível!\n");
        exit(1);
    }else{
        inicia(LISTA);
        int opt;  //Variavel de opção do menu

        do{
            opt = menu();
            opcao(LISTA,opt);
        }while(opt);

        free(LISTA);
        return 0;
    }
}

//Lista criada e zerada  
void inicia(node *LISTA){   
    LISTA->prox = NULL;
}

int menu(void){
    
    int opt;

    printf("=========================================\n");
	printf("============= Escolha a opção ===========\n");
	printf("=========================================\n");

    printf("0 - Sair\n");
    printf("1 - Exibir lista\n");
    printf("2 - Adicionar NÓ no inicio\n");
    printf("3 - Adicionar NÓ no final\n");
    printf("5 - Remover do inicio\n");
    printf("6 - Remover do fim\n");
    printf("Opção: "); scanf("%d", &opt);
 
    return opt;
}

//Função do menu
void opcao(node *LISTA, int op){ 
    
    node *tmp;
    switch (op){
    case 0:
        libera(LISTA);
        break;

    case 1:
        exibe(LISTA);
        break;

    case 2:
        insereInicio(LISTA);
        break;

    case 3:
        insereFim(LISTA);
        break;
    
    case 4:
        tmp = retiraInicio(LISTA);
        printf("Retirado: %3d\n", tmp->conteudo);
        break;
    
    case 5:
        tmp = retiraFim(LISTA);
        printf("Retirado: %3d\n", tmp->conteudo);

    default:
        printf("Comando invalido\n");
    }
}

 //Verificar se a lista esta vazia
int vazia(node *LISTA){     
    
    if(LISTA->prox == NULL)
        return 1;
    else 
        return 0;
}

//Função que aloca os elementros na lista
node *aloca(){   
    
    node *novo = (node *) malloc(sizeof(node));
    
    if(!novo){
        printf("Sem memóroa disponível");
        exit(1);
    }else{
        printf("Novo elemento: "); 
        scanf("%d", &novo->conteudo);
        return novo;
    }
}

//Função que insere no final da lista
void insereFim(node *LISTA){ 
    
    node *novo = aloca();
    novo->prox = NULL;

    if(vazia(LISTA))
        LISTA->prox = novo;
    else{
        
        node *tmp = LISTA->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;
        
        tmp->prox = novo;
    }
}

//Função que insere no inicio da lista
void insereInicio(node *LISTA){ 

    node *novo = aloca();
    node *oldHead = LISTA->prox;

    LISTA->prox = novo;
    novo->prox = oldHead;
}

//Função que exebi a lista
void exibe(node *LISTA){  
    
    if(vazia(LISTA)){
        printf("Lista vazia!\n");
        return;
    }

    node *tmp;
    tmp = LISTA->prox;

    while(tmp != NULL){
        printf("%5d", tmp->conteudo);
        tmp = tmp->prox;
    }
    printf("\n");
}

//Função para terminar ou sair da lista
void libera(node *LISTA){
    
    if(!vazia(LISTA)){
        node *proxNode, *atual;
        atual = LISTA->prox;
    
    while(atual != NULL){
        proxNode = atual->prox;
        free(atual);
        atual = proxNode;
  }
 }
}

//Função que retira o nó no inicio da lista
node *retiraInicio(node *LISTA){ 
    
    if(LISTA->prox == NULL){
        printf("Lista ja esta vazia\n");
        return NULL;
    }else{
        node *tmp = LISTA->prox;
        LISTA->prox = tmp->prox;
        return tmp;
    }
}

//Função que retira o nó no final da lista
node *retiraFim(node *LISTA){  
    
    if(LISTA->prox == NULL){
        printf("Lista ja está vazia\n");
        return NULL;
    }else{
        node *ultimo = LISTA->prox, *penultimo = LISTA;

        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo->prox = NULL;
        return ultimo; 
    }
}
