#include<stdio.h>


typedef struct
{
    float a;
    float b;
    int op;
    double resultado;
} Calculadora;

int main(){

    Calculadora calc;
    do{
     printf("Digite o primeiro numero: ");
     scanf("%f",&calc.a);
     printf("Digite o segundo numero: ");
     scanf("%f",&calc.b);

     printf(" 0 - Sair\n 1 - Somar\n 2 - Subtrair\n 3 - Dividir\n 4 - Multiplicar \n");
     scanf("%d",&calc.op);
     

        switch (calc.op){
            while (calc.b != 0){
            
            case 0: 
            printf(" Saindo da Calculadora\n ");
            break;
            case 1:
            calc.resultado = calc.a + calc.b;
            printf(" %.2f\n",calc.resultado);
            break;
            case 2:
            calc.resultado = calc.a - calc.b;
            printf(" %.2f\n",calc.resultado);
            break;
            case 3:
            if(calc.b == 0){
                printf(" Nao existe divisao por zero \n");
            }else{
                calc.resultado = calc.a / calc.b;
                printf(" %.2f\n",calc.resultado);
            }
            break;
            case 4:
            calc.resultado = calc.a * calc.b;
            printf(" %.2f\n",calc.resultado);
            break;

            default:
            printf("Saindo da Calculadora\n ");  
            break;       

             }
        }  
    }while(calc.op !=0);
}
