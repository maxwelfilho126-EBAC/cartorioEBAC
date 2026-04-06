#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar usuários no sistema	
{
	//inicio criação de variáveis/string
  	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário
	scanf("%s",cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);         //responsavel por copiar os valores das strings
	
	FILE *file;                  //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e"w" significa escrever
	fprintf(file, cpf);        //salvo o valor da variavel
	fclose(file);             //fecha o arquivo	
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");//"printf" exibe a mensagem ao usuário e "\n pula uma linha 
	scanf("%s",nome);//scanf realiza a leitura da string e armazena na variável
	
	 
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
} 

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	  printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\nEssas são as Informações do Usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
    {
		
	int opcao=0;//Definindo variáveis
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{

	system("cls");
	
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	printf("### Cartório EBAC ###\n\n"); //início do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("\t4- Sair do sistema!\n\n"); 
	printf("Opção:");//fim do menu")
	
	
    scanf("%d", &opcao); //armazenando a escolha do usuário
	
	system("cls");//reponsável por limpar a tela
	
	
	
	switch(opcao) //inicio da seleção do menu
	{
		case 1:
		registro();//chamada de funções
	    break;
	  
	    case 2:
	    consulta();
	    break;
		
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar nosso sistema!\n");
		return 0;
		break;
		
		default:
		printf("Essa opção não está disponível!\n");
		system("pause");
		break;	
		//fim da seleção
	}
	
	
    }



    }   
