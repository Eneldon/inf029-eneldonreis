#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// Nome: Eneldon de Jesus Barros Reis
// Semestre:  segundo
// Matrícula: 2019116011
/*4) Crie um programa que tenha uma função ler3Numeros.
     Essa função deve ler três números do usuário e retornar os três números.
     A função main deve imprimir esses três números. Utilize vetor para fazer o retorno.*/

int ler3Numeros(){
    int i;
    int num[3];
           
        for(i=0;i<3;i++){
         printf("\nInforme %d numero:",i+1);    
         scanf("%d",&num[i]);
        }
        for(i=0; i<3; i++){
        printf("%d ",num[i]);
        }       
        return 0;
}
int main(){
    
     ler3Numeros(); // chamada da função ler3Numeros e imprimir os números digitados por ela.

      
    return 0;
}
