#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"dados.h"
#include<time.h>
#include"chamarmenu.h"

void listarAluno(Aluno lista_aluno[], int qtd_alunos_cadastrado, int qtd_alunos){
                       printf("\n### Alunos Cadastrados ####\n");
                int i;
                for(qtd_alunos_cadastrado = 0; qtd_alunos_cadastrado < qtd_alunos; qtd_alunos_cadastrado ++){
                      printf("-----\n");
                      printf("%d  %s \n", lista_aluno[qtd_alunos_cadastrado].matricula,lista_aluno[qtd_alunos_cadastrado].nome);
                }
                    printf("-----\n\n");

}
void listarAlunoSexo(Aluno lista_aluno[], int qtd_alunos_cadastrado, int qtd_alunos){
                char sexo;
                printf("\n### Infomar Qual sexo deseja ser listados ####\n");
                scanf("%c",&sexo);
                getchar();
                sexo = toupper(sexo);
                printf("Lista dos professores do sexo: %c\n\n",sexo);
                for(qtd_alunos_cadastrado = 0; qtd_alunos_cadastrado < qtd_alunos; qtd_alunos_cadastrado ++){
                       
                       if(lista_aluno[qtd_alunos_cadastrado].sexo == sexo){
                       printf("%s\n",lista_aluno[qtd_alunos_cadastrado].nome);
                       
                        }
                }
                    
}
void ListarAlunosOrdemAlfabetica(Aluno lista_aluno[], int qtd_alunos_cadastrado, int qtd_alunos){
    int j, k, pos;
    Aluno troca, menor, trocadentro;

    for(qtd_alunos_cadastrado = 0; qtd_alunos_cadastrado < qtd_alunos; qtd_alunos_cadastrado ++){
        menor = lista_aluno[qtd_alunos];
        for(k=qtd_alunos+1;k<qtd_alunos_cadastrado;k++){
            for(j=0;j<10;j++){
                if(lista_aluno[k].nome[j] < menor.nome[j]){
                    menor = lista_aluno[k];
                    pos = k;
                    trocadentro = lista_aluno[qtd_alunos_cadastrado];
                    lista_aluno[qtd_alunos_cadastrado] = menor;
                    lista_aluno[k] = trocadentro;
                    break;
                }else if(strcmp(menor.nome, lista_aluno[k].nome)==1){
                    break;
                }else{
                    break;
                }
            }
        }
        
    }

       for(qtd_alunos_cadastrado = 0; qtd_alunos_cadastrado < qtd_alunos; qtd_alunos_cadastrado ++)
        printf("\n%s\n", lista_aluno[qtd_alunos].nome);
}

void listarProfessor(Professor lista_professor[], int qtd_professor_cadastrado, int qtd_professor){
                      printf("\n### Professores Cadastrados ####\n");
                int i;
                for(qtd_professor_cadastrado = 0; qtd_professor_cadastrado < qtd_professor; qtd_professor_cadastrado ++){
                      printf("-----\n");
                      printf("%d %s\n", lista_professor[qtd_professor_cadastrado].matricula, lista_professor[qtd_professor_cadastrado].nome);
                }
                    printf("-----\n\n");
}
void listarProfessorSexo(Professor lista_professor[], int qtd_professor_cadastrado, int qtd_professor){
                      char sexo;
                printf("\n### Infomar Qual sexo deseja ser listados ####\n");
                scanf("%c",&sexo);
                getchar();
                sexo = toupper(sexo);
                printf("Lista dos professores do sexo: %c\n\n",sexo);
                for(qtd_professor_cadastrado = 0; qtd_professor_cadastrado < qtd_professor; qtd_professor_cadastrado ++){
                       
                       if(lista_professor[qtd_professor_cadastrado].sexo == sexo){
                       printf("%s\n",lista_professor[qtd_professor_cadastrado].nome);
                       
                        }
                }
}
void ListarProfessoresOrdemAlfabetica(Professor lista_professor[], int qtd_professor_cadastrado, int qtd_professor){
    int i, j, k, pos;
    Professor troca, menor, trocadentro;

    for(i = 0; i < qtd_professor_cadastrado-1;i++){
        menor = lista_professor[i];
        for(k = i+1; k < qtd_professor_cadastrado; k++){
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
        
    }

       for(i = 0; i < qtd_professor_cadastrado; i++){
        printf("\n%s\n", lista_professor[i].nome);
       }
}

void ListarAniversariantesdoMesAluno(Aluno lista_aluno[], int qtd_alunos_cadastrado, int qtd_alunos ){
    int mes;
    printf("Informe o mes que deseja listar:");
    scanf("%d",&mes);
    getchar();
    printf("Aniversariantes do mes\n");
    printf("Alunos:\n");
    for(qtd_alunos_cadastrado = 0; qtd_alunos_cadastrado < qtd_alunos; qtd_alunos_cadastrado++)
        if(lista_aluno[qtd_alunos_cadastrado].dma.mes == mes){
        printf("%s\n",lista_aluno[qtd_alunos_cadastrado].nome);
    }

}
void ListarAniversariantesdoMesProfessor(Professor lista_professor[], int qtd_professor_cadastrado, int qtd_professor){
    int mes;
    printf("Informe o mes que deseja listar:");
    scanf("%d",&mes);
    getchar();
    printf("Aniversariantes do mes\n");
    printf("\nProfessores:\n");
    for(qtd_professor_cadastrado = 0; qtd_professor_cadastrado < qtd_professor; qtd_professor_cadastrado++)
       if(lista_professor[qtd_professor_cadastrado].dma.mes == mes){
        printf("%s\n",lista_professor[qtd_professor_cadastrado].nome);
        }
}

