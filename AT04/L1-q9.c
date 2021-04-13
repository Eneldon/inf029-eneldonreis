#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 256
#define retorno ok 1
#define rerorno nok 0
// Nome: Eneldon de Jesus Barros Reis
// Semestre:  segundo
// Matrícula: 2019116011
/*9) Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. 
     Cada validação deve ser feita em uma função diferente, conforme lista abaixo. 
     A função cadastrarCliente deve chamar cada uma dessas funções. 
     A função main deve imprimir se o cadastro foi realizado com sucesso ou se houve erro, informando onde foi o erro:
•	função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
•	função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para masculino; f e F para feminino, o e O para outro).
•	função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
•	função validarNacimento: recebe o data digitada, e valida é uma data válida.
*/
void validarNome(char nome[256]);
void validarSexo(char sexo);
void validarCPF(char cpf[15]);
void validarNacimento(int dia, int mes, int ano);


int cadastro_cliente(){
        char nome[256];
        char cpf[15];
        char sexo;
        int dia;
        int mes;
        int ano;

        printf("Digite nome: ");              
        fgets(nome,256,stdin);
        fflush(stdin); 

        printf("Digite o Sexo  F -Feminino M - Masculino O - Outros:");      
        scanf("%c",&sexo);
        fflush(stdin); 

        printf("Digite o CPF xxxxxxxxxxx :");              
        fgets(cpf,15,stdin);
        fflush(stdin);

        printf("Digite data  de  Nascimento dd/mm/aaaa : ");              
        scanf("%d%*c%d%*c%d",&dia,&mes,&ano);
        fflush(stdin);

        validarNome(nome);
        validarSexo(sexo);
        validarCPF(cpf);
        validarNacimento(dia,mes, ano);

        
return 0;      
}
void  validarNome(char nome[256]) {
            
            if(strlen(nome)<20){
            printf("Nome: %s",nome);
                return ;
            }else{
            printf("Nome invalido + de 20 caracteres\n");
            } return ;
}
void validarSexo(char sexo){
            if (sexo =='m' || sexo =='M'){
            printf("Sexo: Masculino valido\n");
            }else if(sexo == 'f' || sexo =='F'){
            printf("Sexo: Feminino valido\n");
            }else if(sexo =='o' || sexo =='O'){
            printf("Sexo: Outros valido\n");
            }else{
            printf("Sexo digitado invalido\n");
            }
}
void validarCPF(char cpf[15]){
    char digito10,digito11;
    int soma,resultado,numero,contador;

        /*fgets é uma das funções mais indicadas para ler string do teclado. 
        Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
        Entretanto ela guarda o \n ao final da string, por isso é preciso removê-lo, como feito a seguir
        size_t = unsigned integer type */
        size_t lx = strlen(cpf) - 1;
    if (cpf[lx] =='\n'){
        cpf[lx] ='\0';
    }
    soma = 0; 
    for(contador=0; contador<9; contador++){
        numero = cpf[contador] - 48;
        soma = soma + (numero * (10 - contador));
    }
    resultado = 11 - (soma % 11);
    if((resultado==10)||(resultado==11)){
        digito10 ='0';
    }else {
        digito10 = resultado + 48;
    }
    soma = 0;
    for(contador = 0; contador < 10; contador++){
        numero-cpf[contador]-48;
        soma = soma +(numero*( 11 - contador));
    }
    resultado = 11-(soma % 11);
    if((resultado==10)||(resultado == 11)){
        digito11= '0';
    }else{
        digito11 = resultado - 48;
    }

    if((digito10==cpf[9]) && (digito10==cpf[10])){
        printf("CPF: %s CPF Valido\n",cpf);
    }else{
        printf("CPF: %s invalido\n",cpf);
    }
            
}
void validarNacimento(int dia, int mes, int ano){
        // validando ano
        if(ano >=1900 && ano <=9000){
        // validando mes
        if(mes >= 1 && mes<=12){
        // validando dia
        if((dia >=1 && dia <=31) && (mes ==1 || mes ==3 || mes ==5 || mes ==7 
            || mes ==8 || mes ==10 || mes ==12 ))
            printf("Data Nascimento: %d/%d/%d - Valido \n",dia,mes,ano);
        else if((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
            printf("Data Nascimento: %d/%d/%d - Valido \n",dia,mes,ano);
        else if ((dia >= 1 && dia <= 28) && (mes == 2))
            printf("Data Nascimento: %d/%d/%d - Valido \n",dia,mes,ano);
        else if (dia == 29 && mes == 2 && (ano % 400 == 0
            || (ano % 4 == 0 && ano % 100 != 0)))
            printf("Data Nascimento: %d/%d/%d Data Valiada\n",dia,mes,ano);
            else
            printf("Data Nascimento: %d/%d/%d - Data - Invalido\n",dia,mes,ano);
        }else{
            printf("Data Nascimento: %d/%d/%d - Mes - invalido\n",dia,mes,ano);
            }          
    }else{
        printf("Data Nascimento: %d/%d/%d - Ano invalido\n",dia,mes,ano);
        } 

            

}
int main(){
    
     cadastro_cliente(); 
      
    return 0;
}


    
 
    

