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
    int i;
    long int x = 0;
    long int z = 1;
    
    if(n % 2 == 0){
        for( i =2; i != n; i = i+2 )
        {
            x = x + z;
            z = x + z;
        }
        return z;
    }
    else{
        for( i =1; i != n; i = i+2 )
        {
            x = x + z;
            z = x + z;
        }
        return (x);
    }
        
    
}