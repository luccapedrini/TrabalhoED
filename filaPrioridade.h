
#include "estruturas.h"

#ifndef TRABALHOED_FILAPRIORIDADE_H
#define TRABALHOED_FILAPRIORIDADE_H

nodef *criaNode (rolamento *novoRol);
nodef *insere(nodef *ini, nodef *novoNode);
void printaFila(nodef *ini);
void liberaNode(nodef *node);

#endif //TRABALHOED_FILAPRIORIDADE_H
