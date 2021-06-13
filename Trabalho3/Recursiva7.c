#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define TAM 100

int q7(int *vet, int i);

int main(){

    int cont;
    int vetor[TAM];
    int tamanho;
    printf("Segue vetor com elementos em ordem crescente:\n\n");
    printf("vet = {");
    for (int i=0;i<TAM;i++){
            vetor[i]=i+1;
            printf("%d,",vetor[i]);
      // if(((i>1)&&i%(tamanho-1)!=0)||vetor[i]==1||vetor[i]==2){
      //      printf(", ");
      //  }
    }printf("}\n\n");
    q7(vetor,0);
    printf("Segue vetor com elementos invertidos:\n\n");
    printf("vet = {");
    for (int i=0;i<TAM;i++){
            printf("%d",vetor[i]);
        if(((i>1)&&i%(TAM-1)!=0&&vetor[i]!=1)||vetor[i]==100||vetor[i]==99||vetor[i]==98){
        printf(", ");
    }
  }
  printf("}\n");

    return 0;
}

int q7(int *vetor, int i){
       int aux=vetor[(TAM-1)-i];
       vetor[(TAM-1)-i]=vetor[i];
       vetor[i]=aux;
       i++;

     if (i<(int)(TAM/2)){
        q7(vetor, i);
    }
}
    