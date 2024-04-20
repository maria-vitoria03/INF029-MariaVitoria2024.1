#include "pessoa.h"
#include "arquivo.h"
#include <stdio.h>
#include <string.h>

int sairAluno = 0;
int sairProf = 0;
Pessoa discen;
Pessoa docen;
int matriculasProfessores[TAM_PROF];

Pessoa contAluno[TAM_ALUNO];
int numAlunosCadastrados = 0;
Pessoa contProf[TAM_PROF];
int numProfCadastrados = 0;

void limpar_tela() { printf("\033[2J\033[H"); }

// Sub menu para alunos.
void menuAluno() {
  printf("----------------------------\n");
  printf(" ***** Módulo de alunos ***** \n");
  int opcaoAluno;

  while (!sairAluno) {
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Alunos\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir Aluno\n");
    printf("Informe:");

    scanf("%d", &opcaoAluno);
    limpar_tela();
    getchar(); // Limpar o buffer de entrada.

    switch (opcaoAluno) {
    case 0:
      sairAluno = 1;
      break;
    case 1:
      if (numAlunosCadastrados == TAM_ALUNO) {
        printf("A lista de alunos está cheia!\n ");
      } else {
        cadastroAluno();
      }
      break;
    case 2:
      listarAluno();
      break;
    case 3:
      atualizarAluno();
      break;
    case 4:
      excluirAluno();
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
    }
  }
}

void cadastroAluno() {
  printf(" ***** Cadastro de Aluno! ***** \n");
  printf("Digite o nome:\n ");
  fgets(discen.nome, sizeof(discen.nome), stdin);
  printf("Digite a matrícula (deve ser maior que 0):\n");
  scanf("%d", &discen.matricula);
  getchar(); // Limpar o buffer de entrada
  if (discen.matricula <= 0) {
    printf("Matrícula inválida, tente novamente! \n");
    return;
  }
  printf("Digite sexo (F/M):\n ");
  scanf("%c", &discen.sexo);
  getchar();
  if (discen.sexo != 'f' && discen.sexo != 'F' && discen.sexo != 'm' &&
      discen.sexo != 'M') {
    printf("Sexo Inválido!");
    return;
  }
  printf("Digite a data de nascimento no formato (dd mm aaaa):\n ");
  scanf("%d%d%d", &discen.dataNas.dia, &discen.dataNas.mes,
        &discen.dataNas.ano);
  getchar();
  printf("Digite o CPF no formato (000.000.000-00)\n ");
  fgets(discen.cpf, sizeof(discen.cpf), stdin);
  contAluno[numAlunosCadastrados] = discen;
  contAluno[numAlunosCadastrados].alunoAtivo = 1;
  numAlunosCadastrados++;

  salvarAlunos("alunos.txt");

  printf("Aluno cadastrado com sucesso!\n");
}

