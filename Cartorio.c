#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

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
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings;
	
	FILE *file; // Cria o arquivo no banco de dados;
	file = fopen(arquivo, "w"); // Cria o arquivo no banco de dados, "w" é de write, escreve no arquivo;
	fprintf(file,cpf); // Salva o valor da variável;
	fclose(file); // Fecha o arquivo;
	
	file = fopen(arquivo, "a"); // "a" adiciona algo ao arquivo;
	fprintf(file,","); // Vírgula adicionada;
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
	file = fopen(cpf,"r"); // "r" é para read, logo ele lê o arquivo;
	
	if(file == NULL)
	{
		printf("CPF não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n\n");
		printf("%s", conteudo); // Mostra o conteúdo ao usuário;
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	int confirmacao=0;
	
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
		return 0;
	}
	else
		printf("Certeza que deseja apagar o CPF: ");
		printf("%s", cpf);
		printf("\n\n\t1 = sim\n\t2 = não");
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
				printf("O CPF NÃO foi deletado.\n");
				break;
			default:
				system("cls");
				printf("Essa opção não está disponível!\n");
				break;
		}
	system("pause");
}

int main()
{
	int escolha=0; //Definindo variáveis;
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem;
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu;
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");//Final do menu;
	
		scanf("%d", &escolha); //Armanezando a escolha do usuário;
	
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
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
		}
	}
}
