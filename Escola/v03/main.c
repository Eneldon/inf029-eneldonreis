#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"entraDados.h"
#include"cadastroAluno.h"
#include"cadastroProfessor.h"
#include"cadastroDisciplina.h"
#include"listar.h"
#include"Menu.h"

#define  TAM_LISTA_ALUNO  5
#define  TAM_LISTA_PROFESSOR  5
#define  TAM 5

#define  SUCESSO_CADASTRO  1
#define  ERRO_CADASTRO_MATRICULA  2
#define  ERRO_CADASTRO_SEXO  3


int main()
{    
  Aluno aluno;/* Criando a variável aluno que será do tipo struct Ficha_Aluno */
  Aluno lista_aluno[TAM_LISTA_ALUNO]; // vetor para armazenar uma lista de alunos
  int qtd_alunos = 0 ;//variável para controlar a quantidade de alunos cadastrados

  Professor professor;
  Professor lista_professor[TAM_LISTA_PROFESSOR]; 
  int qtd_professores = 0 ;

  Disciplina disciplina;
  Disciplina lista_disciplina[TAM]; 
  int qtd_disciplina = 0 ;
  

  int opcao, retorno;
  int sair = 0 ;
  
  do{
    
    opcao = opcaoMenuPrincipal ();
    
        switch(opcao){
             case 0:{
                printf(" Finalizando Escola\n ");
                sair = 1 ;
                break;
              }
             case 1:{
                retorno = inserirAluno(lista_aluno, qtd_alunos);
                if (retorno == SUCESSO_CADASTRO) {
                    printf (" Cadastro realizado com sucesso\n ");
                    qtd_alunos ++;
                }else {
                    switch(retorno) {
                        case ERRO_CADASTRO_MATRICULA: {
                            printf(" Matricula Invalida " );
                            break ;
                        }
                        case ERRO_CADASTRO_SEXO: {
                            printf(" Sexo Invalido " );
                            break ;
                        }
                        default : {
                            printf(" Erro desconhecido! ");
                        }
               
                    }
                        printf(" Nao foi possivel fazer o cadastro \n ");
            
                }    
                    break ;
               }
              case 2 : {
                     listarAlunos(lista_aluno, qtd_alunos);
                     break ;
               }
              case 3:{
                retorno = inserirProfessor(lista_professor, qtd_professores);
                if (retorno == SUCESSO_CADASTRO) {
                    printf (" Cadastro realizado com sucesso\n ");
                    qtd_professores ++;
                }else {
                    switch(retorno) {
                        case ERRO_CADASTRO_MATRICULA: {
                            printf(" Matricula Invalida " );
                            break ;
                        }
                        case ERRO_CADASTRO_SEXO: {
                            printf(" Sexo Invalido " );
                            break ;
                        }
                        default : {
                            printf(" Erro desconhecido! ");
                        }
               
                    }
                        printf(" Nao foi possivel fazer o cadastro \n ");
            
                }    
                    break ;
               }
              case 4 : {
                     listarProfessores(lista_professor, qtd_professores);
                     break ;
               }
               case 5:{
                retorno = inserirDisciplina(lista_disciplina, qtd_disciplina);
                if (retorno == SUCESSO_CADASTRO) {
                    printf (" Cadastro realizado com sucesso\n ");
                    qtd_disciplina ++;
                }else {
                    switch(retorno) {
                        case ERRO_CADASTRO_MATRICULA: {
                            printf(" Codigo Invalido " );
                            break ;
                        }
                        
                        default : {
                            printf(" Erro desconhecido! ");
                        }
               
                    }
                        printf(" Nao foi possivel fazer o cadastro \n ");
            
                }    
                    break ;
               }
              case 6 : {
                     listarDisciplinas(lista_disciplina, qtd_disciplina);
                     break ;
               }
              case 7 : {
                     listarAlunosPorSexo(lista_aluno, qtd_alunos);
                     break ;
               }
             case 8 : {
                     listarProfessoresPorSexo(lista_professor, qtd_professores);
                     break ;
               }
             default : {
                      printf( " Opcao Invalida \n ");
               }
         }
   }while(!sair);


  return  1 ;

}