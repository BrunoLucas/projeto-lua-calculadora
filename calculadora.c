#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <dlfcn.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include "./lib/plugin.h"



int abrirPlugins(char **, char*);
int opcao,i,cont,j, valor1, valor2;
char nomes[100];
int k;
DIR *dir = NULL;
static void *lib_handle[100];
char nomeBiblioteca[100];
char *error;
char sair[2];
char sair2;
int (*f_todas)(int, int);

int dif=0;
int total=0;
int tempo;
static char *lista[100];
char diretorio[] = "./plugins/";
struct dirent *drnt = NULL;



void getFuncoes(char** list){
	printf("chamou a getFuncoes %p\n",list);

        abrirPlugins(lista,diretorio);
	
	printf("\n********************** %p\n",list);
	int i=0;
	for (i=0; i<total; i++){
		printf("passo : %d\n",i);
		size_t len = strlen (lista[i]);
		list[i] = (char *) malloc (len);
		strcpy(list[i], lista[i]);
		printf("Função : %d [%s] %p %d\n",i,list[i],list[i],strlen(list[i]));
	}

	printf("total=%d %p\n",total,list);
	
/*	
	for (i=0; i<total; i++){
		printf("passo : %d\n",i);
		printf("Função : %d [%s]\n",i,list[i]);
	}
*/
	printf("\n**********************\n");
/*
	printf("\n Função : 0 [%s]",list[0]);
	printf("\n Função : 1 [%s]",list[1]);
	printf("\n Função : 2 [%s]",list[2]);
	printf("\n Função : 3 [%s]",list[3]);
*/
	//for(i=0;i<total;i++){
	//	printf("\n Função : %d [%s]",i,lista[i]);
   	//}
	//printf("\nTerminou getFuncoes()");

	//for(i=0;i<10;i++){
	//	printf("\n %d",i);
   	//}

//	return lista;
}

int getTotal(){
	return total;
}


void imprimir(char **p_Raiz){
  int i =0;
  int j;
  char **l;

  }

int executar(int v1,int v2,int op){
	printf("\nEstou no executar\n");
	printf("\na[%d]b[%d]op[%d]",v1,v2,op);
	printf("\nlib_handle %p", lib_handle);
		
	
        f_todas = dlsym(lib_handle[op],"execute");

        /*if ((error = dlerror()) != NULL)
        {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }*/
	printf("\nPassei do f_todas\n");
        int resposta = (*f_todas)(v1,v2);

        printf("Resultado= %d\n",resposta);
	return resposta;
       
}

int main(){




 
 printf("\n*************************");

   


  do{
    
      opcao = 0;
  i=0;
    
  imprimir(lista);    
  printf("Informe a opcao: \n");
      scanf("%d",&opcao); // lê a operacao desejada
    
  while(opcao < 0 || opcao > total-1){
     
      printf("\nInforme a opcao valida");
      scanf("%d",&opcao); // lê a operacao desejada
  }
     

          printf("Informe o valor  1  :");
          scanf("%d",&valor1);
         
          printf("Informe o valor  2  :");
          scanf("%d",&valor2);
      
 
      printf("Aguarde... Calculando\n\n");
              //Chamar o Plugin da operação selecionada


        f_todas = dlsym(lib_handle[opcao],"execute");

        if ((error = dlerror()) != NULL)
        {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }

        int resposta = (*f_todas)(valor1,valor2);
        printf("Resultado= %d\n",resposta);
       
  printf("\nAperte 'S' para sair\nQualquer tecla para continuar\n'R' para recarregar plugins\n");
  
  scanf("%s",sair);

  if(strcmp(sair,"R")==0){

      printf("\nRecarregando ...");
      system("clear");
      total = 0;
      abrirPlugins(lista,diretorio);
  }
  }while(strcmp(sair,"S") != 0);
printf("\n Bye bye ^^\n");
}

int abrirPlugins(char **lista, char *diretorio){
      cont = 0;
      printf("Ola!\n");
      printf("Selecione uma operacao para comecar, 'S' para sair:\n\n");
     
      dir=opendir(diretorio);
      if(dir)
      {
      i=0;
  printf("\nDiretório %s aberto\n",diretorio);
              while(drnt = readdir(dir))
     
              {
    
        if( strstr(drnt->d_name,"lib") == NULL) {
          i++;
          dif++;

            continue;
      }
        //puts("oi");  
                  strcpy(nomeBiblioteca,"./plugins/");
                  strcat(nomeBiblioteca,drnt->d_name)       ;
                  printf("\n nomeBiblioteca %s",nomeBiblioteca);
             
                  lib_handle[cont] = dlopen(nomeBiblioteca, RTLD_LAZY);
          total++;
      lista[cont] = strndup(drnt->d_name+3,((strlen(drnt->d_name))- 6));
      //lista[cont] = '\0';
      printf("\nElem add: [%s]",lista[cont]);
        
                  if (!lib_handle[cont])
                  {
                  fprintf(stderr, "%s\n", dlerror());
                  } else {
			printf("vai carregar a funcao\n");
			f_todas = dlsym(lib_handle[cont],"execute");
			printf("carregou a funcao\n");
			/*if ((error = dlerror()) != NULL)
			{
			    fprintf(stderr, "%s\n", error);
			    exit(1);
			}*/
			printf("vai executar a funcao\n");
			int resposta = (*f_todas)(2,3);

			printf("Resultado= %d\n",resposta);
		  }
                cont++;
               
                i++;
      memset(nomeBiblioteca,0,99);
              }
              closedir(dir);

      }
      else
      {
              printf("Erro ao abrir diretorio '%s'\n", diretorio);
      system("pause");
      exit(0);
      }

 
}

    





 
