#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b){
	const int *pa = (const int *)a;
	const int *pb = (const int *)b;
	return *pa - *pb;
}

int main(){
	unsigned int tamanho, i;
	
	int tab[]={231, 524, 324, 738, -34, 0, 123, 6, 347, 1231};
	
	tamanho= sizeof(tab)/sizeof(int);
	
	qsort(tab, tamanho, sizeof(int), compara);
	
	for(i=0; i<10; i++){
		printf("%d\n", tab[i]);
	}
	return 0;
}
