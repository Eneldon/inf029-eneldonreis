#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"entraDados.h"


void listarAlunos(Aluno lista_aluno[], int qtd_alunos){
    printf(" \n ### Alunos Cadastrados ####\n ");
    int i;
    if( qtd_alunos > 0){
        for(i = 0 ; i <qtd_alunos; i ++){
        printf(" ----- \n");
        printf("Matricula: %.3d | Nome: %s \n",lista_aluno[i].matricula,lista_aluno[i].nome);
        }
    }else{
        printf("Nenhum Aluno Cadastrado!\n\n");
    }
    printf(" ----- \n \n " );
}
void listarProfessores(Professor lista_professor[], int qtd_professores){
    printf(" \n ### Professores Cadastrados #### \n ");
    int i;
    if(qtd_professores > 0){
        for(i = 0 ; i < qtd_professores; i++) {
            printf(" ----- \n");
            printf("Matricula: %.3d | Nome: %s \n",lista_professor[i].matricula,lista_professor[i].nome);
        }
    }else {
        printf("Nenhum Aluno Cadastrado!\n\n");
    }
        printf(" ----- \n \n " );
}
void listarDisciplinas(Disciplina lista_disciplina[], int qtd_disciplina){
    printf(" \n ### Disciplinas Cadastradas #### \n ");
    int i;
    if(qtd_disciplina > 0){
            for(i = 0 ; i < qtd_disciplina; i++) {
                printf(" ----- \n");
                printf("Codido: %d \n",lista_disciplina[i].codigo);
                printf("Nome: %s \n",lista_disciplina[i].nome);
                printf("Semestre: %d \n",lista_disciplina[i].semestre);
                printf("Professor: %s \n",lista_disciplina[i].docente.nome);
            }
    }else {
        printf("NAO HA DISCIPLIINAS PARA LISTAR!\n");
    }
    printf(" ----- \n \n " );
}
void listarAlunosPorSexo(Aluno lista_aluno[], int qtd_alunos){
    char sexo;
    printf("informe o sexo que deseja listar:");
    scanf("%c",&sexo);
    sexo = getchar();
    sexo = toupper(sexo);
    printf("Lista dos alunos do sexo: %c\n",sexo);
    int i;
    for(i = 0 ; i < qtd_alunos; i ++) {
    //printf("total %d",qtd_alunos);
    printf(" ----- \n");
     if(lista_aluno[i].sexo == sexo){
        printf("%s \n",lista_aluno[i].nome);
        }
    }
    printf(" ----- \n \n " );
}
void listarProfessoresPorSexo(Professor lista_professor[], int qtd_professores){
    char sexo;
    printf("informe o sexo que deseja listar:");
    scanf("%c",&sexo);
    sexo = getchar();
    sexo = toupper(sexo);
    printf("Lista dos alunos do sexo: %c\n",sexo);
    int i;
    for(i = 0 ; i < qtd_professores; i ++) {
    //printf("total %d",qtd_alunos);
    printf(" ----- \n");
     if(lista_professor[i].sexo == sexo){
        printf("%s \n",lista_professor[i].nome);
        }
    }
    printf(" ----- \n \n " );
}

