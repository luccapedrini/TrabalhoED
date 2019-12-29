
#ifndef TRABALHOED_ESTRUTURAS_H
#define TRABALHOED_ESTRUTURAS_H

typedef struct rolamento rolamento;
typedef struct fila nodef;
typedef struct nodeInstantes nodeInst;
typedef struct fabrica fabrica;

/////////////////////////////////////////////////////// ROLAMENTO
struct rolamento {

    ///int tipo;               /* tipo usado somente para debugar vai de 0 a 3 */
    int prio;               /*prioridade do rolamento vai de 1 a 3*/
    int maquina[5];         /*sequencia de maquinas que o rolamento passa */
    int estado;             /*estado atual do processo*/
    double tmpEmMaq[5];     /*tempo de estadia em cada maquina*/
    double tmpEntrada;      /*tempo que o rolamento entrou na maquina*/
    void (*inicia)(fabrica*);
    void (*finaliza)(fabrica*, double);
    float mediaDeChegada;

}; /*typedef rolamento*/

/////////////////////////////////////////////////////// FILA DE PRIORIDADE
struct fila {

    rolamento *rol;
    nodef *ante,*prox;

}; /*typedef nodef*/

/////////////////////////////////////////////////////// LISTA INSTANTES
struct nodeInstantes {

    double tmpParada;                   /*tempo em que a operaçao vai ser executada*/
    int aux;                            /*usado somente para movePedido, indica a maquina*/
    void (*opera)(fabrica*);    /*operaçao a ser realizada*/
    nodeInst *ante,*prox;

}; /*typedef nodeInst*/

/////////////////////////////////////////////////////// ESTRUTURA FABRICA
struct fabrica {

    nodef *maquinas[3];                 /*vetor com as maquinas da fabrica*/
    nodeInst *instantes;                /*fila de instantes*/


    unsigned long int qtdConcluido[4];                /*cont de rolamentos concluidos*/
    double tmpMedio[4];                    /*soma de tempos de cada rol*/

    double tmpAtual;


}; /*typedef fabrica*/



#endif //TRABALHOED_ESTRUTURAS_H
