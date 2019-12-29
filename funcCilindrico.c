
#include "funcCilindrico.h"
#include "estruturas.h"
#include "pedidos.h"
#include "enum.h"

static int seqMaq[5]={TORNO,FRESA,TORNO,MANDRIL,-1};
static float estadia[5] ={0.8,0.5,0.8,1.2,0.0};
static float chegada = 21.5;

void finalizaCilindro(fabrica *fab,double tmpEntrada){
    fab->qtdConcluido[CILINDRICO]++;
    fab->tmpMedio[CILINDRICO] = fab->tmpMedio[CILINDRICO] + (fab->tmpAtual - tmpEntrada);

}

void iniciaCilindro(fabrica *fab) {
    iniciaPedido(fab,&iniciaCilindro, &finalizaCilindro, seqMaq, estadia, chegada, BAIXA);

}