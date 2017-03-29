//
//  main.c
//  †
//
//  Realizzare l'implementazione di una struttura dati rappresentante una LISTA LINEARE semplice in linguaggio C.
//  Creare un metodo main d'esempio, per testare le funzionalità della lista creata.
//
//  Created by Valentino Tombesi on 29/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define NOMEMORYAVAILABLE printf("Memoria non disponibile.\n"); return 0;

typedef int TipoElemento;

struct node {
    TipoElemento info;
    struct node *next;
};

typedef struct node ElemLista;
typedef ElemLista *pElemLista;

void inizializza(pElemLista *p) {
    *p = NULL;
}

int inserisciInTesta(pElemLista *p, TipoElemento E) {
    pElemLista q;
    
    q = malloc(sizeof(ElemLista));
    if (q==NULL) {
        NOMEMORYAVAILABLE;
    }
    
    q->info = E;
    q->next = *p;
    
    *p=q;
    
    return 1;
}

int stampa(pElemLista p) {
    pElemLista q;
    
    q=p;
    
    printf("Lista: \t");
    while(q!=NULL) {
        printf("%d \t", q->info);
        q=q->next;
    }
    
    printf("\n");
    return 0;
}

pElemLista cercaPosizione(pElemLista p, TipoElemento E) {
    pElemLista q;
    
    q=p;
    
    while(q!=NULL) {
        if(q->info==E)
            return q;
        q=q->next;
    }
    return NULL;
}

void cerca(pElemLista p, TipoElemento E) {
    pElemLista pos;
    pos=cercaPosizione(p, E);
    if(pos==NULL)
        printf("Elemento { %d } non trovato.", E);
    else
        printf("Elemento { %d } trovato all'indirizzo %p", E, pos);
    
    printf("\n");
}

int inserisciDopoElemento(pElemLista *p, TipoElemento E) {
    pElemLista newNode;
    pElemLista pTemp;
    pElemLista pNext;
    
    newNode = malloc(sizeof(ElemLista));
    if (newNode==NULL) {
        NOMEMORYAVAILABLE;
    }
    
    pTemp=*p;
    pNext=pTemp->next;
    if(pNext==NULL)
        newNode->next=NULL;
    else
        newNode->next=pNext;
    
    newNode->info=E;
    pTemp->next=newNode;
    
    return 1;
}

int cancellaElemento(pElemLista *p, TipoElemento E) {
    pElemLista q;
    pElemLista pPrev;

    q=*p;
    
    pPrev=NULL;
    while(q!=NULL){
        if (q->info==E) {
            if (pPrev==NULL) {
                *p=q->next;
            } else {
                if(q->next==NULL)
                    pPrev->next=NULL;
                else
                    pPrev->next=q->next;
            }
            free(q);
            return 1;
        }
        pPrev=q;
        q=q->next;
    }
    return 0;
}

int main() {
    pElemLista pos;
    pElemLista pHead;
    
    inizializza(&pHead);
    
    inserisciInTesta(&pHead, 3); // should be { 3 }
    inserisciInTesta(&pHead, 7); // should be { 7, 3 }
    inserisciInTesta(&pHead, 2); // should be { 2, 7, 3 }
    
    stampa(pHead);
    cerca(pHead, 7);
    cerca(pHead, 1);
    
    pos=cercaPosizione(pHead, 2);
    inserisciDopoElemento(&pos, 1); // should be { 2, 1, 7, 3 }
    stampa(pHead);
    
    pos=cercaPosizione(pHead, 3);
    inserisciDopoElemento(&pos, 9); // should be { 2, 1, 7, 3, 9 }
    stampa(pHead);
    
    cancellaElemento(&pHead, 7);
    stampa(pHead);
    
    return 0;
}
