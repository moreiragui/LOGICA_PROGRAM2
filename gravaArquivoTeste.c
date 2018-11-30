#include<stdlib.h>
#include<stdio.h>

int main(){
	
	FILE *file;
	file = fopen("teste.txt", "a");
	
	if(file == NULL){
		printf("O Arquivo esta com erro e nao pode ser aberto!");
		getchar();
		exit(1);
	}
	
	fprintf(file, "Primeira Linha\n");
	
	fclose(file);
	
	system("pause");
	return 0;
}
