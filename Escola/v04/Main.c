#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"entraDados.h"
#include"cadastroAluno.h"
#include"cadastroProfessor.h"
#include"cadastroDisciplina.h"
#include"listar.h"
#include"opcao.h"
#include"MenuAluno.h"
#include"MenuDisciplina.h"
#include"MenuProfessor.h"
#include"Relatorio.h"
#define  TAM_LISTA_ALUNO  3
#define  TAM_LISTA_PROFESSOR  3
#define  TAM 3
#define  SUCESSO_CADASTRO  1
#define  ERRO_CADASTRO_MATRICULA  2
#define  ERRO_CADASTRO_SEXO  3


int main(){    

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
    
       opcao = MenuPrincipal();
    
        switch(opcao){
            
           case 0:{  printf(" Finalizando Escola\n "); sair = 1 ; break; }
           case 1:{// inicio menu aluno
                  retorno = opcaoMenuAluno();
                  // do{
                    switch (retorno){
                        case 0:{  printf(" Finalizando Escola\n ");/* sair = 1 **/; break; }   
                        case 1:{ retorno =  inserirAluno(lista_aluno,qtd_alunos);
                                if (retorno == SUCESSO_CADASTRO){  printf (" Cadastro realizado com sucesso\n ");
                                    qtd_alunos ++;
                                }else{switch(retorno){
                                        case ERRO_CADASTRO_MATRICULA:{ printf(" Matricula Invalida " );break ;}
                                        case ERRO_CADASTRO_SEXO: { printf(" Sexo Invalido " );break ;}
                                        default : { printf(" Erro desconhecido! ");break;}
                                    }printf(" Nao foi possivel fazer o cadastro \n ");
                                } break ;
                        }
                        case 2:{ExcluirAluno(lista_aluno, qtd_alunos);break;}
                        default :{ printf( " Opcao Invalida \n ");break;}
                    }
              //  }while (!sair);
                break;
            } // fim do menu aluno
            case 2:{// inicio menu Professor
                   retorno = opcaoMenuProfessor();
                      //  do{
                            switch (retorno){   
                                case 0:{  printf(" Finalizando Escola\n ");/* sair = 1 */; break; }   
                                case 1:{retorno =  inserirProfessor(lista_professor,qtd_professores);
                                    if (retorno == SUCESSO_CADASTRO){  
                                        printf (" Cadastro realizado com sucesso\n ");
                                        qtd_professores ++;
                                    }else{switch(retorno){
                                            case ERRO_CADASTRO_MATRICULA:{ printf(" Matricula Invalida " );break ;}
                                            case ERRO_CADASTRO_SEXO: { printf(" Sexo Invalido " );break ;}
                                            default : { printf(" Erro desconhecido! ");break; }
                                        }printf(" Nao foi possivel fazer o cadastro \n ");
                                    }    
                                break ;
                                }
                                case 2:{ExcluirProfessor(lista_professor, qtd_professores);break;}
                                default :{printf( " Opcao Invalida \n ");break;}
                            }
                     //   }while (!sair);    
            }
                break;// fim do menu Professor
            
            case 3:{// inicio menu Disciplina
                   retorno = opcaoMenuDisciplina();
                        //do{
                            switch (retorno){   
                                case 0:{  printf(" Finalizando Disciplina\n ");/* sair = 1 */; break; }   
                                case 1:{retorno =  inserirDisciplina(lista_disciplina, qtd_disciplina);
                                    if (retorno == SUCESSO_CADASTRO){  
                                        printf (" Cadastro realizado com sucesso\n ");
                                        qtd_disciplina ++;
                                    }else{switch(retorno){
                                            case ERRO_CADASTRO_MATRICULA:{ printf(" Codigo Invalido " );break ;}
                                            default : { printf(" Erro desconhecido! ");break; }
                                        }printf(" Nao foi possivel fazer o cadastro \n ");
                                    }    
                                break ;
                                }
                                case 2:{ExcluirDisciplina(lista_disciplina, qtd_disciplina);break;}
                                default :{printf( " Opcao Invalida \n ");break;}
                            }
                       // }while (!sair);

                } break;// fim do menu Disciplina
            case 4:{// inicio menu Disciplina
                   retorno = opcaoMenuRelatorio();

                            switch (retorno){   
                                case 0:{  printf(" Finalizando Relatorio\n "); sair = 1 ; break; }   
                                case 1:{listarAlunos(lista_aluno, qtd_alunos);break;}
                                case 2:{listarProfessores(lista_professor,  qtd_professores);break;}
                                case 3:{listarDisciplinas(lista_disciplina, qtd_disciplina);break;}
                                case 4:{listarumadisciplina(lista_disciplina, qtd_disciplina);break;}
                                case 5:{listarAlunosPorSexo(lista_aluno,  qtd_alunos);break;}
                                case 6:{ListaOrdemNomeAluno(lista_aluno, qtd_alunos);break;}
                              //  case 7:{ExcluirDisciplina(lista_disciplina, qtd_disciplina);break;}
                                case 8:{listarProfessoresPorSexo(lista_professor, qtd_professores);break;}
                                case 9:{ListaOrdemNomeProfessor(lista_professor,  qtd_professores);break;}
                              //  case 10:{ExcluirDisciplina(lista_disciplina, qtd_disciplina);break;}
                                case 11:{ListarAniversariantesdoMes(lista_aluno, qtd_alunos,lista_professor, qtd_professores );break;}
                               // case 12:{ExcluirDisciplina(lista_disciplina, qtd_disciplina);break;}
                               // case 13:{ExcluirDisciplina(lista_disciplina, qtd_disciplina);break;}
                               // case 14:{ExcluirDisciplina(lista_disciplina, qtd_disciplina);break;}


                                default :{printf( " Opcao Invalida \n ");break;}
                            }
                } break;// fim do menu Disciplina

        } // fim primeiro switch opcao

    }while(opcao);// fim do while


}