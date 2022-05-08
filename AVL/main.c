#include "funcao.c"

main() {
	int opcao;
	Avl *arvoreLivros;
	Livro dadoLivros;
	
	inicializarArvore(arvoreLivros);
	
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
				printf("Insira o nome do Autor: ");
				gets(dadoLivros.autor);
				printf("Insira o Titulo do Livro: ");
				gets(dadoLivros.titutlo);
				printf("Insira o codigo do Livro");
				scanf("%d",&dadoLivros.codigo);
				break;
			case 2:// Eliminar
				break;
			case 3: //Calcular altura
				break;
			case 4: //Procurar
				break;
			case 5: //Imprimir
				break;
			default:
				printf("Opcao Inválida");
				system("pause");
				break;
		}
	} while(opcao!=0);
	return 0;
}