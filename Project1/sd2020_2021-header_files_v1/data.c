#include <stdio.h>
#include <stdlib.h>
#include "data.h"

/* Função que cria um novo elemento de dados data_t e reserva a memória
 * necessária, especificada pelo parâmetro size 
 */
struct data_t *data_create(int size) {
    if (size < 0) {
        return NULL;
    }
    struct data_t *elem;
    elem = (struct data_t *) malloc(sizeof(struct data_t));
    if (elem == NULL) {
        return NULL;
    }
    elem -> datasize = size;
    elem -> data = malloc(size);

    if(elem->data == NULL) {
        return NULL;
    }
    return elem;
}

/* Função idêntica à anterior, mas que inicializa os dados de acordo com
 * o parâmetro data.
 */
struct data_t *data_create2(int size, void *data) {
    if (size < 0 || data == NULL) {
        return NULL;
    }
    struct data_t *elem;
    if (elem == NULL) {
        return NULL;
    }
    memcpy(elem -> data, data, size);
    elem -> datasize = size;
    return elem;
}

/* Função que elimina um bloco de dados, apontado pelo parâmetro data,
 * libertando toda a memória por ele ocupada.
 */
void data_destroy(struct data_t *data) {
    if (data != NULL) {
        if (data->data != NULL) {
        free(data -> data);
        }
    free(data);
    }
}

/* Função que duplica uma estrutura data_t, reservando a memória
 * necessária para a nova estrutura.
 */
struct data_t *data_dup(struct data_t *data) {
    return data_create2(data->datasize, data->data);
}

/* Função que substitui o conteúdo de um elemento de dados data_t.
*  Deve assegurar que destroi o conteúdo antigo do mesmo.
*/
void data_replace(struct data_t *data, int new_size, void *new_data) {
    if (data == NULL) {
        data->data = new_data;
        data->datasize = new_size;
    }
}