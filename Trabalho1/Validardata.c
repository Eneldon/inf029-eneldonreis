#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int ValidaData( char data[10]){
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
   
   // validando data 
   if(iAno < 2000)
      iAno = iAno + 2000;
   // imprimindo a data 
   printf(" %d/%d/%d -",iDia,iMes,iAno);

}