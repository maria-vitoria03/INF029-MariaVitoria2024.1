#ifndef PESSOA_H
#define PESSOA_H

#define MAX_LETRAS 50
#define TAM_ALUNO 2
#define TAM_PROF 2

extern int sairAluno; // Declaração da variável global sairAluno
extern int sairProf;

typedef struct {
  int dia, mes, ano;
} DataNas;

typedef struct {
  DataNas dataNas;
  int matricula;
  char nome[MAX_LETRAS], sexo, cpf[15];
  int alunoAtivo;
  int profAtivo;
} Pessoa;

extern Pessoa discen;
extern Pessoa docen;
extern int matriculasProfessores[TAM_PROF];
extern int numProfCadastrados;

extern Pessoa contAluno[TAM_ALUNO];
extern Pessoa contProf[TAM_PROF];
extern int numAlunosCadastrados;
extern int numProfCadastrados;

void limpar_tela();
void menuAluno(); // Protótipo da função menuAluno
void cadastroAluno();
void listarAluno();
void atualizarAluno();
void excluirAluno();
void menuProf();
void cadastroProf();
void listarProf();
void atualizarProf();
void excluirProf();

#endif
