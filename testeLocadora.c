#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define x 3
  /*
  struct TipoDatFilme
  {
      int Dia;
      int Mes;
      int Ano;

  };
  */
  struct filme
  {
      char   nome[30];
      char   genero[20];
      char   atorprincipal[40];
      float  valor;
      //struct TipoDatFilme DataFilme;

  };
  typedef struct filme reg;


  void CadastrarFilme()
  {

    FILE *filme = fopen("C:\\Filmes\\filme.bin", "w+");  

	int continuar = 1, opcao;
	char nomefilme[40];
	reg atributos;


	system("cls");

    /**/
	if(!filme == NULL)
	{


           printf("\n\n==== BEM-VINDO AO CADASTRO DE FILMES ====");

           while(continuar==1)
	       {

	            printf("\n\n\n");
	            printf("\n\n\   INFORME O NOME DO FILME (S - Sair):");
                gets(atributos.nome);


                if(((strcmp(atributos.nome,"S")==0)||(strcmp(atributos.nome,"s")==0)))
                {
                    continuar = 2;
                    break;
                }

                printf("\n\n\   INFORME O GENERO DO FILME  (S - Sair): ");
	            gets(atributos.genero);

	            if(((strcmp(atributos.genero,"S")==0)||(strcmp(atributos.genero,"s")==0)))
                {
                    continuar = 2;
                    break;
                }
                //putc(atributos, *filme);

                if(fwrite(&atributos, sizeof(reg),1, filme)!=1)
                {
                   printf("ERRO NA GRAVACAO DOS DADOS");
                }
                else
                {
                    system("cls");                              
                    printf("DADOS GRAVADOS COM SUCESSO!!!  (1 - CONTINUAR / 2 - SAIR )");
                }

	            fclose(filme);

           }//while


    }//if
    else
    {
         printf("não E POSSIVEL CADASTRAR O FILME.");
    }

  }//void CadastrarFilme()

  void MenuFilme()
  {
      int opcao,continuar = 4;

      while (continuar == 4)
      {
                 system("cls");                             
            do
            {
  printf ("\n\n======= GERENCIADOR DE FILMES ===============");         
                 printf ("\n\n\n    1 - CADASTRAR FILME");
                 printf ("\n\n\    2 - LISTAR FILME");
                 printf ("\n\n\    3 - BUSCAR FILME");
                 printf ("\n\n\    4 - ALTERAR  FILME");   
                 printf ("\n\n\    5 - EXCLUIR FILME");   
                 printf ("\n\n\    6 - RETORNAR AO MENU ANTERIOR: ");                
                // printf ("\n\n\n    ESCOLHA SUA OPCAO: ");                                          
                 scanf("%d",&opcao);
                 system("cls");                 
            }while(opcao < 1 || opcao > 6);

            if(opcao ==6)
            {
                 system("cls");
                 continuar = 3;
            }    

            else
            {  

                 switch (opcao)
                 {



                       case 1:
                              CadastrarFilme();
                              break;
                              system("cls");       
                 }//switch

            } //else


      } //while


  }//void MenuFilme()

int main(int argc, char *argv[])
{

  int opcao, continuar=4;
  FILE *filme;


  // printf ("\n\n\n\n\======= MENU DE OPCAO =======");

   while(continuar == 4)
   {
      do
      {
         printf ("\n\n=============    SEJA BEM-VINDO   ==============\n\n");
         printf ("\n\n============ SITEMA DE LOCADORA ===============");
         printf("\n\n\n 1 - GERENCIADOR DE FILMES \n\n ");
         printf("2 - GERENCIADOR DE CLIENTES \n\n ");   
         printf("3 - GERENCIADOR DE USUARIOS \n\n ");      
         printf("4 - GERENCIADOR DE CONFIGURACOES \n\n ");               
         printf("5 - SAIR DO PROGRAMA");     
         printf("\n\n\nESCOLHA SUA OPCAO: ");     
         scanf("%d",&opcao); 
      }while(opcao < 1 || opcao > 5);

      if (opcao == 5)  
      {
          continuar = 3;
      }
      else 
      {
            switch (opcao)
            {
                case 1:
                      system("cls");
                      MenuFilme();             
                      break;
            }
       }
   }

  printf("\n\n");
  system("PAUSE");
  return 0;
}
