//
//  main.c
//  Ex01_3
//
//  Created by Valentino Tombesi on 27/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//
//  Progettare una funzione che restituisca un valore intero casuale tra 0 e N.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    
    int maxNumber;
    int i;
    
    printf("What is the maximum value? ");
    scanf("%d", &maxNumber);
    printf("\n");
    
    srand(time(NULL));
    i = rand() % maxNumber + 1;
    
    printf("Random number is %d \n", i);
    
    return 0;
}
