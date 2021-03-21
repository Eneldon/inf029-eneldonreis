#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// Nome: Eneldon de Jesus Barros Reis
// Semestre:  segundo
// Matrícula: 2019116011
/*6) Crie um programa que tenha uma função ler3Letras. 
  Essa função deve ler três letras do usuário e retornar as três letras. 
  A função main deve imprimir essas três letras*/

int ler3Letras(){
    int i;
    char letras[3];
        printf("\nEscreva tres letras: ");    
        for(i=0;i<3;i++){
            scanf("%c",&letras[i]);
            getchar();
        }
        for(i=0; i<3; i++){
        printf("%c ",letras[i]);
        }       
        return 0;
}
int main(){
    
     ler3Letras(); // chamada da função ler3Numeros e imprimir os números digitados por ela.

      
    return 0;
}
