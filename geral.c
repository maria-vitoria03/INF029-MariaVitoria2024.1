#include "geral.h"
#include "disciplinas.h"
#include "pessoa.h"
#include <stdio.h>
#include <string.h>

void relatorios() {
  printf("----------------------------\n");
  printf(" ***** Módulo de relatórios ***** \n");
  printf(" 0 - Voltar \n");
  printf(" 1 - Listar uma disciplina com alunos matrículados \n");
  printf(" 2 - Listar alunos por sexo \n");
  printf(" 3 - Listar alunos ordenados por nome \n");
  printf(" 4 - Listar alunos por data de nascimento \n");
  printf(" 5 - Listar professores por sexo \n");
  printf(" 6 - Listar professores ordenados por nome \n");
  printf(" 7 - Listar professores por data de nascimento \n");
  printf(" 8 - Aniversariantes do mês \n");
  printf(" 9 - Listar nomes por letra do nome \n");
  printf(" 10 - Alunos matrículados em menos de 3 disciplinas \n");
  printf(" 11- Disciplinas com mais de 40 vagas \n");
  printf("Informe: \n");
  int opcao;
  scanf("%d", &opcao);
  getchar();
  limpar_tela();

  switch (opcao) {
  case 0:
    return;
    break;
  case 1:
    casoUm();
    break;
  case 2:
    casoDois();
    break;
  case 3:
    casoTres();
    break;
  case 5:
    casoCinco();
    break;
  case 6:
    casoSeis();
    break;
  case 9:
    casoNove();
    break;
  case 10:
    casoDez();
    break;
  case 11:
    casoOnze();
    break;
  default:
    printf("Opção Inválida!");
  }
}

void casoUm() {
  int codigo;
  printf("------ Disciplina com os alunos matrículados ------ \n");
  printf("Informe o código da disciplina: \n");
  scanf("%d", &codigo);
  getchar();
  for (int i = 0; i < numDiscCadastradas; i++) {
    if (contDisc[i].codigo == codigo) {
      printf("Nome: %s \n", contDisc[i].nome);
      printf("Código: %d \n", contDisc[i].codigo);
      printf("Semestre: %d \n", contDisc[i].semestre);
      printf("------ Alunos ------ \n");
      printf("------------ \n");
      printf("Nome: %s \n", contDisc->aluDisc[i].nome);
      printf("Matrícula: %d \n", contDisc->aluDisc[i].matricula);
      printf("------------ \n");
    }
  }
}

void casoDois() {
  int opcao;
  printf("------ Listar alunos por sexo ------ \n");
  printf(" 0 - Voltar \n");
  printf(" 1 - Alunos do sexo feminino \n");
  printf(" 2 - Alunos do sexo masculino \n");
  printf("Informe: \n");
  scanf("%d", &opcao);
  getchar();
  limpar_tela();

  switch (opcao) {
  case 0:
    return;
    break;
  case 1:
    for (int i = 0; i < numAlunosCadastrados; i++) {
      if (contAluno[i].sexo == 'f' || contAluno[i].sexo == 'F') {
        printf("------------ \n");
        printf("Nome: %s \n", contAluno[i].nome);
        printf("Matrícula: %d \n", contAluno[i].matricula);
        printf("Sexo: %c \n", contAluno[i].sexo);
        printf("Data de nascimento: %d/%d/%d \n", contAluno[i].dataNas.dia,
               contAluno[i].dataNas.mes, contAluno[i].dataNas.ano);
        printf("CPF: %s \n", contAluno[i].cpf);
        printf("------------ \n");
      }
    }
    break;
  case 2:
    for (int i = 0; i < numAlunosCadastrados; i++) {
      if (contAluno[i].sexo == 'm' || contAluno[i].sexo == 'M') {
        printf("------------ \n");
        printf("Nome: %s \n", contAluno[i].nome);
        printf("Matrícula: %d \n", contAluno[i].matricula);
        printf("Sexo: %c \n", contAluno[i].sexo);
        printf("Data de nascimento: %d/%d/%d \n", contAluno[i].dataNas.dia,
               contAluno[i].dataNas.mes, contAluno[i].dataNas.ano);
        printf("CPF: %s \n", contAluno[i].cpf);
        printf("------------ \n");
      }
    }
    break;
  default:
    printf("Opção inválida!");
    break;
  }
}

void casoTres() {
  for (int i = 0; i < numAlunosCadastrados - 1; i++) {
    for (int j = i + 1; j < numAlunosCadastrados; j++) {
      if (strcmp(contAluno[i].nome, contAluno[j].nome) > 0) {
        Pessoa temp = contAluno[i];
        contAluno[i] = contAluno[j];
        contAluno[j] = temp;
      }
    }
  }

  printf("------ Lista de Alunos por Nome ------\n");
  for (int i = 0; i < numAlunosCadastrados; i++) {
    if (contAluno[i].alunoAtivo == 1) {
      printf("Matrícula: %d\n", contAluno[i].matricula);
      printf("Nome: %s", contAluno[i].nome);
      printf("Sexo: %c\n", contAluno[i].sexo);
      printf("Data de Nascimento: %d/%d/%d\n", contAluno[i].dataNas.dia,
             contAluno[i].dataNas.mes, contAluno[i].dataNas.ano);
      printf("CPF: %s\n", contAluno[i].cpf);
      printf("------------------------\n");
    }
  }
}

