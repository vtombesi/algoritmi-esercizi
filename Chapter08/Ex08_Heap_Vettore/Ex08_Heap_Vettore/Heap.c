//
//  Heap.c
//  Ex08_Heap_Vettore
//
//  Created by Valentino Tombesi on 31/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

// Primiteve
// Primitiva calcolo del genitore di un nodo
int Parent( int i)
{
    return i/2;
}
// Primitiva calcolo del figlio SX di un nodo
int Left(int i)
{
    return 2*i; }
// Primitiva calcolo del figlio DX di un nodo
int Right(int i)
{
    return (2*i) + 1;
}
// Primitiva calcola il max tra A[i] A[l] e A[r]
int Max(TipoInfo *P, int i, int l, int r)
{
    int larg;
    if(l<=lungHeap && P[l]>P[i])
    {
        larg = l;
    } else
        larg=i;
    if(r<=lungHeap && P[r]>P[larg])
        larg=r;
    return larg;
}
// Primitiva che crea L'heap a partire da un nodo
void Heapify(TipoInfo *H, int i)
{
    int l,r,larg;
    l=Left(i);
    r=Right(i);
    larg=Max(H,i,l,r);
    if(i!=larg)
    {
        Swap(H, i, larg);
        Heapify(H,larg);
    }
    return;
}

// Primitiva di scambio di due nodi
void Swap(TipoInfo *H, int i, int j)
{
    TipoInfo aux;
    aux=H[i];
    H[i]=H[j];
    H[j]=aux;
    return;
}
// Primitiva di costruzione Heap
void BuildHeap(TipoInfo *H){
    int i,n;
    n=(lungHeap)/2;
    for(i=n;i>=1;i--)
    {
        Heapify(H,i);
    }
    return; }
// Inserisce un nuovo elemento nell'heap
void InsertConSwap(TipoInfo *H, TipoInfo k)
{
    int i, p;
    if((lungHeap+1)==MAXEL)
        return;
    lungHeap++;
    H[lungHeap]=k;
    i=lungHeap;
    p=Parent(i);
    while(H[i]>H[p] && p>=1)
    {
        Swap(H ,i,p);
        i=p;
        p=Parent(p);
    }
    return;
}

// Inserisce un nuovo elemento nell'heap
void Insert(TipoInfo *H, TipoInfo k)
{
    int i;
    lungHeap++;
    i=lungHeap;
    while(H[Parent(i)]<k && i>1)
    {
        H[i]=H[Parent(i)];
        i=Parent(i);
    }
    H[i]=k;
    return;
}
TipoInfo Extract(TipoInfo *H)
{
    TipoInfo max;
    // Heap vuoto
    if(lungHeap<1)
        return 0;
    max = H[1];
    H[1]=H[lungHeap];
    H[lungHeap]=max;
    lungHeap--;
    Heapify(H, 1);
    return max; }
void vediHeap(TipoInfo *H)
{
    int i;
    printf("\nVisualizzazione Heap\n");
    for (i=1;i<=lungHeap;i++)
        printf("%d, ",Heap[i]);
    printf("\n");
    return;
}