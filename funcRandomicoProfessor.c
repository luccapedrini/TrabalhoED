//
// funcoes disponibilizadas pelo professor para a realizaçao do trabalho
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "funcRandomicoProfessor.h"

double Gera_Exponencial (float avg)
{
    float u=0; /* Gera randomicamente um numero entre 0 e 1 */
    do
        u = ((float)rand()) / ((float) RAND_MAX);
    while ((u==0) || (u==1));
    return (-avg * log (u));
}

double tempo(float Estadia_Equipamento_Rolamento)
{
    float u = ((float)rand()) / ((float) RAND_MAX);
    return 2.0 * Estadia_Equipamento_Rolamento * u;
}