#include "declaracao.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct livro {
	int codigo;
	char autor[100];
	char titulo[100];
};

struct avl {
	Livro dados_do_livro;
	int altura; //dist√¢ncia at√© a folha
	Avl *esquerda, *direita;
};
<<<<<<< HEAD
Avl *inicializarArvore(){
	return NULL;
}
void imprimir(Avl *arvore){
	if(arvore!=NULL){
		printf("[Autor]: %s [Livro]: %s [cÛdigo]: %d \n",arvore->dados_do_livro.autor,arvore->dados_do_livro.titulo,arvore->dados_do_livro.codigo);
		imprimir(arvore->esquerda);
		imprimir(arvore->direita);
	}
}
void imprimirpreordem(Avl *arvore){
	if(arvore!=NULL){
		imprimirpreordem(arvore->esquerda);
		printf("[Autor]: %s [Livro]: %s [cÛdigo]: %d \n",arvore->dados_do_livro.autor,arvore->dados_do_livro.titulo,arvore->dados_do_livro.codigo);
		imprimirpreordem(arvore->direita);
	}
}
void imprimirposordem(Avl *arvore){
	if(arvore!=NULL){
		imprimirposordem(arvore->direita);
		printf("[Autor]: %s [Livro]: %s [cÛdigo]: %d \n",arvore->dados_do_livro.autor,arvore->dados_do_livro.titulo,arvore->dados_do_livro.codigo);
		imprimirposordem(arvore->esquerda);
	}
}
int bf(Avl *arvore){
=======

Avl *inicializarArvore() {
	return NULL;
}
void imprimir(Avl *arvore) {
	if(arvore!=NULL) {
		imprimir(arvore->esquerda);
		printf("[Autor]: %s [Livro]: %s [c√≥digo]: %d \n",arvore->dados_do_livro.autor,arvore->dados_do_livro.titutlo,arvore->dados_do_livro.codigo);
		imprimir(arvore->direita);
	}
}
int bf(Avl *arvore) {
>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3
	Avl *aux = arvore;
	int esquerda,direita;
	if(aux!=NULL){
			esquerda=altura(aux->esquerda);
			direita=altura(aux->direita);
		return esquerda-direita;	
		}
	else 
		return 0;
<<<<<<< HEAD
}
=======
	else {
		esquerda= 1+altura(aux->esquerda);
		direita= 1+altura(aux->direita);
		return (esquerda-direita);
	}
}/*
>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3
int altura(Avl *arvore){
	Avl *aux = arvore;
	int esquerda,direita;
	if(aux==NULL||aux->direita!=NULL&&aux->esquerda!=NULL)
		return 0;
	else{
		esquerda= 1+altura(aux->esquerda);
		direita= 1+altura(aux->direita);
<<<<<<< HEAD
		return direita>esquerda ? direita:esquerda;		
	}	
}
int alturadeumno(Avl *arvore, Avl* arvore1){
	Avl *aux = arvore;
	int cont;
	if(aux==NULL||arvore1==aux)
		return 0;
	else{
			if(aux->dados_do_livro.codigo>arvore1->dados_do_livro.codigo)
				cont= 1+alturadeumno(aux->esquerda,arvore1);
			else
				cont= 1+alturadeumno(aux->direita,arvore1);
			return cont;
		}
					
}
Avl *buscamenorelemento(Avl *arvore){
=======
		return direita>esquerda ? direita:esquerda;
	}
}*/
Avl *buscamenorelemento(Avl *arvore) {
>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3
	Avl *aux=arvore;
	if(aux->esquerda!=NULL)
		aux=buscamenorelemento(aux->esquerda);
	else
		return aux;
}
Avl *busca(Avl *arvore, int valor) {
	Avl *aux=arvore;
	if(aux!=NULL) {
		//retorna quando o valor do c√≥digo do n√≥ for igual ao que procuramos
		if(aux->dados_do_livro.codigo==valor)
			return aux;
		else if(aux->dados_do_livro.codigo>valor)
			aux=busca(aux->esquerda,valor);
		else
			aux=busca(aux->direita,valor);
	} else {
		printf("Valor n√£o encontrado...");
		system("pause");
	}
	return aux;
}

