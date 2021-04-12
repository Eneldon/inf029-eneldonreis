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
  char cpf [12];

} Aluno;
// criando a struct Professor
typedef struct dados_professor{
  int matricula;
  char nome [50];
  char sexo; // M - Masculino, F - Feminino
  Data data_nascimento;
  char cpf [12];
} Professor;
// criando a struct Disciplina
typedef struct disciplina{
    char nome[50];
    int codigo;
    int semestre;
    int alunosDaMateria;
    Professor docente[50];
    Aluno discentes[50];   
} Disciplina;


