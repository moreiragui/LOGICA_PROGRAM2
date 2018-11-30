#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0;
    int numPalavras = 0;
    char* palavras[50];
    char line[50];

    FILE *arquivo;
    arquivo = fopen("teste.txt", "r");

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        //Adiciona cada palavra no vetor
        palavras[i] = strdup(line);

        i++;

        //Conta a quantidade de palavras
        numPalavras++;
    }

    int j;

    for (j = 0; j < numPalavras; j++)
        printf("\n%s", palavras[j]); //Exibi as palavras que estao no vetor.

    printf("\n\n");

    fclose(arquivo);

    return EXIT_SUCCESS;
}
