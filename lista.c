#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

void inicializaAgenda(TAgenda *agenda){
	
	agenda->inic = NULL;
	agenda->fim = NULL;
	agenda->total = 0;
	
}

int insereContato(TAgenda *agenda, char nomeElem[], char numero[]){
	
	TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
	TElemento *atual = NULL;
	TElemento *anterior;
	int status = 0;
	
	strcpy(novo->nome,nomeElem);
    strcpy(novo->numero,numero);
	novo->prox = NULL;
	
	if(agenda->inic == NULL){
		//LISTA VAZIA
		
		agenda->inic = novo;
		agenda->fim = novo;
		agenda->total++;
		status = 1;
		
	}else{
		
		atual = agenda->inic;
		anterior = NULL;
		
		while(atual != NULL){
			
			if (strcmp(atual->nome, novo->nome) > 0){
				
				novo->prox = atual;
				
				if(anterior == NULL)
					agenda->inic = novo;
				else
					anterior->prox = novo;
					
				status = 1;
                agenda->total++;
				atual = NULL; // interrompe o while sem usar break.
			}else if(strcmp(atual->nome, novo->nome) == 0){
                printf("\n\n===|Contato jÃ¡ existe em sua agenda!|===\n\n"
                       "\n===|O nÃºmero dele Ã©: %s|===\n", atual->numero);
                return status = 2;
            }
			anterior = atual;
			
			if(atual != NULL)
				atual = atual->prox;
		}
		
		if(status == 0){
			
			agenda->fim->prox = novo;
			agenda->fim = novo;
            agenda->total++;
            status = 1;
		}
	}
    
    return status;
}

char *insereTelefone(TAgenda *agenda,char nomeElem[], char numero[],int *status){
	
	TElemento *atual = NULL;
	char *numeroRetornado = (char*)malloc(50*sizeof(char));
    
	if (agenda->inic == NULL){
	    printf("\n\n===|Sua Agenda estÃ¡ vazia|===\n\n");
		
	}else{
		
		atual = agenda->inic;
		
		while(atual != NULL){
			
			if (strcmp(atual->nome, nomeElem) == 0){
				
				if(strlen(atual->numero) == 0){

                    strcpy(atual->numero,numero);
                    *status = 1;
                }else{
                    *status = 2;
                    strcpy(numeroRetornado,numero);
                }
				atual = NULL; // interrompe o while sem usar break.
			}
            if(atual != NULL)
                atual = atual->prox;
               
		}
		if(status == 0)
             printf("\nERRO: Pessoa nÃ£o encontrada!\n");
        

	}

    return numeroRetornado;
}

void excluiContato(TAgenda *agenda, char nomeElem[]){
	
	TElemento *atual, *anterior;
	int excluido = 0;
	char numero[50];
    
	atual = agenda->inic;
	anterior = NULL;
    
    
	if(agenda->inic == NULL)
	    printf("\n\n===|Sua Agenda está vazia|===\n\n");
    
	while(atual != NULL){
		
		if(strcmp(atual->nome, nomeElem) == 0){
			
			excluido = 1;
			strcpy(numero,atual->numero);
            
			if(anterior == NULL)
				agenda->inic = atual->prox;
			else
				anterior->prox = atual->prox;
				
			if(atual == agenda->fim)
				agenda->fim = NULL;
			free(atual);
			atual = NULL;
		}
		
		anterior = atual;
		
		if(atual != NULL)
			atual = atual->prox;
		
	}
	
	//free(atual);
	
	if(excluido == 1)
		printf("\nPessoa '%s' e telefone '%s' excluídos com sucesso!\n", nomeElem,numero);
	else
		printf("\nPessoa não encontrada!\n");

    //return excluido;
}

int excluiTelefone(TAgenda *agenda, char nomeContato[]){
	
	TElemento *atual;
	int excluido = 0;
	
	atual = agenda->inic;
    
	if(agenda->inic == NULL)
	    printf("\n\n===|Sua Agenda está vazia|===\n\n");
        
	while(atual != NULL){
		
		if(strcmp(atual->nome, nomeContato) == 0){
            
            excluido = 1;
            printf("\n\nO número %s do(a) %s foi excluído com sucesso!\n\n", atual->numero, atual->nome);
            strcpy(atual->numero,"\0");
            atual = NULL;
            
		}
	
		if(atual != NULL)
			atual = atual->prox;
	}
        
	return excluido;
}

void exibeAgenda(TAgenda agenda){
	
	TElemento *atual = agenda.inic;
	
	printf("\n\n\n======|SUA AGENDA|======: \n\n\n");
	
	while(atual != NULL){
		printf("Contato: %s\n", atual->nome);
        printf("NÃºmero: %s\n\n", atual->numero);
		atual = atual->prox;
	}
	
	printf("\n======|Fim da Agenda|======\n");
}

char *buscarContatoNome(TAgenda agenda, char nomeElem[], int *status){
    
    TElemento *atual = NULL;
	char *numeroRetornado = (char *)malloc(50 *sizeof(char));
    
	if(agenda.inic == NULL){
	    printf("\n\tSua Agenda estÃ¡ vazia\n");
		
	}else{
		
		atual = agenda.inic;
		
		while(atual != NULL){
			
			if (strcmp(atual->nome, nomeElem) == 0){
                
                *status = 1;
                strcpy(numeroRetornado, atual->numero);
                atual = NULL;
                
            }
            if(atual != NULL)
                atual = atual->prox;
        }
    }
    return numeroRetornado;
}

char *buscarContatoNumero(TAgenda agenda, char numeroContato[], int *status){
    
    TElemento *atual = NULL;
    char *nomeRetornado = (char *)malloc(50 *sizeof(char));
	
	if(agenda.inic == NULL){
	    printf("\n\tSua Agenda estÃ¡ vazia\n");
		
	}else{
		
		atual = agenda.inic;
		
		while(atual != NULL){
			
			if (strcmp(atual->numero, numeroContato) == 0){
                
                *status = 1;
                strcpy(nomeRetornado, atual->nome);
                atual = NULL;
                
            }
            if(atual != NULL)
                atual = atual->prox;
        }
    }
    return nomeRetornado;

    }
