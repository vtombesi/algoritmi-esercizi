//
//  main.c
//  Ex01_4
//
//  Created by GraverValentine on 27/03/17.
//  Copyright © 2017 GraverValentine. All rights reserved.
//
//  Esercizio
//  Progettare una applicazione c che gestisca una matrice di interi M ed una lista di interi	L	.	M	è	una	matrice	quadrata	n	x	n		con	n	scelto	in	maniera	dinamica    (ad es: inserito	dall’utente	in	fase di	esecuzione).
//  Implementare le	strutture dati e le	seguenti funzioni:

//  Serializza:	data	la	matrice	M	di	dimensione	nxn	restituisce	una	lista	contenente
//  n2 elementi.	Gli	elementi	nella	lista	sono	gli	elementi	di	M	ordinati	per	righe	a
//  partire	dalla	prima	riga	fino	all’ultima.

//  Deserializza:	Data	una	lista	L	contenente	n2 interi,	restituisce	una	matrice	nxn
//  che	contiene	gli	elementi	di	L	organizzati	per	file	di	lunghezza	n.
//  Nota:	utilizzare	sempre	l’allocazione	dinamica	per	le	matrici.

//  Main:	nella	funzione	main	l’utente	specifica	la	dimensione	n	della	matrice	e
//  riempie	la	matrice	M	di	valori	interi.	L’applicazione	serializza	la	matrice,	stampa
//  a	video	la	lista	serializzata,	somma	il	valore	5	ad	ogni	elementro	della	lista,
//  deserializza	la	lista	e	termina	visualizzando	la	matrice	che	contiene	gli	elementi
//  deserializzati	della	lista.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** deserializza(int *L, int N) {
    int i, j, k=0;
    int **M;
    
    M = (int**) malloc(N*sizeof(int));
    
    for (i=0;i<N;i++) {
        M[i] = (int*) calloc(N, sizeof(int));
    }
    
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            M[i][j]=L[k++];
        }
    }
    
    return M;
}

int* serializza(int **M, int N) {
    int i, j;
    int *ptrL;
    int *L;
    
    L=(int*) malloc(N*N*sizeof(int));
    ptrL=L;
    
    if (L==NULL)
        return NULL;
    
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            *(L++)=M[i][j];
        }
    }
    
    return ptrL;
}

// Visualizza la lista
void visualizzaL(int *L, int n) {
    int i;
    
    printf("\nLa lista e':\n");
    
    for(i=0;i<n*n;i++) {
        printf("%10d\n",L[i]);
    }
    printf("\n");
    
    return;
}
// Visualizza la matrice
void visualizzaM(int **M, int n)
{
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%10d ", M[i][j]);
        }
    }
    return;
}

int main() {

    int **M;  // Matrice nxn
    int **Mout; // matrice in cui si metterà la lista deserializzata
    int *lista; // Lista vista come vettore
    int n;    // dimensiore M
    int i, j;
    
    printf("Inserire quanti elementi  \n");
    scanf("%d", &n);
    
    M = (int**) malloc(n*sizeof(int));
    
    if(M == NULL) {
        printf("Errore malloc()!!");
        return -1;
    }
    
    for(i=0;i<n;i++)
    {
        M[i] = (int*) calloc(n, sizeof(int));
        if(M[i]==NULL)
        {
            printf("Errore malloc()!!");
            return -1;
        }
    }
    
    srand(time(NULL));
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            M[i][j] = (int) rand();
        }
    }
    
    printf("Visualizziamo la matrice M\n");
    visualizzaM( M, n);
    
    lista = serializza( M, n);
    printf("\nStampo la lista\n");
    
    visualizzaL( lista, n);
    // sommiamo 5 ad ogni elemento della lista
    for (i=0;i<n*n;i++)
        lista[i]+=5;
    // deserializziamo L in Mout
    Mout = deserializza(lista,n);
    printf("Visualizziamo la matrice Mout\n");
    visualizzaM( Mout , n);
    // Liberiamo la memoria
    for (i=0;i<n;i++)
        free(M[0]);
    free(M);
    for (i=0;i<n;i++)
        free(Mout[0]);
    free(Mout);
    free(lista);
    
    return 0;
}
