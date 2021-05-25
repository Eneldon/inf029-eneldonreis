#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"
#define TAM 10




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
//  email: eneldon.reis@gmail.com   
//  Matrícula: 2019116011
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################




typedef struct{
    int *listaAuxiliar;
    int *cont, *tamanho; 
} ListaAux;

void dobrar(int *x){
    *x = *x * 2;
}

ListaAux vetorPrincipal[TAM];

void inicializar(){
    int i;
    ListaAux vetor[TAM];

    for(i=0;i<TAM;i++){
        vetor[i].listaAuxiliar = NULL;
        vetor[i].tamanho = 0;
        vetor[i].cont = 0;
    }
}

int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;
}

int verificarEstruturaAuxiliar(int posicao){
    int retorno;
    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal[posicao];

    if(ptrListaPrincipal->listaAuxiliar != NULL)
            return JA_TEM_ESTRUTURA_AUXILIAR;    
    else
        return SEM_ESTRUTURA_AUXILIAR;
}

int verificaEstrutura(int tamanho, ListaAux *ptrLista){
    int i;

    if(ptrLista->listaAuxiliar == NULL){
        ptrLista->listaAuxiliar = (int *) malloc(tamanho * sizeof(int *));
        if(ptrLista->listaAuxiliar == NULL)
            return SEM_ESPACO_DE_MEMORIA;
        else{
            ptrLista->cont = 0;
            ptrLista->tamanho = tamanho;
            return SUCESSO;
        }    
    }else{
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
}

int criarEstruturaAuxiliar(int tamanho, int posicao){
    int verificaE, retorno = 0;
    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal[posicao]; 

    if(ehPosicaoValida(posicao) == SUCESSO)
        if(tamanho>0)
            verificaE = verificaEstrutura(tamanho, ptrListaPrincipal);
        else
            return TAMANHO_INVALIDO; //TESTAR  
    else{
        return POSICAO_INVALIDA;
    }
        

    if(verificaE == SUCESSO)
        retorno = SUCESSO;
    else if(verificaE == JA_TEM_ESTRUTURA_AUXILIAR)
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    else
        retorno = SEM_ESPACO_DE_MEMORIA;

    return retorno;

}

int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    int contador, retorno;
    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal[posicao];

    if(ehPosicaoValida(posicao+1) == SUCESSO)
        if(verificarEstruturaAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR)
            if(ptrListaPrincipal->cont > 0)
                retorno = ptrListaPrincipal->cont;
            else
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
        else
            retorno = SEM_ESTRUTURA_AUXILIAR;
    else
        retorno = POSICAO_INVALIDA;

    return retorno;
}

int verificarTamanhoEstruturaAuxiliar(int posicao){
    int tamanho, tamanhoEstrutura, contador;

    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal[posicao];

    contador = getQuantidadeElementosEstruturaAuxiliar(posicao);
    
    tamanho = ptrListaPrincipal->tamanho;
    tamanhoEstrutura = tamanho - contador;

    if(tamanhoEstrutura>0)
        return SUCESSO;
    else
        return SEM_ESPACO;
}

