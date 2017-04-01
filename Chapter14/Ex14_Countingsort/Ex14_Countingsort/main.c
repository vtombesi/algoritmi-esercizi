//
//  main.c
//  Ex14_Countingsort
//
//  Created by Valentino Tombesi on 01/04/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// N è il numero degli elementi
#define N 10

// K è il range massimo di valori che può assumere un singolo elemento
#define K 10

int* CountingSort( int A[], int n, int k)
{
    
    int *B, *C;
    int i;
    
    // B è il vettore contenente i vaolri ordinati
    B=(int*)calloc(n,sizeof(int));
    
    // C è il vettore di conteggio
    C=(int*)calloc(k,sizeof(int));
    
    // mette in ogni posizione di C con indice elemento A[i] il conteggio di quanti elementi con quel valore
    for(i=0;i<n;i++)
        C[A[i]-1]++;
    
    // somma ad ogni posizione il numero di valori occupati dalle posizioni precedenti
    for(i=1;i<k;i++)
        C[i] += C[i-1];
    
    // Inserisce i valori ordinati in B
    for(i=n-1;i>=0;i--)
    {
        B[C[A[i]-1]-1] = A[i];
        C[A[i]-1]--;
    }
    return B;
}

int main()
{
    int A[N]={8,1,5,10,7,4,6,2,3,6};
    int *B;
    int i;
    
    printf("Vettore prima dell'ordinamento\n");
    
    for(i=0;i<N;i++)
        printf("%d, ", A[i]);
    
    B=CountingSort(A, N, K);
    
    printf("\nVettore ordinato\n");
    for(i=0;i<N;i++)
        printf("%d, ", B[i]);
    return 0;
}

