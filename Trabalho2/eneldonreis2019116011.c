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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eneldonreis2019116011.h"

NoPrincipal vetorPrincipal[TAM]={};
//inicializa a estrutura principal

void show_log2(char *str){
    if (SHOW_LOG)
        printf("#%s#\n", str);
}

void dobrar(int *x){

    *x = *x * 2;

}

/*int lerArquivo(){
  show_log2("lerArquivo()");
  int retorno=FALHA_ABRIR_ARQUIVO;
  char linha[TAM_LINHA];
  FILE* arquivo;

  arquivo=fopen("arquivo.txt","r");
  if(arquivo==NULL){
    return retorno;
  }
  fgets(linha,TAM_LINHA,arquivo);
  while(!feof(arquivo)){
    retorno=converteLinha(linha);
    fgets(linha,TAM_LINHA,arquivo);
  }
  fclose(arquivo);
  return retorno;
}*/

void lerArquivo(){
  show_log2("LerArquivo()");
  
  FILE *arquivo;
     char linha[TAM_LINHA];
     char numero[TAM_LINHA];
     int x,j=0;
     int vetor[TAM_LINHA],tamanho,posicao;

    arquivo = fopen("arquivo.txt","r");

     if(arquivo == NULL){

    arquivo = fopen("arquivo.txt","w");

     }

     else if(arquivo){
         while(!feof(arquivo)){
             fgets(linha, TAM_LINHA, arquivo);


             int h=0;

            for(x=0; x<strlen(linha); x++){

                if(linha[x]!= ';'){
                    numero[j] = linha[x];
                    j++;
                }
                else if(linha[x] == ';'){
                    numero[j] = '\0';
                    vetor[h] = atoi(numero);
                    h++;
                    j=0;

                }
            }
                for(x=0; x<h; x++){
                    if(x==0){
                        posicao = vetor[x]+1;
                    }
                    else if(x==1){
                        tamanho = vetor[x];
                        criarEstruturaAuxiliar(tamanho,posicao);

                    }
                    else{
                        inserirNumeroEmEstrutura(vetor[x],posicao);
                    }
                }


             }


         }


}

int converteLinha(char linha[]){
  show_log2("converteLinha");
  int i;
  int j = 0;

  char indice[TAM_LINHA];
  char tamanho[TAM_LINHA];
  char qtd[TAM_LINHA];
  

  // Encontra o indice
  j = encontraValor(indice, linha, j);

  // Encontra o tamanho
  j = encontraValor(tamanho, linha, j);
  
  //  Encontra a qtd
  j = encontraValor(qtd, linha, j);
  
  // Conversão de string para inteiro
  int indiceNum = atoi(indice);
  int tamanhoNum = atof(tamanho);
  int qtdNum = atoi(qtd);

  if(tamanhoNum>0){
    int aux[tamanhoNum];
    j=converteValorAux(linha, aux, j, qtdNum);
    vetorPrincipal[indiceNum].vetorAux=aux; 
  }else{
    vetorPrincipal[indiceNum].vetorAux=NULL;
  }
  vetorPrincipal[indiceNum].tamanho=tamanhoNum;
  vetorPrincipal[indiceNum].qtdElementos=qtdNum;

  // // Encontra os elementos da Estrutura Auxiliar
  // for(i = ;  < qtdNum; i++) {
  // }

  // Impressoes
  printf("Indice = %d \n", indiceNum);
  printf("Tamanho = %d \n", tamanhoNum);
  printf("Qtd = %d \n", qtdNum);

  // Impressão dos elementos na estrutura


  // Chamo as funcoes para Inserir na Lista

  return SUCESSO;
}

int encontraValor(char str[], char linha[], int posicao){
  show_log2("encontraValor()");
  int i;

    for(i = 0; linha[posicao] != ';' && linha[posicao] != '\n'; i++, posicao++) { 
        str[i] = linha[posicao];
    }

    str[i++] = '\0';
    posicao++;

    return posicao;
}

int converteValorAux(char linha[], int aux[], int posicao, int qtdElementos){
 
    char str[TAM_LINHA];
    int cont=0;
    while(cont<qtdElementos){
        posicao = encontraValor(str, linha,posicao);
        aux[cont]=atoi(str);
        cont++;
    }
    return posicao;
}

