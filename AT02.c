#include<stdio.h>

int main(){

    float a, b ;
    int op = 1;
    double resultado;
     printf("Digite o primeiro numero: ");;
     scanf("%f",&a);
     printf("Digite o segundo numero: ");;
     scanf("%f",&b);

     printf(" 0 - Sair\n 1 - Somar\n 2 - Subtrair\n 3 - Dividir\n 4 - Multiplicar");
     scanf("%d",&op);
     

        switch (op){
            while (b != 0){

            case 1:
            resultado = a + b;
            printf(" %.2f",resultado);
            break;
            case 2:
            resultado = a - b;
            printf(" %.2f",resultado);
            break;
            case 3:
            if(b == 0){
                printf(" Nao existe divisao por zero ");
            }else{
                resultado = a / b;
                printf(" %.2f",resultado);
            }
            break;
            case 4:
            resultado = a * b;
            printf(" %.2f",resultado);
            break;

            default:
            printf(" Saindo da Calculadora ");

             }
        }   
}
