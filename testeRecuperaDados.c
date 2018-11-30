#include <stdio.h>
#include <stdlib.h>
 void gravaAlun(){
 }
     // um contador global para uso na função principal e booleana
      int cont = 0;
    
     // a struct do Aluno
     struct st_grava_Aluno{
           int codigoAluno;
           char nomeAluno[150];
    };
 
    // criando a função booleana uma vez que estou trabalhando com c
    enum boolean
    {
          true = 1, false = 0
    }; typedef  enum boolean  Grava_dados;
 
  //a função de gravação com uso do contador global
  Grava_Dados (struct st_grava_Aluno pv_gravaAluno[cont]){
      FILE *fp;    
      fp = fopen ("teste.txt", "a");  
      if (fp == NULL){    
           printf("O arquivo não pode ser aberto!");
           return (false);    
           exit(1);    
      }    
      else
      {    
            // usei o fprintf pois melhor se adaptou a gravação com o vetor pv_NotaFiscal.
            fprintf(fp,"\nCODIGO DO ALUNO(A): #%d;",pv_gravaAluno[cont].codigoAluno);
            fprintf(fp,"\nNOME DO ALUNO(A): %s;\n;",pv_gravaAluno[cont].nomeAluno);
            fclose (fp);
            printf ("\n\nDados Gravados com sucesso!\n\n");
      }       
  }
  
  void cadastro(){
  	char op;
          do{
                struct st_grava_Aluno dados[cont];
                printf ("Digite o Codigo do Aluno(a): ");
                scanf ("%d", &dados[cont].codigoAluno);
                setbuf (stdin, NULL);
                printf ("Digite o Nome Completo do Aluno(a): ");
                gets (dados[cont].nomeAluno);
                setbuf (stdin, NULL);
                Grava_Dados (dados);
                cont = cont ++;
                printf ("\nDeseja Cadastrar mais algum aluno? (S/N): ");
                 scanf ("%c", &op);
          } while (op == 'S' || op == 's');
          printf ("\nPrograma finalizado com sucesso\n");
  }
  
  // função principal usei o setbuf apenas para limpar o buffer do teclado e evitar erro na gravação
  int main ()
  {
          cadastro();
          return 0;
   }
