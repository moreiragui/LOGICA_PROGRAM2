#include<stdio.h>
#include<stdlib.h>


//CONTADOR GLOBAL
int cont = 0;

//STRUCT DO ALUNO
struct st_grava_Aluno{
	int codigoAluno;
	char nomeAluno[150];
	int alunoDisc;
};

//STRUCT DA DISCIPLINA
struct st_grava_Disc{
	int codigoDisc;
	char nomeDisc[150];
};

//EU SEI LÁ QUE CARALHOS É ISSO SÓ BOTEI AQUI
enum boolean{
	true = 1, false = 0
}; typedef  enum boolean  Grava_dados;


//FUNÇÃO PARA SALVAR O CADASTRO DOS ALUNOS NO TXT
void Grava_Dados (struct st_grava_Aluno pv_gravaAluno[cont]){
      FILE *fp;    
      fp = fopen ("alunos.txt", "a");  
      if (fp == NULL){    
           printf("O arquivo não pode ser aberto!");
           return (0);    
           exit(1);    
      }    
      else
      {    
            //FPRINTF PRA SALVAR NO TXT
            fprintf(fp,"\nCODIGO DO ALUNO(A): #%d;",pv_gravaAluno[cont].codigoAluno);
            fprintf(fp,"\nNOME DO ALUNO(A): %s;",pv_gravaAluno[cont].nomeAluno);
            fprintf(fp,"\nCODIGO DA DISCIPLINA ESCOLHIDA: %d;\n;",pv_gravaAluno[cont].alunoDisc);
            fclose (fp);
            printf ("\n\nDados Gravados com sucesso!\n\n");
            
      }       
  }
//FUNÇÃO PARA SER CHAMADO NO MENU QUE FAZ O CADASTRO DOS ALUNOS
void cadastro(){
	char op;
	do{
	    struct st_grava_Aluno dados[cont];
	    printf ("\n\nDigite o Codigo do Aluno(a): ");
	    scanf ("%d", &dados[cont].codigoAluno);
	    setbuf (stdin, NULL);
	    printf ("\nDigite o Nome Completo do Aluno(a): ");
	    gets (dados[cont].nomeAluno);
	    setbuf (stdin, NULL);
	    printf ("\nDigite o Codigo da Disciplina escolhida: ");
	    scanf ("%d", &dados[cont].alunoDisc);
	    setbuf (stdin, NULL);
	    Grava_Dados (dados);
	    cont = cont ++;
	    printf ("\nDeseja Cadastrar mais algum aluno? (S/N): ");
	    scanf ("%c", &op);
	} while (op == 'S' || op == 's');
	printf ("\nPrograma finalizado com sucesso\n");
	system("cls || clear");
	menuInicial();
}


//FUNÇÃO PARA SALVAR O CADASTRO DAS DISCIPLINAS NO TXT
void Grava_Dados02 (struct st_grava_Disc pv_gravaDisc[cont]){
      FILE *fp;    
      fp = fopen ("disciplina.txt", "a");  
      if (fp == NULL){    
           printf("O arquivo não pode ser aberto!");
           return (0);    
           exit(1);    
      }    
      else
      {    
            //FPRINTF PRA SALVAR NO TXT
            fprintf(fp,"\nCOD. DISC.: #%d;",pv_gravaDisc[cont].codigoDisc);
            fprintf(fp,"   NOME DISC.: %s;",pv_gravaDisc[cont].nomeDisc);
            fclose (fp);
            printf ("\n\nDados Gravados com sucesso!\n\n");
            
      }       
  }
//FUNÇÃO PARA SER CHAMADO NO MEU QUE FAZ O CADASTRO DAS DISCIPLINAS
void cadastro02(){
	char op;
	do{
	    struct st_grava_Disc dadoss[cont];
	    printf ("\n\nDigite o Codigo da Disciplina: ");
	    scanf ("%d", &dadoss[cont].codigoDisc);
	    setbuf (stdin, NULL);
	    printf ("\nDigite o Nome da Disciplina: ");
	    gets (dadoss[cont].nomeDisc);
	    setbuf (stdin, NULL);
	    Grava_Dados02 (dadoss);
	    cont = cont ++;
	    printf ("\nDeseja Cadastrar mais alguma Disc? (S/N): ");
	    scanf ("%c", &op);
	} while (op == 'S' || op == 's');
	printf ("\nPrograma finalizado com sucesso\n");
	system("cls || clear");
	menuInicial();
}


