/* Programa que faz a sequencia Fibonacci por passagem de parametro
Aluno:Joao Paulo do Nascimento Borges
Matricula: 20190034839
*/

#include <stdio.h>

int fibo (int *, int *); //prototipo da funcao

void main(){

  int n; 		// termo de parada
  int a=0;		// valores da sequencia
  int b=1;		// valores da sequencia
  
  printf("Até qual termo que ver?\n");
  printf("---> ");
  scanf("%d", &n);
  
  printf ("%d ",b);
  n=n-1;
  while (n>0){
    fibo(&a,&b); // chamada da funcao fibo, onde pega o conteudo do a e b que foi modifico indiretamente pela funcao
 	n=n-1;
  } 
}

int fibo (int *a, int *b){ //funcao que vai fazer a sequencia de Fibonacci por passagem de parametro
  int c;
  c = *a + *b; //soma dos conteudos da memoria
  printf("%d ", c);
  
  *a = *b; // substituicao dos conteudos da memoria
  *b = c; 
}
