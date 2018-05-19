#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Monstros.h"
#include "Personagem.h"

Monstro *gerar_ogro(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *ogro_nome;
    char *nomes_ogro[] = {

        "Ogro Bruto",
        "Ogro Shaman",
        "Ogro Guerreiro"

    };

    X = rand() % 3;

    ogro_nome = (char*) malloc(sizeof(char) * strlen(nomes_ogro[X]));

    strcpy(ogro_nome, nomes_ogro[X]);

    meus_monstros = new_ogro(ogro_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}
