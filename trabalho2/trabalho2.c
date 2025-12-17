#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

typedef struct {
    int *valores;
    int qtd;
    int tamanho;
} Ponto;

Ponto vetorPrincipal[TAM];

int valida_posicao(int pos) {
    return (pos >= 1 && pos <= TAM);
}

int tem_estrutura(int pos) {
    return vetorPrincipal[pos].valores != NULL;
}

int estrutura_vaga(Ponto *p) {
    return p->qtd < p->tamanho;
}

int BuscaValor(int posicao, int valor) {
    for (int i = 0; i < vetorPrincipal[posicao].qtd; i++)
        if (vetorPrincipal[posicao].valores[i] == valor)
            return i;
    return -1;
}

int get_qtd(Ponto *vet) {
    int tam = 0;
    for (int i = 0; i < TAM; i++)
        tam += vet[i].qtd;
    return tam;
}

void ordena_vetor(int vet[], int tam) {
    for (int i = 1; i < tam; i++) {
        int aux = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}

int criarEstruturaAuxiliar(int posicao, int tamanho) {
    if (!valida_posicao(posicao))
        return POSICAO_INVALIDA;

    posicao--;

    if (tem_estrutura(posicao))
        return JA_TEM_ESTRUTURA_AUXILIAR;

    if (tamanho < 1)
        return TAMANHO_INVALIDO;

    int *teste = malloc(tamanho * sizeof(int));
    if (!teste)
        return SEM_ESPACO_DE_MEMORIA;
    free(teste);

    vetorPrincipal[posicao].valores = malloc(tamanho * sizeof(int));
    vetorPrincipal[posicao].qtd = 0;
    vetorPrincipal[posicao].tamanho = tamanho;

    return SUCESSO;
}

int inserirNumeroEmEstrutura(int posicao, int valor) {
    if (!valida_posicao(posicao))
        return POSICAO_INVALIDA;

    posicao--;

    if (!tem_estrutura(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    if (!estrutura_vaga(&vetorPrincipal[posicao]))
        return SEM_ESPACO;

    vetorPrincipal[posicao].valores[vetorPrincipal[posicao].qtd++] = valor;
    return SUCESSO;
}

int excluirNumeroDoFinaldaEstrutura(int posicao) {
    if (!valida_posicao(posicao))
        return POSICAO_INVALIDA;

    posicao--;

    if (!tem_estrutura(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    vetorPrincipal[posicao].qtd--;
    return SUCESSO;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    if (!valida_posicao(posicao))
        return POSICAO_INVALIDA;

    posicao--;

    if (!tem_estrutura(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int pos = BuscaValor(posicao, valor);
    if (pos < 0)
        return NUMERO_INEXISTENTE;

    for (int i = pos; i < vetorPrincipal[posicao].qtd - 1; i++)
        vetorPrincipal[posicao].valores[i] =
            vetorPrincipal[posicao].valores[i + 1];

    vetorPrincipal[posicao].qtd--;
    return SUCESSO;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    if (!valida_posicao(posicao))
        return POSICAO_INVALIDA;

    posicao--;

    if (!tem_estrutura(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    for (int i = 0; i < vetorPrincipal[posicao].qtd; i++)
        vetorAux[i] = vetorPrincipal[posicao].valores[i];

    return SUCESSO;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int ret = getDadosEstruturaAuxiliar(posicao, vetorAux);
    if (ret == SUCESSO)
        ordena_vetor(vetorAux, vetorPrincipal[posicao - 1].qtd);
    return ret;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int k = 0;

    for (int i = 0; i < TAM; i++)
        if (tem_estrutura(i))
            for (int j = 0; j < vetorPrincipal[i].qtd; j++)
                vetorAux[k++] = vetorPrincipal[i].valores[j];

    return (k > 0) ? SUCESSO : TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int ret = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if (ret == SUCESSO)
        ordena_vetor(vetorAux, get_qtd(vetorPrincipal));
    return ret;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    if (!valida_posicao(posicao))
        return POSICAO_INVALIDA;

    posicao--;

    if (!tem_estrutura(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].tamanho + novoTamanho < 1)
        return NOVO_TAMANHO_INVALIDO;

    int novoTam = vetorPrincipal[posicao].tamanho + novoTamanho;

    int *novo = realloc(vetorPrincipal[posicao].valores,
                         novoTam * sizeof(int));
    if (!novo)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao].valores = novo;
    vetorPrincipal[posicao].tamanho = novoTam;

    if (vetorPrincipal[posicao].qtd > novoTam)
        vetorPrincipal[posicao].qtd = novoTam;

    return SUCESSO;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    if (!valida_posicao(posicao))
        return POSICAO_INVALIDA;

    posicao--;

    if (!tem_estrutura(posicao))
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return vetorPrincipal[posicao].qtd;
}

void Inserir(No *inicio, int valor) {
    No *novo = malloc(sizeof(No));
    novo->conteudo = valor;
    novo->prox = NULL;

    No *aux = inicio;
    while (aux->prox)
        aux = aux->prox;
    aux->prox = novo;
}

No *montarListaEncadeadaComCabecote() {
    int total = get_qtd(vetorPrincipal);
    if (total == 0)
        return NULL;

    No *inicio = malloc(sizeof(No));
    inicio->prox = NULL;

    int *vet = malloc(total * sizeof(int));
    getDadosDeTodasEstruturasAuxiliares(vet);

    for (int i = 0; i < total; i++)
        Inserir(inicio, vet[i]);

    free(vet);
    return inicio;
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    No *aux = inicio->prox;
    int i = 0;
    while (aux) {
        vetorAux[i++] = aux->conteudo;
        aux = aux->prox;
    }
}

void destruirListaEncadeadaComCabecote(No **inicio) {
    No *aux = *inicio;
    while (aux) {
        No *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    *inicio = NULL;
}

void inicializar() {
    for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i].valores = NULL;
        vetorPrincipal[i].qtd = 0;
        vetorPrincipal[i].tamanho = 0;
    }
}

void finalizar() {
    for (int i = 0; i < TAM; i++) {
        free(vetorPrincipal[i].valores);
        vetorPrincipal[i].valores = NULL;
        vetorPrincipal[i].qtd = 0;
        vetorPrincipal[i].tamanho = 0;
    }
}

