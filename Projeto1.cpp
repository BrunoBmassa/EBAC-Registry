#include <stdio.h> //biblioteca comunicação com usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() // função responsável por registrar os usuários no sistema
{
	//Início criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final criação das variáveis/strings
	printf("Digite o CPF a ser cadastrado:"); //Coletando CPF do usuário
	scanf("%s", cpf); // refere-se a string
	strcpy (arquivo, cpf); // Responsavel por copiar os valores da string
	//Tratativas com o arquivo
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	//Tratativas com o arquivo
	file = fopen(arquivo, "a");
	fprintf(file, ",");  
	fclose(file); 
	
	printf("Digite o nome a ser cadastrado:"); //Coletando nome do usuário
	scanf("%s", nome);
	//Tratativas com o arquivo
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:"); //Coletando sobrenome do usuário
	scanf("%s", sobrenome);
	//Tratativas com o arquivo
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:"); //Coletando cargo do usuário
	scanf("%s", cargo);
	//Tratativas com o arquivo
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
}
int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coletando CPF do usuário
	scanf("%s", cpf);
	//Tratativas com o arquivo
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file ==  NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado!. \n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\n Essas sao as informacoes do usuario: "); 
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
}
int deleta()
{
	char cpf[40];
	printf("Digite o CPF do usuario a ser deletado"); //Coletando informação do usuário
	scanf("%s", cpf );
	remove(cpf); // apaga o arquivo
	//Tratativas com o arquivo
	FILE *file;
	file = fopen (cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema!. \n");
		system ("pause");
	}
	
}
int main()
{
	int opcao = 0;//definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	system("cls"); // responsavel por limpar a tela
	
	 printf(" ### Cartorio da EBAC ### \n\n");//inicio da seleção  do menu	
	 printf("Escolha a opcao desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("\t4 - Sair do sistema\n\n");
	 printf("Opcao: "); //fim do menu
	 
	scanf("%d,", &opcao);//armazenando a escolha do usuario
	
	system("cls");
	
		switch(opcao)
		{
			case 1:
				registro(); // chamada de funções
				break;
				
				
			case 2:
				consulta();
				break;
				
			case 3:
				deleta();
				break;
				
			case 4:
				printf("Obrigado por usar o sistema!\n" );
				return 0;
			default:
				printf("Essa opcao nao esta disponivel! \n");
				system("pause");
				break;
		}
	
	}
	
}