void casoCinco() {
  int opcao;
  printf("------ Listar professores por sexo ------ \n");
  printf(" 0 - Voltar \n");
  printf(" 1 - Professores do sexo feminino \n");
  printf(" 2 - Professores do sexo masculino \n");
  printf("Informe: \n");
  scanf("%d", &opcao);
  getchar();
  limpar_tela();

  switch (opcao) {
  case 0:
    return;
    break;
  case 1:
    for (int i = 0; i < numProfCadastrados; i++) {
      if (contProf[i].sexo == 'f' || contProf[i].sexo == 'F') {
        printf("------------ \n");
        printf("Nome: %s \n", contProf[i].nome);
        printf("Matrícula: %d \n", contProf[i].matricula);
        printf("Sexo: %c \n", contProf[i].sexo);
        printf("Data de nascimento: %d/%d/%d \n", contProf[i].dataNas.dia,
               contProf[i].dataNas.mes, contProf[i].dataNas.ano);
        printf("CPF: %s \n", contProf[i].cpf);
        printf("------------ \n");
      }
    }
    break;
  case 2:
    for (int i = 0; i < numProfCadastrados; i++) {
      if (contProf[i].sexo == 'm' || contProf[i].sexo == 'M') {
        printf("------------ \n");
        printf("Nome: %s \n", contProf[i].nome);
        printf("Matrícula: %d \n", contProf[i].matricula);
        printf("Sexo: %c \n", contProf[i].sexo);
        printf("Data de nascimento: %d/%d/%d \n", contProf[i].dataNas.dia,
               contProf[i].dataNas.mes, contProf[i].dataNas.ano);
        printf("CPF: %s \n", contProf[i].cpf);
        printf("------------ \n");
      }
    }
    break;
  default:
    printf("Opção inválida!");
    break;
  }
}

#include "pessoa.h"
#include <stdio.h>
#include <string.h>

void casoSeis() {
  for (int i = 0; i < numProfCadastrados - 1; i++) {
    for (int j = i + 1; j < numProfCadastrados; j++) {
      if (strcmp(contProf[i].nome, contProf[j].nome) > 0) {
        Pessoa temp = contProf[i];
        contProf[i] = contProf[j];
        contProf[j] = temp;
      }
    }
  }

  printf("------ Lista de Professores por Nome ------\n");
  for (int i = 0; i < numProfCadastrados; i++) {
    if (contProf[i].profAtivo == 1) {
      printf("Matrícula: %d\n", contProf[i].matricula);
      printf("Nome: %s", contProf[i].nome);
      printf("Sexo: %c\n", contProf[i].sexo);
      printf("Data de Nascimento: %d/%d/%d\n", contProf[i].dataNas.dia,
             contProf[i].dataNas.mes, contProf[i].dataNas.ano);
      printf("CPF: %s\n", contProf[i].cpf);
      printf("------------------------\n");
    }
  }
}

void casoNove() {
  char letra1, letra2, letra3;
  printf("------ Alunos e Professores com as letras no nome ------\n");
  printf("Informe as três letras: \n");
  scanf("%c %c %c", &letra1, &letra2, &letra3);

  printf("------ Alunos ------\n");
  int alunosEncontrados = 0;
  for (int i = 0; i < numAlunosCadastrados; i++) {
    if (strstr(contAluno[i].nome, (char[]){letra1, letra2, letra3, '\0'}) !=
        NULL) {
      printf("Nome: %s\n", contAluno[i].nome);
      printf("Matrícula: %d\n", contAluno[i].matricula);
      printf("--------------------\n");
      alunosEncontrados++;
    }
  }

  if (alunosEncontrados == 0) {
    printf("Nenhum aluno encontrado com as letras no nome.\n");
  }

  printf("------ Professores ------\n");
  int professoresEncontrados = 0;
  for (int i = 0; i < numProfCadastrados; i++) {
    if (strstr(contProf[i].nome, (char[]){letra1, letra2, letra3, '\0'}) !=
        NULL) {
      printf("Nome: %s\n", contProf[i].nome);
      printf("Matrícula: %d\n", matriculasProfessores[i]);
      printf("--------------------\n");
      professoresEncontrados++;
    }
  }

  if (professoresEncontrados == 0) {
    printf("Nenhum professor encontrado com as letras no nome.\n");
  }
}

void casoDez() {
  printf("------ Alunos matriculados em menos de 3 disciplinas ------\n");
  int totalDisciplinas;
  for (int i = 0; i < numAlunosCadastrados; i++) {
    totalDisciplinas = 0;
    for (int j = 0; j < numDiscCadastradas; j++) {
      for (int k = 0; k < TAM_ALUNO; k++) {
        if (contDisc[j].aluDisc[k].matricula == contAluno[i].matricula) {
          totalDisciplinas++;
          break;
        }
      }
    }
    if (totalDisciplinas < 3) {
      printf("Nome: %s", contAluno[i].nome);
      printf("Matrícula: %d\n", contAluno[i].matricula);
      printf("------------------------\n");
    }
  }
}

void casoOnze() {
  printf("------ Lista de disciplinas com mais de 40 vagas ------ \n");
  for (int i = 0; i < numDiscCadastradas; i++) {
    if (contDisc[i].vagas > 40) {
      printf("Nome: %s \n", contDisc[i].nome);
      printf("Código: %d \n", contDisc[i].codigo);
      printf("Professor: %s \n", contProf[i].nome);
    }
  }
}
