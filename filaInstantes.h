
#include "estruturas.h"

#ifndef TRABALHOED_FILAINSTANTES_H
#define TRABALHOED_FILAINSTANTES_H
nodeInst *criaNodeInst (void (*funcEnt)(fabrica*),int aux, double tmpParada);
nodeInst *insereInst(nodeInst *ini, nodeInst *novoNode);
void printaFilaInst(nodeInst *ini);

#endif //TRABALHOED_FILAINSTANTES_H
