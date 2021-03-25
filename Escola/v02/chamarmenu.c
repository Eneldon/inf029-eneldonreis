#include<stdio.h>
#include<stdlib.h>
#define lista 2
#include"dados.h"
#include"cadastroAluno.h"
#include"cadastroProfessor.h"
#include"cadastroDisciplina.h"


void chamarmenu(){

    int qtd_alunos = lista;
    int qtd_alunos_cadastrado ;
    int qtd_professor = lista;
    int qtd_professor_cadastrado;
    int qtd_disciplina = lista;
    int qtd_disciplina_cadastrada;

    int opcao;
    int opMenu1;
    int sair = 0;

    Aluno lista_aluno[qtd_alunos]; // Vetor para armazernar a lista de alunos.
    Professor lista_professor[qtd_professor]; // Vetor para armazernar a lista de alunos.
    Disciplina lista_disciplina[qtd_disciplina];

   do{
       printf("\nBem vindo a Menu");
       printf("\n1 - Cadastrar Aluno");
       printf("\n2 - Cadastrar Professor");
       printf("\n3 - Cadastrar Disciplina");
       printf("\n0 - Sair");
       printf("\nOpcao:");
       scanf("%d",&opMenu1);

        if(opMenu1 == 1)
            {                 
                  do{
                        printf("\n1 - Inserir Aluno:");
                        printf("\n2 - Lista de Alunos:");
                        printf("\n3 - Listar Aluno:");
                        printf("\nOpcao:");
                        scanf("%d",&opcao);
                        getchar();

                        switch (opcao) 
                             {
                                   case 0:{
                                          printf("Saindo do Cadastro");
                                          sair = 1;
                                    break ;
                                     }
                                    case 1:{
                                          cadastrarAluno(lista_aluno, qtd_alunos_cadastrado, qtd_alunos );
                                    break;
                                     }
                                    case 2:{
                                          listadeAluno(lista_aluno, qtd_alunos_cadastrado, qtd_alunos);
                                    break;
                                     }
                                    case 3:{
                                          listarAluno(lista_aluno, qtd_alunos_cadastrado, qtd_alunos);
                                    break;
                                     }
                                    default:{
                                          printf("Opção Inválida\n");
                                    }
                              }     
                  }while (!sair);
           
            
            }
            else if (opMenu1 == 2){
                  do{
                        printf("\n1 - Inserir Professor:");
                        printf("\n2 - Lista de Professores");
                        printf("\n3 - Listar Professor:");
                        printf("\n0 - sair:");
                        printf("\nOpcao:");
                        scanf("%d",&opcao);
                        getchar();
                        switch (opcao)
                        {
                              case 0:{
                                    printf("Saindo do Cadastro");
                                    sair = 1;
                              break ;
                              }
                              case 1:{
                                    cadastrarProfessor(lista_professor, qtd_professor_cadastrado, qtd_professor);
                              break;
                              }
                              case 2:{
                                    listadeProfessor(lista_professor, qtd_professor_cadastrado, qtd_professor);
                              break;
                              }
                              case 3:{
                                    listarProfessor(lista_professor,qtd_professor_cadastrado, qtd_professor);
                              break;
                              }
                              default:{
                                    printf("Opção Inválida\n");
                              }
                        }
            
                  }while (!sair);
            }
            else if (opMenu1 == 3){
                  do{
                        printf("\n1 - Inserir Disciplina:");
                        printf("\n2 - Lista de Disciplinas");
                        printf("\n3 - Listar Disciplina:");
                        printf("\n0 - sair:");
                        printf("\nOpcao:");
                        scanf("%d",&opcao);
                        getchar();
                        switch (opcao)
                        {
                              case 0:{
                                    printf("Saindo do Cadastro");
                                    sair = 1;
                              break ;
                              }
                              case 1:{
                                   cadastrarDisciplina(lista_disciplina, qtd_disciplina_cadastrada, qtd_disciplina, lista_professor );
                              break;
                              }
                              case 2:{
                                    listadeDisciplina(lista_disciplina, qtd_disciplina_cadastrada, qtd_disciplina, lista_professor);
                              break;
                              }
                              case 3:{
                                    listarDisciplina( lista_disciplina, qtd_disciplina_cadastrada, qtd_disciplina, lista_professor);
                              break;
                              }
                              default:{
                                    printf("Opção Inválida\n");
                              }
                        }
                  }while (!sair);

            }
            else if(opMenu1 == 0){
                  printf("\nSaindo do Cadastro");
                  sair = 1;
                  }
      }while (!sair);  



  
}