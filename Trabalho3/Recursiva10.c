#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define TAM 100

// Eneldon de Jesus Barros Reis
// Matrícula : 2019116011
// Semestre : 2º

// Protótipo da Função
int q10(int k, int n);

int main(){

    int k,n,resul;

    printf("Informe um digito (ex.: 1): ");
    scanf("%d",&k);
    printf("Informe o inteiro positivo n: ");
    scanf("%d",&n);

    resul=q10(k,n);

    printf("O digito %d aparece %d vezes no inteiro %d\n",k,resul,n);
    printf("FIM");
  

}

// calculo de MDC
int q10(int k, int n){

  int x = n%10;
        if((n > 10)){
           if(n % 10 == k)

            return 1 + q10(k,(int)n/10);

           else

             return q10(k,(int)n/10);

        }
        else if(n % 10 == k){ 

            return 1;
        }
        else{
               
            return 0;
        }
}