#include<stdio.h>
#include<string.h>
#include"entraDados.h"


int opcaoMenuRelatorio(){
    int opcao;
    
    printf("\n*************************************************************************\n");
    printf("**************               Menu Relatorio                *************");
    printf("\n*************************************************************************\n");
    printf("0- Sair\n" );//ok
    printf("1- Listar Alunos\n");//ok
    printf("2- Listar Professores\n");//ok
    printf("3- Listar Disciplinas\n");//ok
    printf("4- Listar uma disciplinas\n");
    printf("5- Listar Alunos por sexo\n"); //ok
    printf("6- Listar Alunos ordenados por Nome\n");//ok
    printf("7- Listar Alunos por data da nascimento\n");
    printf("8- Listar Professores por sexo\n");//ok
    printf("9- Listar Professores ordenado por Nome\n");//ok
    printf("10- Listar Professores  por data de nascimento\n");
    printf("11- Listar Aniversariante do mes\n");
    printf("12- Lista de pessoas a partir de uma string de busca\n");
    printf("13- Lista de alunos matriculados em menos de 3 disciplinas Disciplinas\n");
    printf("14- Lista de  Disciplinas, com nome do professor, que extrapola 40 vagas\n");
    printf("Digite uma opcao: " );
    scanf("%d",&opcao);
    return opcao;
}