
#include "funcConico.h"
#include "estruturas.h"
#include "pedidos.h"
#include "enum.h"

static int seqMaq[5] = {TORNO,MANDRIL,TORNO,-1,-1};
static float estadia[5] = {1.8,2.1,1.8,0.0,0.0};
static float chegada = 19.1;

void finalizaConico(fabrica *fab,double tmpEntrada){
    fab->qtdConcluido[CONICO]++;
    fab->tmpMedio[CONICO] = fab->tmpMedio[CONICO] + (fab->tmpAtual - tmpEntrada);

}

void iniciaConico(fabrica *fab){
    iniciaPedido(fab,&iniciaConico, &finalizaConico, seqMaq, estadia, chegada, MEDIA);

}