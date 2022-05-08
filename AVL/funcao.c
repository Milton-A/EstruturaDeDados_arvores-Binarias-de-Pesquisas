 #include "declaracao.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct livro{
	int codigo;
	char autor[100];
	char titutlo[100];
};

struct avl{
	Livro dados_do_livro;
	int nivel;
	Avl *esquerda, *direita;
};

// Operacoes de AVL
void imprimir(Avl *arvore){ //
	if(arvore!=NULL){
		imprimir(arvore->esquerda);
		printf("[Autor]: %s [Livro]: %s [código]: %d \n",arvore->dados_do_livro.autor,arvore->dados_do_livro.titutlo,arvore->dados_do_livro.codigo);
		imprimir(arvore->direita);
	}
}
int altura(Avl *arvore){
	Avl *aux = arvore;
	int esquerda,direita;
	if(aux!=NULL||aux->direita!=NULL||aux->esquerda!=NULL)
		return 0;
	else{
		esquerda= 1+altura(aux->esquerda);
		direita= 1+altura(aux->direita);
		return (esquerda-direita);		
	}
	
}

Avl *inserirRaiz(Avl *arvore,Livro dados){
	Avl *aux = (Avl *) malloc(sizeof(Avl));
	if(aux){
		strcpy(aux->dados_do_livro.autor,dados.autor);
		strcpy(aux->dados_do_livro.autor,dados.autor);
		aux->dados_do_livro.codigo = dados.codigo;
		aux->direita = NULL;
		aux->esquerda = NULL;
		return aux; 
	}
	else
		printf("Não foi possível alocar memória");
	return arvore;
}
void inserirfilhos(Avl *arvore,Livro dados){
	Avl *aux = arvore,*aux1= (Avl *) malloc(sizeof(Avl));
	if(aux->dados_do_livro.codigo>dados.codigo){
		if(aux->direita!=NULL)
			inserirfilhos(aux->direita,dados);
		else{
			strcpy(aux1->dados_do_livro.autor,dados.autor);
			strcpy(aux1->dados_do_livro.autor,dados.autor);
			aux1->dados_do_livro.codigo = dados.codigo;
			aux1->direita = NULL;
			aux1->esquerda = NULL;
			aux->direita=aux1;
			free(aux1);
		}
			
	}
	else if(aux->dados_do_livro.codigo<dados.codigo){
		if(aux->direita!=NULL)
			inserirfilhos(aux->esquerda,dados);
		else{
			strcpy(aux1->dados_do_livro.autor,dados.autor);
			strcpy(aux1->dados_do_livro.autor,dados.autor);
			aux1->dados_do_livro.codigo = dados.codigo;
			aux1->direita = NULL;
			aux1->esquerda = NULL;
			aux->esquerda=aux1;
			free(aux1);
		}
	}
	
}

void removerElemento(Avl *arvore,Livro dados){
	
}