#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// Nome: Eneldon de Jesus Barros Reis
// Semestre:  segundo
// Matrícula: 2019116011
/*3) Faça um programa que tenha uma função que recebe um número inteiro
 e retorna o fatorial deste número. Esta função deve ainda verificar se
  é possível calcular o fatorial, se não for, ela deve de alguma forma 
  retornar para a main que deu algum erro. A função main deve solicitar 
  o valor do usuário e imprimir o fatorial dele, ou se não é possível 
  calcular o fatorial.*/

int Fatorial( int num){
    int i;
    int fat=1;
    bool teste = false;
        if(num>0){
            teste = true;
            for(i=1;i<=num;i++){
         fat = fat * i;
            }
        return fat; 
        }
        if(!teste){
        /*    for(i=1;i<=num;i++){
             fat = fat * i;
            }*/
            printf("Erro! ");
        }return 0;
        

       
}
int main(){
    int num;
    int fat;

    printf("\nInforme um numero: ");
    scanf("%d",&num);
    fat = Fatorial(num);

    printf(" %d",fat);
   

      
    return 0;
}
