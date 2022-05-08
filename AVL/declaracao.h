// Declação AVL
typedef struct livro Livro;
typedef struct avl Avl;
//Operações Equilibrar AVL
Avl *rotacao_esquerda(Avl *arvore);
Avl *rotacao_direita(Avl *arvore);
Avl *dupla_rotacao_direita(Avl *arvore);
Avl *dupla_rotacao_esquerda(Avl* arvore);
Avl *equilibrar(Avl *arvore);
int altura(Avl *arvore);
//Operações Basicas AVL
Avl *inserirRaiz(Avl *arvore,Livro dados);
Avl *inserirFilhos(Avl *arvore,Livro dados);
Avl *eliminar(Avl *arvore);
void imprimir(Avl *arvore);
Avl *busca(Avl *arvore, int valor);