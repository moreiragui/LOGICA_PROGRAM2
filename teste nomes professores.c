#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearchStr(char *MatrizOrdenada[], int inicio, int fim, char*chave){
	while (inicio <= fim){
	int meio = (inicio + fim) / 2;
	int cmp = strcmp(chave, MatrizOrdenada[meio]);
	
	if(cmp > 0)
		inicio = meio + 1;
	else if (cmp <0)
		fim = meio - 1;
	else
		return meio;
	}
return -1;
}

int cstring_cmp(const void *a, const void *b){
	const char **pa = (const char **)a;
	const char **pb = (const char **)b;
	return strcmp(*pa, *pb);
}

int main(){
	
	unsigned int tamanho, i, procura;
	char *strings[5];
	
	tamanho = sizeof(strings) / sizeof(char *);
	for(i=0; i<tamanho; i++){
		printf("Digite os nomes dos professores: \n");
		scanf("%s",&strings[i]);
	}
	
	puts("Professores Originais");
	for(i=0; i<tamanho; i++) printf("%s\n", strings[i]);
	
	qsort(strings, tamanho, sizeof(char *), cstring_cmp);
	
	puts("\nProfessores Ordenados");
	for(i=0; i<tamanho; i++) printf("%s\n", strings[i]);
	procura = binarySearchStr(strings, 0, 5, "Eaemen");
	printf("\nIndice de Eaemen = %d\n", procura);
	
	system("pause");
	return 0;
}
