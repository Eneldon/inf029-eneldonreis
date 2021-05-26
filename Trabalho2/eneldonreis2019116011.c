// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Eneldon de Jesus Barros Reis
//  email: eneldon.reis@ifba.edu.br
//  Matrícula: 2019116011
//  Semestre: segundo

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################
#include <stdio.h> 
#include <stdlib.h>
#define TAM 10
#include  "eneldonreis2019116011.h"


//definindo estrutura principal
typedef struct lista{
    int tam;
    int posicaoAt;
    int *vt;
}Lista;

  Lista vetorAux[TAM];

void inicializar(){

    int ct;

    for(ct=0; ct<TAM; ct++){

            vetorAux[ct].vt = NULL;
            vetorAux[ct].tam = 0;
            vetorAux[ct].posicaoAt = 0;
    }
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){
    
    int retorno = 0;

    //testar se posição é um valor válido {entre 1 e 10}
    if (ValidaPosicao(posicao)==POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
   
    else{
        //testar se existe a estrutura auxiliar    
        if(vetorAux[posicao-1].vt != NULL)
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    
        else{
            //testar se o tamanho não é menor que 1
            if(tamanho<1)
                retorno = TAMANHO_INVALIDO;
            else{
                // deu tudo certo, crie
                vetorAux[posicao-1].vt = (int*) malloc(tamanho * sizeof(int));

                //testa se a alocação ocorreu corretamente
                if(vetorAux[posicao-1].vt != NULL){
                    vetorAux[posicao-1].tam = tamanho;
                    retorno = SUCESSO;
                }else
                    retorno = SEM_ESPACO_DE_MEMORIA;
            }
        }
    }

    return retorno;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
    int indiceEstruturaAuxiliar;
    
    //testa se a posição é valida    
    if (ValidaPosicao(posicao) != SUCESSO)
        return POSICAO_INVALIDA;
    
    else{
        //se a estrutura existe
        if(vetorAux[posicao-1].vt == NULL)
            return SEM_ESTRUTURA_AUXILIAR;
        
        else{
                
            //testa se a estrutura está vazia
            if(vetorAux[posicao-1].posicaoAt < 1)
                return ESTRUTURA_AUXILIAR_VAZIA;
            
            else{                    
                
                vetorAux[posicao-1].posicaoAt--;

                return SUCESSO;  
            }
        }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliarD
*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){

    int indiceEstruturaAuxiliar;
    int ct =0;

    //testa se a posição é valida    
    if (ValidaPosicao(posicao) != SUCESSO)
        return POSICAO_INVALIDA;
    
    else{
        //se a estrutura existe
        if(vetorAux[posicao-1].vt == NULL)
            return SEM_ESTRUTURA_AUXILIAR;
        
        else{
                
            //testa se a estrutura está vazia
            if(vetorAux[posicao-1].posicaoAt < 1)
                return ESTRUTURA_AUXILIAR_VAZIA;
            
            else{                    
                
                indiceEstruturaAuxiliar = acharNum(valor, posicao);
                
                //testa se o valor informado existe na estrutura auxiliar
                if(indiceEstruturaAuxiliar == NUMERO_INEXISTENTE)
                    return NUMERO_INEXISTENTE;

                else{

                    for(ct=indiceEstruturaAuxiliar;ct<(vetorAux[posicao-1].tam)-1;ct++)
                    {
                     vetorAux[posicao-1].vt[ct] = vetorAux[posicao-1].vt[ct+1];
                    }
                    vetorAux[posicao-1].posicaoAt--;

                    return SUCESSO;                
                }
            }
        }
    }
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;

        //testar se a posicao eh valida
        if (ValidaPosicao(posicao)==POSICAO_INVALIDA)
            retorno = POSICAO_INVALIDA;
        else{
            // testar se existe a estrutura auxiliar
            if (vetorAux[posicao-1].vt!=NULL){
                //testar se tem espaço
                if (vetorAux[posicao-1].posicaoAt < vetorAux[posicao-1].tam){
                  //insere
                  vetorAux[posicao-1].vt[vetorAux[posicao-1].posicaoAt] = valor;
                  //incrementa a quantidade de posições preenchidas
                  vetorAux[posicao-1].posicaoAt++;
                  //define o retorno como sucesso
                  retorno = SUCESSO;
                }else{
                  retorno = SEM_ESPACO;
                }
            }else{
                retorno = SEM_ESTRUTURA_AUXILIAR;
            }
        }


    return retorno;

}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho'
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser menor que 1
    *SEM_ESPACO_DE_MEMORIA - Realocação de memória falhou
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){

    //define o novo tamanho da estrutura
    novoTamanho = vetorAux[posicao-1].tam + novoTamanho;
    
    //testa se a posicao eh valida
    if(ValidaPosicao(posicao) != SUCESSO)
        return POSICAO_INVALIDA;
    
    else{
        //testa se a estrutura auxiliar existe
        if(vetorAux[posicao-1].vt == NULL)
            return SEM_ESTRUTURA_AUXILIAR;
        else{
            //testa se o novo tamanho é um numero maior ou igual a 1
            if(vetorAux[posicao-1].tam + novoTamanho < 1)
                return NOVO_TAMANHO_INVALIDO;
            else{
                //realiza realocação de memória
                vetorAux[posicao-1].vt = (int*) realloc(vetorAux[posicao-1].vt, sizeof(int) * novoTamanho);

                //testa se a realocação foi realizada com sucesso
                if(vetorAux[posicao-1].vt == NULL)
                    return SEM_ESPACO_DE_MEMORIA;                
                else{                    

                    vetorAux[posicao-1].tam = novoTamanho; 
                    if(vetorAux[posicao-1].tam < vetorAux[posicao-1].posicaoAt)
                        vetorAux[posicao-1].posicaoAt = vetorAux[posicao-1].tam;
                    
                    return SUCESSO;           
                }        
            }
        }
    }

}

// se posição é um valor válido {entre 1 e 10}
int ValidaPosicao(int posicao){
   
    if (posicao > 0 && posicao <=10){
        return SUCESSO;
    }else{

        return POSICAO_INVALIDA;
    }
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    *ESTRUTURA_AUXILIAR_VAZIA - A estrutura não possui dados a serem Palavrados
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorEx[]){
    
    int retorno = 0;
    int ct;
    
    //testa se a posicao é valida
    if(ValidaPosicao(posicao) != SUCESSO){
       
        retorno = POSICAO_INVALIDA;
   
    }else{
        //testa se existe estrutura auxiliar
        if (vetorAux[posicao-1].vt == NULL){      
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }else{
            //testa se a estrutura auxiliar está vazia
            if(vetorAux[posicao-1].posicaoAt == 0)
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            else{
                for(ct = 0; ct < vetorAux[posicao-1].posicaoAt; ct++){
                    vetorEx[ct] = vetorAux[posicao-1].vt[ct];
                }
                retorno = SUCESSO;
        
            }
        }
    }

    return retorno;

}

void finalizar(){
    int ct;
    for(ct=0; ct < TAM; ct++){
        
        if(vetorAux[ct].vt!=NULL)
            free(vetorAux[ct].vt);
    }
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorEx[]){

    int ct1;

    //testa se a posicao eh valida
    if(ValidaPosicao(posicao) != SUCESSO)
        return POSICAO_INVALIDA;
    
    else{        
        //testa se a estrutura auxiliar existe
        if(vetorAux[posicao-1].vt != NULL){            
            //testa se a estrutura auxiliar está vazia
            if(vetorAux[posicao-1].posicaoAt > 0){               
                //Preenche vetorAux
                for(ct1 = 0; ct1 < vetorAux[posicao-1].posicaoAt; ct1++)
                    vetorEx[ct1] = vetorAux[posicao-1].vt[ct1];
                //tudo certo, ordena
                ordenaLista(vetorEx, vetorAux[posicao-1].posicaoAt);
                //FIM
                return SUCESSO;
            }else
                return ESTRUTURA_AUXILIAR_VAZIA;
        }else
            return SEM_ESTRUTURA_AUXILIAR;
        
    }
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - nao tem nenhum valor
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorEx[]){

    int ct, ct1, ct2=0, ct3 = 0;

    


    for(ct = 0 ; ct < TAM ; ct++){
        //testa se a estrutura auxiliar está vazia
        if(vetorAux[ct].posicaoAt > 0){
            //se nao está vazia, atribui os valores ao vetor auxiliar
            for(ct1 = 0 ; ct1 < vetorAux[ct].posicaoAt ; ct1++){
                vetorEx[ct2] = vetorAux[ct].vt[ct1];
                ct2++;
            }
        //se está vazia, incrementa o contador
        }else
            ct3++;
    }

    //testa se todas as estruturas auxiliares estão vazias      
    if(ct3 == 10)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        return SUCESSO;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - nao tem nenhum valor
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorEx[]){

     int ct, ct1, ct2, ct3 = 0;


    for(ct = 0 ; ct < TAM ; ct++){
        //testa se a estrutura auxiliar está vazia
        if(vetorAux[ct].posicaoAt > 0){
            //se nao está vazia, atribui os valores ao vetor auxiliar
            for(ct1 = 0 ; ct1 < vetorAux[ct].posicaoAt ; ct1++){
                vetorEx[ct2] = vetorAux[ct].vt[ct1];
                ct2++;
            }
        //se está vazia, incrementa o contador
        }else
            ct3++;
    }

    //testa se todas as estruturas auxiliares estão vazias      
    if(ct3 == 10)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{

        ordenaLista(vetorEx, contElement());
        return SUCESSO;
    }

}

int acharNum(int elemento, int posicao){

    int ct;

    for(ct=0; ct < vetorAux[posicao-1].posicaoAt; ct++){

        if(vetorAux[posicao-1].vt[ct] == elemento){
            return ct;
        }
    }

    return NUMERO_INEXISTENTE;
}


/*
Objetivo: retorna a quantidade de elementos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    int retorno = 0;
    
    //testa se a posicao eh valida
    if(ValidaPosicao(posicao)==POSICAO_INVALIDA){
        retorno = POSICAO_INVALIDA;
    }else{
        //testa se a estrutura auxiliar existe
        if(vetorAux[posicao-1].vt == NULL)
            retorno = SEM_ESTRUTURA_AUXILIAR;
        else{
            //testa se a posição está vazia
            if(vetorAux[posicao-1].posicaoAt < 1)
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            //tudo certo, retorne a qtd de preenchidos
            else
                retorno = vetorAux[posicao-1].posicaoAt;
        }
    }

    return retorno;

}

/*
Objetivo: retorna a quantidade total de elementos na estrutura vetorPrincipal
Retorno (int)
    Sempre retorna algum valor válido, mesmo que 0, pois os testes são realizados na função reutilizada
*/
int contElement(void){
    
    int ct,ct1 = 0;
    
    for(int ct = 1; ct <= TAM; ct++){
        if(getQuantidadeElementosEstruturaAuxiliar(ct) > 0)
            ct1 = ct1 + getQuantidadeElementosEstruturaAuxiliar(ct);
    }
    return ct1;
    printf("\n total %d\n",ct1 );
}

void ordenaLista(int *v, int tam){

    int ct,ct1,ct2=0;

    for(ct=1; ct <tam; ct++){

        ct2=v[ct];

        for(ct1=ct-1; ct1>=0 && v[ct1]>ct2; ct1--){

            v[ct1+1]=v[ct1];
        }

        v[ct1+1]=ct2;
    }
}

/*
Objetivo: montar a Palavra encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas Palavras
    No*, ponteiro para o início da Palavra com cabeçote
*/
No* montarPalavraEncadeadaComCabecote(){
    int ct;
    No *inicio = (No*) malloc(sizeof(No));

    inicio->prox = NULL;

    int qtdTotal = contElement();
    int vetorEx[qtdTotal];
    int ret = 0;

    ret = getDadosDeTodasEstruturasAuxiliares(vetorEx);

    if(ret == SUCESSO)
        for(int ct = 0 ; ct < qtdTotal; ct++)
            inserirFimPalavraEncadeada(inicio, vetorEx[ct]);
    else
        return NULL;

    return inicio;

}

/*
Objetivo: retorna os números da Palavra enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosPalavraEncadeadaComCabecote(No* inicio, int vetorEx[]){

    No *atual;
    int ct;

    if(inicio != NULL)
        for(ct = 0 , atual = inicio->prox ; atual != NULL ; atual = atual->prox , ct++)
            vetorEx[ct] = atual->conteudo; 

}

/*
Objetivo: Destruir a Palavra encadeada com cabeçote a partir de início.
Retorno 
    void.
*/
void destruirPalavraEncadeadaComCabecote(No* inicio){
   
   No *atual = inicio;
   No *tmp;

   while(atual != NULL){

        tmp = atual->prox;
        free(atual);
        atual = tmp;
   }

}

No* criarElementoEncadeado(int valor){

    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL)
        return NULL;

    novo->conteudo = valor;

    novo->prox = NULL;

    return novo;
}

void inserirFimPalavraEncadeada(No *inicio, int valor){

    No *tmp;
    No *novo = criarElementoEncadeado(valor);

    if(inicio->prox  == NULL)
        inicio->prox = novo;
    else{

        tmp = inicio->prox;

        while(tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;

    }
}