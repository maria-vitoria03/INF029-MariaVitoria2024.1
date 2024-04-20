#include "geral.h"
#include "arquivo.h"
#include "disciplinas.h"
#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int sair = 0;
  int menu;
  int qtdAluno = 0;

  // Menu principal do programa.
  while (!sair) {
    printf("-------------------------------------------------------------------"
           "--\n");
    printf("***** Bem vindo(a) ao Projeto Escola!! O que você deseja fazer? "
           "*****\n");
    printf("0 - Sair\n");
    printf("1 - Entrar no módulo de alunos\n");
    printf("2 - Entrar no módulo de professores\n");
    printf("3 - Entrar no módulo de disciplinas\n");
    printf("4 - Emitir relatórios\n");
    printf("Informe:");

    scanf("%d", &menu);
    limpar_tela();
    getchar(); // Limpar o buffer de entrada.

    switch (menu) {
    case 0:
      sair = 1;
      break;
    case 1:
      sairAluno = 0;
      menuAluno();
      break;
    case 2:
      sairProf = 0;
      menuProf();
      break;
    case 3:
      sairDisc = 0;
      menuDisc();
      break;
    case 4:
      relatorios();
      break;
    default:
      printf("Opção inválida! Tente novamente.\n"); // Condição caso o usuário
                                                    // informe um valor não
                                                    // fornecido no meu.
    }
  }

  salvarAlunos("alunos.txt");
  salvarProfessores("professores.txt");

  return 0;
}