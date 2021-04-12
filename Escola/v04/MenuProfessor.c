#include<stdio.h>
#include<string.h>
#include"entraDados.h"


int opcaoMenuProfessor(){
    int opcao;
    
    printf("\n****************************\n");
    printf("***    Menu Professor    ***");
    printf("\n****************************\n");
    printf("0 - Sair\n" );
    printf("1 - Cadastrar Professor\n");
    printf("2 - Excluir Professor\n ");
    printf("Digite uma opcao: " );
    scanf("%d",&opcao);
    

    return opcao;
}