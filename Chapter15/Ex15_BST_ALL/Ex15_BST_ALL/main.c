//
//  main.c
//  Ex15_BST_ALL
//
//  Created by Valentino Tombesi on 01/04/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

# define TRUE 1 
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

typedef int TipoDato;
struct BST_A {
    TipoDato key;
    struct BST_A *left; // Figlio sinistro
    struct BST_A *right; // Figlio destro
    struct BST_A *p; // Genitore
};
typedef struct BST_A BST;
typedef struct BST_A *pBST;

// INORDER
void inorder(pBST x) {
    if(x!=NULL) {
        inorder(x->left);
        printf("%d, ",x->key);
        inorder(x->right);
    }
    return;
}

// PREORDER
void preorder(pBST x)
{
    if(x!=NULL)
    {
        printf("%d, ",x->key);
        preorder(x->left);
        preorder(x->right);
    }
    return;
}

// PREORDER
void postorder(pBST x) {
    if(x!=NULL) {
        postorder(x->left);
        postorder(x->right);
        printf("%d, ",x->key);
    }
    return;
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

// Crea un nuovo nodo
pBST newnodo(TipoDato x)
{
    pBST A;
    A=(pBST)malloc(sizeof(BST)); A->key=x;
    A->left=NULL; A->right=NULL;
    A->p=NULL;
    return A;
}

// Ricerca il valore nell'albero con iterazione
pBST searchBST( pBST T, TipoDato x)
{
    pBST B = T;
    while(B!=NULL) {
        if(B->key==x)
            return B;
        if(B->key>x)
            B=B->left;
        else if(B->key<x)
            B=B->right;
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
    if(X->right!=NULL) {
        return minimo(X->right);
    // Metto in Y il puntatore al genitore
    Y=X->p;
    // se X ha un figlio destro, il più piccolo
    // elemento del sottoalbero destro è il successore
    while( Y != NULL && X == Y->right) {
        X=Y;
        Y=Y->p;
    }
        
    return Y;
}

// cancellazione di un nodo: riceve l'albero e il puntatore all'elemento da cancellare // pertanto bisogna prima eseguire una ricerca con searhBST()
pBST cancella(pBST T, pBST z)
    {
        pBST y,x;
        // Cerco se è una
        if(z->left==NULL || z->right==NULL)
            y=z; else
                y=successore(z);
        // y ora contiene il nodo da cancellare
        if(y->left!=NULL) x=y->left;
        else x=y->right;
        if(x!=NULL) x->p=y->p;
        // in x ora ho il sostituto del nodo
        if(y->p==NULL) T=x;
        else if( y == (y->p)->left) (y->p)->left = x;
        else
            (y->p)->right = x;
        // a questo punto ho estratto y dalla BST if( y != z)
        z->key=y->key;
        //ora libero la memoria free(y);
        return y;
    }
    
    // Inserisce nella giusta posizione dell'albero un valore void insertBst(pBST *T, TipoDato u)
    {
        pBST x,y,v,a;
        x=*T;
        y=v=a=NULL;
        // Cerca il valore nell'albero while(x!=NULL)
        {
            y=x;
            if(x->key >u) x=x->left;
            else x=x->right;
        }
        v=y; // in v ho il puntatore all'elemento trovato
        a=newnodo( u );
        a->p=v; // valorizzo il genitore
        // Se non lo ha trovato lo aggiunge come foglia if(v==NULL)
        *T=a;
        else // Se lo ha trovato lo aggiunge come nodo
            if(u<v->key) v->left=a;
            else v->right=a;
        return; }

int main() {
    int i,numel,loop, scelta;
    pBST a,z; a=NULL;
    //TipoDato app[]={3,5,1,8,99,44,0,7,5,4,2,1};
    //TipoDato app[]={4,3,2,1,6,8,12,9,15};
    TipoDato app[]={6,2,8,1,4,12,3,9,15};
    numel=sizeof(app)/sizeof(app[0]);
    for(i=0;i<numel;i++)
    {
        insertBst(&a, app[i]);
    }
    loop = TRUE;
    while(loop) {
        printf("\n\nMenu di scelta programma BST\n"); printf("1: Cerca elemento.\n");
        printf("2: Estrai elemento dal BST.\n"); printf("3: Visita BST in inorder.\n");
        printf("4: Visita BST in preorder.\n"); printf("5: Visita BST in postorder.\n"); printf("0: Uscita.\n"); scanf("%d",&scelta);
        switch(scelta) {
            case 1:
                printf("\nInserisci elemento da cercare\n"); scanf("%d", &i);
                if(searchBST(a,i)!=NULL)
                    printf("Trovato!\n"); else
                        printf("Non Trovato!\n"); break;
            case 2:
                printf("\nInserisci elemento da cancellare\n"); scanf("%d", &i); if((z=searchBST(a,1))!=NULL)
                {
                    a=cancella(a,z);
                    printf("Elemento cancellato!\n"); } else
                        printf("Elemento non cancellato!\n"); break;
            case 3: inorder(a);
                break; case 4:
                preorder(a);
                break; case 5:
                postorder(a);
                break; case 0:
                loop=FALSE;
            break; }
    }
    return 0;
}