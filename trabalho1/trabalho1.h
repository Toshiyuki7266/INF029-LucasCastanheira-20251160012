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

#ifndef TRABALHO1_H
#define TRABALHO1_H


typedef struct DadosData
{
int dia;
int mes;
int ano;
int valido;
} DadosData;


typedef struct Diferenca
{
int dias;
int meses;
int anos;
int retorno;
} Diferenca;


int somar(int x, int y);
int fatorial(int x);
int q1(char data[]);
Diferenca q2(char dataInicial[], char dataFinal[]);
int q3(char *texto, char caractere, int sensivel);
int q4(char *textoBase, char *palavraBusca, int posicoes[30]);
int q5(int numero);
int q6(int numeroBase, int numeroBusca);
int q7(char matriz[8][10], char palavra[6]);
DadosData quebrarData(char data[]);


int ehAnoBissexto(int ano);
int diasDoMes(int mes, int ano);
char normalizarCaractere(char c);
int busca_em_direcao(char matriz[8][10], int linhas, int colunas, int li, int cj, char palavra[6], int di, int dj);


#endif
