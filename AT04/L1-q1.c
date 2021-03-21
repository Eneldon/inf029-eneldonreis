#include<stdio.h>
#include<stdlib.h>
// Nome: Eneldon de Jesus Barros Reis
// Semestre:  segundo
// Matrícula: 2019116011

/*1) Crie um programa que tenha uma função soma e a função main. 
    A função main deve ler dois valores, enviar para a função soma. 
    A função soma deve realizar a soma e retornar o valor. 
    A Função main deve imprimir o resultado da soma.*/

int soma( int a, int b){
    int soma;
    soma = a + b;
    return soma;
}

int main(){

    int v1,v2,resultado;
    printf(" informa valor 1: ");
    scanf("%d",&v1);
    printf(" informa valor 2: ");
    scanf("%d",&v2);

    resultado = soma(v1,v2);

    printf(" A soma de %d + %d = %d ",v1,v2,resultado);

    return 0;
}