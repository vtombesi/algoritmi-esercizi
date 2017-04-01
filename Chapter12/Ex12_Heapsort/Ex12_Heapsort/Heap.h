//
//  Heap.h
//  Ex12_Heapsort
//
//  Created by Valentino Tombesi on 01/04/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#ifndef __Ex12_Heapsort__Heap__
#define __Ex12_Heapsort__Heap__

#define MAXEL 6
#define TRUE 1
#define FALSE 0
#define VUOTA -1
typedef int TipoInfo;
TipoInfo Heap[MAXEL];
int lungHeap;
int Left(int i);
int Right(int i);
void Heapify(TipoInfo *H, int i);
int Max(TipoInfo *P,int i, int L, int R );
void Swap(TipoInfo *H, int i, int j);
void BuildHeap(TipoInfo *H);
void HeapSort(TipoInfo *H);

#endif /* defined(__Ex12_Heapsort__Heap__) */
