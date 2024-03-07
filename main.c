#include <stdio.h>
#include <stdlib.h>
#define TAM_ALUNO 3

int main(void) {

  int sair = 0;
  int menu;
  int qtdAluno = 0;
  int listaAluno[TAM_ALUNO];
  int sairAluno = 0;

  // Menu principal do programa.
  while (!sair) {
    printf("-------------------------------------------------------------------"
           "--\n");
    printf("***** Bem vindo(a) ao Projeto Escola!! O que você deseja fazer? "
           "*****\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar um(a) aluno(a)\n");
    printf("2 - Cadastrar um(a) professor(a)\n");
    printf("3 - Cadastrar uma disciplina\n");
    printf("4 - Emitir relatórios\n");
    printf("Informe:");

    scanf("%d", &menu);
    getchar(); // Limpar o buffer de entrada.

    // Menu do aluno
    switch (menu) {

    case 0: {
      sair = 1;
      break;
    }
    case 1: {
      printf("----------------------------\n");
      printf(" ***** Pasta de alunos ***** \n");
      int opcaoAluno;

      while (!sairAluno) {
        printf("0 - Voltar\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Aluno\n");
        printf("3 - Atualizar Aluno\n");
        printf("4 - Excluir Aluno\n");
        printf("Informe:");

        scanf("%d", &opcaoAluno);
        getchar(); // Limpar o buffer de entrada.

        // subMenu
        switch (opcaoAluno) {
        case 0: {
          sairAluno = 1;
          break;
        }
        case 1: {
          printf("---------------\n");
          printf("Cadastrar Aluno\n");
          printf("Digite a matrícula:");
          int matricula;
          scanf("%d", &matricula);
          if (matricula < 0) {
            printf("Matrícula Inválida!\n");
          } else {
            if (qtdAluno == TAM_ALUNO) {
              printf("Lista de alunos cheia!!\n");
            } else {
              listaAluno[qtdAluno] = matricula;
              qtdAluno++;
            }
          }
          break;
        }
        }
      }
      sairAluno = 0;
      break;
    }
    }
  }

  return 0;
}