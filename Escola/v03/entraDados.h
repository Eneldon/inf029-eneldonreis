// criando a struct data de Nascimento
typedef  struct dma {
  int dia;
  int mes;
  int ano;
} Data; 


// criando a struct Aluno
typedef struct dados_aluno{

  int matricula;
  char nome [50];
  char sexo; // M - Masculino, F - Feminino
  Data data_nascimento;
  char cpf [15];
    
} Aluno;

// criando a struct Aluno
typedef struct dados_professor{

  int matricula;
  char nome [50];
  char sexo; // M - Masculino, F - Feminino
  Data data_nascimento;
  char cpf [15];
    
} Professor;

typedef struct disciplina{
    char nome[50];
    int codigo;
    int semestre;
    int alunosDaMateria;
    Professor docente;
    Aluno discentes[60];
    
} Disciplina;


