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

int somar(int x, int y)
{ int soma = 0; 
      soma = x + y; 
return soma;
}
int fatorial(int x)
{ 
  int fat = 1;
  int i;
  for(i=1; i <=x; i++){
      fat = fat * i;
  }
  return fat;
}

int q1(char data[11]){
   int datavalida = 1;
   int i,j=0; // variável contador
   int vet[2]; // vetor para guarda as posições de /
   int p1,p2; // vriável para guardar a posição da barra
   char dia[3],mes[3],ano[5];
   int iDia,iMes,iAno;
     
  // guardar posição da /
   for( i=0; i<11 ; i++){
      if(data[i]=='/'){
         vet[j] = i;
         j++;
         p1 = vet[0];
         p2 = vet[1];    
      }  
   }
   for(i=0; i<p1; i++){    // guardando o valor da string dia
         dia[i] = data[i]; 
   }
   j =0;
   for(i=p1+1; i<p2; i++){  // guardando o valor da string mes
      mes[j] = data[i];
      j++;
   }
   j =0;
   for(i=p2+1; i < data[i]; i++){  // guardando o valor da string ano
      ano[j] = data[i];
      j++;
   }

   // Fazendo conversão de string para Inteiro
   iDia = atoi(dia);
   iMes = atoi(mes);
   iAno = atoi(ano);

   if(iAno < 2000) // Caso o ano seja digitado apenas com 2 digitos, coma com 2000 pra finalizar o processo.
      iAno = iAno + 2000;    // imprimindo a data      // printf(" %d/%d/%d -",iDia,iMes,iAno);

   switch (iMes){
         case 1: if(iDia > 31) datavalida = 0;  break;
         case 2:  if((iAno % 4 == 0 && iAno % 100 !=0) ||(iAno % 400 == 0)){
                     if(iDia > 29)
                      datavalida = 0;
                      }else{
                         if(iDia > 28)
                           datavalida = 0;
         }break;    
         case 3:  if(iDia < 1 || iDia > 31){ datavalida = 0; }break;
         case 4:  if(iDia > 30){ datavalida = 0; }break;
         case 5:  if(iDia > 31){ datavalida = 0; }break;
         case 6:  if(iDia > 30){ datavalida = 0; }break;
         case 7:  if(iDia > 31){ datavalida = 0; }break;
         case 8:  if(iDia > 31){ datavalida = 0; }break;
         case 9:  if(iDia > 30){ datavalida = 0; }break;
         case 10: if(iDia > 30){ datavalida = 0; }break;
         case 11: if(iDia > 30){ datavalida = 0; }break;
         case 12: if(iDia > 31){ datavalida = 0; }break;
         default: datavalida = 0; break;
        
      }

      if(datavalida){
         return 1;
      }else
         return 0;
}

