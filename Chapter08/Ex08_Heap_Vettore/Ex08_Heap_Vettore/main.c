//
//  main.c
//  Ex08_Heap_Vettore
//
//  Created by Valentino Tombesi on 31/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

int main(int argc, const char * argv[]) {
    TipoInfo Dummy[]={10, 4,1,3,2,16,9,10,14,8,7};
    // All'interno del vettore Heap all'indice 0 inseriamo il numero degli elementi
    lungHeap = Dummy[0];
    int i;
    for (i=0;i<=lungHeap;i++)
        Heap[i]=Dummy[i];
    printf("Vedi Heap prima del BuildHeap\n");
    vediHeap(Heap);
    BuildHeap(Heap);
    int loop, scelta;
    loop = TRUE;
    while(loop)
    {
        printf("\n\nMenu di scelta programma Heap con vettore\n");
        printf("1: Visualizza Heap.\n");
        printf("2: Estrai l'elemento max dallo Heap.\n");
        printf("3: Inserisci elemento nello heap.\n");
        printf("0: Uscita.\n");
        scanf("%d",&scelta);
        switch(scelta)
        {
            case 1:
                printf("Vedi Heap\n");
                vediHeap(Heap);
                break;
            case 2:
                printf("\n\nEstratto il max valore %d dallo Heap\n", Extract(Heap));
                break;
            case 3:
                printf("\nInserisci valore nello Heap\n");
                scanf("%d", &i);
                InsertConSwap(Heap, i);
                break;
            case 0:
                loop=FALSE;
            break; }
    }
    return 0;
    
}
