
#include "fabrica.h"
#include "estruturas.h"
#include "stdio.h"
#include "stdlib.h"
#include "funcCilindrico.h"
#include "funcConico.h"
#include "funcEsfA.h"
#include "funcEsfT.h"
#include "enum.h"
#include "filaPrioridade.h"

fabrica *iniciaFabrica(){
    fabrica *fab;
    fab = malloc(sizeof(fabrica));

    int i;
    for (i=0; i < 3; i++) {
        fab->maquinas[i]=NULL;
    }

    fab->instantes = NULL;
    fab->tmpAtual = 0.0;

    for (i=0; i < 4; i++) {
        fab->qtdConcluido[i] = 0;
        fab->tmpMedio[i] = 0.0;
    }

    iniciaCilindro(fab);
    iniciaConico(fab);
    iniciaEsfA(fab);
    iniciaEsfT(fab);

    return fab;
}

double getTempoAtual (fabrica *fab){
    return fab->tmpAtual;
}

void setTempoAtual(fabrica *fab, double tempo){
    fab->tmpAtual = tempo;
}

double getTmpParada(fabrica *fab){
    return fab->instantes->tmpParada;
}

void realizaOperacao(fabrica *fab){
    fab->instantes->opera(fab);
}

void proxInstante(fabrica *fab){

    if (fab->instantes->prox != NULL){
        fab->instantes = fab->instantes->prox;
        free(fab->instantes->ante);
        fab->instantes->ante = NULL;
    }
    else{
        free(fab->instantes);
        fab->instantes = NULL;
    }
}

void printaResultados(fabrica *fab){
    if(fab->qtdConcluido[CILINDRICO] != 0) {
        printf("Quantidade de rolamentos Cilindros concluidos: %d \t Tempo Medio: %lf\n", fab->qtdConcluido[CILINDRICO], fab->tmpMedio[CILINDRICO] / fab->qtdConcluido[CILINDRICO]);
    }
    if(fab->qtdConcluido[CONICO] != 0) {
        printf("Quantidade de rolamentos Conicos concluidos: %d \t Tempo Medio: %lf\n", fab->qtdConcluido[CONICO], fab->tmpMedio[CONICO] / fab->qtdConcluido[CONICO]);
    }
    if(fab->qtdConcluido[ESFA] != 0) {
        printf("Quantidade de rolamentos Efericos Aco concluidos: %d \t Tempo Medio: %lf\n", fab->qtdConcluido[ESFA], fab->tmpMedio[ESFA] / fab->qtdConcluido[ESFA]);
    }
    if(fab->qtdConcluido[ESFT] != 0) {
        printf("Quantidade de rolamentos Efericos Titanio concluidos: %d \t Tempo Medio: %lf\n", fab->qtdConcluido[ESFT], fab->tmpMedio[ESFT] / fab->qtdConcluido[ESFT]);
    }
}


void finalizaFabrica(fabrica *fab){
    printaResultados(fab);

    int i;
    for (i = 0; i < 3; i++ ){                               /*libera memoria alocada para as filas de maquinas*/

        while(fab->maquinas[i] != NULL){
            if (fab->maquinas[i]->prox != NULL){
                fab->maquinas[i] = fab->maquinas[i]->prox;
                liberaNode(fab->maquinas[i]->ante);
				fab->maquinas[i]->ante = NULL;
            }
            else {
                liberaNode(fab->maquinas[i]);
				fab->maquinas[i] = NULL;
            }

        }

    }
    while(fab->instantes != NULL){                          /*libera memoria alocada para a fila de instantes*/

        if (fab->instantes->prox != NULL){
            fab->instantes = fab->instantes->prox;
            free(fab->instantes->ante);
            fab->instantes->ante = NULL;
        }
        else {
            free(fab->instantes);
            fab->instantes = NULL;
        }
    }

    free(fab);
}