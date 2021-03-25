#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dados.h"

int cadastrarDisciplina(Disciplina lista_disciplina[], int qtd_disciplina_cadastrada, int qtd_disciplina, Professor lista_professor[] ){
    printf("\n***Cadastro de disciplins ***\n");
    for(qtd_disciplina_cadastrada = 0; qtd_disciplina_cadastrada < qtd_disciplina; qtd_disciplina_cadastrada ++){
        printf("Digite o codigo: ");
        scanf("%d", &lista_disciplina[qtd_disciplina_cadastrada].codigo);
        getchar();

        printf("\nInserir o nome: ");
        fgets(lista_disciplina[qtd_disciplina_cadastrada].nome,50,stdin);
        /*fgets é uma das funções mais indicadas para ler string do teclado. 
        Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
        Entretanto ela guarda o \n ao final da string, por isso é preciso removê-lo, como feito a seguir
        size_t = unsigned integer type */
        size_t ly = strlen(lista_disciplina[qtd_disciplina_cadastrada].nome) - 1;
        if (lista_disciplina[qtd_disciplina_cadastrada].nome[ly] =='\n'){
            lista_disciplina[qtd_disciplina_cadastrada].nome[ly] ='\0';
        }
        printf("\nInserir o semestre: ");
        scanf("%d",&lista_disciplina[qtd_disciplina_cadastrada].semestre);
        getchar();

        printf("\nInforme o professor: ");
        fgets(lista_disciplina[qtd_disciplina_cadastrada].docente.nome,50,stdin);
        
                       
    } // fim do for

}

int listadeDisciplina(Disciplina lista_disciplina[], int qtd_disciplina_cadastrada, int qtd_disciplina, Professor lista_professor[]){
    printf("\n### Disciplinas Cadastradas ####\n");
    int i;
    for(qtd_disciplina_cadastrada = 0; qtd_disciplina_cadastrada < qtd_disciplina; qtd_disciplina_cadastrada ++){
       printf("-----\n");
       printf("Codigo: %d\n", lista_disciplina[qtd_disciplina_cadastrada].codigo);
       printf("Nome: %s\n", lista_disciplina[qtd_disciplina_cadastrada].nome);
       printf("Semestre: %d\n", lista_disciplina[qtd_disciplina_cadastrada].semestre);
       printf("Professor: %s\n", lista_disciplina[qtd_disciplina_cadastrada].docente.nome);
                                           
    }
    printf("-----\n\n");

}
int listarDisciplina(Disciplina lista_disciplina[], int qtd_disciplina_cadastrada, int qtd_disciplina, Professor lista_professor[]){
    char nome[50];
    int i =0;
    int prof;
                printf("\nDigite o nome da disciplina que deseja listar: ");
                fgets(nome,50,stdin);
                size_t lx = strlen(nome) - 1;
                if (nome[lx] =='\n'){
                nome[lx] ='\0';
                 }
                 int sl=0, existe = 1;

                for(qtd_disciplina_cadastrada = 0; qtd_disciplina_cadastrada < qtd_disciplina; qtd_disciplina_cadastrada ++){
                    if(strcmp(nome,lista_disciplina[qtd_disciplina_cadastrada].nome) == 0){
                      printf("-----\n");
                      printf("Codifo: %d | Nome: %s | Semestre: %d | Professor: %s\n", 
                      lista_disciplina[qtd_disciplina_cadastrada].codigo,
                      lista_disciplina[qtd_disciplina_cadastrada].nome,
                      lista_disciplina[qtd_disciplina_cadastrada].semestre,
                      lista_disciplina[qtd_disciplina_cadastrada].docente.nome);
                     
                    }
                }
                    printf("-----\n\n");

}