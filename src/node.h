#ifndef _NODE_H_
#define _NODE_H_

typedef void* informacao;

typedef struct tNode
{
    informacao value;
    struct tNode *prev;
    struct tNode *next;
} tNode;

tNode *constroiNo(informacao value, tNode *prev, tNode *next);
void destroiNo(tNode *n);

#endif