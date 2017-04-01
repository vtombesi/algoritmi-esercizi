//
//  main.c
//  Ex12_Heapsort
//
//  Created by Valentino Tombesi on 01/04/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main()
{
    // Vettore da ordinare
    TipoInfo Dummy[]={10, 4,1,3,2,16,9,10,14,8,7};
    
    // Numero di elementi
    lungHeap = 11;
    
    int i;
    for (i=0;i<lungHeap;i++)
        Heap[i]=Dummy[i];
    
    printf("Vedi  prima dell'ordinamento\n");
    
    for (i=0;i<lungHeap;i++)
        printf("%d, ", Heap[i]);
    
    printf("\nVedi dopo l'ordinamento\n");
    
    HeapSort(Heap);
    
    for (i=0;i<lungHeap;i++)
        printf("%d, ", Heap[i]);
    
    printf("\n");

    return 0;
}