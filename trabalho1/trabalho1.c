// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

// Nome: Lucas Toshiyuki Katayama Castanheira
// email: ltoshikc@gmail.com
// Matrícula: 20251160012
// Semestre: 2025.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabalho1.h"

int q1(char data[])
{
    int i = 0, barra = 0;

    while (data[i] != '\0') {
        if (data[i] == '/') barra++;
        i++;
    }

    if (barra != 2) return 0;

    DadosData d = quebrarData(data);
    if (!d.valido) return 0;

    if (d.mes < 1 || d.mes > 12) return 0;
    if (d.dia < 1) return 0;

    int diasMes;

    if (d.mes == 1 || d.mes == 3 || d.mes == 5 || d.mes == 7 || d.mes == 8 || d.mes == 10 || d.mes == 12)
        diasMes = 31;
    else if (d.mes == 4 || d.mes == 6 || d.mes == 9 || d.mes == 11)
        diasMes = 30;
    else {
        if ((d.ano % 400 == 0) || (d.ano % 4 == 0 && d.ano % 100 != 0))
            diasMes = 29;
        else
            diasMes = 28;
    }

    if (d.dia > diasMes) return 0;

    return 1;
}

Diferenca q2(char dataInicial[], char dataFinal[])
{
    Diferenca r;
    r.dias = 0;
    r.meses = 0;
    r.anos = 0;

    DadosData ini = quebrarData(dataInicial);
    DadosData fim = quebrarData(dataFinal);

    if (!ini.valido) {
        r.retorno = 2;
        return r;
    }

    if (!fim.valido) {
        r.retorno = 3;
        return r;
    }

    if (fim.ano < ini.ano ||
       (fim.ano == ini.ano && fim.mes < ini.mes) ||
       (fim.ano == ini.ano && fim.mes == ini.mes && fim.dia < ini.dia))
    {
        r.retorno = 4;
        return r;
    }

    r.anos = fim.ano - ini.ano;
    r.meses = fim.mes - ini.mes;
    r.dias = fim.dia - ini.dia;

    if (r.dias < 0) {
        r.meses--;
        int diasMesAnterior = diasDoMes(fim.mes == 1 ? 12 : fim.mes - 1,
                                        fim.mes == 1 ? fim.ano - 1 : fim.ano);
        r.dias += diasMesAnterior;
    }

    if (r.meses < 0) {
        r.anos--;
        r.meses += 12;
    }

    r.retorno = 1;
    return r;
}

int q3(char *texto, char caractere, int sensivel)
{
    int i = 0;
    int qtd = 0;

    if (!sensivel) {
        if (caractere >= 'A' && caractere <= 'Z')
            caractere = caractere + 32;
    }

    while (texto[i] != '\0') {

        char atual = texto[i];

        if (!sensivel) {
            if (atual >= 'A' && atual <= 'Z')
                atual = atual + 32;
        }

        if (atual == caractere)
            qtd++;

        i++;
    }

    return qtd;
}

int q4(char *texto, char *busca, int posicoes[])
{
    int i = 0;
    int j = 0;
    int tamanhoTexto = strlen(texto);
    int tamanhoBusca = strlen(busca);
    int qtd = 0;
    int pos = 0;

    while (i < tamanhoTexto) {

        if (texto[i] == busca[0]) {
            j = 0;

            while (j < tamanhoBusca && texto[i+j] == busca[j]) {
                j++;
            }

            if (j == tamanhoBusca) {

                posicoes[pos] = i;
                pos++;
                posicoes[pos] = i + tamanhoBusca - 1;
                pos++;

                qtd++;
            }
        }

        i++;
    }

    return qtd;
}

int q5(int n)
{
    int invertido = 0;

    while (n > 0) {
        invertido = invertido * 10 + (n % 10);
        n /= 10;
    }

    return invertido;
}

int q6(int numerogrande, int numerobusca)
{
    char texto[50];
    char busca[50];
    int i = 0, j = 0;
    int tamTexto, tamBusca;
    int qtd = 0;

    sprintf(texto, "%d", numerogrande);
    sprintf(busca, "%d", numerobusca);

    tamTexto = strlen(texto);
    tamBusca = strlen(busca);

    while (i < tamTexto) {

        if (texto[i] == busca[0]) {
            j = 0;

            while (j < tamBusca && texto[i+j] == busca[j]) {
                j++;
            }

            if (j == tamBusca) {
                qtd++;
            }
        }

        i++;
    }

    return qtd;
}

int q7(char matriz[8][10], char busca[])
{
    int linha, coluna;
    int i;
    int tamanho = strlen(busca);

    int direcaoLinha[8]  = { 0, 0, 1, -1, 1, 1, -1, -1 };
    int direcaoColuna[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

    for (linha = 0; linha < 8; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {

            if (matriz[linha][coluna] == busca[0]) {

                int d;

                for (d = 0; d < 8; d++) {
                    int l = linha;
                    int c = coluna;
                    int k = 0;

                    while (k < tamanho) {

                        if (l < 0 || l >= 8 || c < 0 || c >= 10)
                            break;

                        if (matriz[l][c] != busca[k])
                            break;

                        l += direcaoLinha[d];
                        c += direcaoColuna[d];
                        k++;
                    }

                    if (k == tamanho)
                        return 1;
                }
            }
        }
    }

    return 0;

}


