#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define qtdAluno 1 //variável que define a quantidade de alunos que serão cadastrados

void cadastrarAluno(void); // Protótipo 
void ListaDEAlunos(void);
void ListarAlunos(void);


struct registroData{ // tipo de dados
    int dia, mes, ano; 
}; // definição da struct

struct registroAluno{ // tipo de dados
    char nome[50];
    char cpf[15];
    char sexo;
    int matricula;
    struct registroData dma; // Variável da struct RegistroAluno aninhada com 
                            // a struct registoData
};// definição da struct
struct registroAluno aluno[qtdAluno]; // Variável da struct RegistroAluno

int main(){
    int op;

    do{
    printf("\n1 - Inserir Aluno:");
    printf("\n2 - Lista de Alunos:");
    printf("\n3 - Listar Aluno:");
    printf("\n0 - sair:");
    printf("\nOpcao:");
    scanf("%d",&op);
    getchar();

    switch (op)
    {
    case 0:printf("Saindo do Cadastro");
        break;
    case 1:cadastrarAluno();
        break;
    case 2:ListaDEAlunos();
        break;
    case 3:ListarAlunos();
        break;
    
    default:printf("\n Opcao invalida:");
        break;
    }
    }while (op!=0);
   
    
getchar();
}

void cadastrarAluno(void){ 
    
    for (int i=0; i<qtdAluno;i++){    
        printf("\nInserir o nome do Aluno: ");
        fgets(aluno[i].nome,50,stdin);

        /*fgets é uma das funções mais indicadas para ler string do teclado. 
        Ela controla o tamanho do buffer, e não deixa o buffer com lixo. 
        Entretanto ela guarda o \n ao final da string, por isso é preciso removê-lo, como feito a seguir
        size_t = unsigned integer type */

        size_t ly = strlen(aluno[i].nome) - 1;
        if (aluno[i].nome[ly] =='\n'){
        aluno[i].nome[ly] ='\0';
             }
        
        printf("\nInserir o CPF  Aluno: ");
        fgets(aluno[i].cpf,15,stdin);

        size_t lx = strlen(aluno[i].cpf) - 1;
        if (aluno[i].cpf[lx] =='\n'){
        aluno[i].cpf[lx] ='\0';
             }

        printf("\nInserir  o sexo do Alunno ( F-Feminino ou M-Maculino ou O-Outros): ");
        scanf("%c",&aluno[i].sexo);

        getchar();

        printf("\nInforme um numero de matricula para o Aluno): ");
        scanf("%d",&aluno[i].matricula);

        getchar();

        printf("\nInforme a data de nascimento do Aluno padrao dd/mm/aaaa: ");
        scanf("%d%*c%d%*c%d",&aluno[i].dma.dia,&aluno[i].dma.mes,&aluno[i].dma.ano);

        getchar();
    }    
  }   
void ListaDEAlunos(){
  
    int i;
        printf("********** - Alunos Cadastrados - **********\n");
        printf("Lista de Alunos:\n");
        for (i=0; i<qtdAluno;i++){
        printf("%s",aluno[i].nome);
     /* printf("CPF:%s",aluno[i].cpf);
        printf("Sexo:%c\n",aluno[i].sexo);
        printf("Matricula:%d\n",aluno[i].matricula);
        printf("Data Nascimento:%d/%d/%d\n",aluno[i].dma.dia,aluno[i].dma.mes,aluno[i].dma.ano);*/
        
    } 
} 
void ListarAlunos(void){
    int i;
    char nome[50];
        printf("\nDigite o nome do aluno que deseja listar: ");
        fgets(nome,50,stdin);
        size_t lx = strlen(nome) - 1;
        if (nome[lx] =='\n'){
        nome[lx] ='\0';
             }
        int sl=0, existe = 1;

        for(i=0; i<qtdAluno; i++){
        if(strcmp(nome,aluno[i].nome) == 0){
			printf("Nome: %s | CPF: %s | Sexo: %c | Matricula: %d | Data Nascimento: %d/%d/%d \n",
				aluno[i].nome,
				aluno[i].cpf,
				aluno[i].sexo,
				aluno[i].matricula,
				aluno[i].dma.dia,
				aluno[i].dma.mes,
                aluno[i].dma.ano);
            existe = 1;
            break;
        }else{
            existe = 0;
        }
    }
    
    
}
