#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// Nome: Eneldon de Jesus Barros Reis
// Semestre:  segundo
// Matrícula: 2019116011
/*5) Crie um programa que tenha uma função ler4Numeros. 
     Essa função deve ler quatro números do usuário e retornar os quatro números. 
     A função main deve imprimir esses quatro números. Utilize struct para fazer o retorno*/

int ler3Numeros(){
    int i;
    int num[4];
           
        for(i=0;i<4;i++){
         printf("\nInforme %d numero:",i+1);    
         scanf("%d",&num[i]);
        }
        for(i=0; i<4; i++){
        printf("%d ",num[i]);
        }       
        return 0;
}
int main(){
    
     ler3Numeros(); // chamada da função ler3Numeros e imprimir os números digitados por ela.

      
    return 0;
}
