#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pela cria��o de strings

int main ()
{
   setlocale(LC_ALL, "Portuguese");
   printf("### Cart�rio da EBAC  ###\n\n");	
   printf("Escolha a op��o desejada do menu:\n\n");
   printf("\t1 - Registrar Nomes \n ");
   printf("\t2 - Consultar Nomes \n ");
   printf("\t3 - Deletar Nomes \n\n\n");  
   printf ("Esse Software � de Felipe Luiz Cunha Barretto \n");
}


