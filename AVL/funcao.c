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
	Avl *esquerda, *direita;
};

// Operações AVL
void imprimir(Avl *arvore){
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

Avl *busca(Avl *arvore, int valor){
	Avl *aux=arvore;
	if(aux!=NULL){
		//retorna quando o valor do código do nó for igual ao que procuramos
		if(aux->dados_do_livro.codigo==valor)
			return aux;
		else if(aux->dados_do_livro.codigo<valor)
			aux=busca(aux->esquerda,valor);
		else
			aux=busca(aux->direita,valor);
	}
	else{
		printf("Valor não encontrado...");
		system("pause");
	}
	return aux;
}

Avl *rotacao_esquerda(Avl *arvore){
	Avl *aux = arvore->esquerda;
	arvore->esquerda = aux->direita;
	aux->direita = arvore;
	return aux;
}
Avl *rotacao_direita(Avl *arvore){
	Avl *aux = arvore->direita;
	arvore->direita = aux->esquerda;
	aux->esquerda = arvore;
	return aux;
}

Avl *dupla_rotacao_direita(Avl *arvore){
	Avl* aux=arvore;
	aux=rotacao_esquerda(aux);
	aux=rotacao_direita(aux);
	return aux;
}

Avl *dupla_rotacao_esquerda(Avl* arvore){
	Avl* aux=arvore;
	aux=rotacao_direita(aux);
	aux=rotacao_esquerda(aux);
	return aux;
}
Avl *equilibrar(Avl *arvore){
	int BF=altura(arvore);
	Avl* aux=arvore;
	if(BF< -1 && altura(aux) <=0)
		aux = rotacao_esquerda(aux);
	else if(BF<1 && altura(aux) <=0)
		aux = rotacao_direita(aux);
	else if(BF<-1 && altura(aux) <0)
		aux = dupla_rotacao_esquerda(aux);
	else if(BF>1 && altura(aux) >0)
		aux = dupla_rotacao_direita(aux);
	return aux;
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
Avl *inserirFilhos(Avl *arvore,Livro dados){
	Avl *aux = arvore,*aux1= (Avl *) malloc(sizeof(Avl));
	if(aux){
		if(aux->dados_do_livro.codigo>dados.codigo){
			if(aux->direita!=NULL)
				inserirFilhos(aux->direita,dados);
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
				inserirFilhos(aux->esquerda,dados);
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
	}else{
		return arvore;
	}
	return equilibrar(aux);
}
Avl *eliminar(Avl *arvore){
	Avl *aux=arvore,*aux1= (Avl *) malloc(sizeof(Avl));

	if(aux!=NULL){
		//Eliminar nós que não têm filhos(a esquerda e a direita)
		if(aux->direita==NULL && aux->esquerda==NULL){
				free(aux);
				return aux;
			}
		else if(aux->direita!=NULL && aux->esquerda==NULL ){
			aux1=aux->direita;
			aux1->esquerda=aux;
			free(aux);
			return equilibrar(aux);;
		}
		else if(aux->direita==NULL && aux->esquerda!=NULL ){
			aux1=aux->esquerda;
			aux1->direita=aux;
			free(aux);
			return equilibrar(aux);;

		}	
	}
	return aux;
}