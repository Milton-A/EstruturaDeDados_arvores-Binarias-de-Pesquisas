#include "declaracao.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct livro {
	int codigo;
	char autor[100];
	char titutlo[100];
};

struct avl {
	Livro dados_do_livro;
	int altura; //distância até a folha
	Avl *esquerda, *direita;
};

Avl *inicializarArvore() {
	return NULL;
}
void imprimir(Avl *arvore) {
	if(arvore!=NULL) {
		imprimir(arvore->esquerda);
		printf("[Autor]: %s [Livro]: %s [código]: %d \n",arvore->dados_do_livro.autor,arvore->dados_do_livro.titutlo,arvore->dados_do_livro.codigo);
		imprimir(arvore->direita);
	}
}
int bf(Avl *arvore) {
	Avl *aux = arvore;
	int esquerda,direita;
	if(aux!=NULL||aux->direita!=NULL||aux->esquerda!=NULL)
		return 0;
	else {
		esquerda= 1+altura(aux->esquerda);
		direita= 1+altura(aux->direita);
		return (esquerda-direita);
	}
}/*
int altura(Avl *arvore){
	Avl *aux = arvore;
	int esquerda,direita;
	if(aux!=NULL||aux->direita!=NULL||aux->esquerda!=NULL)
		return 0;
	else{
		esquerda= 1+altura(aux->esquerda);
		direita= 1+altura(aux->direita);
		return direita>esquerda ? direita:esquerda;
	}
}*/
Avl *buscamenorelemento(Avl *arvore) {
	Avl *aux=arvore;
	if(aux->esquerda!=NULL)
		aux=buscamenorelemento(aux->esquerda);
	else
		return aux;
}
Avl *busca(Avl *arvore, int valor) {
	Avl *aux=arvore;
	if(aux!=NULL) {
		//retorna quando o valor do código do nó for igual ao que procuramos
		if(aux->dados_do_livro.codigo==valor)
			return aux;
		else if(aux->dados_do_livro.codigo<valor)
			aux=busca(aux->esquerda,valor);
		else
			aux=busca(aux->direita,valor);
	} else {
		printf("Valor não encontrado...");
		system("pause");
	}
	return aux;
}

Avl *rotacao_esquerda(Avl *arvore) {
	Avl *aux = arvore->esquerda;
	arvore->esquerda = aux->direita;
	aux->direita = arvore;
	return aux;
}
Avl *rotacao_direita(Avl *arvore) {
	Avl *aux = arvore->direita;
	arvore->direita = aux->esquerda;
	aux->esquerda = arvore;
	return aux;
}

Avl *dupla_rotacao_direita(Avl *arvore) {
	Avl* aux=arvore;
	aux=rotacao_esquerda(aux);
	aux=rotacao_direita(aux);
	return aux;
}

Avl *dupla_rotacao_esquerda(Avl* arvore) {
	Avl* aux=arvore;
	aux=rotacao_direita(aux);
	aux=rotacao_esquerda(aux);
	return aux;
}
Avl *equilibrar(Avl *arvore) {
	int BF=bf(arvore);
	Avl* aux=arvore;
	if(BF< -1 && bf(aux) <=0)
		aux = rotacao_esquerda(aux);
	else if(BF<1 && bf(aux) <=0)
		aux = rotacao_direita(aux);
	else if(BF<-1 && bf(aux) <0)
		aux = dupla_rotacao_esquerda(aux);
	else if(BF>1 && bf(aux) >0)
		aux = dupla_rotacao_direita(aux);
	return aux;
}
/*
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
Avl *inserirfilhos(Avl *arvore,Livro dados){
	Avl *aux = arvore,*aux1= (Avl *) malloc(sizeof(Avl));
	if(aux){
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
	}else{
		return arvore;
	}
	return equilibrar(aux);
}*/

Avl *Eliminar(Avl *arvore) {
	Avl *aux=arvore,*aux1= NULL;

	if(aux!=NULL) {
		//Eliminar nós que não têm filhos(a esquerda e a direita)
		if(aux->direita==NULL && aux->esquerda==NULL) {
			free(aux);
			return NULL;
		} else if(aux->direita!=NULL && aux->esquerda==NULL ) {
			aux1=aux->direita;
			aux1->esquerda=aux;
			free(aux);
			return equilibrar(aux1);;
		} else if(aux->direita==NULL && aux->esquerda!=NULL ) {
			aux1=aux->esquerda;
			aux1->direita=aux;
			free(aux);
			return equilibrar(aux1);

		} else {
			aux1=buscamenorelemento(aux->direita);
			strcpy(aux->dados_do_livro.autor,aux1->dados_do_livro.autor);
			strcpy(aux->dados_do_livro.autor,aux1->dados_do_livro.autor);
			aux->dados_do_livro.codigo = aux1->dados_do_livro.codigo;
			free(aux1);
			return equilibrar(aux);
		}
	}
	return aux;
}/*
void distancia(Avl *arvore,int valor, int valor1){
	Avl *aux=busca(arvore,valor),*aux1=busca(arvore,valor1);
	int d,h1,h2;
	if(aux!=NULL && aux1!=NULL){
		if(aux->direita==aux1||aux1->direita==aux||aux->esquerda==aux1||aux1->esquerda==aux)
			printf("A distância de %d a %d é 1",valor,valor1);
		else{
			h1=altura(aux);
			h2=altura(aux1);
			d= h1+h2-1;
			printf("A distância de %d a %d é %d",valor,valor1,d);

		}
	}
}
*/




//  Código de teste Milton

Avl * insere(Avl *arvore, Livro lvr ) {
	int info=lvr.codigo;
	if( arvore == NULL ) {
		arvore = aloca(info);
	} else if( lvr.codigo < arvore->dados_do_livro.codigo) {
		arvore->esquerda = insere( arvore->esquerda, lvr );
		if( altura( arvore->esquerda ) - altura( arvore->direita ) == 2 ) {
			if( lvr.codigo < arvore->esquerda->dados_do_livro.codigo )
				arvore = rotacao_direita(arvore);
			else
				arvore = rotacao_esquerda(arvore);
		}
	} else if( lvr.codigo > arvore->dados_do_livro.codigo ) {
		arvore->direita = insere( arvore->direita, lvr );
		if( altura( arvore->direita ) - altura( arvore->esquerda ) == 2 ) {
			if( lvr.codigo > arvore->direita->dados_do_livro.codigo )
				arvore = rotacao_esquerda(arvore);
			else
				arvore = rotacao_direita(arvore);
		}
	}
	return arvore;
}
Avl * aloca(int info) {
	Avl *arv;
	arv = (Avl*)malloc(sizeof(Avl));
	arv->dados_do_livro.codigo = info;
	arv->altura = 0;
	arv->esquerda = arv->direita = NULL;
	return arv;
}
int altura (Avl *a) {
	if( a == NULL)
		return -1;
	return a->altura;
}

