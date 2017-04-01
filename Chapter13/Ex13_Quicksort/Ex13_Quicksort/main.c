//
//  main.c
//  Ex13_Quicksort
//
//  Created by Valentino Tombesi on 01/04/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef int TipoDato;

int Partition(TipoDato *A, int p, int r) {
    TipoDato x, app;
    int i,j;
    
    x=A[p];
    i=p-1;
    j=r+1;
    
    while(1)
    {
        do
            j--;
        while(A[j]>x);
        do
            i++;
        while(A[i]<x);
        if(i<j)
        {
            app=A[i];
            A[i]=A[j];
            A[j]=app;
        } else
            return j;
    }
}

void QuickSort(TipoDato *A, int p, int r) {
    int q;
    if(p<r)
    {
        q = Partition(A, p, r);
        QuickSort(A, p, q);
        QuickSort(A, q+1, r);
    }
    return;
}

int main() {
    int nI, l;
    
    TipoDato A[] = {4,1,25,55,0,11,-44,9,56,77,115,-3};
    l=sizeof(A);
    l=12;
    
    printf("Vettore prima dell'ordinamento\n");
    
    for(nI=0;nI<l;nI++)
        printf("%d, ", A[nI]);
    
    QuickSort(A, 0, l-1);
    
    printf("\nVettore dopo dell'ordinamento\n");
    
    for(nI=0;nI<l;nI++)
        printf("%d, ", A[nI]);
    
    printf("\n");
    
    return 0;
}