int criarEstruturaAuxiliar(int tamanho, int posicao){
    //printf("criarEstruturaAuxiliar()\n");
    int retorno=0;

    // o tamanho nao pode ser menor que 1
    if (tamanho<1)
        retorno = TAMANHO_INVALIDO;
    // se posição é um valor inválido {nao esta entre 1 e 10}
    else if (ehPosicaoValida(posicao)==POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    // a posicao pode já existir estrutura auxiliar
    else if (vetorPrincipal[posicao-1].vetorAux!=NULL)
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    //ok crie
    else {
        vetorPrincipal[posicao-1].vetorAux = malloc(sizeof(int)*tamanho);

        // o tamanho ser muito grande
        if (vetorPrincipal[posicao-1].vetorAux==NULL)
            retorno = SEM_ESPACO_DE_MEMORIA;
        else
        //inicializa o tamanho
        vetorPrincipal[posicao-1].tamanho=tamanho;
        vetorPrincipal[posicao-1].qtdElementos=0;
        //tudo certo
        retorno = SUCESSO;
    }
    return retorno;
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
    //printf("inserirNumeroEmEstrutura()\n");
    // se posição é um valor válido {entre 1 e 10}
    if (ehPosicaoValida(posicao)==POSICAO_INVALIDA){
        retorno = POSICAO_INVALIDA;
    // testar se existe a estrutura auxiliar
    }else if (existeExtruturaAuxiliar(posicao)==SEM_ESTRUTURA_AUXILIAR){
          retorno = SEM_ESTRUTURA_AUXILIAR;
    //testar se a estrutura tem espaço
    }else if (vetorPrincipal[posicao-1].qtdElementos<vetorPrincipal[posicao-1].tamanho){
              //insere
              int* vet=vetorPrincipal[posicao-1].vetorAux;
              int index=vetorPrincipal[posicao-1].qtdElementos++;
              vet[index]=valor;
              retorno = SUCESSO;
    }else{
      retorno = SEM_ESPACO;
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
  int retorno;
  //printf("excluirNumeroDoFinaldaEstrutura()\n");
    //se posição é um valor válido {entre 1 e 10}
    if (ehPosicaoValida(posicao)==POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    //se existe estrutura auxiliar
    else if(existeExtruturaAuxiliar(posicao)==SEM_ESTRUTURA_AUXILIAR){
      retorno = SEM_ESTRUTURA_AUXILIAR;
    //se a estrutura esta vazia    
    }else if (vetorPrincipal[posicao-1].qtdElementos<1)
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else{
      //excluir ultimo elemento
      vetorPrincipal[posicao-1].qtdElementos--;
      retorno = SUCESSO;
    }
  return retorno;
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
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
    int retorno;
  //printf("excluirNumeroEspecificoDeEstrutura()\n");
    //se a posisao eh invalida
    if (ehPosicaoValida(posicao)==POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    //se existe a estrutura auxiliar
    else if (existeExtruturaAuxiliar(posicao)==SEM_ESTRUTURA_AUXILIAR)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    //se a estrutura esta vazia
    else if (vetorPrincipal[posicao-1].qtdElementos<1)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else{
    	int qtdElementos=vetorPrincipal[posicao-1].qtdElementos;
        //buscar numero
        int index = -1;
        for(int i=0;i<qtdElementos;i++){
            if (vetorPrincipal[posicao-1].vetorAux[i]==valor)
                index=i;
        }
        //se o numero existe na estrutura
        if (index!=-1){
            int qtdElementos=vetorPrincipal[posicao-1].qtdElementos--;
            int* vet = vetorPrincipal[posicao-1].vetorAux;
            int aux;
            //[sihif] puxa todos os itens posteriores a posicao do valor
            for (int i=index;i<qtdElementos-1;i++){
                vet[i]=vet[i+1];
            }
            retorno = SUCESSO;
        }else
            retorno = NUMERO_INEXISTENTE;
    }
    return retorno;
}
/*
Objetivo: verifica se existe estrutura auxiliar na posicao indicada

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int existeExtruturaAuxiliar(int posicao){
    int retorno;
    //printf("existeExtruturaAuxiliar()\n");
    if (ehPosicaoValida(posicao)==POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao-1].vetorAux==NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else
        retorno = SUCESSO;

    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    //printf("ehPosicaoValida()\n");
    int retorno;
    if (posicao < 1 || posicao > TAM){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;

}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
  //printf("getDadosEstruturaAuxiliar()\n");
    int retorno=0;
    if (ehPosicaoValida(posicao)==POSICAO_INVALIDA){
        retorno = POSICAO_INVALIDA;
    }else if (existeExtruturaAuxiliar(posicao)==SEM_ESTRUTURA_AUXILIAR){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else if (vetorPrincipal[posicao-1].qtdElementos<1){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }else{
        for(int i=0;i<vetorPrincipal[posicao-1].qtdElementos;i++)
            vetorAux[i]=vetorPrincipal[posicao-1].vetorAux[i];
        retorno = SUCESSO;
    }

    return retorno;
}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    //tenta pegar os dados da estrutura auxiliar
    int retorno=getDadosEstruturaAuxiliar(posicao,vetorAux);

    //se conseguiu pegar dados
    if(retorno==SUCESSO)
        //ordena
        quick(vetorAux,0,vetorPrincipal[posicao-1].qtdElementos-1);

    return retorno;
}

/*
Objetivo: Ordena o vetor no trecho especificado [esq,...,dir]
Rertono (void)
*/

void quick(int vet[], int esq, int dir){
    int pivo = esq, i,ch,j;
    for(i=esq+1;i<=dir;i++){
        j = i;
        if(vet[j] < vet[pivo]){
            ch = vet[j];
            while(j > pivo){
                vet[j] = vet[j-1];
                j--;
            }
            vet[j] = ch;
            pivo++;
        }
    }
    if(pivo-1 >= esq){
        quick(vet,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quick(vet,pivo+1,dir);
    }
 }

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    //printf("getDadosDeTodasEstruturasAuxiliares()\n");
    int retorno;
    int semEstrutura=1;
    int estruturasVazias=1;
    int index=0;

    for(int i=0;i<TAM;i++){
        //se existe extrutura auxiliar
        if (existeExtruturaAuxiliar(i+1)==SUCESSO){
            semEstrutura=0;
            //se a estrutura nao esta vazia
            if (vetorPrincipal[i].qtdElementos>1){
                estruturasVazias=0;
                int *estrutura=vetorPrincipal[i].vetorAux;
                //pega os dados da estrutura pro vetorAux
                for(int j=0;j<vetorPrincipal[i].qtdElementos;j++){
                vetorAux[index++]=estrutura[j];
            }
            }
        }
    }
    if (semEstrutura)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else if (estruturasVazias)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
  //printf("getDadosOrdenadosDeTodasEstruturasAuxiliares()\n");
    //pega dados de todas as estruturas
    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);

    //se conseguiu pegar os dados
    if (retorno==SUCESSO){
        //ordena o vetorAux
        quick(vetorAux,0,qtdTotalElementos()-1);
    }
    return retorno;
}

/*
Objetivo: Somar a quantidade total de elementos nas 'TAM' Estruturas Auxiliares do vetorPrincipal

Rertono (int)
    total - Soma da quantidade total de elementos
*/
int qtdTotalElementos(){
  //printf("qtdTotalElementos()\n");
    int total=0;

    for(int i=0;i<TAM;i++)
            total=total+vetorPrincipal[i].qtdElementos;

    return total;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno = SUCESSO;
    int tam2;

    tam2 = vetorPrincipal[posicao-1].qtdElementos + novoTamanho;

    if(!ehPosicaoValida(posicao))
        retorno = POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao-1].vetorAux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else if(tam2 <= 0)
        retorno = NOVO_TAMANHO_INVALIDO;
    else{
        vetorPrincipal[posicao - 1].vetorAux = (int*)realloc(vetorPrincipal[posicao - 1].vetorAux , tam2*sizeof(int));

        if(vetorPrincipal[posicao - 1].vetorAux == NULL)
            retorno = SEM_ESPACO_DE_MEMORIA;
        else{
            if(novoTamanho < 0 && vetorPrincipal[posicao-1].qtdElementos == vetorPrincipal[posicao-1].tamanho)
                vetorPrincipal[posicao-1].qtdElementos = vetorPrincipal[posicao-1].qtdElementos + novoTamanho;
            vetorPrincipal[posicao-1].tamanho = tam2;
        }
    }
    return retorno;
}


/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    //printf("getQuantidadeElementosEstruturaAuxiliar()\n");
    int retorno;
    //se a posicao eh valida
    if (ehPosicaoValida(posicao)==POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    //se existe estrutura na posicao
    else if (existeExtruturaAuxiliar(posicao)==SEM_ESTRUTURA_AUXILIAR)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    //se a estrutura esta vazia
    else if (vetorPrincipal[posicao-1].qtdElementos>1)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else
        retorno = vetorPrincipal[posicao-1].qtdElementos;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No* montarListaEncadeadaComCabecote(){
    //printf("montarListaEncadeadaComCabecote()\n");
    int vetorAux[10];
    int retorno;
    int qtdElementos;
    No *cabeca;
    No* atual;
    No* proximo=NULL;

    retorno=getDadosDeTodasEstruturasAuxiliares(vetorAux);

    //verifica se as estruturas auxiliares sao vazias ou inexistentes
    if (retorno==SEM_ESTRUTURA_AUXILIAR || retorno== TODAS_ESTRUTURAS_AUXILIARES_VAZIAS)
        return NULL;
    else{
        //alocar a cabeca
        cabeca=(No*)malloc(sizeof(No));
        //verifica se alocacao anterior falhou
        if (cabeca==NULL)
            return NULL;
        else{
            //alocar primeiro no da lista
            atual=(No*)malloc(sizeof(No));
            //verifica se alocacao anterior falhou
            if (atual==NULL)
                return NULL;
            else{
                //linka a cabeca c o primeiro no
                cabeca->prox=atual;

                //calcula o tamanho do vetorAux
                qtdElementos=qtdTotalElementos();

                for(int i=0;i<qtdElementos-1;i++){
                    //atribui conteudo ao no atual
                    atual->conteudo=vetorAux[i];
                    atual->prox=NULL;

                    //verifica se o vetAux acabou
                    if (i==qtdElementos-1)
                        break;

                    //aloca o proximo no
                    proximo=(No*)malloc(sizeof(No));
                    //verifica se alocacao anterior falhou
                    if (proximo==NULL){
                        return NULL;
                    }else{
                        proximo->prox=NULL;
                        //link o proximo ao atual
                        atual->prox=proximo;
                        atual=proximo;
                    }
                }
                return cabeca;
            }
        }
    }
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){
  //printf("getDadosListaEncadeadaComCabecote()\n");
        No* busca;
        busca=inicio->prox;
        int* endNovo=NULL;

        for(int i=0;busca!=NULL;i++){
              vetorAux[i]=busca->conteudo;
              busca=busca->prox;
        }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No** inicio){
    //printf("destruirListaEncadeadaComCabecote()\n");
    No* anterior;

    while((*inicio)!=NULL){
        anterior=(*inicio);
        (*inicio)=(*inicio)->prox;
        free(anterior);
    }
    free(*inicio);
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/
void inicializar(){
  show_log2("inicializar");
  for(int i=0;i<TAM;i++){
      vetorPrincipal[i].qtdElementos=0;
      vetorPrincipal[i].tamanho=0;
      vetorPrincipal[i].vetorAux=NULL;
  }
  lerArquivo();
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/
void finalizar(){
  show_log2("finalizar()");
  escreverArquivo();
    for(int i=0;i<TAM;i++){
        if(vetorPrincipal[i].vetorAux!=NULL){
          free(vetorPrincipal[i].vetorAux);
        }
    }
}

void escreverArquivo(){

    FILE *output;
    int i,x;

    output = fopen("arquivo.txt","w");

    for(i=0; i<10; i++){
       fprintf(output,"%d",i);
    fprintf(output,"%s",";");

    fprintf(output,"%d",vetorPrincipal[i].tamanho);
    fprintf(output,"%s",";");

         for(x=0; x<vetorPrincipal[i].qtdElementos; x++)
        {
            fprintf(output,"%d",vetorPrincipal[i].vetorAux[x]);
            fprintf(output,"%s",";");
        }
        fprintf(output,"%s","\n");
    }

    fclose(output);
}

int salvaEstrutura(){
    show_log2("salvarEstrutura()");
    int i;
    int indicePrincipal, tamanho, qtd;

    int retorno = SUCESSO;

    // Apaga o já existente e cria um novo arquivo;
    FILE *output = fopen("arquivo.txt", "w");
    fclose(output);

    // Vai percorrer a estrutura principal
    for(i = 0; i < TAM; i++) {
        // Quando achar uma estrutura que existe, ele vai armazenar os seus dados
        if(vetorPrincipal[i].vetorAux != NULL) {
            indicePrincipal = i+1; // +1    por quê o índice inicia no 0
            tamanho = vetorPrincipal[i].tamanho;
            qtd = vetorPrincipal[i].qtdElementos;

            int elementosAux[qtd];
            // Pega os dados Presentes na estrutura auxiliar e armazena no vetor.
            retorno = getDadosEstruturaAuxiliar(indicePrincipal, elementosAux);

            if(retorno != SUCESSO) {
                return retorno;
            }
            // Grava no arquivo
            retorno = gravaNoArquivo(indicePrincipal, tamanho, qtd, elementosAux);

            if(retorno != SUCESSO) {
                return retorno;
            }
        }
    }

    return retorno;
}

int gravaNoArquivo(int indice, int tamanho, int qtd, int elementos[]) {
    show_log2("gravaNoArquivo()");
    // Vai escrever no final do arquivo estrutura.txt
    FILE *output = fopen("arquivo.txt", "a");
    int i;

    if(output == NULL) {
        return FALHA_ABRIR_ARQUIVO;
    }

    // Imprime no Arquivo as Propriedades
    fprintf(output, "%d;", indice);
    fprintf(output, "%d;", tamanho);
    fprintf(output, "%d;", qtd);
        
    // Imprime no Arquivo os Elementos da Estrutura Auxiliar    
    for(i = 0; i < qtd; i++){
        fprintf(output, "%d;", elementos[i]);
    }

    // Imprime o \n no final da linha
    fprintf(output, "\n");
    fclose(output);

    return SUCESSO;

}