#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Eneldon de Jesus Barros Reis
// Matrícula : 2019116011
// Semestre : 2º

// Questão 15

// Protótipo da função que escreve números pares em ordem decrescente
int q15(int n);

int main(){

    int numero;
    int resposta;

    printf("Digite um numero: ");
    scanf("%d",&numero);

    resposta = q15(numero);

  //  printf(" %d ",resposta);

    return 0;

}

int q15(int n){
       
       if(n > 0){ 
           if(n%2==0){
           printf(" %d ",n);
           }
           q15(n-1);
       }else{
           return 0;
       }
    
    
}