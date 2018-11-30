#include<stdio.h>
#include<stdlib.h>

int main(void){
	FILE*pont_arq; //Cria variável ponteiro para o arquivo
	char palavra[20]; //variavel do tipo string
	
	//abrindo o arquivo com tipo de abertura W
	pont_arq = fopen("teste.txt", "a"); //primeiro parametro: arquivo || a: se exite abre, se n crie. w: se n existir cria, se exister substitui. r:somente leitura.
	
	//testando se o arquivo foi realmente criado
	if(pont_arq == NULL){
		printf("Erro na abertura do arquivo!");
		return 1;
	}
	
	printf("Escreva uma palavra pra testar gravacao de arquivo: ");
	scanf("%s\n", palavra);
	
	//usando fprintf para armazenar a string no arquivo
	fprintf(pont_arq, "%s", palavra);
	
	//usando fclose para fechar o arquivo
	fclose(pont_arq);
	
	printf("Dados gravados com sucesso!");
	
	return(0);
}
