
#ifndef TRABALHOED_FUNCROL_H
#define TRABALHOED_FUNCROL_H

#include "estruturas.h"

rolamento *criaRol(void (*funcInicia)(fabrica*), void (*funcFinaliza)(fabrica*,double), int seqMaq[],float estadia[], float chegada, int prio);

#endif //TRABALHOED_FUNCROL_H
