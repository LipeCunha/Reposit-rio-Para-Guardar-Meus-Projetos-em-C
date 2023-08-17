#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável pela criação de strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis ou string
	char arquivo[60]; //Definindo quem é o arquivo quantos caracteres ele pode terv
	char CPF[60]; //Definindo quem é o CPF quantos caracteres ele pode ter
	char Nome[60]; //Definindo quem é o Nome quantos caracteres ele pode ter
	char Sobrenome[200]; //Definindo quem é o Sobrenome quantos caracteres ele pode ter
	char Cargo[60]; //Definindo quem é o Cargo e quantos caracteres ele pode ter
	//final da criação de variáveis ou string
	
	printf("Digite o CPF a ser Cadastrado : "); //Coletando informações do usuário
	scanf("%s",CPF); //%s refere-se ao armazenamento de uma string
	
	strcpy(arquivo, CPF); // Responsável por Copiar os Valores das Strings
	
	FILE *file; // Cria o Arquivo no Banco de Dados 
	file = fopen(arquivo, "w"); // Cria o Arquivo no Banco de Dados e o "w" significa ESCREVER
	fprintf(file,CPF);  // Salvo o Valor da Variável
	fclose(file); // Fecha o Arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o Nome a ser Cadastrado : "); //Coletando informações do usuário
	scanf("%s",Nome);
		
	file = fopen(arquivo, "a");
	fprintf(file,Nome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o Sobrenome a ser Cadastrado : "); //Coletando informações do usuário
	scanf("%s",Sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,Sobrenome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); 
	
	printf("Digite o Cargo a ser Cadastrado " ); //Coletando informações do usuário
	scanf("%s",Cargo);
	
	file = fopen(arquivo, "a");
    fprintf(file,Cargo);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); 
	
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	char CPF[60];
    char conteudo[200];
    
    printf("Digite o CPF a ser Consultado : ");
    scanf("%s",CPF);
    
    FILE *file;
    file = fopen(CPF,"r");
    
    if(file == NULL)
    {
    	
		printf("Não foi possível Encontrar o Arquivo que você está buscando\n ");
		
	}
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	
    	printf("\nEssas são as informações do usuário : ");
    	printf("%s", conteudo);
    	printf("\n\n");
    	
	}
    
    system("pause");


}

int deletar()
{	
	
	char CPF[60];
	
	printf("Qual CPF Você Deseja Deletar? " );
	scanf("%s",CPF);
	
	FILE *file;
	file = fopen(CPF,"r"); // "r" Significa READ ou LEIA
	
	if(file == NULL) // Caso Não Encontre o CPF NO SISTEMA
	{
		printf("Este CPF Não se Encontra no Sistema!.\n");
		system("pause");
	}
	
	else // Mensagem de CONFIRMACAO QUE O CPF FOI DELETADO

	{
		printf("Este Cpf Foi Deletado com sucesso. \n");
		system("pause");
		
	}
	fclose(file);
	
	remove(CPF); // Responsável por Apagar o CPF
	
} // FIM DA FUNÇÃO DELETAR

int main () 
{	
	int opcao=0; //Definindo Variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
   		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
   		
   		system("cls"); //Responsável por Limpar a Tela
   		
   		printf("### Cartório da EBAC  ###\n\n");	 //Início do menu 
   		printf("Escolha a opção desejada do menu:\n\n");
   		printf("\t1 - Registrar Nomes \n ");
   		printf("\t2 - Consultar Nomes \n ");
   		printf("\t3 - Deletar Nomes \n\n\n");
   		printf("Escolha a Opção Desejada: ");  //Fim do Menu
   
   		scanf("%d" , &opcao); //armazenamendo a escolha do usuário
   		
   		system("cls");
		
		switch(opcao)
   		{ 
   			case 1:
   			registro(); // Chamada de funções
   			break;
   			
   			case 2:
   			consulta(); // Chamada de funções
			break;
			
			case 3:
			deletar(); // Chamada de funções
			break;
			
			default:
			printf("Esta Opção Está Indisponível!\n"); // Na inexistência de Função, apresente esta mensagem
			system("pause");
			break;   	
		}
   		
	}
	
}

