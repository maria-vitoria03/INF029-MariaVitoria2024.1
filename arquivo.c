#include "arquivo.h"
#include "disciplinas.h"
#include "pessoa.h"
#include "string.h"
#include <stdio.h>

void salvarAlunos(const char *alunos) {
  FILE *arquivo = fopen(alunos, "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", alunos);
    return;
  }

  for (int i = 0; i < numAlunosCadastrados; i++) {
    fprintf(arquivo, "%d\n", contAluno[i].matricula);
    fprintf(arquivo, "%s", contAluno[i].nome);
    fprintf(arquivo, "%c\n", contAluno[i].sexo);
    fprintf(arquivo, "%d %d %d\n", contAluno[i].dataNas.dia,
            contAluno[i].dataNas.mes, contAluno[i].dataNas.ano);
    fprintf(arquivo, "%s", contAluno[i].cpf);
    fprintf(arquivo, "%d\n", contAluno[i].alunoAtivo);
  }

  fclose(arquivo);
}

void carregarAlunos(const char *alunos) {
  FILE *arquivo = fopen(alunos, "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", alunos);
    return;
  }

  int matricula;
  char nome[MAX_LETRAS];
  char sexo;
  int dia, mes, ano;
  char cpf[15];
  int alunoAtivo;

  while (fscanf(arquivo, "%d", &matricula) != EOF) {
    fgets(nome, sizeof(nome), arquivo);
    fscanf(arquivo, " %c", &sexo);
    fscanf(arquivo, "%d %d %d", &dia, &mes, &ano);
    fgets(cpf, sizeof(cpf), arquivo);
    fscanf(arquivo, "%d", &alunoAtivo);

    contAluno[numAlunosCadastrados].matricula = matricula;
    strcpy(contAluno[numAlunosCadastrados].nome, nome);
    contAluno[numAlunosCadastrados].sexo = sexo;
    contAluno[numAlunosCadastrados].dataNas.dia = dia;
    contAluno[numAlunosCadastrados].dataNas.mes = mes;
    contAluno[numAlunosCadastrados].dataNas.ano = ano;
    strcpy(contAluno[numAlunosCadastrados].cpf, cpf);
    contAluno[numAlunosCadastrados].alunoAtivo = alunoAtivo;

    numAlunosCadastrados++;
  }

  fclose(arquivo);
}

void salvarProfessores(const char *professores) {
  FILE *arquivo = fopen(professores, "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s.\n", professores);
    return;
  }

  for (int i = 0; i < numProfCadastrados; i++) {
    fprintf(arquivo, "%d\n", contProf[i].matricula);
    fprintf(arquivo, "%s", contProf[i].nome);
    fprintf(arquivo, "%c\n", contProf[i].sexo);
    fprintf(arquivo, "%d %d %d\n", contProf[i].dataNas.dia,
            contProf[i].dataNas.mes, contProf[i].dataNas.ano);
    fprintf(arquivo, "%s", contProf[i].cpf);
    fprintf(arquivo, "%d\n", contProf[i].alunoAtivo);
  }

  fclose(arquivo);
}