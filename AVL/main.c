#include "funcao.c"

main() {
	int opcao, codigoLivro;
	Avl *arvoreLivros, *aux;
	Livro dadoLivros;

	arvoreLivros=inicializarArvore(arvoreLivros);
	aux=inicializarArvore(aux);

	do {
		system("cls");
		printf("\t\t\t\t Menu Arvores Binarias \n");
		printf("\t\t\t1- Inserir       \t\t2- Eliminar\n");
		printf("\t\t\t3- Calcular altura \t\t4- Procurar\n");
		printf("\t\t\t5- Imprimir       \t\t0- Sair\n");
		printf("\t\t\tR:_");
		scanf("%d",&opcao);
		switch(opcao) {
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

				break;
			case 2:// Eliminar
				printf("\t\t\tInsira o código do livro: ");
				scanf("%d",&codigoLivro);
				//aux=busca(arvoreLivros, codigoLivro);
				//Eliminar(aux);
				break;
			case 3: //Calcular altura
				break;
			case 4: //Procurar
				printf("\t\t\tInsira o código do livro: ");
				scanf("%d",&codigoLivro);
				aux=busca(arvoreLivros, codigoLivro);
				if(aux!=NULL)
					imprimir(aux);
				break;
			case 5: //Imprimir
				printf("\t\t\tLirvos Armazenados\n");
				imprimir(arvoreLivros);
				break;
			case 0:
				printf("\t\t\t Terminar Operações");
				system("Pause");
				break;
			default:
				printf("\t\t\tOpcao Inválida");
				system("pause");
				break;
		}
	} while(opcao!=0);
	return 0;
}