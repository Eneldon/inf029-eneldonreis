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

int acharNum(int elemento, int posicao);
int buscaElemento(int, int);
int ehPosicaoValida(int);
int getQuantidadeTotalElementos(void);
void shiftEsquerda(int, int);
void insertionSort(int *v, int tam);
void inserirFimListaEncadeada(No*, int);
int criarEstruturaAuxiliar(int tamanho, int posicao);
int inserirNumeroEmEstrutura(int valor, int posicao);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
No *criarencadearLista(int valor);
void inserirFim(No *inicio, int valor);
void encadearLista(No *inicio, int valor);
No* montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No* inicio);
void inserirFimPalavraEncadeada(No *inicio, int valor);

int contElement(void);
void ordenaLista(int *vt, int tamanho);
int ValidaPosicao(int posicao);
void inicializar();
void finalizar();
void dobrar(int *x);