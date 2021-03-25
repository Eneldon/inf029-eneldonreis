#include<stdio.h>
#include<stdlib.h>
#include"dados.h"
#include"cadastroAluno.h"
#include"cadastroProfessor.h"


void chamarmenu(){

    //  Aluno aluno; // Variável aluno que será do tipo struct RegistroAluno 
    int qtd_alunos; // variável para controlar a quantidade de alunos cadastrado
    int qtd_alunos_cadastrado ;

    int qtd_professor;
    int qtd_professor_cadastrado;

    int opcao;
    int sair = 0;

    printf("Quantos Alunos deseja cadastrar:");
    scanf("%d",&qtd_alunos);
    Aluno lista_aluno[qtd_alunos]; // Vetor para armazernar a lista de alunos.

    printf("Quantos Professores deseja cadastrar:");
    scanf("%d",&qtd_professor);
    Professor lista_professor[qtd_professor]; // Vetor para armazernar a lista de alunos.

    do{
        printf("\n1 - Inserir Aluno:");
        printf("\n2 - Inserir Professor:");
        printf("\n3 - Listar Aluno:");
        printf("\n4 - Listar Professor:");
        printf("\n5 - Lista de Alunos:");
        printf("\n6 - Lista de Professores");
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
                  cadastrarAluno(lista_aluno, qtd_alunos_cadastrado, qtd_alunos );
            break;
            }
            
            case 2:{
                  cadastrarProfessor(lista_professor, qtd_professor_cadastrado, qtd_professor);
            break;
            }
            case 3:{
                  listarAluno(lista_aluno, qtd_alunos_cadastrado, qtd_alunos);
            break;
            }
            case 4:{
                  listarProfessor(lista_professor,qtd_professor_cadastrado, qtd_professor);
            break;
            }
            
            case 5:{
                  listadeAluno(lista_aluno, qtd_alunos_cadastrado, qtd_alunos);
            break;
            }
            case 6:{
                  listadeProfessor(lista_professor, qtd_professor_cadastrado, qtd_professor);
            break;
            }
            default:{
              printf("Opção Inválida\n");
            }
        }// fim do switch
    }while (!sair); // fim  do Do while
   
  
}