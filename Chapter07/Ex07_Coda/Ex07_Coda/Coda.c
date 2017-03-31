//
//  Coda.c
//  Ex07_Coda
//
//  Created by Valentino Tombesi on 31/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Coda.h"

void Inizializza(TipoCoda *q)
{
    q->front=q->rear=0;
}

int CodaVuota(TipoCoda q)
{
    return (q.front==q.rear);
}

// Controlla che la coda non sia piena
int CodaPiena(TipoCoda q)
{
    return(((q.rear+1)%MAXEL)==q.front);
}

TipoInfo Front(TipoCoda q)
{
    return q.info[q.front];
}

void EnQueue(TipoCoda *q, TipoInfo x)
{
    if(CodaPiena(*q))
    {
        printf("La coda e' piena!!\n");
        return; }
    q->info[q->rear++]=x;
    q->rear=q->rear%MAXEL;
    return;
}

TipoInfo DeQueue(TipoCoda *q)
{
    if(CodaVuota(*q))
        return NULL;
    q->front++;
    q->front=q->front%MAXEL;
    return q->info;
}