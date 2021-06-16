#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Eneldon de Jesus Barros Reis
// Matrícula : 2019116011
// Semestre : 2º

// Protótipo de escreve números naturias em ordem crescente
int q12(int n);

int main(){

    int numero;
    int resposta;

    printf("Digite um numero: ");
    scanf("%d",&numero);

    resposta = q12(numero);

  //  printf(" %d ",resposta);

    return 0;

}

int q12(int n){
       
       if(n >= 0){ 
            q12(n-1);
            printf(" %d ",n);
           
          
       }else{
           return 0;
       }
    
    
}