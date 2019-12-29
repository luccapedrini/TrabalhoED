
#ifndef TRABALHOED_PEDIDOS_H
#define TRABALHOED_PEDIDOS_H

#include "estruturas.h"

void iniciaPedido(fabrica *fab, void (*funcInicia)(fabrica*), void (*funcFinaliza)(fabrica*, double), int seqMaq[],float estadia[], float chegada, int prio);
void movePedido (fabrica *fab);


#endif //TRABALHOED_PEDIDOS_H