// Estrutua struct para atender data inicial e data final.
typedef struct d{
  char dia[3],mes[3],ano[5];
  int iDia,iMes,iAno;
  int p1,p2; // vriável para guardar a posição da barra
  int vet[2];// vetor para guarda as posições de /
 
}Dados;

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
      Dados d1;
      Dados d2;
      int op;
      int idatainicial, idatafinal;
      int datavalida =1;
      int nDias, nMeses, nAnos;
      int i,j=0; // variável contador para data inicial
      int k,y=0; // variável contador para data final
   
        // programa para guardar a posiçao da '/'.
            for( k=0; k<10 ; k++){
               if(datainicial[k] =='/'){
                   d1.vet[y] = k;
                   y++;
                   d1.p1 = d1.vet[0];
                   d1.p2 = d1.vet[1];    
               }  
            }
   
         // Laço para guardar s string dia.
         for(k=0; k<d1.p1; k++){
              d1.dia[k] = datainicial[k]; 
         }
         // Laço para guardar s string mês.
          y = 0;
         for(k=d1.p1+1; k<d1.p2; k++){
            d1.mes[y] = datainicial[k];
             y++;
         }
         // Laço para guardar s string ano.
            y = 0;
         for(k=d1.p2+1; k < datainicial[k]; k++){
               d1.ano[y] = datainicial[k];
               y++;
            }
         // Convertendo a string para inteiro:
            d1.iDia = atoi(d1.dia);
            d1.iMes = atoi(d1.mes);
            d1.iAno = atoi(d1.ano);
   
         // Condição, se data for menot que 2000, somar data + 2000 
       if(d1.iAno < 2000)
            d1.iAno = d1.iAno + 2000;
         // programa para guardar a posiçao da '/'.
          for( i=0; i<10 ; i++){
               if(datafinal[i] =='/'){
                  d2.vet[j] = i;
                  j++;
                  d2.p1 = d2.vet[0];
                  d2.p2 = d2.vet[1];    
               }  
            }
   
         // guardando o valor da string dia
            for(i=0; i<d2.p1; i++){
                  d2.dia[i] = datafinal[i];    
               }
         // guardando o valor da string mes
            j =0;
            for(i=d2.p1+1; i<d2.p2; i++){
                d2.mes[j] = datafinal[i];
                  j++;
            }
         // guardando o valor da string ano
             j =0;
            for(i=d2.p2+1; i < datafinal[i]; i++){
                d2.ano[j] = datafinal[i];
                j++;
               } 
   // Convertendo a string para inteiro dia, mes, ano
               d2.iDia = atoi(d2.dia);
               d2.iMes = atoi(d2.mes);
               d2.iAno = atoi(d2.ano);
      
   // Condição, se data for menot que 2000, somar data + 2000 
    if(d2.iAno < 2000)
      d2.iAno = d2.iAno + 2000;

    //*************************************************************************
      
      if (q1(datainicial) == 0 )
      return 2; 
      nDias  = d2.iDia - d1.iDia;
      nMeses = d2.iMes - d1.iMes;
      nAnos  = d2.iAno - d1.iAno;

      if (q1(datafinal) == 0 )
      return 3; 
      nDias  = d2.iDia - d1.iDia;
      nMeses = d2.iMes - d1.iMes;
      nAnos  = d2.iAno - d1.iAno;
            
      if (q1(datainicial) == 1)
          if(q1(datafinal) == 1)
            if(d1.iAno > d2.iAno || d1.iMes > d2.iMes || d1.iDia > d2.iDia )
             
      return 4;        
     //mantenha o código abaixo, para salvar os dados em nos parâmetros da funcao
        
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
    uma string texto, um caracter c e um inteiro que informa 
    se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1,
     a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças
         entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

// função para conversão, mas não está em uso
void minusculo(char s1[250], char s2[250]){
   int i=0;
   while (s1[i !='\0']){
      s2[i] = tolower(s1[i]);
      i++;
   }  
}
int q3(char texto[250], char c, int isCaseSensitive){
   int i,j, qtdOcorrencias = 0;
   char texto2[250];
                 // converter string para Minusculo e guarda em uma nova variável
                 for(i=0; i<=strlen(texto);i++){
                    texto2[i] = tolower(texto[i]);
                 }

      // verificar condição, se 0 não levar em consideração maiuscula e minuscula           
      if(isCaseSensitive == 0){
         for(i=0; i<=strlen(texto2); i++){        
                     if(texto2[i]==  tolower(c)) {
                          qtdOcorrencias++;   }
         }
      }  printf("%c - ",c);
      // verificar condição, se 1 levar em consideração maiuscula e minuscula      
     if(isCaseSensitive == 1){
         for(j=0; j<=strlen(texto); j++){        
               if(texto[j] == c ){
                       qtdOcorrencias++;    }
         }
      }    
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

 // printf("%5d -   ",numInvertido);
   
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
   int qtdOcorrencias = 0 ;
     char cBusca[10];
     char cBase[10];
     int x=0;
     int i = 0;
 
   
     itoa(numerobase,cBase,10); // N2
     itoa(numerobusca, cBusca,10); //N1
    // scanf(" %s",&N1);
    // scanf(" %s",&N2);
    do
    {
        if(!strncmp(cBase+x, cBusca, strlen(cBusca)))
        {
            qtdOcorrencias++;
            
            x+=strlen(cBusca);
        }
        else
            x+=1;
    }    while(x<strlen(cBase));
   
    return qtdOcorrencias;
}
