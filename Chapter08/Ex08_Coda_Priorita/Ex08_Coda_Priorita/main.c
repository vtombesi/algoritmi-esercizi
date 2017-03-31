//
//  main.c
//  Ex08_Coda_Priorita
//
//  Created by Valentino Tombesi on 31/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CodaPriorita.h"

int main(int argc, const char * argv[]) {
    int loop, scelta;
    TipoCoda Coda;
    TipoInfo valore;
    Inizializza(&Coda);
    loop = TRUE;
    while(loop)
    {
        printf("Menu di scelta programma ADT coda a priorita'\n");
        printf("1: Inizializza.\n");
        printf("2: Vedi primo elemento.\n");
        printf("3: Inserisci elemento in coda.\n");
        printf("4: Estrai elemento dalla coda.\n");
        printf("5: Estrai elemento dalla coda a priorita'.\n");
        printf("6: Vedi se la coda e' vuota.\n");
        printf("7: Vedi se la pila ha raggiunto il massimo numero di elementi.\n");
        printf("0: Uscita.\n");
        scanf("%d",&scelta);
        switch(scelta)
        {
            case 1:
                Inizializza(&Coda);
                break;
            case 2:
                if(!CodaVuota(Coda))
                    printf("Il primo elemento della coda e': %d\n", Front(Coda));
                break;
            case 3:
                printf("Inserisci valore nella coda:\n");
                scanf("%d", &valore);
                EnQueue(&Coda, valore);
                break;
            case 4:
                DeQueue(&Coda);
                break;
            case 5:
                if(CodaVuota(Coda))
                    printf("La coda e' vuota\n");
                else
                    printf("E' stato levato il seguente elemento dalla coda %d\n", DeQueuePriorita(&Coda));
                break;
            case 6:
                if(CodaVuota(Coda))
                    printf("La coda e' vuota\n");
                else
                    printf("La coda ha elementi\n");
                break;
            case 7:
                if(CodaPiena(Coda))
                    printf("La coda e' piena\n");
                else
                    printf("La coda non e' piena\n");
                break;
            case 0:
                loop=FALSE;
            break;
        }
    }
    return 0;
}
