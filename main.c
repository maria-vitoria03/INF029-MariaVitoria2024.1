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
    if (menu < 0 || menu > 4) { // Condição caso o usuário informe um valor
                                // diferente dos fornecidos no menu
      printf("Condição Inválida! Tente novamente.\n");
    } else {
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

          if (opcaoAluno < 0 ||
              opcaoAluno > 4) { // Condição caso o usuário informe um valor
                                // diferente dos fornecidos no menu.
            printf("Condição Inválida! Tente novamente.\n");
          } else {
            // subMenu
            switch (opcaoAluno) {
            case 0: {
              sairAluno = 1;
              break;
            }
            case 1: {
              printf("---------------\n");
              printf("Cadastrar Aluno\n");
              int matricula;
              if (qtdAluno == TAM_ALUNO) {
                printf("Lista de alunos cheia!!\n");
              } else {
                printf("Digite a matrícula:\n");
                scanf("%d", &matricula);
                if (matricula < 0) {
                  printf("Matrícula Inválida!\n");
                } else {
                  listaAluno[qtdAluno] = matricula;
                  qtdAluno++;
                  printf("Aluno cadastrado com sucesso!!\n");
                }
              }
              break;
            }
            }
          }
        }
        sairAluno = 0;
        break;
      }
      }
    }
  }
  return 0;
}