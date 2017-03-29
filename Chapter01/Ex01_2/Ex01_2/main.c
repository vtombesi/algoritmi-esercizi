//
//  main.c
//  Ex01_2
//
//  Created by Valentino Tombesi on 27/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//
//  Modificare l’esercizio 1 chiedendo all’utente di inserire il numero di interi N ed allocando dinamicamente il vettore.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int maxElements;
    int c=0;
    int *px;
    int totale=0;

    printf("## How many integers should I sum this time? ");
    scanf("%d", &maxElements);
    
    px = malloc(sizeof(int) * maxElements);
    
    printf("## Insert %d integers, I'll calculate their sum.", maxElements);
    
    while (c != maxElements) {
        printf("\n## Insert integer n°%d: \n", c+1);
        scanf("%d", (px+c));
        c++;
    }
    
    for (c=0;c<maxElements;c++)
        totale+=*(px+c);
    
    printf("\n## Your numbers sum is: %d \n", totale);
    
    return 0;
}
