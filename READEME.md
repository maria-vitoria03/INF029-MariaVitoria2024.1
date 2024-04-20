O que é avaliado: 
• Corretude: se ele faz o que se espera que ele faça 
• Modularidade: se ele utiliza boas técnicas de modularização, com a criação de módulos os mais reutilizáveis possíveis 
• Número de bugs: bugs são contados negativamente

Desenvolver um programa em C que controle o funcionamento de uma Escola. Existem diversas funcionalidades em uma Escola, mas você deve focar no que é pedido. Caso tenha interesse você pode evoluir sua solução para adicionar mais funcionalidades. 
Funcionalidades solicitadas: 
• Cadastro de Alunos (Matrícula, Nome, Sexo, Data Nascimento, CPF) . (FEITO!);
• Cadastro de Professores (Matrícula, Nome, Sexo, Data Nascimento, CPF). (FEITO!);
• Cadastro de Disciplinas (Nome, Código, Semestre, Professor). (FEITO!); 
◦ Inserir/Excluir aluno de uma disciplina. (FEITO!)
• Relatórios. 
◦ Listar Alunos. (FEITO!);
◦ Listar Professores. (FEITO!); 
◦ Listar Disciplinas (dados da disciplina sem os alunos). (FEITO!);
◦ Listar uma disciplina (dados da disciplina e os alunos matriculados). (FEITO!);
◦ Listar Alunos por sexo (Masculino/Feminino). (FEITO!);
◦ Listar Alunos ordenados por Nome. (FEITO!);
◦ Listar Alunos ordenados por data de nascimento. 
◦ Listar Professores por sexo (Masculino/Feminino). (FEITO!); 
◦ Listar Professores ordenados por Nome. (FEITO!); 
◦ Listar Professores ordenados por data de nascimento 
◦ Aniversariantes do mês. 
◦ Lista de pessoas (professor/aluno) a partir de uma string de busca. O usuário informa no mínimo três letras e deve ser listado todas as pessoas que contem essas três letras no nome. (FEITO!); 
◦ Lista de alunos matriculados em menos de 3 disciplinas. (FEITO!);
◦ Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas. (FEITO!); 
Observação: 
• Por Cadastro entenda Incluir, excluir, atualizar 
• Valide todos os campos necessários (ex. Data nascimento, CPF)

Comandos: cd projetoEscola -- Entra na pasta
gcc main.c pessoa.c disciplinas.c geral.c -o projetoescola -- Compila
./projetoEscola -- Executa a aplicação