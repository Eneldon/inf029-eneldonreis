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
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  int i;
  for(i=1; i < x; i++){
      fat = fat * i;
  }
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char data[10]){
   int datavalida = 1;
   int i,j=0; // variável contador
   int vet[2]; // vetor para guarda as posições de /
   int p1,p2; // vriável para guardar a posição da barra
   char dia[3],mes[3],ano[5];
   int iDia,iMes,iAno;
 // guardar posição da /
   for( i=0; i<10 ; i++){
      if(data[i]=='/'){
         vet[j] = i;
         j++;
         p1 = vet[0];
         p2 = vet[1];    
      }  
   }
   // guardando o valor da string dia
   for(i=0; i<p1; i++){
         dia[i] = data[i];
      
   }
   // guardando o valor da string mes
   j =0;
   for(i=p1+1; i<p2; i++){
      mes[j] = data[i];
      j++;
   }
   // guardando o valor da string ano
   j =0;
   for(i=p2+1; i < data[i]; i++){
      ano[j] = data[i];
      j++;
   }
   // Convertendo a string para inteiro dia, mes, ano
   iDia = atoi(dia);
   iMes = atoi(mes);
   iAno = atoi(ano);
   // imprimindo a data 
   printf(" %d/%d/%d -   ",iDia,iMes,iAno);
   // validando data 

   switch (iMes){

      case 1: if(iDia > 31)
                  datavalida = 0;
             break;
      case 2: if((iAno % 4 == 0 && iAno % 100 !=0) ||(iAno % 400 == 0)){
                  if(iDia > 29)
                  datavalida = 0;
               }else{
                  if(iDia > 28)
                  datavalida = 0;
               }   
               break;    
      case 3: if(iDia < 1 || iDia > 31){
                  datavalida = 0;
              }break;
      case 4: if(iDia > 30){
                  datavalida = 0;
      }        break;
      case 5: if(iDia > 31){
                  datavalida = 0;
               }break;
      case 6: if(iDia > 30){
                  datavalida = 0;
               }break;
      case 7: if(iDia > 31){
                  datavalida = 0;
               }break;
      case 8: if(iDia > 31){
                  datavalida = 0;
               }break;
      case 9: if(iDia > 30){
                  datavalida = 0;
              }break;
      case 10: if(iDia > 30){
                  datavalida = 0;
               }break;
      case 11: if(iDia > 30){
                  datavalida = 0;
               }break;
      case 12: if(iDia > 31){
                  datavalida = 0;
               }break;
      default:
         datavalida = 0;
         break;
        
      }

      if(datavalida){
         return 1;
      }else
         return 0;
 
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */

typedef struct d{  
   int datavalida;
   int vet[2]; // vetor para guarda as posições de /
   int p1,p2; // vriável para guardar a posição da barra
   char dia[3],mes[3],ano[5];
   int iDia,iMes,iAno;  
}Dados;

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    Dados d1;
    Dados d2;
    int nDias, nMeses, nAnos;

    if (q1(datainicial) == 0)
        return 2;

    nDias = 4;
    nMeses = 10;
    nAnos = 2;




    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;

}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = -1;

    return qtdOcorrencias;

}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = -1;

    return qtdOcorrencias;

}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){

   int numInvertido = 0;

   while(num)
   {
      numInvertido = numInvertido * 10 + num % 10;
      num = num / 10;
   }
   num = numInvertido;

  printf("%5d -   ",numInvertido);
   
    return num;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias;
    return qtdOcorrencias;
}
