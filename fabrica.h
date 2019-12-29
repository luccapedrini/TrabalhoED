
#include "estruturas.h"

#ifndef TRABALHOED_FABRICA_H
#define TRABALHOED_FABRICA_H

fabrica *iniciaFabrica();
double getTempoAtual (fabrica *fab);
void setTempoAtual(fabrica *fab, double tempo);
double getTmpParada(fabrica *fab);
void realizaOperacao(fabrica *fab);
void proxInstante(fabrica *fab);
void finalizaFabrica(fabrica *fab);

#endif //TRABALHOED_FABRICA_H
