#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Eneldon de Jesus Barros Reis
// Matrícula : 2019116011
// Semestre : 2º

// Questão 01



// protótipo da função fatorial

double fatorial(int n);

int main(void){

    int numero; 
    double fat;

    printf("Digite o numero que deseja calcular oo fatorial: ");
    scanf("%d",&numero);

    // chamada da função farorial

    fat = fatorial(numero);

    printf("Fatorial de %d = %.0lf",numero,fat);

    getch();
    return 0;
}

// Função recursiva que calcula o fatorial
// de um número inteiro n

double fatorial(int n){
    double vfat;
    
    if(n <=1)
    // Caso base: fartorial de n <= 1 retorna 1
    return (1);
    
    else
    {
        // chamada da função recursiva
        vfat = n * fatorial(n-1);
        return (vfat);
    }
}