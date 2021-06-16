#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define TAM 100

// Eneldon de Jesus Barros Reis
// Matrícula : 2019116011
// Semestre : 2º

// Questão 04

// Protótipo da Função
int q4(int *vet, int tam);

int main(){

  int vet[TAM];
  int  tamanho;
  int cont;
  int result;


    printf("Informe o tamanho do vetor (de 1 a %d): ",TAM);
    scanf("%d",&tamanho);
    printf("vet = {");
    for (cont=0; cont<tamanho; cont++){
         vet[cont]=cont+1;
         printf("%d",vet[cont]);
    if(((cont>1)&&cont%(tamanho-1)!=0)||vet[cont]==1||vet[cont]==2){
      printf(", ");
    }
  }printf("}\n");

  int *vetor = vet;
  result=q4(vetor,tamanho);
  printf("A soma dos elementos de vet = %d\n",result);

}


// calculo de MDC
int q4(int *vet, int tam){

  if(tam==1){
    return *vet;
  }
  return *vet + q4(++vet,--tam);
}