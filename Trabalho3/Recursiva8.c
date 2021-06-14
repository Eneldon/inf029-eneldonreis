#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int q8(int k, int n);

int main(){

    int x,y,result;


    printf("6) Informe o inteiro positivo x: ");
    scanf("%d",&x);
    printf("Informe o inteiro positivo y: ");
    scanf("%d",&y);
    result=q8(x,y);
    printf("O mdc de %d e %d = %d\n",x,y,result);

}


// calculo de MDC
int q8(int x, int y){
  if(y==0){
    return x;
  }else{
    return q8(y,x%y);
  }
}