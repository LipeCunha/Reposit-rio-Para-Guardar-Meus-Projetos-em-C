#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel pela cria��o de strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis ou string
	char arquivo[60]; //Definindo quem � o arquivo quantos caracteres ele pode terv
	char CPF[60]; //Definindo quem � o CPF quantos caracteres ele pode ter
	char Nome[60]; //Definindo quem � o Nome quantos caracteres ele pode ter
	char Sobrenome[60]; //Definindo quem � o Sobrenome quantos caracteres ele pode ter
	char Cargo[60]; //Definindo quem � o Cargo e quantos caracteres ele pode ter
	//final da cria��o de vari�veis ou string
	
	printf("Digite o CPF a ser Cadastrado : \n"); //Coletando informa��es do usu�rio
	scanf("%s",CPF); //%s refere-se ao armazenamento de uma string
	
	strcpy(arquivo, CPF); // Respons�vel por Copiar os Valores das Strings
	
	FILE *file; // Cria o Arquivo no Banco de Dados 
	file = fopen(arquivo, "w"); // Cria o Arquivo no Banco de Dados e o "w" significa ESCREVER
	fprintf(file,"CPF : ");
	fprintf(file,CPF);  // Salvo o Valor da Vari�vel
	fclose(file); // Fecha o Arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", \nNOME : ");
	fclose(file); 
	
	printf("Digite o Nome a ser Cadastrado : \n"); //Coletando informa��es do usu�rio
	scanf("%s",Nome);
		
	file = fopen(arquivo, "a");
	fprintf(file,Nome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,", \nSOBRENOME : ");
	fclose(file); 
	
	printf("Digite o Sobrenome a ser Cadastrado : \n"); //Coletando informa��es do usu�rio
	scanf("%s",Sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,Sobrenome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,", \nCARGO : ");
	fclose(file); 
	
	printf("Digite o Cargo a ser Cadastrado : \n" ); //Coletando informa��es do usu�rio
	scanf("%s",Cargo);
	
	file = fopen(arquivo, "a");
    fprintf(file,Cargo);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n\n");
	fclose(file); 
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	char CPF[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser Consultado : "); //Recebendo qual usu�rio vai ser consultado
    scanf("%s",CPF); //
    
    FILE *file;
    file = fopen(CPF,"r"); //Busca o CPF do usu�rio no banco de Dados
    
    if(file == NULL)
    {
    	
		printf("N�o foi poss�vel Encontrar o Arquivo que voc� est� buscando\n ");	
	}
    
	printf("\nEssas s�o as informa��es do usu�rio : \n\n");
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("%s", conteudo);
    	printf("\n");	
	}
    
    system("pause");


}

int deletar()
{	
	
	char CPF[60];
	
	printf("Qual CPF Voc� Deseja Deletar? " );
	scanf("%s",CPF);
	
	FILE *file;
	file = fopen(CPF,"r"); // "r" Significa READ ou LEIA
	
	if(file == NULL) // Caso N�o Encontre o CPF NO SISTEMA
	{
		printf("Este CPF N�o se Encontra no Sistema!.\n");
		system("pause");
	}
	
	else // Mensagem de CONFIRMACAO QUE O CPF FOI DELETADO
	{
		printf("Este Cpf Foi Deletado com sucesso. \n");
		system("pause");	
	}
	fclose(file);
	remove(CPF); // Respons�vel por Apagar o CPF
	
} // FIM DA FUN��O DELETAR

int main () 
{	
	int opcao=0; //Definindo Vari�veis
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
    
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
    
    printf("### Cart�rio da EBAC  ###\n\n");
    printf("Login de Administrador! \n\nDigite sua Senha: ");
    scanf("%s" ,senhadigitada);
    
    comparacao = strcmp(senhadigitada, "s04b30100");
    
if(comparacao == 0)
{  		
    system("cls");
    for(laco=1;laco=1;)
    {
   		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
   		
   		system("cls"); //Respons�vel por Limpar a Tela
   		
		printf("### Cart�rio da EBAC  ###\n\n");	 //In�cio do menu 
   		printf("Escolha a op��o desejada do menu:\n\n");
   		printf("\t1 - Registrar Nomes \n ");
   		printf("\t2 - Consultar Nomes \n ");
   		printf("\t3 - Deletar Nomes \n");
   		printf("\t4 - Sair do Sistema\n\n");
   		printf("Escolha a Op��o Desejada: ");  //Fim do Menu
   
   		scanf("%d" , &opcao); //armazenamendo a escolha do usu�rio
   		
   		system("cls");
		
		switch(opcao)
   		{ 
   			case 1:
   			registro(); // Chamada de fun��es
   			break;
   			
   			case 2:
   			consulta(); // Chamada de fun��es
			break;
			
			case 3:
			deletar(); // Chamada de fun��es
			break;
			
			case 4:
		    printf("Obrigado por utilizar o Sistema!\n");
		    return 0;
		    break;
			
			default:
			printf("Esta Op��o Est� Indispon�vel!\n"); // Na inexist�ncia de Fun��o, apresente esta mensagem
			system("pause");
			break;   	
		}   //fim da sele��o
	
	}
	
  }
  else
  	printf("Senha Incorreta");
}
