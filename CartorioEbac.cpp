#include <stdio.h> //biblioteca de comunica��o ao usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o para cadastrar os usuarios no sistema
{
	//inicio da cria��o de variaveis/strings
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de variaveis/strings
    
    printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usuario
    scanf("%s", cpf);//%s refere-se a string
    
    strcpy(arquivo, cpf);  // respons�vel por copiar os valores das strings
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo/fopen abre o arquivo/ "w" escreve o arquivo
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo,"a");// cria o arquivo/fopen abre o arquivo/ "w" escreve o arquivo
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
    
    
    
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	    printf("\nEssas s�o as informa��es do usuario: ");
	    printf("%s", conteudo);
	    printf("\n\n");
	}
	
	system("pause");
	
	
	
	
}

int deletar()
{
	char cpf[40];
	
    printf("Digite o CPF do usu�rio a ser deletado:\n");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file ==NULL)
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}
	
}



int main ()
{
	int opcao=0;//definindo a variavel
	int x=1;
	
	for(x=1;x=1;)
	{
	  
	
	
	  setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	  
	  system("cls");
	
	  printf("###Cart�rio da EBAC###\n\n");//inicio do menu
	  printf("Escolha a op��o desejada no menu\n\n");
	  printf("\t1 - Registrar Nomes\n");
	  printf("\t2 - Consultar Nomes\n");
	  printf("\t3 - Deletar Nomes\n\n");//final do menu
	  printf("op��o desejada: ");
	
	  scanf("%d", &opcao);//armazenando a escolha do usuario
	
	  system("cls");//para limpar o sistema
	  
	  switch(opcao)
	  {
	  	case 1:
	  	 registro();
		 break;
		 
		 case 2:
		 consultar();
		 break;
		 
		 case 3:
		 deletar();
		 break;
		 
		 default:
		 printf("Essa op��o n�o est� d�sponivel!\n");
		 system("pause");
		 break;
		 
	  }


	
}
}
	
	

