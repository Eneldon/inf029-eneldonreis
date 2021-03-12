#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int calculadora(){
    float peso,altura;
    int imc;

    printf("Informe seu peso ");
    scanf("%f",&peso);
    printf("Informe sua altura ");
    scanf("%f",&altura);

    imc = peso / pow(altura,2);

    return imc;
}