void listarAluno() {
  if (numAlunosCadastrados == 0) {
    printf("Lista de alunos vazia!\n ");
  } else {
    printf("------ Lista de Alunos ------\n");
    for (int i = 0; i < numAlunosCadastrados; i++) {
      if (contAluno[i].alunoAtivo == 1)
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

void atualizarAluno() {
  printf("Informe a matrícula do aluno para ser atualizado:\n ");
  int matriculaAluno;
  scanf("%d", &matriculaAluno);
  getchar();
  int achouAluno = 0;

  for (int i = 0; i < numAlunosCadastrados; i++) {
    if (matriculaAluno == contAluno[i].matricula && contAluno[i].alunoAtivo) {
      printf("Digite o nome atual:\n ");
      fgets(contAluno[i].nome, sizeof(contAluno[i].nome), stdin);
      printf("Digite sexo atual (F/M):\n ");
      scanf("%c", &contAluno[i].sexo);
      getchar();
      printf("Digite a data de nascimento atual no formato (dd mm aaaa):\n ");
      scanf("%d%d%d", &contAluno[i].dataNas.dia, &contAluno[i].dataNas.mes,
            &contAluno[i].dataNas.ano);
      achouAluno = 1;
      break;
    }
  }
  if (achouAluno)
    printf("Aluno atualizado com sucesso!\n");
  else
    printf("Matrícula inexistente!\n");
}

void excluirAluno() {
  printf("Informe a matrícula do aluno a ser excluído:\n ");
  int matriculaAluno;
  scanf("%d", &matriculaAluno);
  getchar();
  int achouAluno = 0;

  for (int i = 0; i < numAlunosCadastrados; i++) {
    if (matriculaAluno == contAluno[i].matricula) {
      contAluno[i].alunoAtivo = -1;
      for (int j = i; j < numAlunosCadastrados - 1; j++) {
        contAluno[j].matricula = contAluno[j + 1].matricula;
        strcpy(contAluno[j].nome, contAluno[j + 1].nome);
        contAluno[j].sexo = contAluno[j + 1].sexo;
        contAluno[j].dataNas.dia = contAluno[j + 1].dataNas.dia;
        contAluno[j].dataNas.mes = contAluno[j + 1].dataNas.mes;
        contAluno[j].dataNas.ano = contAluno[j + 1].dataNas.ano;
        strcpy(contAluno[j].cpf, contAluno[j + 1].cpf);
        contAluno[j].alunoAtivo = contAluno[j + 1].alunoAtivo;
      }
      numAlunosCadastrados--;
      achouAluno = 1;
      break;
    }
  }
  if (achouAluno)
    printf("Aluno excluído com sucesso!\n");
  else
    printf("Matrícula inexistente!\n");
}

// Sub menu para professores.
void menuProf() {
  printf("----------------------------\n");
  printf(" ***** Módulo de professores ***** \n");
  int opcaoProf;

  while (!sairProf) {
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professores\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");
    printf("Informe:");

    scanf("%d", &opcaoProf);
    limpar_tela();
    getchar(); // Limpar o buffer de entrada.

    switch (opcaoProf) {
    case 0:
      sairProf = 1;
      break;
    case 1:
      if (numProfCadastrados == TAM_PROF) {
        printf("A lista de professores está cheia!\n ");
      } else {
        cadastroProf();
      }
      break;
    case 2:
      listarProf();
      break;
    case 3:
      atualizarProf();
      break;
    case 4:
      excluirProf();
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
    }
  }
}

void cadastroProf() {
  printf("Digite o nome:\n ");
  fgets(docen.nome, sizeof(docen.nome), stdin);
  printf("Digite a matrícula (deve ser maior que 0):\n");
  scanf("%d", &docen.matricula);
  getchar(); // Limpar o buffer de entrada
  if (docen.matricula <= 0) {
    printf("Matrícula inválida, tente novamente! \n");
    return;
  } else {
    matriculasProfessores[numProfCadastrados] = docen.matricula;
  }
  printf("Digite sexo (F/M):\n ");
  scanf("%c", &docen.sexo);
  getchar();
  if (docen.sexo != 'f' && docen.sexo != 'F' && docen.sexo != 'm' &&
      docen.sexo != 'M') {
    printf("Sexo Inválido! \n");
    return;
  }
  printf("Digite a data de nascimento no formato(dd mm aaaa):\n ");
  scanf("%d%d%d", &docen.dataNas.dia, &docen.dataNas.mes, &docen.dataNas.ano);
  getchar();
  printf("Digite o CPF no formato(000.000.000-00)\n ");
  fgets(docen.cpf, sizeof(docen.cpf), stdin);
  contProf[numProfCadastrados] = docen;
  contProf[numProfCadastrados].profAtivo = 1;
  numProfCadastrados++;

  salvarProfessores("professores.txt");

  printf("Professor cadastrado com sucesso!\n");
}

void listarProf() {
  if (numProfCadastrados == 0) {
    printf("Lista de professores vazia!\n ");
  } else {
    printf("------ Lista de Professores ------\n");
    for (int i = 0; i < numProfCadastrados; i++) {
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

void atualizarProf() {
  printf("Informe a matrícula do professor para ser atualizado:\n ");
  int matriculaProf;
  scanf("%d", &matriculaProf);
  getchar();
  int achouProf = 0;

  for (int i = 0; i < numProfCadastrados; i++) {
    if (matriculaProf == contProf[i].matricula && contProf[i].profAtivo) {
      printf("Digite o nome atual:\n ");
      fgets(contProf[i].nome, sizeof(contProf[i].nome), stdin);
      printf("Digite sexo atual (F/M):\n ");
      scanf("%c", &contProf[i].sexo);
      getchar();
      printf("Digite a data de nascimento atual no formato (dd mm aaaa):\n");
      scanf("%d/%d/%d", &contProf[i].dataNas.dia, &contProf[i].dataNas.mes,
            &contProf[i].dataNas.mes);
      achouProf = 1;
      break;
    }
  }
  if (achouProf)
    printf("Professor atualizado com sucesso!\n");
  else
    printf("Matrícula inexistente!\n");
}

void excluirProf() {
  printf("Informe a matrícula do professor a ser excluído:\n ");
  int matriculaProf;
  scanf("%d", &matriculaProf);
  getchar();
  int achouProf = 0;

  for (int i = 0; i < numProfCadastrados; i++) {
    if (matriculaProf == contProf[i].matricula) {
      contProf[i].profAtivo = -1;
      for (int j = i; j < numProfCadastrados - 1; j++) {
        contProf[j].matricula = contProf[j + 1].matricula;
        strcpy(contProf[j].nome, contProf[j + 1].nome);
        contProf[j].sexo = contProf[j + 1].sexo;
        contProf[j].dataNas.dia = contProf[j + 1].dataNas.dia;
        contProf[j].dataNas.mes = contProf[j + 1].dataNas.mes;
        contProf[j].dataNas.ano = contProf[j + 1].dataNas.ano;
        strcpy(contProf[j].cpf, contProf[j + 1].cpf);
        contProf[j].alunoAtivo = contProf[j + 1].profAtivo;
      }
      numProfCadastrados--;
      achouProf = 1;
      break;
    }
  }
  if (achouProf)
    printf("Professor excluído com sucesso!\n");
  else
    printf("Matrícula inexistente!\n");
}