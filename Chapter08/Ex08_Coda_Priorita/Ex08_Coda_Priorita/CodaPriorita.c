//
//  CodaPriorita.c
//  Ex08_Coda_Priorita
//
//  Created by Valentino Tombesi on 31/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CodaPriorita.h"

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
void DeQueue(TipoCoda *q)
{
    if(CodaVuota(*q))
        return;
    q->front++;
    q->front=q->front%MAXEL;
    return; }
TipoInfo DeQueuePriorita(TipoCoda *q)
{
    int i, imax;
    TipoInfo max;
    if(CodaVuota(*q))
        return -1;
    // Assegno valore massimo
    max=q->info[q->front];
    imax=q->front;
    for(i=(q->front+1)%MAXEL; i<q->rear; i++)
    {
        if(q->info[i%MAXEL]>max)
        {
            max=q->info[i%MAXEL];
            imax=i; }
    }
    for(i=imax; i<q->rear; i++)
    {
        q->info[i%MAXEL]= q->info[(i-1)%MAXEL];
    }
    q->rear=(q->rear-1)%MAXEL;
    return max;
}