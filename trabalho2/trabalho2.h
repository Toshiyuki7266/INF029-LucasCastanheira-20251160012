#ifndef TRABALHO2_H
#define TRABALHO2_H

#define SUCESSO 1

#define POSICAO_INVALIDA -1
#define SEM_ESTRUTURA_AUXILIAR -2
#define ESTRUTURA_AUXILIAR_VAZIA -3
#define SEM_ESPACO -4
#define NUMERO_INEXISTENTE -5
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -6
#define TAMANHO_INVALIDO -7
#define JA_TEM_ESTRUTURA_AUXILIAR -8
#define NOVO_TAMANHO_INVALIDO -9
#define SEM_ESPACO_DE_MEMORIA -10

typedef struct No {
    int conteudo;
    struct No *prox;
} No;


int criarEstruturaAuxiliar(int posicao, int tamanho);
int inserirNumeroEmEstrutura(int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);

No *montarListaEncadeadaComCabecote();

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No **inicio);
void inicializar();
void finalizar();

#endif

