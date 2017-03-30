//
//  main.c
//  Ex07_Pila
//
//  Created by Valentino Tombesi on 29/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

int main() {
    int loop, scelta;
    Pila sPila;
    TipoInfo valore;
    
    InizializzaPila(&sPila);
    
    loop = TRUE;
    while(loop) {
        printf("Menu di scelta programma ADT Pila con vettore\n");
        printf("1: Inizializza.\n");
        printf("2: Vedi il Top.\n");
        printf("3: Inserisci elemento.\n");
        printf("4: Estrai elemento.\n");
        printf("5: Vedi se la pila e' vuota.\n");
        printf("6: Vedi se la pila ha raggiunto il massimo numero di elementi.\n");
        printf("0: Uscita.\n");
        scanf("%d",&scelta);
        
        switch(scelta) {
            case 1:
                InizializzaPila(&sPila);
                break;
            case 2:
                printf("L'elemento in cima alla pila e': %d\n", Top(sPila));
                break;
            case 3:
                printf("Inserisci valore nella pila:\n");
                scanf("%d", &valore);
                if(!Push(&sPila, valore))
                    printf("Pila piena!!\n");
                break;
            case 4:
                printf("L'elemento e': %d\n", Pop(&sPila));
                break;
            case 5:
                if(PilaVuota(sPila))
                    printf("La pila e' vuota\n");
                else
                    printf("La pila ha elementi\n");
                break;
            case 6:
                if(PilaPiena(sPila))
                    printf("La pila e' piena\n");
                else
                    printf("La pila non e' piena\n");
                break;
            case 0:
                loop=FALSE;
                break;
        }
    }
    return 0;
}
