#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"entraDados.h"
#include<time.h>

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
                printf(" %d | %s\n",lista_disciplina[i].codigo, lista_disciplina[i].nome);            
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

void ListaOrdemNomeAluno(Aluno lista_aluno[], int qtd_alunos){
    int i, j, k, pos;
    Aluno troca, menor, trocadentro;

    for(i=0;i<qtd_alunos-1;i++){
        menor = lista_aluno[i];
        for(k=i+1;k<qtd_alunos;k++){
            for(j=0;j<10;j++){
                if(lista_aluno[k].nome[j] < menor.nome[j]){
                    menor = lista_aluno[k];
                    pos = k;
                    trocadentro = lista_aluno[i];
                    lista_aluno[i] = menor;
                    lista_aluno[k] = trocadentro;
                    break;
                }else if(strcmp(menor.nome, lista_aluno[k].nome)==1){
                    break;
                }else{
                    break;
                }
            }
        }
        //listaDeAlunos[pos] = trocadentro;
    }

    for(i=0;i<qtd_alunos;i++){
        printf("\n%d | %s\n", lista_aluno[i].matricula, lista_aluno[i].nome);
    }
}
void ListaOrdemNomeProfessor(Professor lista_professor[], int qtd_professores){
    int i, j, k, pos;
    Professor troca, menor, trocadentro;

    for(i=0;i<qtd_professores-1;i++){
        menor = lista_professor[i];
        for(k=i+1;k<qtd_professores;k++){
            for(j=0;j<10;j++){
                if(lista_professor[k].nome[j] < menor.nome[j]){
                    menor = lista_professor[k];
                    pos = k;
                    trocadentro = lista_professor[i];
                    lista_professor[i] = menor;
                    lista_professor[k] = trocadentro;
                    break;
                }else if(strcmp(menor.nome, lista_professor[k].nome)==1){
                    break;
                }else{
                    break;
                }
            }
        }
        //listaDeAlunos[pos] = trocadentro;
    }

    for(i=0;i<qtd_professores;i++){
        printf("\n%d | %s\n", lista_professor[i].matricula, lista_professor[i].nome);
    }
}
void listarumadisciplina(Disciplina lista_disciplina[], int qtd_disciplina){
    int i, codigo;
    printf("Informa o codigo da disciplina que deseja listar: ");
    scanf("%d",&codigo);
    
            for(i = 0 ; i < qtd_disciplina; i++) {
                if(lista_disciplina[i].codigo == codigo){
                printf(" ----- \n");
                printf("Codigo: %d\n",lista_disciplina[i].codigo);
                printf("Nome: %s\n",lista_disciplina[i].nome);
                printf("Semestre: %d\n",lista_disciplina[i].semestre);
                printf("Professor: %s",lista_disciplina[i].docente->nome);
                printf("Aluno: %s",lista_disciplina[i].discentes->nome);
                  
                }
            }
    printf(" ----- \n \n " );
}

void ListarAniversariantesdoMes( Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){

    int mes, i;
    printf("informe o Mes: ");
    scanf("%d",&mes);
    printf("\n");
    printf("Aniversariantes do mes\n");
    printf("Alunos:\n");
    for(i=0;i<qtd_alunos;i++)
        if(mes == lista_aluno[i].data_nascimento.mes)
            printf("%d | %s\n",lista_aluno[i].matricula, lista_aluno[i].nome);
    
    printf("\nProfessores:\n");
    for(i=0;i<qtd_professores;i++)
        if(mes == lista_professor[i].data_nascimento.mes)
            printf("%d | %s\n",lista_professor[i].nome, lista_professor[i].matricula);
}