<<<<<<< HEAD
Avl *rotacao_direita(Avl *arvore){
=======
Avl *rotacao_esquerda(Avl *arvore) {
>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3
	Avl *aux = arvore->esquerda;
	arvore->esquerda = aux->direita;
	aux->direita = arvore;
	return aux;
}
<<<<<<< HEAD
Avl *rotacao_esquerda(Avl *arvore){
=======
Avl *rotacao_direita(Avl *arvore) {
>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3
	Avl *aux = arvore->direita;
	arvore->direita = aux->esquerda;
	aux->esquerda = arvore;
	return aux;
}

Avl *dupla_rotacao_direita(Avl *arvore) {
	Avl* aux=arvore;
	aux->direita=rotacao_direita(aux->direita);
	aux=rotacao_esquerda(aux);
	return aux;
}

Avl *dupla_rotacao_esquerda(Avl* arvore) {
	Avl* aux=arvore;
	aux->esquerda=rotacao_esquerda(aux->esquerda);
	aux=rotacao_direita(aux);
	return aux;
}
Avl *equilibrar(Avl *arvore) {
	int BF=bf(arvore);
	Avl* aux=arvore;
	if(BF< -1 && bf(aux->direita) <=0)
		aux=rotacao_direita(aux);
	else if(BF>1 && bf(aux->esquerda) >=0)
		aux=rotacao_direita(aux);
	else if(BF<-1 && bf(aux->direita) >0)
		aux=dupla_rotacao_direita(aux);
	else if(BF>1 && bf(aux->esquerda) <0)
		aux=dupla_rotacao_esquerda(aux);
	return aux;
}
/*
Avl *inserirRaiz(Avl *arvore,Livro dados){
	Avl *aux = (Avl *) malloc(sizeof(Avl));
	if(aux){
		strcpy(aux->dados_do_livro.autor,dados.autor);
		strcpy(aux->dados_do_livro.titulo,dados.titulo);
		aux->dados_do_livro.codigo = dados.codigo;
		aux->direita = NULL;
		aux->esquerda = NULL;
<<<<<<< HEAD
	}
	else
		printf("N„o foi possÌvel alocar memÛria");
	
=======
		return aux;
	}
	else
		printf("N√£o foi poss√≠vel alocar mem√≥ria");
	return arvore;
>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3
}
void inserirfilhos(Avl *arvore,Livro dados){
	Avl *aux = arvore,*aux1= (Avl *) malloc(sizeof(Avl));
	if(aux){
		if(aux->dados_do_livro.codigo<dados.codigo){
			if(aux->direita!=NULL)
				inserirfilhos(aux->direita,dados);
			else{
				strcpy(aux1->dados_do_livro.autor,dados.autor);
				strcpy(aux1->dados_do_livro.titulo,dados.titulo);
				aux1->dados_do_livro.codigo = dados.codigo;
				aux1->direita = NULL;
				aux1->esquerda = NULL;
				aux->direita=aux1;
<<<<<<< HEAD
				aux=equilibrar(aux);
				
=======
				free(aux1);

>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3
			}

		}
		else if(aux->dados_do_livro.codigo>dados.codigo){
			if(aux->esquerda!=NULL)
				inserirfilhos(aux->esquerda,dados);
			else{
				strcpy(aux1->dados_do_livro.autor,dados.autor);
				strcpy(aux1->dados_do_livro.titulo,dados.titulo);
				aux1->dados_do_livro.codigo = dados.codigo;
				aux1->direita = NULL;
				aux1->esquerda = NULL;
				aux->esquerda=aux1;
<<<<<<< HEAD
				aux=equilibrar(aux);
				
				
=======
				free(aux1);

>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3
			}
		}
	}
<<<<<<< HEAD
}
void imprimirno(Avl* arvore){
	printf("[Autor]: %s [Livro]: %s [cÛdigo]: %d \n",arvore->dados_do_livro.autor,arvore->dados_do_livro.titulo,arvore->dados_do_livro.codigo);
}
Avl *Eliminar(Avl *arvore,int valor){
	Avl *aux=arvore,*aux1= NULL;

	if(aux!=NULL){
		if(aux->dados_do_livro.codigo!=valor){
			if(aux->dados_do_livro.codigo>valor)
				aux->esquerda=Eliminar(aux->esquerda,valor);
			else if(aux->dados_do_livro.codigo<valor)
				aux->direita=Eliminar(aux->direita,valor);
		}else  {
			//Eliminar nÛs que n„o tÍm filhos(a esquerda e a direita)
			if(aux->direita==NULL && aux->esquerda==NULL){
					free(aux);
					return NULL;
				}
			
			else if(aux->direita!=NULL && aux->esquerda==NULL ){
				aux1=aux->direita;
				aux1->esquerda=NULL;
				aux1->direita=NULL;
				free(aux);
				return equilibrar(aux1);
			}
			else if(aux->direita==NULL && aux->esquerda!=NULL ){
				aux1=aux->esquerda;
				aux1->direita=NULL;
				aux1->esquerda=NULL;
				free(aux);
				return equilibrar(aux1);
	
			}else{
				aux1=buscamenorelemento(aux->direita);
				Livro v=aux1->dados_do_livro;
				aux=Eliminar(aux,v.codigo);
				strcpy(aux->dados_do_livro.autor,v.autor);
				strcpy(aux->dados_do_livro.titulo,v.titulo);
				aux->dados_do_livro.codigo =v.codigo;
				return equilibrar(aux);
			}
		}	
	}
}
Avl *minimo(Avl *Arvore){
	Avl *aux= Arvore;
	if(aux->esquerda!=NULL)
		aux=minimo(aux->esquerda);
	else
		return aux;
}
Avl *maximo(Avl *Arvore){
	Avl *aux= Arvore;
	if(aux->direita!=NULL)
		aux=maximo(aux->direita);
	else
		return aux;
}
Avl *sucessor(Avl *arvore, Avl *arvore1,int valor){
	Avl *aux=arvore,*aux1=arvore1,*aux2=arvore; 
	if(aux1->direita!=NULL){
		aux2=minimo(aux->direita);
		return aux2;
	}
	else{
	
		if(aux1->dados_do_livro.codigo<aux->dados_do_livro.codigo){
			if(aux1->dados_do_livro.codigo-aux->dados_do_livro.codigo&&aux1->dados_do_livro.codigo>aux->dados_do_livro.codigo<valor){
				valor=aux1->dados_do_livro.codigo-aux->dados_do_livro.codigo;
				aux2=aux;
			}
			if(aux->esquerda!=NULL)
				aux2=sucessor(aux->esquerda,aux1,valor);
		}
		else{	
			if(aux1->dados_do_livro.codigo-aux->dados_do_livro.codigo&&aux1->dados_do_livro.codigo>aux->dados_do_livro.codigo<valor){
				valor=aux1->dados_do_livro.codigo-aux->dados_do_livro.codigo;
				aux2=aux;
			}
			if(aux->direita!=NULL)
				aux2=sucessor(aux->direita,aux1,valor);
=======
	return equilibrar(aux);
}*/

Avl *Eliminar(Avl *arvore) {
	Avl *aux=arvore,*aux1= NULL;

	if(aux!=NULL) {
		//Eliminar n√≥s que n√£o t√™m filhos(a esquerda e a direita)
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
			printf("A dist√¢ncia de %d a %d √© 1",valor,valor1);
		else{
			h1=altura(aux);
			h2=altura(aux1);
			d= h1+h2-1;
			printf("A dist√¢ncia de %d a %d √© %d",valor,valor1,d);

>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3
		}
	}
		return aux2;
	
}

void distancia(Avl *arvore,int valor, int valor1){
	
	Avl *aux2=arvore, *aux=busca(aux2,valor),*aux1=busca(aux2,valor1);
	int d,h1,h2;
	if(aux!=NULL && aux1!=NULL){
			
		if(arvore->dados_do_livro.codigo<valor && arvore->dados_do_livro.codigo<valor1){
			distancia(aux2->direita,valor,valor1);	
					printf("s„o maiores");
		}else if(arvore->dados_do_livro.codigo>valor&&arvore->dados_do_livro.codigo>valor1){
		
			distancia(aux2->esquerda,valor,valor1);
				printf("s„o menores");
		}else{
			d= alturadeumno(aux2,aux1)+alturadeumno(aux2,aux) ;
			printf("A dist‚ncia de %d a %d È %d",valor,valor1,d);
			}
	}
	else
		printf("Um dos cÛdigos digitados n„o existe!!");	
}
*/




//  C√≥digo de teste Milton

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

