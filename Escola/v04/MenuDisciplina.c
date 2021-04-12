#include<stdio.h>
#include<string.h>
#include"entraDados.h"


int  opcaoMenuDisciplina(){
    int opcao;
    
    printf("\n****************************\n");
    printf("***    Menu Disciplina   ***");
    printf("\n****************************\n");
    printf(" 0 - Sair\n" );
    printf(" 1 - Cadastrar Disciplina\n");
    printf(" 2 - Excluir Disciplina\n");
    printf(" Digite uma opcao: " );
    scanf("%d",&opcao);

    return opcao;
}