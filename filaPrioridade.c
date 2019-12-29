
#include "filaPrioridade.h"
#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"


nodef *criaNode (rolamento *novoRol){
    nodef *novoNode = (nodef*)malloc(sizeof(nodef));

    novoNode->rol = novoRol;
    novoNode->ante = NULL;
    novoNode->prox = NULL;

    return novoNode;
}

nodef *insere(nodef *ini, nodef *novoNode){
    if (ini == NULL){
        ini = novoNode;
        return ini;
    }

    if (ini->prox == NULL){
        ini->prox = novoNode;
        novoNode->ante = ini;
        return ini;

    }

    nodef *aux = ini->prox;
    while (aux->rol->prio > novoNode->rol->prio && aux != NULL){
        if (aux->prox == NULL && aux->rol->prio > novoNode->rol->prio){
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

/*void printaFila(nodef *ini){ ///funcao usada para debugar o codigo
    nodef *aux = ini;
    printf("\n\n[   ");
    while (aux != NULL){
        printf ("%d   ", aux->rol->tipo);
        aux = aux->prox;
    }
    printf("]\n");
}*/

void liberaNode(nodef *node){

    if (node != NULL){
        free(node->rol);
        free(node);
    }

}