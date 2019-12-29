
#include "funcEsfT.h"
#include "estruturas.h"
#include "pedidos.h"
#include "enum.h"

static int seqMaq[5]= {FRESA,MANDRIL,TORNO,FRESA,TORNO};
static float estadia[5] = {0.6,1.5,1.6,0.6,1.6};
static float chegada = 8.0;

void finalizaEsfT(fabrica *fab,double tmpEntrada){
    fab->qtdConcluido[ESFT]++;
    fab->tmpMedio[ESFT] = fab->tmpMedio[ESFT] + (fab->tmpAtual - tmpEntrada);

}

void iniciaEsfT(fabrica *fab){
    iniciaPedido(fab,&iniciaEsfT, &finalizaEsfT, seqMaq, estadia, chegada, ALTA);

}