#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11

typedef struct reg {
	int conteudo;
  struct reg *prox;
} No;


int criarEstruturaAuxiliar(int tamanho, int posicao); // OK - TESTAR
int inserirNumeroEmEstrutura(int valor, int posicao); // OK - TESTAR
int excluirNumeroDoFinaldaEstrutura(int posicao); // OK - TESTAR
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao); //OK
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]); // OK
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);// OK
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]); //OK
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]); //OK
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);//OK
int getQuantidadeElementosEstruturaAuxiliar(int posicao); // OK
No* montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No** inicio);

void inicializar();
void finalizar();
void dobrar(int *x);