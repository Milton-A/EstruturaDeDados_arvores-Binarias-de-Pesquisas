#include "funcao.c"
<<<<<<< HEAD
#include <stdio.h>
main() {
	int opcao, codigoLivro;
	Avl *arvorelivros, *aux;
	Livro dadolivros;
	int codigo,cont=0;
=======

int main() {
	int opcao, codigoLivro;
	Avl *arvoreLivros, *aux;
	Livro dadoLivros;

	arvoreLivros=inicializarArvore();
	aux=inicializarArvore();
>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3

	arvorelivros=inicializarArvore();
	do {
		aux=inicializarArvore();
		system("cls");
		printf("\t\t\t\t Menu Arvores Binarias \n");
		printf("\t\t\t1- Inserir       \t\t2- Eliminar\n");
		printf("\t\t\t3- Calcular altura \t\t4- Procurar\n");
		printf("\t\t\t5- Imprimir em pós-ordem       \t\t6- Imprimir em pré-ordem\n");
		printf("\t\t\t7- Imprimir em ordem       \t\t8- Calcular a distância\n");
		printf("\t\t\t9- Maior elemento       \t\t10- Menor elemento\n");
		printf("\t\t\t11- Sucessor       \t\t12- Sair\n");
		printf("\t\t\tR:_ ");
		fflush(stdin);
		scanf("%d",&opcao);
		switch(opcao) {
<<<<<<< HEAD
=======
			case 1: //Inserir
				fflush(stdin);
				printf("\t\t\tInsira o nome do Autor: ");
				gets(dadoLivros.autor);
				fflush(stdin);
				printf("\t\t\tInsira o Titulo do Livro: ");
				gets(dadoLivros.titutlo);
				fflush(stdin);
				printf("\t\t\tInsira o codigo do Livro");
				scanf("%d",&dadoLivros.codigo);
			arvoreLivros=	insere(arvoreLivros, dadoLivros);
				break;
			case 2:// Eliminar
				printf("\t\t\tInsira o cÃ³digo do livro: ");
				scanf("%d",&codigoLivro);
				//aux=busca(arvoreLivros, codigoLivro);
				//Eliminar(aux);
				break;
			case 3: //Calcular altura
				break;
			case 4: //Procurar
				printf("\t\t\tInsira o cÃ³digo do livro: ");
				scanf("%d",&codigoLivro);
				aux=busca(arvoreLivros, codigoLivro);
				if(aux!=NULL)
					imprimir(aux);
				break;
			case 5: //Imprimir
				printf("\t\t\tLirvos Armazenados\n");
				imprimir(arvoreLivros);
				system("pause");
				break;
>>>>>>> d45e014fb0f707a5fb269bb36a24035e22e450d3
			case 0:
				printf("\t\t\t Terminar OperaÃ§Ãµes");
				system("Pause");
				break;
			case 1: //Inserir
				fflush(stdin);
				printf("\t\t\tInsira o nome do Autor: ");
				gets(dadolivros.autor);
				fflush(stdin);
				printf("\t\t\tInsira o Titulo do Livro: ");
				gets(dadolivros.titulo);
				fflush(stdin);
				printf("\t\t\tInsira o codigo do Livro: ");
				scanf("%d",&dadolivros.codigo);
				if(arvorelivros==NULL)
					arvorelivros=inserirRaiz(arvorelivros,dadolivros);
				else{
				
					inserirfilhos(arvorelivros,dadolivros);
					arvorelivros=equilibrar(arvorelivros);
				}
				break;
			case 2:// Eliminar
				printf("\t\t\tInsira o cÃ³digo do livro: ");
				scanf("%d",&dadolivros.codigo);
				
				if(busca(arvorelivros, dadolivros.codigo)!=NULL)
					arvorelivros=Eliminar(arvorelivros, dadolivros.codigo);
				if(arvorelivros!=NULL)
				arvorelivros==equilibrar(arvorelivros);
				break;
			case 3: //Calcular altura
				fflush(stdin);
				printf("\t\t\tInsira o cÃ³digo do livro: ");
				scanf("%d",&dadolivros.codigo);
				aux=busca(arvorelivros, dadolivros.codigo);
				if(aux!=NULL)
					printf("A altura deste nó é %d ",alturadeumno(arvorelivros,aux));
				else
					printf("O código digitado não existe!!");
				system("pause");	
				break;
			case 4: //Procurar
				fflush(stdin);
				printf("\t\t\tInsira o cÃ³digo do livro: ");
				scanf("%d",&dadolivros.codigo);
				aux=busca(arvorelivros, dadolivros.codigo);
				if(aux!=NULL)
					imprimirno(aux);
				system("pause");
				break;
			case 5: //Imprimir
				printf("\t\t\tLirvos Armazenados\n");
				imprimir(arvorelivros);
				system("pause");
				break;
			case 6:
				printf("\t\t\tLirvos Armazenados\n");
				imprimirpreordem(arvorelivros);
				system("pause");
				break;
			case 7:
				printf("\t\t\tLirvos Armazenados\n");
				imprimirposordem(arvorelivros);
				system("pause");
				break;
			case 8://Menor elemento da árvore
				fflush(stdin);
				printf("\t\t\tInsira o cÃ³digo do livro: ");
				scanf("%d",&dadolivros.codigo);
				fflush(stdin);
				printf("\t\t\tInsira o cÃ³digo do livro: ");
				scanf("%d",&codigo);
				distancia(arvorelivros,dadolivros.codigo,codigo);
				system("pause");
				break;
			case 9://Maior elemento da árvore
				fflush(stdin);
				aux=maximo(arvorelivros);
				printf("O maior elemento da árvore é ");
				if(aux!=NULL)
					imprimirno(aux);	
				system("pause");
				break;
			case 10://Menor elemento da árvore
				fflush(stdin);
				aux=minimo(arvorelivros);
				printf("O menor elemento da árvore é ");
				if(aux!=NULL)
					imprimirno(aux);	
				system("pause");
				break;
			case 11: //Sucessor
				fflush(stdin);
				printf("\t\t\tInsira o cÃ³digo do livro: ");
				scanf("%d",&dadolivros.codigo);
				aux=busca(arvorelivros, dadolivros.codigo);
				//aux=sucessor(arvorelivros,aux,arvorelivros->dados_do_livro.codigo-aux->dados_do_livro.codigo);
				if(aux!=NULL&&aux->dados_do_livro.codigo!=dadolivros.codigo){
					printf("O sucessor de %d é ",aux->dados_do_livro.codigo);
					imprimirno(aux);
				}
				else
					printf("Não existe o sucessor de %d na árvore ",dadolivros.codigo);
				system("pause");
				break;
			default:
				printf("\t\t\tOpcao InvÃ¡lida");
				system("pause");
				break;
		}
	} while(opcao!=0);
	return 0;
}
