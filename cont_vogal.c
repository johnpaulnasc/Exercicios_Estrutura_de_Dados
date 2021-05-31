/* Programa que elabora uma função que conta o numero de vogais em um vetor de caracteres local a main.
Aluno:Joao Paulo do Nascimento Borges
Matricula: 20190034839
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contaVogais(char*); //prototipo da funcao

int main(){

    char palavra[50];

    printf("Digite uma palavra: \n");
    fgets(palavra, 50, stdin);

    printf("O numero de vogais sao %d", contaVogais(palavra));
}

int contaVogais(char* s){ //funcao que conta os numeros de vogais em uma palavra
    int i;           //termo usado para a estrutura de repeticao
    int cont = 0;   // contador para saber o número de vogais
    char vogais[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

    while(*s){                      //estrutura de repetição que pecorre a palavra
        for (i= 0; i < 10; i++){    //estrutura de repetição que procura as vogais
            if (*s == vogais[i]){
                cont++;
            }
        }s++;
    }
    return cont;
}