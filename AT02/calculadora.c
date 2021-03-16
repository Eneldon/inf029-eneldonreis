#include<stdio.h>
// atividade 02 calculadora

typedef struct{
    float x, y;
    double resultado;
    int op;

}Calculadora;

int somar(int  a, int b);
int subtrair(int a, int b);
float dividir(float a, float b);
int multiplicar(int a, int b);

int main(){

    Calculadora calc;
    do{
         printf("\nInsira um numero: ");
         scanf("%f",&calc.x);
         printf("\nInsira outro numero: ");
         scanf("%f",&calc.y);

         printf(" 0 - Sair\n 1 - Somar\n 2 - Subtrair\n 3 - Dividir\n 4 - Multiplicar \n");
         printf("Op: ");
         scanf("%d",&calc.op);
         

         switch (calc.op){
                while (calc.y != 0){
            
                    case 0: 
                        printf(" Saindo da Calculadora\n ");
                    break;
                    case 1:
                        calc.resultado = somar(calc.x,calc.y);
                        printf("Resultado da soma = %.2f\n",calc.resultado);
                    break;
                    case 2:
                        calc.resultado = subtrair(calc.x,calc.y);;
                        printf("Resultado da subtracao =  %.2f\n",calc.resultado);
                    break;
                    case 3:
                         if(calc.y == 0){
                            printf(" Nao existe divisao por zero \n");
                        }else{
                                calc.resultado = dividir(calc.x,calc.y);;
                                printf("Resultado da divisao =  %.2f\n",calc.resultado);
                            }
                     break;
                    case 4:
                        calc.resultado = multiplicar(calc.x,calc.y);;
                        printf("resultado da multiplicacao =  %.2f\n",calc.resultado);
                     break;

                    default:
                        printf("Saindo da Calculadora\n ");  
                    break;       
                } 
            }
      
    }while(calc.op !=0);
return 0;
}
int somar(int a, int b){
    double res = a + b;
return res;  
}
int subtrair(int a, int b){
    double res = a - b;
    return res;
}
float dividir(float a, float b){
    double res = a / b;
    return res;
}
int multiplicar(int a, int b){
    double res = a * b;
    return res;
}