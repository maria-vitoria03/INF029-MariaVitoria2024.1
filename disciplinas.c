#include "disciplinas.h"
#include "pessoa.h"
#include <stdio.h>
#include <string.h>

int sairDisc = 0;
Disc disc;

Disc contDisc[MAX_DISC];
int numDiscCadastradas = 0;

// Sub menu para disciplinas.
void menuDisc() {
  while (!sairDisc) {
    printf("----------------------------\n");
    printf(" ***** Módulo de disciplinas ***** \n");
    int opcaoDisc;
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplinas\n");
    printf("3 - Atualizar Disciplina\n");
    printf("4 - Excluir Disciplina\n");
    printf("5 - Inserir ou Excluir aluno\n");
    printf("Informe:");

    scanf("%d", &opcaoDisc);
    limpar_tela();
    getchar(); // Limpar o buffer de entrada.

    switch (opcaoDisc) {
    case 0:
      sairDisc = 1;
      break;
    case 1:
      if (numDiscCadastradas == MAX_DISC) {
        printf("A lista de disciplinas está cheia!\n ");
      } else {
        cadastroDisc();
      }
      break;
    case 2:
      listarDisc();
      break;
    case 3:
      atualizarDisc();
      break;
    case 4:
      excluirDisc();
      break;
    case 5:
      incluirRemoverAlun();
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
    }
  }
}

void cadastroDisc() {
  printf(" ***** Cadastro de disciplinas! ***** \n");
  printf("Digite o nome:\n ");
  fgets(disc.nome, sizeof(disc.nome), stdin);
  printf("Digite o código:\n ");
  scanf("%d", &disc.codigo);
  getchar();
  printf("Informe quantas vagas estão disponíveis: \n");
  scanf("%d", &disc.vagas);
  getchar();
  printf("Digite o semestre que ela está vínculada:\n ");
  scanf("%d", &disc.semestre);
  getchar();
  printf(
      "Informe a matrícula do professor que irá lencionar essa disciplina:\n ");
  scanf("%d", &disc.matriculaProf);

  int professorEncontrado = 0;

  for (int i = 0; i < numProfCadastrados; i++) {
    if (disc.matriculaProf == matriculasProfessores[i]) {
      contDisc[numDiscCadastradas] = disc;
      contDisc[numDiscCadastradas].discAtiva = 1;
      strcpy(contProf[numDiscCadastradas].nome, contProf[i].nome);
      numDiscCadastradas++;
      printf("Disciplina cadastrada com sucesso!\n ");
      professorEncontrado = 1;
      break;
    }
  }

  if (!professorEncontrado) {
    printf("Professor não existe. Tente novamente!!\n ");
  }
}

void listarDisc() {
  if (numDiscCadastradas == 0) {
    printf("Lista de disciplinas vazia!\n ");
  } else {
    printf("------ Lista de Disciplinas ------\n");
    for (int i = 0; i < numDiscCadastradas; i++) {
      printf("Nome: %s", contDisc[i].nome);
      printf("Código: %d\n", contDisc[i].codigo);
      printf("Semestre: %d\n", contDisc[i].semestre);
      printf("Professor: %s\n", contProf[i].nome);
      printf("------------------------\n");
    }
  }
}

void atualizarDisc() {
  printf("Informe o código da disciplina para ser atualizada:\n ");
  int codigoDisc;
  scanf("%d", &codigoDisc);
  getchar();
  int achouDisc = 0;
  for (int i = 0; i < numDiscCadastradas; i++) {
    if (codigoDisc == contDisc[i].codigo && contDisc[i].discAtiva) {
      printf("Digite o nome atual:\n ");
      fgets(contDisc[i].nome, sizeof(contDisc[i].nome), stdin);
      printf("Digite o semestre autual:\n ");
      scanf("%d", &contDisc[i].semestre);
      getchar();
      printf("Digite a matrícula do novo professor:\n");
      scanf("%d", &contDisc[i].matriculaProf);
      achouDisc = 1;
      break;
    }
  }
  if (achouDisc)
    printf("Disciplina atualizada com sucesso!\n");
  else
    printf("Código de disciplina inexistente!\n");
}

void excluirDisc() {
  printf("Informe o código da disciplina a ser excluída:\n ");
  int codigoDisc;
  scanf("%d", &codigoDisc);
  getchar();
  int achouDisc = 0;

  for (int i = 0; i < numDiscCadastradas; i++) {
    if (codigoDisc == contDisc[i].codigo) {
      contDisc[i].discAtiva = -1;
      for (int j = i; j < numDiscCadastradas - 1; j++) {
        strcpy(contDisc[j].nome, contDisc[j + 1].nome);
        contDisc[j].codigo = contDisc[j + 1].codigo;
        contDisc[j].semestre = contDisc[j + 1].semestre;
        contDisc[j].matriculaProf = contDisc[j + 1].matriculaProf;
        contDisc[j].discAtiva = contDisc[j + 1].discAtiva;
      }
      numDiscCadastradas--;
      achouDisc = 1;
      break;
    }
  }
  if (achouDisc)
    printf("Disciplina excluída com sucesso!\n");
  else
    printf("Código inexistente!\n");
}

void incluirRemoverAlun() {
  int opcao, matAluno, codigoDisc, cont = 0;
  printf("------ Adicionar ou Remover Aluno(a) de uma Disciplina ------ \n");
  printf("0 - Voltar \n");
  printf("1 - Adicionar \n");
  printf("2 - Remover \n");
  printf("Informe: \n");
  scanf("%d", &opcao);
  limpar_tela();
  getchar();

  switch (opcao) {

  case 0:
    return;
    break;
  case 1:
    printf("Informe a matrícula do estudante: \n");
    scanf("%d", &matAluno);
    getchar();
    for (int i = 0; i < numAlunosCadastrados; i++) {
      if (matAluno == contAluno[i].matricula && contAluno[i].alunoAtivo) {
        printf("Informe o código da disciplina para inserir o aluno: \n");
        scanf("%d", &codigoDisc);
        for (int j = 0; j < numDiscCadastradas; j++) {
          if (codigoDisc == contDisc[j].codigo) {
            strcpy(contDisc[j].aluDisc[i].nome, contAluno[i].nome);
            contDisc[j].aluDisc[i].matricula = contAluno[i].matricula;
            cont++;
            printf("Aluno inserido com sucesso! \n");
          } else {
            printf("Disciplina não encontrada! \n");
          }
        }
      } else {
        printf("Aluno não encontrado! \n");
      }
    }
    break;
  case 2:
    printf("Informe o código da disciplina: \n");
    scanf("%d", &codigoDisc);
    getchar();
    int disciplinaEncontrada = 0;
    for (int i = 0; i < numDiscCadastradas; i++) {
        if (codigoDisc == contDisc[i].codigo) {
            disciplinaEncontrada = 1; 
            int alunoEncontrado = 0; 
            for (int j = 0; j < numAlunosCadastrados; j++) {
                if (matAluno == contDisc[i].aluDisc[j].matricula) {
                    alunoEncontrado = 1;
                    contDisc[i].aluDisc[j].matricula = 0;
                    strcpy(contDisc[i].aluDisc[j].nome, "");
                    cont--;
                    printf("Aluno removido com sucesso! \n");
                    break;
                }
            }
            if (!alunoEncontrado) {
                printf("Aluno não encontrado nessa disciplina! \n");
            }
            break;
        }
    }
    if (!disciplinaEncontrada) {
        printf("Disciplina não encontrada! \n");
    }
    break;
  }
}
