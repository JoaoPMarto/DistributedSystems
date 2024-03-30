#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "tree-private.h"

struct tree_t; /* A definir pelo grupo em tree-private.h */

/* Função para criar uma nova árvore tree vazia.
 * Em caso de erro retorna NULL.
 */
struct tree_t *tree_create() {
    struct tree_t* tree;

    tree = (struct tree_t*) malloc(sizeof(tree));

    if (tree == NULL) {
        return NULL;
    }

    tree->entry = NULL;
    tree->right = NULL;
    tree->left = NULL;

    return tree;
}

/* Função para libertar toda a memória ocupada por uma árvore.
 */
void tree_destroy(struct tree_t *tree) {
    if (tree == NULL) {
        return;
    } 

    entry_destroy(tree->entry);

    if (tree->right != NULL) {
        tree_destroy(tree->right);
    }
    if (tree->left != NULL) {
        tree_destroy(tree->left);
    }
}

/* Função para adicionar um par chave-valor à árvore.
 * Os dados de entrada desta função deverão ser copiados, ou seja, a
 * função vai *COPIAR* a key (string) e os dados para um novo espaço de
 * memória que tem de ser reservado. Se a key já existir na árvore,
 * a função tem de substituir a entrada existente pela nova, fazendo
 * a necessária gestão da memória para armazenar os novos dados.
 * Retorna 0 (ok) ou -1 em caso de erro.
 */
int tree_put(struct tree_t *tree, char *key, struct data_t *value) {
    
    if (key == NULL || value == NULL) {
        return -1;
    }

    struct entry_t *entry1 = (struct entry_t*) entry_create(key,value);
    
    if (tree == NULL) {
        tree->entry = entry_create(key, value);
        if (tree->entry == NULL) {
            return -1;
        }
        tree->right = NULL;
        tree->left = NULL;
        return 0;
    }

    if (entry_compare(tree->entry, entry1) == 0) {
        entry_replace(tree->entry, key, value);
        return 0;
    } else if (entry_compare(tree->entry, entry1) > 0) {
        tree_put(tree->right, key, value);
    } else {
        tree_put(tree->left, key, value);
    }
    
    return -1;
}

/* Função para obter da árvore o valor associado à chave key.
 * A função deve devolver uma cópia dos dados que terão de ser
 * libertados no contexto da função que chamou tree_get, ou seja, a
 * função aloca memória para armazenar uma *CÓPIA* dos dados da árvore,
 * retorna o endereço desta memória com a cópia dos dados, assumindo-se
 * que esta memória será depois libertada pelo programa que chamou
 * a função.
 * Devolve NULL em caso de erro.
 */
struct data_t *tree_get(struct tree_t *tree, char *key) {
    char* key0 = tree->entry->key;
    if (tree == NULL) {
        return NULL;
    }
    if (key0 == key) {
        return data_dup(tree->entry->value);
    } else if (key0 > key) {
        tree_get(tree->right, key);
    } else {
        tree_get(tree->left, key);
    }
    return NULL;
}

/* Função para remover um elemento da árvore, indicado pela chave key,
 * libertando toda a memória alocada na respetiva operação tree_put.
 * Retorna 0 (ok) ou -1 (key not found).
 */
int min (struct tree_t *tree) {
    struct tree_t* t = tree;
    while (tree && tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

struct tree_t* del(struct tree_t *tree, char *key) {
    if (tree == NULL) {
        return NULL;
    }

    if (tree->entry->key > key) {
        tree->right = tree_del(tree->right, key);
    } 
    if (tree->entry->key < key) {
        tree->left = tree_del(tree->left, key);
    }
    else {
        if (tree->left == NULL) {
            struct tree_t *t = tree->right;
            free(tree);
            return t;
        } else if (tree->right == NULL){
            struct tree_t *t = tree->left;
            free(tree);
            return t;
        }
        struct tree_t *t = min(tree->right);
        tree->entry->key = t->entry->key;
        tree->right = del(tree->right, t->entry->key);
    } 
    return tree;
}

int tree_del(struct tree_t *tree, char *key) {
    if (del(tree, key) == NULL) {
        return -1;
    }
    return del(tree, key);
}

/* Função que devolve o número de elementos contidos na árvore.
 */
int tree_size(struct tree_t *tree) {
    if (tree == NULL) {
        return 0;
    }
    if (tree->right != NULL) {
        return tree_size(tree) + 1;
    } 
    if (tree->left != NULL){
        return tree_size(tree) + 1;
    }
    return 1;
}

/* Função que devolve a altura da árvore.
 */
int tree_height(struct tree_t *tree) {
    if (tree == NULL) {
        return 0;
    } else {
        int lHeight = tree_height(tree->left);
        int rHeight = tree_height(tree->right);

        if (lHeight > rHeight) {
            return lHeight;
        } else {
            return rHeight;
        }
    }
}

/* Função que devolve um array de char* com a cópia de todas as keys da
 * árvore, colocando o último elemento do array com o valor NULL e
 * reservando toda a memória necessária.
 */
char *get_keys(struct tree_t *tree, char* array, int i) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->right != NULL) {
        array[i] = tree->entry->key;
        get_keys(tree, array, i + 1);
    } 
    if (tree->left != NULL){
        array[i] = tree->entry->key;
        get_keys(tree, array, i + 1);
    }
    return array;
}

char **tree_get_keys(struct tree_t *tree) {
    char array[tree_size(tree) + 1];
    array[sizeof(array)] = NULL;
    char **ptr = get_keys(tree, array, 0);
    return ptr;
}

/* Função que liberta toda a memória alocada por tree_get_keys().
 */
void tree_free_keys(char **keys) {
    if (keys != NULL) {
        int i = 0;
        while (i < sizeof(keys)) {
            free(keys[i]);
            i++;
        }
        free(keys);
    }
}
