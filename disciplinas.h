#ifndef DISC_H
#define DISC_H
#include "pessoa.h"

#define MAX_DISC 2

extern int sairDisc; // Declaração da variável global sairAluno

typedef struct {
  char nome[MAX_LETRAS];
  int codigo, semestre, matriculaProf;
  int discAtiva;
  Pessoa aluDisc[TAM_ALUNO];
  int vagas;
} Disc;

extern Disc disc;
extern Pessoa aluDisc;
extern int numDiscCadastradas;
extern Disc contDisc[MAX_DISC];

void menuDisc(); // Protótipo da função menuDisc
void cadastroDisc();
void listarDisc();
void atualizarDisc();
void excluirDisc();
void incluirRemoverAlun();

#endif