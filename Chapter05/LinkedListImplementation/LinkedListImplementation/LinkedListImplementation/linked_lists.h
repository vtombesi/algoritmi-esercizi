//
//  linked_lists.h
//  LinkedListImplementation
//
//  Created by Valentino Tombesi on 13/03/17.
//  Copyright (c) 2017 Valentino Tombesi. All rights reserved.
//

//typedef struct TipoElemento ElemLista;
//typedef ElemLista *PElemLista;
//
//typedef struct
//{
//    int value;
//    PElemLista next;
//} TipoElemento;

typedef struct node {
    int value;
    struct node *next;
} node_t;