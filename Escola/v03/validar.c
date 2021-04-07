#include <stdio.h>
#include <stdlib.h>


int ValidarCPF(char cpf[]){
    int icpf[12],i;
    int resto1,resto2,dv1,dv2;
    int soma=0;

    //converte char pra int
    for(i=0;i<11;i++)
        icpf[i]=cpf[i]-48;

    //gera o 1 digito verificador
    for(i=0;i<9;i++){
        soma+=icpf[i]*(10-i);
    }
    resto1=soma%11;
    if((resto1==1) || (resto1==0)){
        dv1=0;
    }
    else
        dv1=11-resto1;

    //gera o 2 digito verificador
    soma=0;
    for(i=0;i<10;i++){
        soma+=icpf[i]*(11-i);
    }
    resto2=soma%11;
    if((resto2==1) || (resto2==0)){
        dv2=0;
    }
    else
        dv2=11-resto2;

    //checa se os DVs sao validos
    if ((dv1==icpf[9])&&(dv2==icpf[10]))
        return 1;
    else
        return 0;
}

int ValidarData(int dia,int mes, int ano){
    
    if(dia >0 && dia < 32 && mes > 0 && mes < 13 && ano < 2019){
        return 1;
    }
    else{
        return 0;  
    }
    
}