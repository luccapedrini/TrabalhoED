
#include <stdio.h>
#include <stdlib.h>
#include "pedidos.h"
#include "estruturas.h"
#include "filaPrioridade.h"
#include "filaInstantes.h"
#include "funcRol.h"
#include "funcRandomicoProfessor.h"
#include "funcCilindrico.h"
#include "funcConico.h"
#include "funcEsfA.h"
#include "funcEsfT.h"


void movePedido (fabrica *fab){
    int maquina;
    maquina = fab->instantes->aux;

    nodef *aux;
    aux = fab->maquinas[maquina]; /*auxiliar para guardar a primeira posisçao*/

    if(fab->maquinas[maquina] != NULL) {
        fab->maquinas[maquina] = fab->maquinas[maquina]->prox; /*pula para o proximo rolamento da fila*/
    }
    else{
        return;
    }


    if (fab->maquinas[maquina] != NULL){            /*se ele não for nulo incia seu tempo em maquina*/
        fab->maquinas[maquina]->ante = NULL;

        nodeInst *novoInstante;
        double proxParada = fab->tmpAtual + fab->maquinas[maquina]->rol->tmpEmMaq[fab->maquinas[maquina]->rol->estado];
        novoInstante = criaNodeInst(&movePedido,maquina,proxParada);
        fab->instantes = insereInst(fab->instantes, novoInstante);

    }

    aux->prox = NULL;
    aux->rol->estado++;




    if (aux->rol->estado > 4 || aux->rol->maquina[aux->rol->estado] < 0){  /*verifica se o rolamento passou por tds as maquinas*/
        aux->rol->finaliza(fab, aux->rol->tmpEntrada);
        liberaNode(aux);
		aux = NULL;


    }
    else{
        int maq = aux->rol->maquina[aux->rol->estado];
        if (fab->maquinas[maq] == NULL){ /*verifica se a maquina esta vazia, se sim começa o tempo do pedido em prod. na maquina*/
            nodeInst *novoInstante;
            double proxParada = fab->tmpAtual + aux->rol->tmpEmMaq[aux->rol->estado]; /*tempo que vai sair da maquina = tempo atual + tempo de estadia*/
            novoInstante = criaNodeInst(&movePedido,maq,proxParada);
            fab->instantes = insereInst(fab->instantes,novoInstante);

        }
        fab->maquinas[maq] = insere(fab->maquinas[maq],aux);

    }

}


void iniciaPedido(fabrica *fab, void (*funcInicia)(fabrica*), void (*funcFinaliza)(fabrica*, double), int seqMaq[],float estadia[], float chegada, int prio){

    rolamento *rol;
    rol = criaRol(funcInicia, funcFinaliza, seqMaq, estadia, chegada, prio);

    nodef *novoNode;
    novoNode = criaNode(rol);  /*cria novo rolamento a ser inserido na fabrica*/

    int maq = rol->maquina[rol->estado]; /*pega a maquina que deve ser inserido*/

    if (fab->maquinas[maq] == NULL){ /*verifica se a maquina esta vazia, se sim começa o tempo do pedido em prod. na maquina*/

        nodeInst *novoInstante;
        double proxParada = fab->tmpAtual + rol->tmpEmMaq[rol->estado]; /*tempo que vai sair da maquina = tempo atual + tempo de estadia*/
        novoInstante = criaNodeInst(&movePedido,maq,proxParada);
        fab->instantes = insereInst(fab->instantes,novoInstante);

    }
    novoNode->rol->tmpEntrada = fab->tmpAtual;                  /*guarda o tempo de entrada*/
    fab->maquinas[maq] = insere(fab->maquinas[maq], novoNode); /*insere o rolamento na maquina*/


    ////// GERA PROXIMO PEDIDO
    nodeInst *novoInstante;
    double proxParada = fab->tmpAtual + Gera_Exponencial(rol->mediaDeChegada) ; /*tempo que vai sair da maquina = tempo atual + tempo para chegar o proximo*/
    novoInstante = criaNodeInst(rol->inicia,maq,proxParada);                    /*cria um instante com a funçao inicia do rolamento*/
    fab->instantes = insereInst(fab->instantes,novoInstante);
}
