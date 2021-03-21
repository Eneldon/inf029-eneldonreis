#include<stdio.h>
#include<stdlib.h>
#define TAM 256
// Nome: Eneldon de Jesus Barros Reis
// Semestre:  segundo
// Matrícula: 2019116011
/*7) Crie um programa que tenha uma função ler3Palavras. 
     Essa função deve ler três palavras do usuário e retornar as três palavras. 
     A função main deve imprimir essas três palavras.*/

/*fgets - Lê do fluxo para a cadeia de caracteres string até a quantidade de caracteres (tamanho - 1) 
ser lida ou até uma nova linha (\n) ou EOF ser encontrado. Após a leitura, a posição atual do fluxo 
é avançada para o próximo caractere não lido.*/


struct palavra{
    char palavra[256];
}dados[3];// variável struct para guardar as palavaras

int ler3Palavras(){
    
    int i;// contador
           
        for(i=0;i<3;i++){
            printf("\nEscreva %d palavra: ",i+1);              
            fgets(dados[i].palavra,TAM,stdin);
            fflush(stdin);
        }
        for(i=0; i<3; i++){
            printf("%s",dados[i].palavra);
        }   

return 0;
      
}
int main(){
    
     ler3Palavras(); // chamada da função ler3Numeros e imprimir os números digitados por ela.

      
    return 0;
}
