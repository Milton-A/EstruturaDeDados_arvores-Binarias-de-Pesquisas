typedef struct livro Livro;
typedef struct avl Avl;
void imprimir(Avl *arvore);
int altura(Avl *arvore);
Avl *inserirRaiz(Avl *arvore,Livro dados);
Avl *inserirfilhos(Avl *arvore,Livro dados);

