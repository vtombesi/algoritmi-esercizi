//
//  main.c
//  Ex01_4
//
//  Created by Valentino Tombesi on 27/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.

//  Allocare dinamicamente una matrice di interi di dimensioni specificate dall’utente in fase di esecuzione. Inizializzare tutti gli elementi della matrice a zero.
//  Definire un puntatore all’elemento (0,0).
//  Scrivere un algoritmo che sposti il puntatore in posizione (i,j) , con i,j numeri casuali non negativi e minori delle dimensioni della matrice). Eseguire H volte (con H richiesto all’utente in fase di esecuzione) la procedura di spostamento e ogni volta aumentare il valore della casella di (i+j). Stampare a video la matrice
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* Shift(int **x, int r, int c)
{
    int i, j;
    i=rand()%r;
    j=rand()%c;
    return &x[i][j];
}

int main() {
    int **x;  // Matrice
    int *px;  // Puntatore di x
    int r; // Numero delle righe
    int c; // Numero delle colonne
    int H; // Numero spostamenti
    int i, j;
    
    printf("\nInsert number of rows: ");
    scanf("%d",&r);
    printf("\nInsert number of columns: ");
    scanf("%d",&c);
    
    x = (int**) malloc(r*sizeof(int));
    
    if(x==NULL) {
        printf("\nErrore nella malloc!");
        return -1;
    }
    
    for(i=0;i<r;i++) {
        x[i] = (int*) calloc(c,sizeof(int));
        if(x[i]==NULL) {
            printf("\nErrore nella malloc!");
            return -1;
        }
    }
    
    printf("\nInsert offset: ");
    scanf("%d",&H);
    
    srand(time(NULL));
    
    for(i=0;i<H;i++) {
        px=Shift(x, r, c);
        *(px)+=(r+c);
    }

    printf("\n");
    
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++)
            printf("%10d ", x[i][j]);
        printf("\n");
    }

    free(x);
    
    return 0;
}
