//
//  Heap.c
//  Ex12_Heapsort
//
//  Created by Valentino Tombesi on 01/04/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

// Primitive
// Primitiva calcolo del figlio SX di un nodo

int Left(int i)
{
    return 2*i;
}

// Primitiva calcolo del figlio DX di un nodo
int Right(int i)
{
    return (2*i) + 1;
}

// Primitiva calcola il max tra A[i] A[l] e A[r]
int Max(TipoInfo *P, int i, int l, int r)
{
    int larg;
    if(l<=lungHeap && P[l-1]>P[i-1])
    {
        larg = l; }
    else larg=i;
    if(r<=lungHeap && P[r-1]>P[larg-1])
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
    return; }
// Primitiva di scambio di due nodi
void Swap(TipoInfo *H, int i, int j)
{
    TipoInfo aux;
    aux=H[i-1];
    H[i-1]=H[j-1];
    H[j-1]=aux;
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
    return;
}

// Funzione ordinamento com Heapsort
void HeapSort(TipoInfo *H)
{
    int l = lungHeap; // Salviamo la lunghezza dello Heap
    BuildHeap(H);
    while(lungHeap>0)
    {
        Swap(H,1,lungHeap);
        lungHeap--;
        Heapify(H,1);
    }
    lungHeap=l;
}