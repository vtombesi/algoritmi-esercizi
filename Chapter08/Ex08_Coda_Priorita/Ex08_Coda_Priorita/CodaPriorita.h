//
//  CodaPriorita.h
//  Ex08_Coda_Priorita
//
//  Created by Valentino Tombesi on 31/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

#ifndef __Ex08_Coda_Priorita__CodaPriorita__
#define __Ex08_Coda_Priorita__CodaPriorita__

#define MAXEL 6
#define TRUE 1
#define FALSE 0
#define VUOTA -1
// definizioni struttura dati Coda
typedef int TipoInfo;
typedef struct {
    int front;
    int rear;
    TipoInfo info[MAXEL];
} TipoCoda;
void Inizializza(TipoCoda *q);
int CodaVuota(TipoCoda q);
int CodaPiena(TipoCoda q);
TipoInfo Front(TipoCoda q);
void EnQueue(TipoCoda *q, TipoInfo x);
void DeQueue(TipoCoda *q);

#endif /* defined(__Ex08_Coda_Priorita__CodaPriorita__) */
