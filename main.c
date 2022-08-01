#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

void incluirContato(TAgenda *agenda){
    
    int status;
    char nomeContato[50];
    char numeroContato[50];
    
    printf("\n======|INCLUIR CONTATO|======");
    printf("\n\n\tInforme o nome da Pessoa a ser incluída na Agenda: ");
    gets(nomeContato);
    gets(nomeContato);

    printf("\n\n\tAgora informe o número da Pessoa a ser incluída na Agenda: ");
    gets(numeroContato);

    status = insereContato(agenda, nomeContato, numeroContato);

    if(status == 1)
        printf("\n\tContato inserido com sucesso em sua Agenda!");
    else if(status == 2){
        do{
            
            printf("\n\tPor favor, Digite o nome do novo contato ou 'cancelar' para sair: \n");
            gets(nomeContato);
    
            if(strcmp(nomeContato,"cancelar") == 0)
                status = 0;
            else
                status = insereContato(agenda, nomeContato, numeroContato);
        }while(status == 2);
        
        if(status == 1)
            printf("\n\tContato inserido com sucesso em sua Agenda!");
        else
            printf("\n\tVocê optou por sair!\n");
    }else
        printf("\n\tContato não inserido!\n");
}

void incluirTelefone(TAgenda *agenda){
    
    int status = 0;
    char *numeroRetornado;
    char nomeContato[50];
    char numeroContato[50];
    
    printf("\n======|INCLUIR TELEFONE|======");
    
    printf("\n\n\tInforme o nome da Pessoa associada ao novo telefone: ");
    gets(nomeContato);
    gets(nomeContato);

    printf("\n\n\tAgora informe o número da Pessoa a ser incluído na Agenda: ");
    gets(numeroContato);

    numeroRetornado = insereTelefone(agenda,nomeContato,numeroContato,&status);

    if(status == 2){
        printf("\n\n====|ERRO: Essa pessoa já possui um número em sua Agenda!|====\n\n");
        printf("\n====|Seu número é: %s", numeroRetornado);
    }else if(status == 1)
        printf("\n\n====|Telefone inserido com Sucesso!|====\n\n");
    else
        printf("\n\n====|ERRO: Telefone não pôde ser inserido!|====\n\n");
}

void excluirContato(TAgenda *agenda){
    
    int status;
    char nomeContato[50];
    
    printf("\n======|EXCLUIR CONTATO|======");
    
    printf("\n\nInforme o nome da pessoa a ser excluída: ");
    gets(nomeContato);
    gets(nomeContato);

    excluiContato(agenda,nomeContato);
}

void excluirTelefoneContato(TAgenda *agenda){
    
    int status;
    char nomeContato[50];
    
    printf("\n======|EXCLUIR TELEFONE DE CONTATO|======");
    
    printf("\n\n\tInforme o nome da pessoa cujo contato há de ser excluído: ");
    gets(nomeContato);
    gets(nomeContato);

    status = excluiTelefone(agenda,nomeContato);
    
    if(status == 1)
        printf("\n\n====|Telefone excluído com Sucesso!|====\n\n");
    else
        printf("\n\n====|ERRO: Telefone não encontrado!|====\n\n");
}

void buscarContatoPeloNome(TAgenda agenda){
    
    int status = 0;
    char nomeContato[50];
    char *numeroContato;
    
    printf("\n======|BUSCAR CONTATO PELO NOME|======");
    
    printf("\n\n\tInforme o nome a ser procurado: ");
    gets(nomeContato);
    gets(nomeContato);

    numeroContato = buscarContatoNome(agenda,nomeContato,&status);
    
    if(status == 1){
        printf("\n\n====|Contato encontrado:|====\n\n");
        printf("\n\n====|Nome: %s\n====|Número: %s\n\n", nomeContato, numeroContato);
    }else
        printf("\n\n====|ERRO: Telefone não encontrado!|====\n\n");
}

void buscarContatoPeloNumero(TAgenda agenda){
    
    int status = 0;
    char numeroContato[50];
    char *nomeContato;
    
    printf("\n======|BUSCAR CONTATO PELO NOME|======");
    
    printf("\n\n\tInforme o nome a ser procurado: ");
    gets(numeroContato);
    gets(numeroContato);

    nomeContato = buscarContatoNumero(agenda,numeroContato,&status);
    
    if(status == 1){
        printf("\n\n====|Contato encontrado:|====\n\n");
        printf("\n\n====|Nome: %s\n====|Número: %s\n\n", nomeContato, numeroContato);
    }else
        printf("\n\n====|ERRO: Telefone não encontrado!|====\n\n");
}

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");

    int indice;
	
	TAgenda agenda;
	
	inicializaAgenda(&agenda);

    do{
        //MENU INICIAL
    	
    	printf("\n\n\n===========================|Bem Vindo à sua Agenda|===========================");
        //OPÇÕES DO MENU
    		
    		printf("\n\nServiços disponíveis:\n"
    				"1 - Adicionar pessoa com contato na Agenda\n"
    				"2 - Adicionar contato de uma pessoa na Agenda\n"
    				"3 - Retirar pessoa da Agenda e exibí-lo\n"
    				"4 - Retirar telefone de contato da Agenda\n"
                    "5 - Buscar pessoa pelo nome na Agenda\n"
                    "6 - Buscar pessoa na Agenda pelo número de telefone\n"
                    "7 - Exibir agenda\n"
    				"0 - Sair do programa\n");
    				
    		printf("\n\nPor favor, digite o serviço que necessita: ");			
    		scanf("%d", &indice);
    		
    		if(indice < 0 || indice > 7){
    		
    			do{
    				
    				printf("\n\nERRO: número inválido!\n"
    				"Por favor, digite o serviço que necessita baseado no menu apresentado: ");	//Verifica a integridade do scanf dentro dos padrões apresentados
    				scanf("%d", &indice);
    				
    			}while(indice < 0 || indice > 7);
    			
    		}
    
        switch(indice){
    
            case 1:
                incluirContato(&agenda);
            break;

            case 2:
                incluirTelefone(&agenda);
            break;

            case 3:
                excluirContato(&agenda);
            break;

            case 4:
                excluirTelefoneContato(&agenda);
            break;

            case 5:
                buscarContatoPeloNome(agenda);
            break;

            case 6:
                buscarContatoPeloNumero(agenda);
            break;

            case 7:
                exibeAgenda(agenda);
            break;
                
            default:
                printf("\n\n====|Você optou por sair do programa|====\n");
        }
        
    }while(indice != 0);
    
	return 0;
}
