#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct tipoElemento{
	
	char nome[50];
    char numero[50];
    
	struct tipoElemento *prox;
	
}TElemento;

typedef struct tipoAgenda{
	
	TElemento *inic, *fim;
	int total;
	
}TAgenda;

void inicializaAgenda(TAgenda *agenda);

int insereContato(TAgenda *agenda, char nomeElem[], char numero[]);

char *insereTelefone(TAgenda *agenda,char nomeElem[], char numero[], int *status);

void excluiContato(TAgenda *agenda, char nomeElem[]);

int excluiTelefone(TAgenda *agenda, char numero[]);

void exibeAgenda(TAgenda agenda);

char *buscarContatoNome(TAgenda agenda, char nomeElem[], int *status);

char *buscarContatoNumero(TAgenda agenda, char numeroContato[], int *status);