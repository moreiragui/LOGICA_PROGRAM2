#include <stdio.h>
#include <stdlib.h>
 
     // um contador global para uso na função principal e booleana
      int cont = 0;
    
     // a struct citada
     struct st_Nota_Fiscal 
     {
           int CodigoNF;
           char DT_Emissao[10];
           int CodigoCliente;
           int QtdeItens;
           char CategoriaNota[1];
           char TipoFrete[1];
    };
 
    // criando a função booleana uma vez que estou trabalhando com c
    enum boolean
    {
          true = 1, false = 0
    }; typedef  enum boolean  Grava_dados;
 
  //a função de gravação com uso do contador global
  Grava_Dados (struct st_Nota_Fiscal pv_NotaFiscal[cont])
  {
         FILE *fp;    
          fp = fopen ("NF_010015.txt", "a");  
          if (fp == NULL)
          {    
               return (false);    
               exit(1);    
          }    
          else
          {    
                // usei o fprintf pois melhor se adaptou a gravação com o vetor pv_NotaFiscal.
                fprintf(fp,"CODIGO DA NOTA FISCAL: %d;",pv_NotaFiscal[cont].CodigoNF);
                fprintf(fp,"\nDATA DE EMISSAO: %s;",pv_NotaFiscal[cont].DT_Emissao);
                fprintf(fp,"\nCODIGO DO CLIENTE: %d;",pv_NotaFiscal[cont].CodigoCliente); 
                fprintf(fp,"\nQUANTIDADE DE ITENS: %d;",pv_NotaFiscal[cont].QtdeItens);
                fprintf(fp,"\nCATEGORIA DA NOTA: %s;",pv_NotaFiscal[cont].CategoriaNota);
                fprintf(fp,"\nTIPO DE FRETE: %s;\n",pv_NotaFiscal[cont].TipoFrete);
                fclose (fp);
                printf ("\n\nDados Gravados com sucesso!\n\n");
          }       
  }
  
  // função principal usei o setbuf apenas para limpar o buffer do teclado e evitar erro na gravação
  int main ()
  {
          char op;
          do{
                struct st_Nota_Fiscal dados[cont];
                printf ("Digite o Codigo da NF: ");
                scanf ("%d", &dados[cont].CodigoNF);
                setbuf (stdin, NULL);
                printf ("Digite a data da emissao da NF [DD/MM/AAAA]: ");
                gets (dados[cont].DT_Emissao);
                setbuf (stdin, NULL);
                printf ("Digite o codigo do cliente: ");
                scanf ("%d", &dados[cont].CodigoCliente);
                setbuf (stdin, NULL);
                printf ("Digite a quantidade disponivel: ");
                setbuf (stdin, NULL);
                scanf ("%d", &dados[cont].QtdeItens);
                setbuf (stdin, NULL);
                printf ("Digite a categoria da NF [V] - Venda ou [T] - Transferencia: ");
                gets (dados[cont].CategoriaNota);
                setbuf (stdin, NULL);
                printf ("Digite o tipo do frete [C] - CIF ou [F] - FOB: ");
                gets (dados[cont].TipoFrete);
                setbuf (stdin, NULL);
                Grava_Dados (dados);
                cont = cont ++;
                printf ("\nDeseja gravar mais alguma NF: ");
                 scanf ("%c", &op);
          } while (op == 'S' || op == 's');
          printf ("\nPrograma finalizado com sucesso\n");
          return 0;
   }
