//
//  main.c
//  Ex15_BST
//
//  Created by Valentino Tombesi on 01/04/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h> 
#include <stdlib.h>

typedef int TipoDato;
struct BST_A {
    TipoDato key;
    struct BST_A *left;
    struct BST_A *right; // Figlio destro
    struct BST_A *p; // Genitore
};
typedef struct BST_A BST; typedef struct BST_A *pBST;

// Crea un nuovo nodo
pBST newnodo(TipoDato x) {
    pBST A;
    A=(pBST)malloc(sizeof(BST)); A->key=x;
    A->left=NULL;
    A->right=NULL;
    A->p=NULL;
    return A;
}

// Ricerca nel nodo con ricorsione
int searchB( pBST T, TipoDato x) {
    if(T==NULL)
        return 0;
    if(T->key==x)
        return 1;
    if(T->key>x)
        searchB(T->left,x);
    else
        searchB(T->right,x);
    return 0;
}

// Ricerca il valore nell'albero con iterazione
pBST searchBST( pBST T, TipoDato x)
{
    pBST B = T;
    while(B!=NULL) {
        if(B->key==x) return B;
        if(B->key>x) B=B->left;
        else if(B->key<x) B=B->right;
    }
    return NULL;
}

// trova il minimo
pBST minimo(pBST T) {
    pBST X=T;
    
    while(X->left!=NULL)
        X=X->left;
    
    return X;
}

// trova il massimo
pBST massimo(pBST T) {
    pBST X=T;
    
    while(X->right!=NULL)
        X=X->right;
    
    return X;
}


// Trova il successore secondo l'ordinamento
pBST successore(pBST T)
{
    pBST X=T; // salviamo T per non modificarlo
    pBST Y;
    
    // Se ha elementi a destra allora il successore è il nodo
    // più a sinistra del sottoalbero a destra
    if(X->right!=NULL)
        return minimo(X->right);
    // Metto in Y il puntatore al genitore Y=X->p;
    // se X ha un figlio destro, il più piccolo
    // elemento del sottoalbero destro è il successore
    while( Y != NULL && X == Y->right)
    {
        X=Y;
        Y=Y->p;
    }
    return Y;
    
}

pBST cancella(pBST *T, pBST z)
{
    pBST y,x;
    // Cerco se è una
    if(z->left==NULL || z->right==NULL)
        y=z; else
            y=successore(z);
    if(y->left!=NULL) x=y->left;
    else x=y->right;
    if(x!=NULL) x->p=y->p;
    if(y->p==NULL) *T=x;
    else if( y == (y->p)->left) (y->p)->left = x;
    else
        (y->p)->right = x;
    if( y == z) z->key=y->key;
    return y;
}

// Inserisce nella giusta posizione dell'albero un valore
void insertBst(pBST *T, TipoDato u) {
    pBST x,y,v,a;
    x=*T;
    y=v=a=NULL;
    // Cerca il valore nell'albero
    while(x!=NULL)
    {
        y=x;
        
        if(x->key >u)
            x=x->left;
        else
            x=x->right;
    }
    
    v=y; // in v ho il puntatore all'elemento trovato
    
    a=newnodo( u );
    a->p=v; // valorizzo il genitore
    // Se non lo ha trovato lo aggiunge come foglia
    if(v==NULL)
        *T=a;
    else // Se lo ha trovato lo aggiunge come nodo
        if(u<v->key) v->left=a;
        else v->right=a;
    return;
}

int main(int argc, const char * argv[]) {
    pBST a,z;
    a=NULL;
    
    insertBst(&a, 1);
    insertBst(&a, 7);
    insertBst(&a, 2);
    insertBst(&a, 15);
    
    if(searchBST(a,12)!=NULL) printf("Trovato!\n");
    else
        printf("Non Trovato!\n");
    if((z=searchBST(a,7))!=NULL) cancella(&a,z);
    return 0;
}
