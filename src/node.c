#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

tNode *constroiNo(informacao value, tNode *prev, tNode *next)
{
    tNode *n = (tNode *)calloc(1, sizeof(tNode));
    n->value = value;
    n->next = next;
    n->prev = prev;
    return n;
}

void destroiNo(tNode *n)
{
    if (n) {
        free(n);
    }
}