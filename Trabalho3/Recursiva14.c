#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int q14(int n);

int main(){

    int numero;
    int resposta;

    printf("Digite um numero: ");
    scanf("%d",&numero);

    resposta = q14(numero);

  //  printf(" %d ",resposta);

    return 0;

}

int q14(int n){
       
       if(n > 0){ 
           q14(n-1);

           if(n%2==0){
           printf(" %d ",n);
           }
       }else{
           return 0;
       }
    
    
}