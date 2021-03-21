#include<stdio.h>
#include<stdlib.h>
// Nome: Eneldon de Jesus Barros Reis
// Semestre:  segundo
// Matrícula: 2019116011
/*2) Crie um programa que tenha uma função subtrai e a função main. 
    A função main deve ler três valores, enviar para a função subtrai. 
    A função subtrai deve realizar a subtração dos três valores 
    (primeiro menos o segundo menos o terceiro) e retornar o valor. 
    A Função main deve imprimir o resultado da subtração*/

int subtrair( int v1, int v2, int v3){
    int resul;
    resul = v1 - v2 - v3;

    return resul;

}
int main(){
    int x,y,z,resultado;

    printf("\nInforme tres numeros: ");
    scanf("%d%d%d",&x,&y,&z);
    resultado = subtrair(x,y,z);

    printf(" Resultado de %d - %d - %d = %d",x,y,z,resultado);


   
    return 0;
}