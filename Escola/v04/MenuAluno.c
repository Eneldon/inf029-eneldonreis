#include<stdio.h>
#include<string.h>
#include"entraDados.h"

int opcaoMenuAluno(){
    int opcao;
    printf("\n****************************\n");
    printf("***      Menu Aluno      ***");
    printf("\n****************************\n");
    printf("0 -Sair\n" );
    printf("1 -Cadastrar Aluno\n" );
    printf("2 -Excluir Alunos\n" );
    printf("Digite uma opcao: " );
    scanf("%d",&opcao);
   
    return opcao;
   
return 0;
}