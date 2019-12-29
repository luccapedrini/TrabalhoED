
#include <stdio.h>
#include <stdlib.h>
#include "funcRol.h"
#include "estruturas.h"
#include "pedidos.h"
#include "enum.h"
#include "funcRandomicoProfessor.h"

rolamento *criaRol(void (*funcInicia)(fabrica*), void (*funcFinaliza)(fabrica*,double), int seqMaq[],float estadia[], float chegada, int prio){


    rolamento *novoRol;
    novoRol = malloc(sizeof(rolamento));
    novoRol->prio = prio;
    int i;
    for (i=0;i<=4;i++) {
        novoRol->maquina[i] = seqMaq[i];
        novoRol->tmpEmMaq[i] = tempo(estadia[i]);
    }
    novoRol->estado = 0;
    novoRol->tmpEntrada= 0;
    novoRol->inicia = funcInicia;
    novoRol->finaliza = funcFinaliza;
    novoRol->mediaDeChegada = chegada;



    return novoRol;
}