int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    int sContador = 1, ptrContador, soma;

    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal[posicao];
    ptrContador = ptrListaPrincipal->cont;

    posicao_invalida = ehPosicaoValida(posicao);
    existeEstruturaAuxiliar = verificarEstruturaAuxiliar(posicao);
    temEspaco = verificarTamanhoEstruturaAuxiliar(posicao);

    soma = ptrContador + sContador;

    if (posicao_invalida != SUCESSO)
        retorno = POSICAO_INVALIDA;
    else{
        if (existeEstruturaAuxiliar == JA_TEM_ESTRUTURA_AUXILIAR){
          if (temEspaco == SUCESSO){
              ptrListaPrincipal->listaAuxiliar[ptrContador] = valor;
              ptrListaPrincipal->cont = soma;
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

void selectionSort(int lista[], int n){
    int i, j, troca, menor;

    for(i=0;i<n;i++){
        menor = i;
        for(j=i+1;j<n;j++)
            if(lista[j]<lista[menor])
                menor = j;

        if(menor != i){
            troca = lista[i];
            lista[i] = lista[menor];
            lista[menor] = troca;
        }
    }
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0, j, tj;
    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal;

    int len = sizeof(vetorAux)/sizeof(vetorAux[0]);

    if(ehPosicaoValida(posicao) == SUCESSO)
        if(verificarEstruturaAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR){
           for(j=0;j<len;j++)
                vetorAux[j] = ptrListaPrincipal[posicao].listaAuxiliar[j]; 
            
            retorno = SUCESSO;
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    else
        retorno = POSICAO_INVALIDA;

    return retorno;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0, contadorGeral = 0, i, x=0, j, k, tamanhoListasAuxiliares, tj;
    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal;

    for(i=0; i<10;i++)
        contadorGeral += getQuantidadeElementosEstruturaAuxiliar(i) > 0 ? getQuantidadeElementosEstruturaAuxiliar(i) : 0;
    
    if(contadorGeral == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        retorno = SUCESSO;
    
    vetorAux[contadorGeral]; //É O MESMO QUE DAR UM MALLOC?

    for(k=0;k<10;k++)
        for(j=0;j<getQuantidadeElementosEstruturaAuxiliar(k);j++)
            for(i=x;i<contadorGeral;i++){
                vetorAux[i] = ptrListaPrincipal[k].listaAuxiliar[j];
                x++;
                break;
            }

    return retorno;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0, j, tj;
    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal;

    if(ehPosicaoValida(posicao) == SUCESSO)
        if(verificarEstruturaAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR){
            int len = sizeof(vetorAux)/sizeof(int);

            for(j=0;j<len;j++)
                vetorAux[j] = ptrListaPrincipal[posicao].listaAuxiliar[j]; 
   
            selectionSort(vetorAux, tj);   

            retorno = SUCESSO;
        }else
            retorno = SEM_ESTRUTURA_AUXILIAR;
    else
        retorno = POSICAO_INVALIDA;

    return retorno;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    //PARA OTIMIZAR EU POSSO BUSCAR APENAS OS VETORES QUE TEM LISTA AUXILIAR DEFINIDA

    int retorno = 0, contadorGeral = 0, i, x=0, j, k, tamanhoListasAuxiliares;
    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal;

    for(i=0; i<10;i++)
        contadorGeral += getQuantidadeElementosEstruturaAuxiliar(i) > 0 ? getQuantidadeElementosEstruturaAuxiliar(i) : 0;
        
    if(contadorGeral == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        retorno = SUCESSO;
    
    vetorAux[contadorGeral]; 

    for(k=0;k<10;k++)
        for(j=0;j<getQuantidadeElementosEstruturaAuxiliar(k);j++)
            for(i=x;i<contadorGeral;i++){
                vetorAux[i] = ptrListaPrincipal[k].listaAuxiliar[j];
                x++;
                break;
            }
    selectionSort(vetorAux, contadorGeral);


   return retorno;
}

void ordenarEstruturaAuxiliarPosRemocao(int posicaoPrincipal, int posicaoAuxiliar){
    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal;
    int i;

    for(i=posicaoAuxiliar;i<ptrListaPrincipal[posicaoPrincipal].tamanho;i++){
        ptrListaPrincipal[posicaoPrincipal].listaAuxiliar[i] = ptrListaPrincipal[posicaoPrincipal].listaAuxiliar[i+1];
    }
}

int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
  int retorno = SUCESSO;
  int i, encontrado = 0, subtracao = 0;

  ListaAux *ptrListaPrincipal = NULL;
  ptrListaPrincipal = &vetorPrincipal;

  while (i < ptrListaPrincipal->tamanho && encontrado == 0){
      if(ptrListaPrincipal[posicao].listaAuxiliar[i] == valor){
          encontrado = 1;
          ptrListaPrincipal->cont = (subtracao - encontrado);
          ordenarEstruturaAuxiliarPosRemocao(posicao,i);
          break;
      }else{
          encontrado = 0;
          i++;
      }
  }
  
  return retorno;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno = 0, tamanhoAtual = 0;

    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal;
    
    tamanhoAtual = ptrListaPrincipal[posicao].tamanho;

    if(ehPosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;

    if((tamanhoAtual + novoTamanho) <= 0)
        return NOVO_TAMANHO_INVALIDO;

    if(ptrListaPrincipal[posicao].listaAuxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    else{
        novoTamanho += tamanhoAtual;
        ptrListaPrincipal[posicao].listaAuxiliar = (int *) realloc(ptrListaPrincipal[posicao].listaAuxiliar, novoTamanho * sizeof(int *));
        
        if(ptrListaPrincipal[posicao].listaAuxiliar == NULL)
            return SEM_ESPACO_DE_MEMORIA;
        else{
            ptrListaPrincipal[posicao].tamanho = novoTamanho;
            if(ptrListaPrincipal[posicao].cont > novoTamanho)
                ptrListaPrincipal[posicao].cont = novoTamanho;
            return SUCESSO;
        }
    }  

    return retorno;   
}

int  excluirNumeroDoFinaldaEstrutura(int posicao){
  int retorno = SUCESSO;
  int i, encontrado = 0, subtracao = 1, contatual = 0;

  ListaAux *ptrListaPrincipal = NULL;
  ptrListaPrincipal = &vetorPrincipal;

  contatual = ptrListaPrincipal[posicao].cont;
  
  if(ehPosicaoValida(posicao) == SUCESSO)
    if(verificarEstruturaAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR){
        if(getQuantidadeElementosEstruturaAuxiliar(posicao) >= 0){
            ptrListaPrincipal[posicao].cont = contatual - subtracao;
            retorno = SUCESSO;
        }else
            return ESTRUTURA_AUXILIAR_VAZIA;
    }else
        retorno = SEM_ESTRUTURA_AUXILIAR;
  else
    retorno = POSICAO_INVALIDA;
      
  
  return retorno;
}

No* montarListaEncadeadaComCabecote(){
    int i, contadorGeral = 0, k = 0,x = 0,j =0, cont = 0;
    ListaAux *ptrListaPrincipal = NULL;
    ptrListaPrincipal = &vetorPrincipal;

    No *inicio, *novo, *np;
    inicio = (No*) malloc(sizeof(No*));

    if(inicio == NULL)
        return NULL;

    for(i=0; i<10;i++)
        contadorGeral += getQuantidadeElementosEstruturaAuxiliar(i) > 0 ? getQuantidadeElementosEstruturaAuxiliar(i) : 0;
    
    int vetorAux[contadorGeral];

    for(k=0;k<10;k++)
        for(j=0; j< getQuantidadeElementosEstruturaAuxiliar(k) > 0 ? getQuantidadeElementosEstruturaAuxiliar(k) : 0 ;j++)
            for(i=x;i<contadorGeral;i++){
                vetorAux[i] = ptrListaPrincipal[k].listaAuxiliar[j];
                x++;
                break;
            }

    for(i=0;i<contadorGeral;i++){
        if(inicio->prox == NULL){
            novo = (No*) malloc(sizeof(No*));
            inicio->prox = novo;
            novo->conteudo = vetorAux[i];
            novo->prox = NULL;
            cont = 1;
        }else{
            novo = inicio;
            while(novo->prox != NULL){
                novo = novo->prox;
            }
            np = (No*) malloc(sizeof(No*));
            np->conteudo = vetorAux[i];
            np->prox = NULL;
            novo->prox = np;
        }
    }

    if(cont !=0)
        return inicio;
    else
        return NULL;
}

void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){
    No *aux;
    int i=0;

    if(inicio != NULL){
        aux = inicio->prox;
        while(aux != NULL){
            vetorAux[i] = aux->conteudo;
            i++;
            aux = aux->prox;
        }
    }else{
        printf("Lista vazia");
    }

    for(i=0;i<10;i++)
        printf("vet[%d]: %d\n",i,vetorAux[i]);
}

void destruirListaEncadeadaComCabecote(No* inicio){
     No *elemento = *inicio;
     No *auxiliar = NULL;

     whille(elemento != NULL)
     {
         auxiliar = elemento->prox;
         free(elemento);
         elemento = auxiliar;
     }
      *inicio = NULL;
}


void finalizar(){
     int i;

     for(i = 0; i < TAM; i += 1)
         free(vetorPrincipal[i].listaAuxiliar);
     free(vetorPrincipal);
}
