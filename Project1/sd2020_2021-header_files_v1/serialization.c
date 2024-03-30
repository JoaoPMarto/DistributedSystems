#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "entry.h"
#include "tree.h"

/* Serializa uma estrutura data num buffer que será alocado
 * dentro da função. Além disso, retorna o tamanho do buffer
 * alocado ou -1 em caso de erro.
 */
int data_to_buffer(struct data_t *data, char **data_buf) {
    if (data_buf != NULL) {
        int size = sizeof(struct data_t*);
        data = htonl(data);
        data_buf = malloc(size);
        memcpy(data_buf, data, size);
        return size;
    }
    return -1;
}


/* De-serializa a mensagem contida em data_buf, com tamanho
 * data_buf_size, colocando-a e retornando-a numa struct
 * data_t, cujo espaco em memoria deve ser reservado.
 * Devolve NULL em caso de erro.
 */
struct data_t *buffer_to_data(char *data_buf, int data_buf_size) {
    if (data_buf == NULL || data_buf_size < 0) {
        return NULL;
    }
    struct data_t *data = data_create2(data_buf_size, data_buf);
    memcpy(data,data_buf, data_buf_size);
    return data;
}

/* Serializa uma estrutura entry num buffer que será alocado
 * dentro da função. Além disso, retorna o tamanho deste
 * buffer ou -1 em caso de erro.
 */
int entry_to_buffer(struct entry_t *entry, char **entry_buf) {
    if (entry_buf != NULL) {
        int size = sizeof(struct entry_t*);
        entry = htonl(entry);
        entry_buf = malloc(size);
        memcpy(entry_buf, entry, size);
        return size;
    }
    return -1;
}

abc key
teste123 data
[a,b,c,t,e,s,t,e,1,2,3]
abc para inteiro
bytes que estao na memoria de abc
no caso 3 descodificar o inteiro de 4 bytes para saber o numero de caracteres da chave
[ , , , ,a,b,c, , , , ,t,e,s,t,e,1,2,3]
     3             8
    19 bytes para reservar no fim
    nbytes = 
    *entry_buf = malloc(nbytes)
    ptr = *entry_buf;
    int a;
    char *ptr;
    aux = ptr;
    memcpy(aux, &a, sizeof(int));
    aux += sizeof(int);
    memcpy(aux, entry->key, strlen(entry->key));
    aux += strlen(entry->key);
    memcpy(aux, entry->value->datasize, sizeof(int));
    aux += sizeof(int);
    memcpy(aux, entry->value, strlen(entry->value->data));
    aux += strlen(entry->value->data);

    char *buffer;
    entry_to_buffer(entry,&buffer)

    void *data;
    int j = 0;
    for (int i = sizeof(int); i < data_buf_size; i++) {
        data[j] = &data_buf[i];
        j++;
    }

/* De-serializa a mensagem contida em entry_buf, com tamanho
 * entry_buf_size, colocando-a e retornando-a numa struct
 * entry_t, cujo espaco em memoria deve ser reservado.
 * Devolve NULL em caso de erro.
 */
struct entry_t *buffer_to_entry(char *entry_buf, int entry_buf_size) {
    if (entry_buf == NULL || entry_buf_size < 0) {
        ptr = *entry_buf;
        aux = ptr;
        t = entry_buf[0];
}

/* Serializa uma estrutura tree num buffer que será alocado
 * dentro da função. Além disso, retorna o tamanho deste
 * buffer ou -1 em caso de erro.
 */
int tree_to_buffer(struct tree_t *tree, char **tree_buf) {
    if (tree_buf != NULL) {
        int size = sizeof(struct tree_t*);
        tree = htonl(tree);
        tree_buf = malloc(size);
        memcpy(tree_buf, tree, size);
        return size;
    }
    return -1;
}

/* De-serializa a mensagem contida em tree_buf, com tamanho
 * tree_buf_size, colocando-a e retornando-a numa struct
 * tree_t, cujo espaco em memoria deve ser reservado.
 * Devolve NULL em caso de erro.
 */
struct tree_t *buffer_to_tree(char *tree_buf, int tree_buf_size) {
    if (tree_buf == NULL || tree_buf_size < 0) {
        return NULL;
    }
    struct tree_t *tree = tree_create();
    memcpy(tree,tree_buf, tree_buf_size);
    return tree;
}

