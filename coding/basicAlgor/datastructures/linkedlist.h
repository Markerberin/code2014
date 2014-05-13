#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct node_s {
    uint32_t value; 
    node_t *next;
} node_t;

typedef struct linkedlist_s{
    node_t *head;
    uint32_t size;
} linkedlist_t;

 




#endif
