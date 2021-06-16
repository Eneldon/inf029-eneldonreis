#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Eneldon de Jesus Barros Reis
// Matrícula : 2019116011
// Semestre : 2º

// Questão 13

// Protótipo da função que escreve números naturias em ordem decrescente
int q13(int n);

int main(){

    int numero;
    int resposta;

    printf("Digite um numero: ");
    scanf("%d",&numero);

    resposta = q13(numero);

  //  printf(" %d ",resposta);

    return 0;

}

int q13(int n){
       
       if(n >= 0){ 
            
            printf(" %d ",n);
            q13(n-1);
          
       }
       
       else{
           return 0;
       }
    
    
}