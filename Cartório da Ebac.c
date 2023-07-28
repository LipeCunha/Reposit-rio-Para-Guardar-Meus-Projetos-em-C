#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pela criação de strings

int main ()
{
   setlocale(LC_ALL, "Portuguese");
   printf("### Cartório da EBAC  ###\n\n");	
   printf("Escolha a opção desejada do menu:\n\n");
   printf("\t1 - Registrar Nomes \n ");
   printf("\t2 - Consultar Nomes \n ");
   printf("\t3 - Deletar Nomes \n\n\n");  
   printf ("Esse Software é de Felipe Luiz Cunha Barretto \n");
}


