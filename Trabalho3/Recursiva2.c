#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


// protótipo da função fatorial

long int fibonacci(int n);

void main(){

//Sequencia fibonacci 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55..
    int numero; 
    long int fibo;

    printf("Digite uma posicao: ");
    scanf("%d",&numero);

    // chamada da função farorial

    fibo = fibonacci(numero);

    printf("Posicao %d da sequencia de fibonacci:  %li",numero,fibo);

}

// Função recursiva sequencia fibonacci


long int fibonacci(int n){
    if(n==1){
    return 0;
  }else if(n==2||n==3){
    return 1; 
  }else{
    return fibonacci(n-1)+fibonacci(n-2);
  }
}