//
//  Pila.c
//  Ex07_Pila
//
//  Created by Valentino Tombesi on 29/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdlib.h>
#include "Pila.h"

void InizializzaPila(Pila *s)
{
    s->top=VUOTA;
}

int PilaVuota(Pila s)
{
    return(s.top==VUOTA);
}

int PilaPiena(Pila s)
{
    return(s.top==(MAXEL-1));
}

TipoInfo Top(Pila s)
{
    if(!PilaVuota(s))
        return s.info[s.top];
    return VUOTA;
}
TipoInfo Pop(Pila *s)
{
    if(!PilaVuota(*s))
    {
        return s->info[s->top--];
    }
    return VUOTA;
}
int Push(Pila *s, TipoInfo x)
{
    if(!PilaPiena(*s))
    {
        s->info[++(s->top)]=x;
        return TRUE;
    }
    return FALSE;
}