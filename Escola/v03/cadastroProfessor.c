#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"dados.h"



int cadastrarProfessor(Professor lista_professor[], int qtd_professor_cadastrado, int qtd_professor ){
                     printf("\n***Cadastro de Professor ***\n");
    for(qtd_professor_cadastrado = 0; qtd_professor_cadastrado < qtd_professor; qtd_professor_cadastrado ++){
                    printf("Digite a matricula: ");
                    scanf("%d", &lista_professor[qtd_professor_cadastrado].matricula);
                    getchar();

                    printf("\nInserir o nome: ");
                    fgets(lista_professor[qtd_professor_cadastrado].nome,50,stdin);
                     /*fgets é uma das funções mais indicadas para ler string do teclado. 
                    Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
                    Entretanto ela guarda o \n ao final da string, por isso é preciso removê-lo, como feito a seguir
                    size_t = unsigned integer type */
                    size_t ly = strlen(lista_professor[qtd_professor_cadastrado].nome) - 1;
                    if (lista_professor[qtd_professor_cadastrado].nome[ly] =='\n'){
                            lista_professor[qtd_professor_cadastrado].nome[ly] ='\0';
                    }
                    printf("\nInserir  sexo: ( F - Feminino M - Maculino  O - Outros): ");
                    scanf("%c",&lista_professor[qtd_professor_cadastrado].sexo);
                    lista_professor[qtd_professor_cadastrado].sexo = toupper(lista_professor[qtd_professor_cadastrado].sexo);
                    getchar();
                    

                    printf("\nInserir o cpf: ");
                    fgets(lista_professor[qtd_professor_cadastrado].cpf,15,stdin);
                    size_t lx = strlen(lista_professor[qtd_professor_cadastrado].cpf) - 1;
                    if (lista_professor[qtd_professor_cadastrado].cpf[lx] =='\n'){             
                            lista_professor[qtd_professor_cadastrado].cpf[lx] ='\0';
                    }

                    printf("\nInforme a data de nascimento do Aluno padrao dd/mm/aaaa: ");
                    scanf("%d%*c%d%*c%d",&lista_professor[qtd_professor_cadastrado].dma.dia
                                        ,&lista_professor[qtd_professor_cadastrado].dma.mes
                                        ,&lista_professor[qtd_professor_cadastrado].dma.ano);
                    getchar();
                       
                    
                   // qtd_alunos_cadastrado ++;
                } // fim do for

}
