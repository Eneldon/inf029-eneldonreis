#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Eneldon de Jesus Barros Reis
// Matrícula : 2019116011
// Semestre : 2º

// protótipo da função invert

int invert(int num);

int main(void){

    int numero; 
    int invertido;

    printf("Digite o numero que deseja inverter: ");
    scanf("%d",&numero);

    invertido = invert(numero);

    printf("O inverso de  %d = %d",numero,invertido);

    getch();
    return 0;
}

// Função recursiva para inverter um numero


int invert(int num){

   int numInvertido = 0;

   while(num)
   {
      numInvertido = numInvertido * 10 + num % 10;
      num = num / 10;
   }
   num = numInvertido;

 // printf("%5d -   ",numInvertido);
   
    return num;
}
