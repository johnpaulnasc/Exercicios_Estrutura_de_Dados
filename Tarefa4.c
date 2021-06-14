/* Programa que implementar as funções da lista: Criar, Limpar, Inserir e Remover no/do final, Mostrar, verificar se é vazia, verificar se é cheia.
Aluno:Joao Paulo do Nascimento Borges
Matricula: 20190034839
*/


#include<stdio.h>


#define N 10                 //Definicoes
struct lista{                //Tipo
    int ocupacao;
    int dados[N];
};


//prototipos das funcoes
void criar_lista(struct lista *VL);
char cheia(struct lista VL);
char vazia(struct lista VL);
char inserir_fim(struct lista *VL);
void limpar_lista(struct lista *VL);
void mostrar_lista(struct lista VL);
void remover_lista(struct lista *VL);


void main(){
    
    struct lista L1;    //Lista definida

    int i;             //Termo para rodar a estrutura de repeticao

    criar_lista(&L1);

    printf("\nA Lista esta vazia?\n");
    if(vazia(L1))
        printf("\nSim\n");
    else printf("\nNão\n");


    limpar_lista(&L1);     //Lipando a lista

    for(i = 0; i < 10; i++){
        inserir_fim(&L1);      //Acrescentando componentes na lista
    }

    mostrar_lista(L1);       //Mostrar os componentes da lista
    remover_lista(&L1);      //Ultimo componente sendo removido
    mostrar_lista(L1);       //Mostrar os componentes da lista
}

void criar_lista(struct lista *VL){  //Lista criada e zerada  
    VL -> ocupacao =- 1;                           
}

char vazia(struct lista VL){   //Verificar se a lista esta vazia
    if(VL.ocupacao == -1)     
        return(1);
    else return(0);
}

char cheia(struct lista VL){  //Verificar se a lista esta cheia
    if(VL.ocupacao == N - 1)
        return(1);
    else return(0);

}

char inserir_fim(struct lista *VL){   //Verificar se esta chei, se não deve preencher
    if(cheia(*VL)){
        return(0);
    }

    printf("\nColoque o valor que deseja: ");
    scanf("%d", &VL -> dados[(VL-> ocupacao) + 1]);        //Valores sendo preencidos

    VL->ocupacao = (VL -> ocupacao)+1;     //Contador sendo somado

    return(1);
}

void limpar_lista(struct lista *VL){  //Lista sendo zerada
    VL -> ocupacao =- 1;
}

void mostrar_lista(struct lista VL){  //Expondo a lista
    int j;     //Termo para rodar a estrutura de repeticao

    printf("Os componentes da lista sao: ");
    for(j = 0; j <= VL.ocupacao; j++){
        printf("%d ",VL.dados[j]);  //Mostando componentes 
    };
    printf("\n");
}

void remover_lista(struct lista *VL){  //Ultimo componente sendo removido
    if(vazia(*VL)){
        return;
    };

    VL -> ocupacao = (VL -> ocupacao)-1;
}
