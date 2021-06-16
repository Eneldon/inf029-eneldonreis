#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Eneldon de Jesus Barros Reis
// Matrícula : 2019116011
// Semestre : 2º

// Questão 06

// protótipo  função multiplicação
int q6(int k, int n);

int main(){

    int k,n,result;


    printf("Informe o inteiro positivo k: ");
    scanf("%d",&k);
    printf("Informe o inteiro positivo n: ");
    scanf("%d",&n);
    result=q6(k,n);
    printf("%d elevado a %d = %d\n",k,n,result);

}



int q6(int k, int n){
  if(n<1){
    return 1;
  }
  return k * q6(k,n-1);
}