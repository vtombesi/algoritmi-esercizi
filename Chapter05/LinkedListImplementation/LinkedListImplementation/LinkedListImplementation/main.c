//
//  main.c
//  LinkedListImplementation
//
//  Created by Valentino Tombesi on 13/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "linked_lists.h"

void Inizializza(node_t *p)
{
    p = NULL;
}

int Ricerca(node_t *p, int v)
{
    node_t *q;
    q = p;
    while (q!=NULL) {
        if (q->value == v)
            return 1;
        q = q->next;
    }
    return 0;
}

void PrintList(node_t *head)
{
    node_t *current = head;
    while (current != NULL)
    {
        printf("%p\t%d", current, current->value);
        current = current->next;
    }
}

void AggiungiElemento(node_t *head, int val)
{
    node_t *current = head;
    while (current != NULL)
    {
        printf("head: %p, current: %p\t\n", head, current);
        current = current->next;
        
    }
    printf("exited loop");
    current = malloc(sizeof(node_t));
    current->value = val;
    current->next = NULL;
}

int main()
{
    node_t *Head = NULL;
    
//    Inizializza(Head);
    
    AggiungiElemento(Head, 3);
    //PrintList(&Head);
    
    printf("done.\n");
    
    return 0;
}

