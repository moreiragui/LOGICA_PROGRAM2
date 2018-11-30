#include<stdio.h>
#include<stdlib.h>

int main(void){
	FILE*pont_arq; //Cria variável ponteiro para o arquivo
	char texto_str[20];
	char palavra[20]; //variavel do tipo string
	
	//abrindo o arquivo com tipo de abertura W
	pont_arq = fopen("teste.txt", "r"); //primeiro parametro: arquivo || a: se exite abre, se n crie. w: se n existir cria, se exister substitui. r:somente leitura.
	
	//testando se o arquivo foi realmente criado
	if(pont_arq == NULL){
		printf("Erro na abertura do arquivo!");
		return 1;
	}
	
	while(fgets(texto_str, 20, pont_arq) != NULL)
	printf("%s", texto_str);
	
	//usando fclose para fechar o arquivo
	fclose(pont_arq);
	
	return(0);
}
