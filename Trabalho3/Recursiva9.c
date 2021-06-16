#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


// Eneldon de Jesus Barros Reis
// Matrícula : 2019116011
// Semestre : 2º

// Questão 09

// protótipo da função soma

int somaAteN(int n);

int main(){

    int numero;
    int res;

    printf("Informe um numero inteiro");
    scanf("%d",&numero);

    res = somaAteN(numero);

    printf("A soma de 1 ate %d = %d\n",numero,res);

}

int somaAteN(int n)
{
    if (n == 1 ){
        return 1;
    }
    return n + somaAteN(n-1);
}