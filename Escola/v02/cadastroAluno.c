#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"dados.h"

int cadastrarAluno(Aluno lista_aluno[], int qtd_alunos_cadastrado, int qtd_alunos ){
                     printf("\n***Cadastro de Aluno ***\n");
    for(qtd_alunos_cadastrado = 0; qtd_alunos_cadastrado < qtd_alunos; qtd_alunos_cadastrado ++){
                    printf("Digite a matricula: ");
                    scanf("%d", &lista_aluno[qtd_alunos_cadastrado].matricula);
                    getchar();

                    printf("\nInserir o nome: ");
                    fgets(lista_aluno[qtd_alunos_cadastrado].nome,50,stdin);
                     /*fgets é uma das funções mais indicadas para ler string do teclado. 
                    Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
                    Entretanto ela guarda o \n ao final da string, por isso é preciso removê-lo, como feito a seguir
                    size_t = unsigned integer type */
                    size_t ly = strlen(lista_aluno[qtd_alunos_cadastrado].nome) - 1;
                    if (lista_aluno[qtd_alunos_cadastrado].nome[ly] =='\n'){
                            lista_aluno[qtd_alunos_cadastrado].nome[ly] ='\0';
                    }
                    printf("\nInserir  sexo: ( F - Feminino M - Maculino  O - Outros): ");
                    scanf("%c",&lista_aluno[qtd_alunos_cadastrado].sexo);
                    lista_aluno[qtd_alunos_cadastrado].sexo = toupper(lista_aluno[qtd_alunos_cadastrado].sexo);
                    getchar();
                    

                    printf("\nInserir o cpf: ");
                    fgets(lista_aluno[qtd_alunos_cadastrado].cpf,15,stdin);
                    size_t lx = strlen(lista_aluno[qtd_alunos_cadastrado].cpf) - 1;
                    if (lista_aluno[qtd_alunos_cadastrado].cpf[lx] =='\n'){             
                            lista_aluno[qtd_alunos_cadastrado].cpf[lx] ='\0';
                    }

                    printf("\nInforme a data de nascimento do Aluno padrao dd/mm/aaaa: ");
                    scanf("%d%*c%d%*c%d",&lista_aluno[qtd_alunos_cadastrado].dma.dia
                                        ,&lista_aluno[qtd_alunos_cadastrado].dma.mes
                                        ,&lista_aluno[qtd_alunos_cadastrado].dma.ano);
                    getchar();
                       
                    
                   // qtd_alunos_cadastrado ++;
                } // fim do for

}

int listadeAluno(Aluno lista_aluno[], int qtd_alunos_cadastrado, int qtd_alunos){
                printf("\n### Alunos Cadastrados ####\n");
                int i;
                for(qtd_alunos_cadastrado = 0; qtd_alunos_cadastrado < qtd_alunos; qtd_alunos_cadastrado ++){
                      printf("-----\n");
                      printf("Matricula: %d\n", lista_aluno[qtd_alunos_cadastrado].matricula);
                      printf("Nome: %s\n", lista_aluno[qtd_alunos_cadastrado].nome);
                      printf("Sexo: %c\n", lista_aluno[qtd_alunos_cadastrado].sexo);
                      printf("Data Nascimento: %d/%d/%d\n", lista_aluno[qtd_alunos_cadastrado].dma.dia
                                                          , lista_aluno[qtd_alunos_cadastrado].dma.mes
                                                          , lista_aluno[qtd_alunos_cadastrado].dma.ano);
                     printf("CPF: %s\n", lista_aluno[qtd_alunos_cadastrado].cpf);
                    }
                    printf("-----\n\n");

}
int listarAluno(Aluno lista_aluno[], int qtd_alunos_cadastrado, int qtd_alunos){
    char nome[50];
                printf("\nDigite o nome do aluno que deseja listar: ");
                fgets(nome,50,stdin);
                size_t lx = strlen(nome) - 1;
                if (nome[lx] =='\n'){
                nome[lx] ='\0';
                 }
                 int sl=0, existe = 1;

                for(qtd_alunos_cadastrado = 0; qtd_alunos_cadastrado < qtd_alunos; qtd_alunos_cadastrado ++){
                    if(strcmp(nome,lista_aluno[qtd_alunos_cadastrado].nome) == 0){
                      printf("-----\n");
                      printf("Matricula: %d | Nome: %s | Sexo: %c | Data Nascimento: %d/%d/%d | CPF: %s\n", 
                      lista_aluno[qtd_alunos_cadastrado].matricula,
                      lista_aluno[qtd_alunos_cadastrado].nome,
                      lista_aluno[qtd_alunos_cadastrado].sexo,
                      lista_aluno[qtd_alunos_cadastrado].dma.dia,
                      lista_aluno[qtd_alunos_cadastrado].dma.mes,
                      lista_aluno[qtd_alunos_cadastrado].dma.ano,
                      lista_aluno[qtd_alunos_cadastrado].cpf);

                    /*  printf("Nome: %s\n", lista_aluno[qtd_alunos_cadastrado].nome);
                      printf("Sexo: %c\n", lista_aluno[qtd_alunos_cadastrado].sexo);
                      printf("Data Nascimento: %d/%d/%d\n", lista_aluno[qtd_alunos_cadastrado].dma.dia
                                                          , lista_aluno[qtd_alunos_cadastrado].dma.mes
                                                          , lista_aluno[qtd_alunos_cadastrado].dma.ano);
                     printf("CPF: %s\n", lista_aluno[qtd_alunos_cadastrado].cpf);*/
                    }
                }
                    printf("-----\n\n");

}