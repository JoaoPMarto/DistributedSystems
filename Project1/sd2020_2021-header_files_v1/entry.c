#include <stdio.h>
#include <stdlib.h>
#include "entry.h"
#include "data.h"

/* Função que cria uma entry, reservando a memória necessária e
 * inicializando-a com a string e o bloco de dados passados.
 */
struct entry_t *entry_create(char *key, struct data_t *data) {
    if (key == NULL || data == NULL) {
        return NULL;
    }
    
    struct entry_t *entry = (struct entry_t *)malloc(sizeof(struct entry_t));
    
    if(entry == NULL)
        return NULL;

    entry->value = data_create2(sizeof(char) * strlen(key), data);
    entry->key = key;
    return entry;
}

/* Função que inicializa os elementos de uma entry com o
 * valor NULL.
 */
void entry_initialize(struct entry_t *entry)
{
    if (entry != NULL)
    {
        entry->value = NULL;
    }
}

/* Função que elimina uma entry, libertando a memória por ela ocupada
 */
void entry_destroy(struct entry_t *entry)
{
    if (entry != NULL)
    {
        data_destroy(entry->value);
        free(entry->key);
    }
}

/* Função que duplica uma entry, reservando a memória necessária para a
 * nova estrutura.
 */
struct entry_t *entry_dup(struct entry_t *entry)
{
    if (entry == NULL)
    {
        return NULL;
    }
    struct entry_t *entry1 = (struct entry_t*) malloc(sizeof(struct entry_t));
    struct data_t *d = data_dup(entry->value);
    return entry_create(entry->key, d);
}

/* Função que substitui o conteúdo de uma entrada entry_t.
*  Deve assegurar que destroi o conteúdo antigo da mesma.
*/
void entry_replace(struct entry_t *entry, char *new_key, struct data_t *new_value) {
    if (entry != NULL) {
        entry->key = new_key;
        data_replace(entry->value, new_value->datasize, new_value);

    }
}

/* Função que compara duas entradas e retorna a ordem das mesmas.
*  Ordem das entradas é definida pela ordem das suas chaves.
*  A função devolve 0 se forem iguais, -1 se entry1<entry2, e 1 caso contrário.
*/
int entry_compare(struct entry_t *entry1, struct entry_t *entry2) {
    if (entry1 != NULL && entry2 != NULL) {
        int n = strcmp(entry1->key,entry2->key);
        if (n > 0) {
            return 1;
        } else if (n < 0) {
            return -1;
        } else {
            return 0;
        }
    }
    return NULL;
}
