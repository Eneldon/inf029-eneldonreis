#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"entraDados.h"
#define  SUCESSO_CADASTRO  1
#define  ERRO_CADASTRO_MATRICULA  2


int inserirDisciplina(Disciplina lista_disciplina[], int qtd_disciplina){
    
    printf("\n ### Cadastro de Disciplina ### \n");
    fflush(stdin);
    printf("Digite o Codigo: ");
    scanf("%d",&lista_disciplina[qtd_disciplina].codigo);
    fflush(stdin);
    
    if (lista_disciplina[qtd_disciplina].codigo <= 0) {
        return ERRO_CADASTRO_MATRICULA;
    }    
    
    printf("Digite o nome: ");
    fgets (lista_disciplina[qtd_disciplina].nome , 50 , stdin);
    /* o fgets é uma das funções mais indicadas para ler string do teclado.
    Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
    Entretanto ela guarda o \ n ao final da corda, por isso é preciso removê-lo, como feito a seguir */
    size_t ln = strlen (lista_disciplina[qtd_disciplina].nome) - 1 ; // size_t = tipo inteiro sem sinal
    if (lista_disciplina[qtd_disciplina].nome[ln]== '\n')
        lista_disciplina[qtd_disciplina].nome[ln]= '\0';
    
    printf("Digite o Professor: ");
    fgets (lista_disciplina[qtd_disciplina].docente.nome , 50 , stdin);

    printf("Digite o Semestre: ");
    scanf("%d",&lista_disciplina[qtd_disciplina].semestre);
    
    printf("\n");
    
    return SUCESSO_CADASTRO;
    
    
}

