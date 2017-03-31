//
//  Heap.h
//  Ex08_Heap_Vettore
//
//  Created by Valentino Tombesi on 31/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#ifndef __Ex08_Heap_Vettore__Heap__
#define __Ex08_Heap_Vettore__Heap__

#define MAXEL 6
#define TRUE 1
#define FALSE 0
#define VUOTA -1

// definizioni struttura dati Coda
typedef int TipoInfo;
TipoInfo Heap[MAXEL];
int lungHeap;

int Parent(int i);
int Left(int i);
int Right(int i);
void Heapify(TipoInfo *H, int i);
int Max(TipoInfo *P,int i, int L, int R );
void Swap(TipoInfo *H, int i, int j);
void BuildHeap(TipoInfo *H);
void InsertConSwap(TipoInfo *H, TipoInfo k);
void Insert(TipoInfo *H, TipoInfo k);
TipoInfo Extract(TipoInfo *H);
void vediHeap(TipoInfo *H);

#endif /* defined(__Ex08_Heap_Vettore__Heap__) */
