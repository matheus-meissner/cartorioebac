#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	// Strings;
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // Ler o que foi digitado e armazenar na string CPF;
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings;
	
	FILE *file; // Cria o arquivo no banco de dados;
	file = fopen(arquivo, "w"); // Cria o arquivo no banco de dados, "w" � de write, escreve no arquivo;
	fprintf(file,cpf); // Salva o valor da vari�vel;
	fclose(file); // Fecha o arquivo;
	
	file = fopen(arquivo, "a"); // "a" adiciona algo ao arquivo;
	fprintf(file,","); // V�rgula adicionada;
	fclose(file); // Fecha o arquivo;
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" � para read, logo ele l� o arquivo;
	
	if(file == NULL)
	{
		printf("CPF n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo); // Mostra o conte�do ao usu�rio;
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	int confirmacao=0;
	
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
		return 0;
	}
	else
		printf("Certeza que deseja apagar o CPF: ");
		printf("%s", cpf);
		printf("\n\n\t1 = sim\n\t2 = n�o");
		printf("\n\n\t");
		scanf("%d", &confirmacao);
		
		switch(confirmacao)
		{
			case 1:
				remove(cpf);
				system("cls");
				printf("O CPF: ");
				printf("%s", cpf);
				printf(" foi deletado com sucesso!\n");
				break;
			case 2:
				system("cls");
				printf("O CPF N�O foi deletado.\n");
				break;
			default:
				system("cls");
				printf("Essa op��o n�o est� dispon�vel!\n");
				break;
		}
	system("pause");
}

int main()
{
	int escolha=0; //Definindo vari�veis;
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem;
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu;
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: ");//Final do menu;
	
		scanf("%d", &escolha); //Armanezando a escolha do usu�rio;
	
		system("cls");
		
		
		switch(escolha)
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
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
		}
	}
}
