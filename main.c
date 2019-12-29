#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "estruturas.h"
#include "filaPrioridade.h"
#include "filaInstantes.h"
#include "funcRol.h"
#include "pedidos.h"
#include "fabrica.h"



int main() {
    srand(time(NULL));
    printf("Hello, World!\n");

    fabrica *fab;
    fab = iniciaFabrica();

    double tempoTotal;
    printf("\n Digite o tempo de simulacao: ");
    scanf("%lf", &tempoTotal);

    setTempoAtual(fab, getTmpParada(fab));
    while (getTempoAtual(fab) < tempoTotal){

        realizaOperacao(fab);
        proxInstante(fab);
        setTempoAtual(fab, getTmpParada(fab));

    }



    finalizaFabrica(fab);





    return 0;
}