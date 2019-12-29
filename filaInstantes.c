
#include "filaInstantes.h"
#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

nodeInst *criaNodeInst (void (*funcEnt)(fabrica*), int aux, double tmpParada){
    nodeInst *novoNode = (nodeInst*)malloc(sizeof(nodeInst));
    novoNode->opera = funcEnt;
    novoNode->tmpParada = tmpParada;
    novoNode->aux = aux;
    novoNode->ante = NULL;
    novoNode->prox = NULL;

    return novoNode;
}

nodeInst *insereInst(nodeInst *ini, nodeInst *novoNode){
    if (ini == NULL){
        ini = novoNode;
        return ini;
    }

    if (ini->tmpParada >= novoNode->tmpParada){
        ini->ante = novoNode;
        novoNode->prox = ini;
        ini = novoNode;
        return ini;

    }

    nodeInst *aux = ini;
    while (aux->tmpParada < novoNode->tmpParada && aux != NULL){ ///////////////////
        if (aux->prox == NULL && aux->tmpParada < novoNode->tmpParada){ /////////////////
            aux->prox = novoNode;
            novoNode->ante = aux;
            return ini;
        }
        aux = aux->prox;
    }




    novoNode->prox = aux;
    novoNode->ante = aux->ante;
    aux->ante = novoNode;
    novoNode->ante->prox = novoNode;


    return ini;
}

void printaFilaInst(nodeInst *ini){ /*funcao usada para debugar o codigo*/
    nodeInst *aux = ini;
    printf("\n\n[   ");
    while (aux != NULL){
        printf ("%lf", aux->tmpParada);
        printf(", %d   ", aux->aux);
        aux = aux->prox;
    }
    printf("]\n\n");
}
