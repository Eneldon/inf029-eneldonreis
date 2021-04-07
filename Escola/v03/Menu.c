#include<stdio.h>
#include<string.h>
#include"entraDados.h"


int  opcaoMenuPrincipal () {
    int opcao;
    printf(" Digite uma opcao: \n " );
    printf(" 0 - Sair \n " );
    printf(" 1 - Inserir Aluno \n " );
    printf(" 2 - Listar Alunos \n " );
    printf(" 3 - Inserir Professor \n " );
    printf(" 4 - Listar Professores \n " );
    printf(" 5 - Inserir Disciplina \n " );
    printf(" 6 - Listar Disciplinas \n " );
    printf(" 7 - Listar Alunos por sexo \n " );
    printf(" 8 - Listar Professores por sexo \n " );
  //printf(" 9 - Listar Por data de nascimento \n " );
  //printf(" 10 - Listar Professores por sexo \n " );

    scanf("%d",&opcao);
    return opcao;
}
