
typedef struct data{ 
    int dia, mes, ano; 
}Data; 

/*Criando a Struct Aluno */
typedef struct a{ 
    int matricula;
    char nome[50];
    char sexo; // M - Masculino, F - Feminino
    char cpf[15];
    Data  dma; 
}Aluno;

typedef struct p{ 
    int matricula;
    char nome[50];
    char sexo; // M - Masculino, F - Feminino
    char cpf[15];
    Data  dma; 
}Professor;

typedef struct d{
    char nome[50];
    int codigo;
    int semestre;
    Professor docente;
    
} Disciplina;
