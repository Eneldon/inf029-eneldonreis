
typedef struct registroData{ 
    int dia, mes, ano; 
}Data; 

/*Criando a Struct Aluno */
typedef struct registroAluno{ 
    int matricula;
    char nome[50];
    char sexo; // M - Masculino, F - Feminino
    char cpf[15];
    Data  dma; 
}Aluno;

typedef struct registroDocente{ 
    int matricula;
    char nome[50];
    char sexo; // M - Masculino, F - Feminino
    char cpf[15];
    Data  dma; 
}Professor;

typedef struct disciplina{
    char nome[50];
    int codigo;
    int semestre;
    int alunosDaMateria;
    Professor docente;
    Aluno discentes[60];
} Disciplina;
