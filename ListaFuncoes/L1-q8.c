#include<stdio.h>
#include<stdlib.h>
#define TAM 256
// Nome: Eneldon de Jesus Barros Reis
// Semestre:  segundo
// Matrícula: 2019116011
/*8) Crie um programa que tenha uma função cadastrarCliente. 
     Essa função deve ler os dados do cliente (nome, dataNascimento, cpf, sexo)
     e retornar os dados do cliente. A função main deve imprimir os dados do cliente.*/

 struct data_nascimento{
    int dia;
    int mes;
    int ano;
};

struct cadastro_cliente{
    char nome[256];
    char cpf[15];
    char sexo;
    struct data_nascimento data;
}cad_cliente[1];


int cadastro_cliente(){
    
    int i;

            for(i=0;i<1;i++){
            printf("Digite nome: ");              
            fgets(cad_cliente[i].nome,256,stdin);
            fflush(stdin);

            printf("Digite dia de  Nascimento: ");              
            scanf("%d%*c%d%*c%d",&cad_cliente[i].data.dia,&cad_cliente[i].data.mes,&cad_cliente[i].data.ano);
            fflush(stdin);

            printf("Digite o CPF xxxxxxxxxxx :");              
            fgets(cad_cliente[i].cpf,15,stdin);
            fflush(stdin);

            printf("Digite o Sexo  F ou M:");              
            scanf("%c",&cad_cliente[i].sexo);
            getchar();
        }
        printf("\n");
        for(i=0; i<1; i++){
            printf("Nome: %s",cad_cliente[i].nome);
            printf("Data: %d/%d/%d\n",cad_cliente[i].data.dia,cad_cliente[i].data.mes,cad_cliente[i].data.ano);
            printf("CPF: %s",cad_cliente[i].cpf);
            printf("Sexo: %c",cad_cliente[i].sexo);
        }   

return 0;
      
}

int main(){
    
     cadastro_cliente(); // chamada da função ler3Numeros e imprimir os números digitados por ela.

      
    return 0;
}
