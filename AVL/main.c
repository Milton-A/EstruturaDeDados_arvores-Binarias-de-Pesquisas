#include "funcao.c"
#include <stdio.h>
main() {
	int opcao, codigoLivro;
	Avl *arvorelivros, *aux;
	Livro dadolivros;
	int codigo,cont=0;

	arvorelivros=inicializarArvore();
	do {
		aux=inicializarArvore();
		system("cls");
		printf("\t\t\t\t Menu Arvores Binarias \n");
		printf("\t\t\t1- Inserir       \t\t2- Eliminar\n");
		printf("\t\t\t3- Calcular altura \t\t4- Procurar\n");
		printf("\t\t\t5- Imprimir em pÛs-ordem       \t\t6- Imprimir em prÈ-ordem\n");
		printf("\t\t\t7- Imprimir em ordem       \t\t8- Calcular a dist‚ncia\n");
		printf("\t\t\t9- Maior elemento       \t\t10- Menor elemento\n");
		printf("\t\t\t11- Sucessor       \t\t12- Sair\n");
		printf("\t\t\tR:_ ");
		fflush(stdin);
		scanf("%d",&opcao);
		switch(opcao) {
			case 0:
				printf("\t\t\t Terminar Opera√ß√µes");
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
				printf("\t\t\tInsira o c√≥digo do livro: ");
				scanf("%d",&dadolivros.codigo);
				
				if(busca(arvorelivros, dadolivros.codigo)!=NULL)
					arvorelivros=Eliminar(arvorelivros, dadolivros.codigo);
				if(arvorelivros!=NULL)
				arvorelivros==equilibrar(arvorelivros);
				break;
			case 3: //Calcular altura
				fflush(stdin);
				printf("\t\t\tInsira o c√≥digo do livro: ");
				scanf("%d",&dadolivros.codigo);
				aux=busca(arvorelivros, dadolivros.codigo);
				if(aux!=NULL)
					printf("A altura deste nÛ È %d ",alturadeumno(arvorelivros,aux));
				else
					printf("O cÛdigo digitado n„o existe!!");
				system("pause");	
				break;
			case 4: //Procurar
				fflush(stdin);
				printf("\t\t\tInsira o c√≥digo do livro: ");
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
			case 8://Menor elemento da ·rvore
				fflush(stdin);
				printf("\t\t\tInsira o c√≥digo do livro: ");
				scanf("%d",&dadolivros.codigo);
				fflush(stdin);
				printf("\t\t\tInsira o c√≥digo do livro: ");
				scanf("%d",&codigo);
				distancia(arvorelivros,dadolivros.codigo,codigo);
				system("pause");
				break;
			case 9://Maior elemento da ·rvore
				fflush(stdin);
				aux=maximo(arvorelivros);
				printf("O maior elemento da ·rvore È ");
				if(aux!=NULL)
					imprimirno(aux);	
				system("pause");
				break;
			case 10://Menor elemento da ·rvore
				fflush(stdin);
				aux=minimo(arvorelivros);
				printf("O menor elemento da ·rvore È ");
				if(aux!=NULL)
					imprimirno(aux);	
				system("pause");
				break;
			case 11: //Sucessor
				fflush(stdin);
				printf("\t\t\tInsira o c√≥digo do livro: ");
				scanf("%d",&dadolivros.codigo);
				aux=busca(arvorelivros, dadolivros.codigo);
				//aux=sucessor(arvorelivros,aux,arvorelivros->dados_do_livro.codigo-aux->dados_do_livro.codigo);
				if(aux!=NULL&&aux->dados_do_livro.codigo!=dadolivros.codigo){
					printf("O sucessor de %d È ",aux->dados_do_livro.codigo);
					imprimirno(aux);
				}
				else
					printf("N„o existe o sucessor de %d na ·rvore ",dadolivros.codigo);
				system("pause");
				break;
			default:
				printf("\t\t\tOpcao Inv√°lida");
				system("pause");
				break;
		}
	} while(opcao!=0);
	return 0;
}
