//
//  main.c
//  Ex03_1
//
//  Implementare la funzione di ricerca binaria in versione ricorsiva
//
//  Created by Valentino Tombesi on 28/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int ricercaBin(int X[], int cerca, int sx, int dx)
{
    int mid;
    
    if(sx > dx)
        return -1;
    
    mid = (sx + dx) / 2;
    
    if(X[mid]==cerca)
        return mid;
    
    if(X[mid]>cerca)
        return ricercaBin(X,cerca, sx, mid-1);
    else
        return ricercaBin(X,cerca, mid+1, dx);
}

int main() {
    int lista[10] = {0,1,2,3,4,5,6,7,8,9};
    int c, risultato;
    
    printf("Inserire il valore da cercare nel vettore\n");
    scanf("%d", &c);
    
    if ((risultato=ricercaBin(lista, c, 0, 9))>0)
        printf("Il valore è stato trovato nella posizione %d\n", risultato);
    else
        printf("Il valore non è stato trovato\n");
    
    return 0;
}
