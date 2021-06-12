#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


// protótipo da função fatorial

int fibonacci(int n);

int main(void){

    int numero; 
    double f;

    printf("Digite o numero que deseja calcular oo fatorial: ");
    scanf("%d",&numero);

    // chamada da função farorial

    f = fatorial(numero);

    printf("Fatorial de %d = %.0lf",numero,f);

    getch();
    return 0;
}

// Função recursiva que calcula o fatorial
// de um número inteiro n

int fibonacci(int n){

    int vfib;
    
    if(n <=1)
    // Caso base: fartorial de n <= 1 retorna 1
    return (1);
    
    else
    {
        // chamada da função recursiva
        vfib = n * fibonacci(n-1);
        return (vfib);
    }
}