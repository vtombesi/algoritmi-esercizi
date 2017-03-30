//
//  Pila.h
//  Ex07_Pila
//
//  Created by Valentino Tombesi on 29/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#ifndef __Ex07_Pila__Pila__
#define __Ex07_Pila__Pila__

#include <stdio.h>

#define MAXEL 3
#define TRUE 1
#define FALSE 0
#define VUOTA -1

typedef int TipoInfo;
typedef struct {
    int top;
    TipoInfo info[MAXEL];
} Pila ;

// Dichiarazione delle Funzioni
void InizializzaPila(Pila *s);
int PilaVuota(Pila s);
int PilaPiena(Pila s);
TipoInfo Top(Pila s);
TipoInfo Pop(Pila *s);
int Push(Pila *s, TipoInfo x);

#endif /* defined(__Ex07_Pila__Pila__) */
