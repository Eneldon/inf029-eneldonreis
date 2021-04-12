#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"entraDados.h"
#include"validar.h"
#define  SUCESSO_CADASTRO  1
#define  ERRO_CADASTRO_MATRICULA  2
#define  ERRO_CADASTRO_SEXO  3

int  inserirAluno(Aluno lista_aluno[], int qtd_alunos) {
    
    printf("\n ### Cadastro de Aluno ### \n" );
    fflush(stdin);
    printf("Digite a matricula: " );
    scanf("%d",&lista_aluno[qtd_alunos].matricula );
    fflush(stdin);
       
    if(lista_aluno[qtd_alunos].matricula <= 0 ) {
        return ERRO_CADASTRO_MATRICULA;
    }    
    
    printf("Digite o nome: ");
    fgets (lista_aluno[qtd_alunos].nome, 50, stdin);
    /* o fgets é uma das funções mais indicadas para ler string do teclado.
    Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
    Entretanto ela guarda o \ n ao final da corda, por isso é preciso removê-lo, como feito a seguir */
    size_t ln = strlen(lista_aluno [qtd_alunos].nome) - 1 ; // size_t = tipo inteiro sem sinal
    if (lista_aluno [qtd_alunos].nome[ln] == '\n' )
        lista_aluno [qtd_alunos].nome[ln] = '\0' ;
    
    printf("Digite o sexo: ( F - Feminino M - Maculino ) ");
    scanf("%c",&lista_aluno[qtd_alunos].sexo);
    lista_aluno[qtd_alunos].sexo = toupper(lista_aluno[qtd_alunos].sexo);
    getchar();
    if(lista_aluno[qtd_alunos].sexo != 'M' && lista_aluno[qtd_alunos].sexo != 'F' ) {
        return ERRO_CADASTRO_SEXO;
    }
    
    /* obs. a data de nascimento será recuperada dia, mês e ano,
        mas depois tem que mudar para informar uma string dd / mm / aaaa, e validar um dado */
  
    printf("Digite o dia de nascimento: " );
    scanf("%d",&lista_aluno[qtd_alunos].data_nascimento.dia);
    getchar ();
    printf("Digite o mes de nascimento: " );
    scanf("%d",&lista_aluno[qtd_alunos].data_nascimento.mes);
     getchar ();
    printf("Digite o ano de nascimento: " );
    scanf("%d",&lista_aluno[qtd_alunos].data_nascimento.ano);
    getchar ();

    printf("Digite o CPF: ");
    fgets(lista_aluno [qtd_alunos].cpf, 15, stdin);
    ln = strlen(lista_aluno [qtd_alunos].cpf) - 1 ;
    if(lista_aluno[qtd_alunos].cpf [ln] == '\n')
       lista_aluno[qtd_alunos].cpf [ln] = '\0';

    printf("\n");
    
    return SUCESSO_CADASTRO;
    
    
}
int ExcluirAluno(Aluno lista_aluno[], int qtd_alunos){
     int i, resultado, matricula;
   
  printf("Informe a matricula do aluno para excluir: ");
  scanf("%d",&matricula);
  fflush(stdin);

  for(i = 0 ; i < qtd_alunos; i++){
      if(matricula == lista_aluno[i].matricula){
        lista_aluno[i] = lista_aluno[qtd_alunos - 1];
        printf("Aluno excluido\n");
        resultado = -1;
        return resultado;
      }else{
        printf("Aluno nao encontrado");
        return resultado = 0;
      }
  }
}