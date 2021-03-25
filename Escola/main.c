#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dados.h"
#include"cadastroAluno.h"


int main(){

  //  Aluno aluno; // Variável aluno que será do tipo struct RegistroAluno 
    int qtd_alunos; // variável para controlar a quantidade de alunos cadastrado
    int qtd_alunos_cadastrado ;
    int opcao;
    int sair = 0;

    printf("Quantos Alunos deseja cadastrar:");
    scanf("%d",&qtd_alunos);
    Aluno lista_aluno[qtd_alunos]; // Vetor para armazernar a lista de alunos.

    do{
        printf("\n1 - Inserir Aluno:");
        printf("\n2 - Lista de Alunos:");
        printf("\n3 - Listar Aluno:");
        printf("\n0 - sair:");
        printf("\nOpcao:");
        scanf("%d",&opcao);
        getchar();
        

        switch (opcao){

            case 0:{
                  printf("Saindo do Cadastro");
                  sair = 1;
            break ;
            } // fim case 0
            case 1:{
                  cadatrarAluno(lista_aluno,qtd_alunos_cadastrado, qtd_alunos );
            break;
            }
            
            case 2:{
                listadeAluno(lista_aluno,qtd_alunos_cadastrado,qtd_alunos);
            break;
            }
            case 3:{
                listarAluno(lista_aluno, qtd_alunos_cadastrado, qtd_alunos);
            break;
            }
            default:{
              printf("Opção Inválida\n");
            }
        }// fim do switch
    }while (!sair); // fim  do Do while
   
    
getchar();
}


