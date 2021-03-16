#include<stdio.h>

// Atividade lista de Funnções 
// l1-q1.c
int soma();

int main(){
    int a, b, resultado;

    printf(" Informe pirmeiro numero: ");
    scanf("%d",&a);
    printf(" Informe segundo numero: ");
    scanf("%d",&b);

    resultado = soma(a, b);

    printf(" A soma entre %d e %d = %d \n",a,b,resultado);

}

int soma(int x , int y){
    int res = x + y ;
    return res;

}