#include <stdio.h>
#include <stdlib.h>

float valor[10]= {3,6,8,1,4,9,5,14,56,790};
float temp=0;
int i,j;

int main(){
	
	for(i=0; 1<10; i++){
		for(j=i+1;j<10; j++){
			if(valor[i]>valor[j]){
				temp=valor[i];
				valor[i]=valor[j];
				valor[j]=temp;
			}
		}
	}
		
	for(i=0; i<10; i++){
		printf("%.2f \n",valor[i]);
	}
	return 0;
}