//FUNÇÃO PARA LER O ARQUIVO .TXT COM OS ALUNOS NO DIRETÓRIO
void leituraArquivo(){
	system("cls || clear");
	int i = 0;
    int numPalavras = 0;
    char* palavras[400];
    char line[400];

    FILE *arquivo;
    arquivo = fopen("alunos.txt", "r");

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
        printf("\n%s", palavras[j]); //Exibe as palavras que estao no vetor

    printf("\n\n");

    fclose(arquivo);

	printf("ESSES FORAM OS DADOS DO REGISTRO\nTECLE ENTER PARA VOLTAR AO MENU PRINCIPAL!\n");
    system ("pause");
    menuInicial();
}

//FUNÇÃO PARA LER O ARQUIVO .TXT COM AS DISCIPLINAS
void leituraArquivo2(){
	system("cls || clear");
	int i = 0;
    int numPalavras = 0;
    char* palavras[400];
    char line[400];

    FILE *arquivo;
    arquivo = fopen("disciplina.txt", "r");

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

    printf("ESSES FORAM OS DADOS DO REGISTRO\nTECLE ENTER PARA VOLTAR AO MENU PRINCIPAL!\n");
    system ("pause");
    menuInicial();
}


//MENU QUE MOSTRA QUANDO SE SELECIONA OPÇÃO 03
void menuLeitura(){
	int opcaoLeitura=1;
	
	printf("QUAL REGISTRO DE DADOS VOCE QUER QUE SEJA EXIBIDO?: \n");
	printf("\n 1 - REGISTRO DE ALUNOS\n 2 - REGISTRO DE DISCIPLINAS\n 3 - VOLTAR AO MENU ANTERIOR\n\nDIGITE A OPCAO DESEJADA:\n\n");
	scanf("%d",&opcaoLeitura);
	
	switch(opcaoLeitura){
		case 1:
			printf("OK, SEGUE DADOS DOS ALUNOS CADASTRADOS ABAIXO: \n");
			leituraArquivo();
		break;
		
		case 2:
			printf("OK, SEGUE DADOS DAS DISCIPLINAS CADASTRADAS ABAIXO: \n");
			leituraArquivo2();
		break;
		
		case 3:
			system("cls || clear");
			menuInicial();
		break;
		
		default: printf("Opcao Invalida!");
	}
}

//MENU QUE MOSTRA QUANDO SE SELECIONA OPÇÃO 01
void menuAluno(){
	system("cls || clear");
	printf("\nDISCIPLINAS DISPONIVEIS NO SISTEMA:\n");
	leituraCadastro();
	printf("\n====================================\n");
	printf("OK, SEGUE FORMULARIO PARA CADASTRO ABAIXO:\n");
	cadastro();
}
//FUNÇÃO PARA MOSTRAR AS DISCIPLINAS CADASTRADAS NO CADASTRO DOS ALUNOS
void leituraCadastro(){
	int i = 0;
    int numPalavras = 0;
    char* palavras[400];
    char line[400];

    FILE *arquivo;
    arquivo = fopen("disciplina.txt", "r");

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
}


//MENU QUE MOSTRA QUANDO INICIA O PROGRAMA
void menuInicial(){
	system("cls || clear");
	int opcao=1;
	
	printf("===== CADASTRO DE ALUNOS E DISCIPLINAS =====\n");
	printf("\n============== MENU DE OPCOES ==============\n");
	printf("\n 1 - CADASTRO DE ALUNO\n 2 - CADASTRO DE DISCIPLINA\n 3 - MOSTRAR REGISTRO DE DADOS\n 4 - SAIR\n\nDIGITE SUA OPCAO DESEJADA:\n\n");
	
	scanf("%d",&opcao);
	system("cls || clear");
	
	switch(opcao){
		case 1:
			menuAluno();
		break;
		
		case 2:
			system("cls || clear");
			printf("OK, SEGUE FORMULARIO PARA CADASTRO ABAIXO:\n");
			cadastro02();
		break;
		
		case 3:
			system("cls || clear");
			menuLeitura();
		break;
		
		case 4:
			printf("\nFINALIZANDO O PROGRAMA! TECLE ENTER NOVAMENTE PARA SAIR!");
			return 0;
		break;
		
		default:
			printf("Digita uma opcao valida!");
	}
}


int main(){
	
	menuInicial();
	
	return 0;
}
