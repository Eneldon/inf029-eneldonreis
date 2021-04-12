#include<stdio.h>
#include<string.h>
#include"entraDados.h"

int MenuPrincipal(){

    int opcao;
    printf("\n****************************\n");
    printf("***    Menu Principal    ***");
    printf("\n****************************\n");
    printf(" 0 - Sair\n" );
    printf(" 1 - Menu Aluno \n" );
    printf(" 2 - Menu Professor\n" );
    printf(" 3 - Menu Disciplina\n" );
    printf(" 4 - Menu relatorio\n" );
    printf(" Digite uma opcao: " );
    scanf("%d",&opcao);
    return opcao;
}
