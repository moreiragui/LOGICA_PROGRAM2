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


Aluno novoAluno(){
	Aluno aluno;
	printf("\nDigite o nome do aluno: ");
	scanf("%s",&aluno.nome);
	printf("\n===DISCIPLINAS E CODIGOS===\nPORTUGUES = 1\nMATEMATICA = 2\nCIENCIAS = 3\nHISTORIA = 4\n");
	printf("Digite o codigo da disciplina: ");
	scanf("%d",&aluno.codigo);
	return aluno;
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
	
	fprintf(pont_arq, "Nome do Aluno Cadastrado: %s \nCódigo da Disciplina Cadastrado: %d \n\n", aluno.nome,aluno.codigo);
	
	fclose(pont_arq);
	
	printf("\nDados gravados com sucesso!");
}

void function1(){
	Aluno aluno;
	gravaAluno(aluno);
	aluno= novoAluno();
}

void menuInicio(void){
	int a;
	
	do{
		printf("====MENU INICIAL TOP====");
		printf("\nESCOLHA A OPÇÃO DESEJADA:\n1 - CADASTRAR NOVO ALUNO\n2 - CADASTRAR NOVA DISCIPLINA\n");
		scanf("%d",&a);
		system("cls || clear");
		switch(a){
			case 1:
				function1();
				return 0;
			break;
				
			case 2:
				printf("top");
			break;
			
			case 3:
				return 0;
			break;
			
			default:
				printf("\nDigite uma opção válida!\n\n");
		}
	}while(a);
	
}

int main(void){
	
	menuInicio();
	
	
	return(0);
}
