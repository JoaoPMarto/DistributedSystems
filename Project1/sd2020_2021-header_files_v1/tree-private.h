#ifndef _TREE_PRIVATE_H
#define _TREE_PRIVATE_H

#include "tree.h"
#include "entry.h"

struct tree_t {
	/** a preencher pelo grupo */
	struct entry_t *entry;
	struct tree_t *right;
	struct tree_t *left;
};

#endif
