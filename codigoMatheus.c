#include <stdio.h>
#include <stdlib.h>

//Criando a struct
typedef struct{
	char nome[50];
	int codigo;
	int codigoDisciplina;
}Aluno;

typedef struct{
	char nome[50];
	int codigo;
}Disciplina;

Disciplina novaDisciplina(){
	Disciplina disciplinaNova;
	printf("Digite o nome da nova Disciplina: ");
	scanf("%s",disciplinaNova.nome);
	printf("Digite o código da Disciplina: ");
	scanf("%d",disciplinaNova.codigo);
	return disciplinaNova;
}

Aluno novoAluno(){
	Aluno aluno;
	printf("Digite o nome do aluno: ");
	scanf("%s",aluno.nome);
	system("cls || clear");
	printf("\n===DISCIPLINAS E CODIGOS===\nPORTUGUES = 1\nMATEMATICA = 2\nCIENCIAS = 3\nHISTORIA = 4\n");
	printf("Digite o codigo da disciplina: ");
	scanf("%d",&aluno.codigo);
	return aluno;
}

void gravaDisc(Disciplina disciplinaNova){
	FILE *pont_arq;
	int i;
	
	pont_arq = fopen("teste.txt", "a");
	
	//testando se o arquivo foi realmente criado
	if(pont_arq == NULL){
		printf("Erro na abertura do arquivo!");
		return 1;
	}
	
	fprintf(pont_arq, "Nome da Disciplina: %s \nCódigo da Disciplina: %d \n\n", disciplinaNova.nome,disciplinaNova.codigo);
	
	fclose(pont_arq);
		
	
	printf("Dados gravados com sucesso!");
}


void gravaAluno(Aluno aluno){
	FILE *pont_arq;
	int i;
	
	pont_arq = fopen("teste.txt", "a");
	
	//testando se o arquivo foi realmente criado
	if(pont_arq == NULL){
		printf("Erro na abertura do arquivo!");
		return 1;
	}
	
	fprintf(pont_arq, "Nome do Aluno: %s \nCódigo do Aluno: %d \n\n", aluno.nome,aluno.codigo);
	
	fclose(pont_arq);
		
	
	printf("Dados gravados com sucesso!");
}


int main(void){
	Aluno aluno;
	
	aluno= novoAluno();
	
	gravaAluno(aluno);
	
	return(0);
}
