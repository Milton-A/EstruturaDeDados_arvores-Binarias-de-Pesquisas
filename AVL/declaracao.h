// Declação AVL
typedef struct livro Livro;
typedef struct avl Avl;
//Operações Equilibrar AVL
int bf(Avl *arvore);
void distancia(Avl *arvore,int valor, int valor1);
int altura(Avl *arvore);
Avl *busca(Avl *arvore, int valor);
Avl *rotacao_esquerda(Avl *arvore);
Avl *rotacao_direita(Avl *arvore);
Avl *dupla_rotacao_direita(Avl *arvore);
Avl *dupla_rotacao_esquerda(Avl* arvore);
Avl *equilibrar(Avl *arvore);
//Operações Basicas AVL
void inicializarArvore(Avl *arvore);
Avl *inserirRaiz(Avl *arvore,Livro dados);
Avl *inserirfilhos(Avl *arvore,Livro dados);
Avl *Eliminar(Avl *arvore);
void imprimir(Avl *arvore);