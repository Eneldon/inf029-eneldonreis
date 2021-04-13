#include <stdio.h>
#include <string.h>
#include"eneldonreis2019116011.h"

int main (){

    char texto[300] = " A Policia Civil esta investigando se o menino Henry Borel demorou 
    39 minutos para ser socorrido pela mae, Monique Medeiros e pelo padrasto, o vereador 
    Dr Jairinho sem partido apos a sessao de tortura que terminou com a morte da crianca
    A ultima imagem do menino de 4 anos foi feita as 4h09 do dia 8 de marco no elevador do predio
     a caminho do hospital Nela segundo o laudo da pericia o garoto ja esta morto " ;
    int texto_int[100];
    int texto_int2[100];
    int i, j;
    
    for (i = 0; texto[i] != '\0'; i+=2){
        printf("%c : ", texto[i]);
        printf("%i, %i\n", texto[i], texto[i+1]);
        
        texto_int[i] = texto[i]; 
        texto_int[i+1] = texto[i+1]; 
    }
    
    printf("Numeros \n");
    for (j = 0; j < i; j++){
        printf("%i\n", texto_int[j]);
    }
    
    printf("copia \n");
    int k = 0;
    for (j = 0; j < i; j++){
        if (texto_int[j] != -61){
            texto_int2[k] = texto_int[j];
            k++;
        }    
    }
    
}    
