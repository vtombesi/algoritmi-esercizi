//
//  main.c
//  Ex01_1
//
//  Created by Valentino Tombesi on 27/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//
//  Esercizio: Scrivere un programma che chieda in input N interi (N scelto in maniera statica) e li memorizzi in un vettore x.
//  Creare un puntatore p al vettore x e calcolare la somma degli interi usando l’aritmetica dei puntatori (quindi non usare x[i]).
//  Mostrare a video la somma ottenuta.

#include <stdio.h>

#define MAX_ELEMENTS 3

int main() {
    int x[MAX_ELEMENTS];
    int c=0;
    int *px;
    int totale=0;
    
    printf("## Insert %d integers, I'll calculate their sum.", MAX_ELEMENTS);
    
    while (c != MAX_ELEMENTS) {
        printf("\n## Insert integer n°%d: \n", c+1);
        scanf("%d", &x[c]);
        c++;
    }
    px = x;
    
    for (c=0;c<MAX_ELEMENTS;c++)
        totale+=*(px+c);

    printf("\n## Your numbers sum is: %d \n", totale);
    
    return 0;
}
