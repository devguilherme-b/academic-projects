#include <stdio.h>
#include <stdlib.h>

// ENUMS
enum Statuslivro{
	DISPONIVEL, // => 0
	EMPRESTADO // => 1
};
enum StatusEmprestimo{
	ATIVO, // => 0
	DEVOLVIDO // => 1
};

// STRUCTS AUXILIARES
struct Data{
	unsigned short int Dia;
	unsigned short int Mes;
	unsigned short int Ano;
};

// STRUCTS 
struct Livro{
	int codigo_livro;
	char titulo[100];
	char autor[80];
	char editora[60];
	int ano_publicacao;
	unsigned int exemplares_disponiveis;
	enum Statuslivro status;
};
struct Usuario{
	int matricula;
	char nome_completo[100];
	char curso[50];
	char telefone[15];
	struct Data cadastro;
};
struct Emprestimo{
	int codigo_emprestimo;
	int matricula_usuario;
	int codigo_livro;
	struct Data data_emprestimo;
	struct Data previsao_devolucao;
	enum StatusEmprestimo status;
};

// PROTÓTIPO DE FUNÇÕES 
void InstalaDependencias();
void CadastrarLivro();
void CadastrarUsuario();
void RealizarEmprestimo();

// Função para realizar empréstimo
// Função para realizar devolução
// Função para pesquisar livros (por código, título ou autor)
// Função para pesquisar usuários (por matrícula ou nome)
// Função para listar empréstimos ativos
// Todas as funções devem utilizar passagem de parâmetros adequada

// VARIÁVEIS GLOBAIS  
struct Livro livro;
struct Usuario usuario;
struct Emprestimo emprestimo;

// CONSTANTES GLOBAIS
#define LIVROS_DB "livros.txt"
#define USUARIOS_DB "usuarios.txt"
#define EMPRESTIMOS_DB "emprestimos.txt"

// INÍCIO 
int main(int argc, char *argv[]) {
	InstalaDependencias();
	printf("Compilado e executado.");
	// CadastrarLivro(); 
	// CadastrarUsuario(); 
	// RealizarEmprestimo();
	return 0;
}

// FUNÇÕES 
void InstalaDependencias(){
	FILE * arq1 = fopen(LIVROS_DB, "a");
	FILE * arq2 = fopen(USUARIOS_DB, "a");
	FILE * arq3 = fopen(EMPRESTIMOS_DB, "a");
	
	fclose(arq1);
	fclose(arq2);
	fclose(arq3);
}
void CadastrarLivro(){
	FILE * arq = fopen(LIVROS_DB, "a");
	
	printf("\nPreecha as seguintes informacoes para cadastrar um novo Livro.\n\n");
	printf("Codigo do Livro: ");
	scanf("%d", &livro.codigo_livro);
	printf("Titulo do Livro: ");
	getchar(); // descarta o ENTER anterior para ser possível armazenar textos com espaços em branco entre palavras.
	scanf("%100[^\n]", &livro.titulo);;
	printf("Nome do Autor: ");
	scanf(" %80[^\n]", &livro.autor);
	printf("Nome da Editora: ");
	scanf(" %60[^\n]", &livro.editora);
	printf("Ano de publicacao: ");
	scanf("%d", &livro.ano_publicacao);
	printf("Exemplares disponiveis: ");
	scanf("%u", &livro.exemplares_disponiveis);
	livro.status = DISPONIVEL;
	
	fprintf(arq, "\n%d|%s|%s|%s|%d|%u|%d|\n",
            livro.codigo_livro,
            livro.titulo,
            livro.autor,
            livro.editora,
            livro.ano_publicacao,
            livro.exemplares_disponiveis,
            livro.status);
            
    fclose(arq);
    
    printf("\nLivro cadastrado com sucesso!\n");
}
void CadastrarUsuario(){
	FILE * arq = fopen(USUARIOS_DB, "a");
	
	printf("\nPreecha as seguintes informacoes para cadastrar um novo Usuario.\n\n");
	printf("Numero matricula: ");
	scanf("%d", &usuario.matricula);
	printf("Nome completo: ");
	getchar();
	scanf("%100[^\n]", &usuario.nome_completo);
	printf("Curso: ");
	scanf(" %50[^\n]", &usuario.curso);
	printf("Telefone: ");
	scanf(" %15[^\n]", &usuario.telefone);
	printf("Informe a data de cadadastro logo abaixo.\n");
	printf("Dia: ");
	scanf("%u", &usuario.cadastro.Dia);
	printf("Mes: ");
	scanf("%u", &usuario.cadastro.Mes);
	printf("Ano: ");
	scanf("%u", &usuario.cadastro.Ano);	
	
	fprintf(arq, "%d|%s|%s|%s|%u|%u|%u\n",
            usuario.matricula,
            usuario.nome_completo,
            usuario.curso,
            usuario.telefone,
            usuario.cadastro.Dia,
            usuario.cadastro.Mes,
            usuario.cadastro.Ano
			);
			
    fclose(arq);
    
    printf("\nUsuario cadastrado com sucesso!\n");
}
void RealizarEmprestimo(){
	FILE * arq = fopen(EMPRESTIMOS_DB, "a");
	
	printf("\nPreecha as seguintes informacoes para cadastrar um novo Emprestimo.\n\n");
	printf("Codigo do emprestimo: ");
	scanf("%d", &emprestimo.codigo_emprestimo);
	printf("Matricula do Usuario: ");
	scanf("%d", &emprestimo.matricula_usuario);	
	printf("Codigo do Livro: ");
	scanf("%d", &emprestimo.codigo_livro);	
	printf("Informe a data do emprestimo logo abaixo.\n");
	printf("Dia: ");
	scanf("%u", &emprestimo.data_emprestimo.Dia);
	printf("Mes: ");
	scanf("%u", &emprestimo.data_emprestimo.Mes);
	printf("Ano: ");
	scanf("%u", &emprestimo.data_emprestimo.Ano);
	
	emprestimo.previsao_devolucao.Dia = emprestimo.data_emprestimo.Dia + 7;
	emprestimo.previsao_devolucao.Mes = emprestimo.data_emprestimo.Mes;
	emprestimo.previsao_devolucao.Ano = emprestimo.data_emprestimo.Ano;
	
	emprestimo.status = ATIVO;
	
	fprintf(arq, "%u|%u|%u|%u|%u|%u|%u|%u|%u|%u\n",
            emprestimo.codigo_emprestimo,
            emprestimo.matricula_usuario,
            emprestimo.codigo_livro,
            emprestimo.data_emprestimo.Dia,
            emprestimo.data_emprestimo.Mes,
            emprestimo.data_emprestimo.Ano,
            emprestimo.previsao_devolucao.Dia,
            emprestimo.previsao_devolucao.Mes,
            emprestimo.previsao_devolucao.Ano,
            emprestimo.status
			);
	
	printf("Emprestimo cadastrado com sucesso!")
	
	fclose(arq);
}