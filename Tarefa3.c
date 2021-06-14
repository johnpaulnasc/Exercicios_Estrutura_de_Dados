/*
Programa que guardar 10 nomes simples em um vetor de ponteiros alocado dinamicamente
Aluno:Joao Paulo do Nascimento Borges
Matricula: 20190034839
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


mostarNomes(char **nomes);
void guardarNomes(char** nomes);

void main(int argc, char** argv){
    char **nomes;
    int i;

    nomes = malloc(sizeof(char*)*10); // aloca 10 ponteiros de char, ou seja, 10 strings **vazias**, ainda **não alocadas**.

    if(!nomes) return;     //não consegui alocar

    for(i = 0; i < 10; i++){                //Percorre o "Vetor"
        nomes[i]=malloc(sizeof(char)*100);  //String Dinâmica
        if(!nomes[i]) return;
    }

    for(i = 0; i < 10; i++){  
        free(nomes[i]);      //Libera a String
    }
    free(nomes);             //libera o "Vetor"
 }

// Função para guardar os nomes
void guardarNomes(char** nomes){
     for (int i = 0; i < 10; i++){     

        printf("\nDigite os nomes:");  
        scanf("%s", nomes[i]);
    }
}

//Função para printar os nomes
mostarNomes(char** nomes){
    for(int i = 0; i < 10; i++){
        printf("%s", nomes[i]);
    }
}
