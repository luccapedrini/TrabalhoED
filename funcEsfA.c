
#include "funcEsfA.h"
#include "estruturas.h"
#include "pedidos.h"
#include "enum.h"

static int seqMaq[5]={FRESA,MANDRIL,TORNO,-1,-1};
static float estadia[5] ={0.5,1.4,1.0,0.0,0.0};
static float chegada = 8.0;

void finalizaEsfA(fabrica *fab,double tmpEntrada){
    fab->qtdConcluido[ESFA]++;
    fab->tmpMedio[ESFA] = fab->tmpMedio[ESFA] + (fab->tmpAtual - tmpEntrada);

}

void iniciaEsfA(fabrica *fab){
    iniciaPedido(fab,&iniciaEsfA, &finalizaEsfA, seqMaq, estadia, chegada, ALTA);

}