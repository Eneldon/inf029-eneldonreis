#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"entraDados.h"
#define  SUCESSO_CADASTRO  1
#define  ERRO_CADASTRO_MATRICULA  2
#define  ERRO_CADASTRO_SEXO  3



int inserirProfessor(Professor lista_professor[], int qtd_professores){
    
    printf("\n ### Cadastro de Professor ### \n");
    fflush(stdin);
    printf("Digite a matricula: ");
    scanf("%d",&lista_professor[qtd_professores].matricula);
    fflush(stdin);
    
    if (lista_professor[qtd_professores].matricula <= 0) {
        return ERRO_CADASTRO_MATRICULA;
    }    
    
    printf("Digite o nome: ");
    fgets (lista_professor[qtd_professores].nome , 50 , stdin);
    /* o fgets é uma das funções mais indicadas para ler string do teclado.
    Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
    Entretanto ela guarda o \ n ao final da corda, por isso é preciso removê-lo, como feito a seguir */
    size_t ln = strlen (lista_professor[qtd_professores].nome) - 1 ; // size_t = tipo inteiro sem sinal
    if (lista_professor[qtd_professores].nome[ln]== '\n')
        lista_professor[qtd_professores].nome[ln]= '\0';
    
    printf("Digite o sexo: ");
    scanf("%c",&lista_professor[qtd_professores].sexo);
    
    lista_professor[qtd_professores].sexo = toupper(lista_professor[qtd_professores].sexo );
    if (lista_professor[qtd_professores].sexo  != 'M' && lista_professor[qtd_professores].sexo != 'F' ) {
        return ERRO_CADASTRO_SEXO;
    }
    
    /* obs. a data de nascimento será recuperada dia, mês e ano,
        mas depois tem que mudar para informar uma string dd / mm / aaaa, e validar um dado */
    printf("Digite o dia de nascimento: ");
    scanf("%d",&lista_professor[qtd_professores].data_nascimento .dia);

    printf("Digite o mes de nascimento: ");
    scanf("%d",&lista_professor[qtd_professores].data_nascimento.mes);

    printf("Digite o ano de nascimento: ");
    scanf("%d",&lista_professor[qtd_professores].data_nascimento.ano);
    getchar();

    printf("Digite o CPF: ");
    fgets(lista_professor[qtd_professores].cpf , 15 , stdin);
    ln = strlen(lista_professor[qtd_professores].cpf ) - 1 ;
    if (lista_professor[qtd_professores].cpf[ln]== '\n' )
        lista_professor[qtd_professores].cpf[ln]= '\0' ;

    printf("\n");
    
    return SUCESSO_CADASTRO;
    
    
}

int ExcluirProfessor(Professor lista_professor[], int qtd_professores){
     int i, resultado, matricula;
   
  printf("Informe a matricula do professor para excluir: ");
  scanf("%d",&matricula);
  fflush(stdin);

  for(i = 0 ; i < qtd_professores; i++){
      if(matricula == lista_professor[i].matricula){
        lista_professor[i] = lista_professor[qtd_professores - 1];
        printf("Aluno excluido\n");
        resultado = -1;
        return resultado;
      }else{
        printf("Aluno nao encontrado");
        return resultado = 0;
      }
  }
}

