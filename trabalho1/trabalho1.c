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

int somar(int x, int y) {
    return x + y;
}

int fatorial(int x) {
    if (x <= 1) return 1;
    return x * fatorial(x - 1);
}

int ehAnoBissexto(int ano) {
    return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
}

int diasDoMes(int mes, int ano) {
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 ||
        mes == 8 || mes == 10 || mes == 12)
        return 31;

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 30;

    if (mes == 2)
        return ehAnoBissexto(ano) ? 29 : 28;

    return 0;
}

DadosData quebrarData(char data[]) {
    DadosData d;
    d.valido = 0;

    if (sscanf(data, "%d/%d/%d", &d.dia, &d.mes, &d.ano) != 3)
        return d;

    if (d.mes < 1 || d.mes > 12)
        return d;

    if (d.dia < 1 || d.dia > diasDoMes(d.mes, d.ano))
        return d;

    d.valido = 1;
    return d;
}

int q1(char data[]) {
    int barras = 0;
    for (int i = 0; data[i]; i++)
        if (data[i] == '/') barras++;

    if (barras != 2) return 0;

    DadosData d = quebrarData(data);
    return d.valido;
}

DiasMesesAnos q2(char dataInicial[], char dataFinal[]) {
    DiasMesesAnos r = {0, 0, 0, 0};

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
       (fim.ano == ini.ano && fim.mes == ini.mes && fim.dia < ini.dia)) {
        r.retorno = 4;
        return r;
    }

    r.qtdAnos = fim.ano - ini.ano;
    r.qtdMeses = fim.mes - ini.mes;
    r.qtdDias = fim.dia - ini.dia;

    if (r.qtdDias < 0) {
        r.qtdMeses--;
        int mesAnterior = fim.mes == 1 ? 12 : fim.mes - 1;
        int anoAnterior = fim.mes == 1 ? fim.ano - 1 : fim.ano;
        r.qtdDias += diasDoMes(mesAnterior, anoAnterior);
    }

    if (r.qtdMeses < 0) {
        r.qtdAnos--;
        r.qtdMeses += 12;
    }

    r.retorno = 1;
    return r;
}

int q3(char *texto, char caractere, int sensivel) {
    int qtd = 0;

    if (!sensivel && caractere >= 'A' && caractere <= 'Z')
        caractere += 32;

    for (int i = 0; texto[i]; i++) {
        char c = texto[i];
        if (!sensivel && c >= 'A' && c <= 'Z')
            c += 32;
        if (c == caractere)
            qtd++;
    }

    return qtd;
}

int q4(char *texto, char *busca, int posicoes[30])
{
    int i, j;
    int tamTexto = strlen(texto);
    int tamBusca = strlen(busca);
    int qtd = 0;
    int p = 0;

    for (i = 0; i <= tamTexto - tamBusca; i++) {
        j = 0;

        while (j < tamBusca && texto[i + j] == busca[j]) {
            j++;
        }

        if (j == tamBusca) {
            posicoes[p++] = i;
            posicoes[p++] = i + tamBusca - 1;
            qtd++;
        }
    }

    return qtd;
}

int q5(int numero) {
    int inv = 0;
    while (numero > 0) {
        inv = inv * 10 + numero % 10;
        numero /= 10;
    }
    return inv;
}

int q6(int numeroBase, int numeroBusca) {
    char base[50], busca[50];
    sprintf(base, "%d", numeroBase);
    sprintf(busca, "%d", numeroBusca);

    int tb = strlen(base);
    int ts = strlen(busca);
    int qtd = 0;

    for (int i = 0; i <= tb - ts; i++) {
        int j = 0;
        while (j < ts && base[i + j] == busca[j])
            j++;
        if (j == ts)
            qtd++;
    }

    return qtd;
}

int q7(char matriz[8][10], char palavra[]) {
    int dl[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int tamanho = strlen(palavra);

    for (int l = 0; l < 8; l++) {
        for (int c = 0; c < 10; c++) {
            if (matriz[l][c] == palavra[0]) {
                for (int d = 0; d < 8; d++) {
                    int i = l, j = c, k = 0;
                    while (k < tamanho) {
                        if (i < 0 || i >= 8 || j < 0 || j >= 10)
                            break;
                        if (matriz[i][j] != palavra[k])
                            break;
                        i += dl[d];
                        j += dc[d];
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
