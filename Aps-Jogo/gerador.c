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

Monstro *gerar_orc(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *orc_nome;
    char *nomes_orc[] = {

        "Orc Berseker",
        "Lider Orc",
        "Orc Shaman",
        "Orc Saqueador",
        "Guerreiro Orc"

    };

    X = rand() % 5;

    orc_nome = (char*) malloc(sizeof(char) * strlen(nomes_orc[X]));

    strcpy(orc_nome, nomes_orc[X]);

    meus_monstros = new_orcs(orc_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}

Monstro *gerar_gigante(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *gigante_nome;
    char *nomes_gigante[] = {

        "Cyclop",
        "Yeti",
        "Gigante",
        "Behemoth",
        "Orclops"

    };

    X = rand() % 5;

    gigante_nome = (char*) malloc(sizeof(char) * strlen(nomes_gigante[X]));

    strcpy(gigante_nome, nomes_gigante[X]);

    meus_monstros = new_gigante(gigante_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}

Monstro *gerar_goblin(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *goblin_nome;
    char *nomes_goblin[] = {

        "Lider Goblin",
        "Goblin Assasino",
        "Goblin Guerreiro",
        "Mago Goblin"

    };

    X = rand() % 4;

    goblin_nome = (char*) malloc(sizeof(char) * strlen(nomes_goblin[X]));

    strcpy(goblin_nome, nomes_goblin[X]);

    meus_monstros = new_goblin(goblin_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}

Monstro *gerar_troll(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *troll_nome;
    char *nomes_troll[] = {

        "Troll Furioso",
        "Guarda Troll",
        "Troll Legionario",
        "Troll do Pantano",
        "Lider Troll"

    };

    X = rand() % 5;

    troll_nome = (char*) malloc(sizeof(char) * strlen(nomes_troll[X]));

    strcpy(troll_nome, nomes_troll[X]);

    meus_monstros = new_troll(troll_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}

Monstro *gerar_minotauro(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *minotauro_nome;
    char *nomes_minotauro[] = {

        "Minotauro Hunter",
        "Legionario Minotauro",
        "Guarda Minotauro",
        "Centauro",
        "Executor"

    };

    X = rand() % 5;

    minotauro_nome = (char*) malloc(sizeof(char) * strlen(nomes_minotauro[X]));

    strcpy(minotauro_nome, nomes_minotauro[X]);

    meus_monstros = new_minotauro(minotauro_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}

Monstro *gerar_pirata(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *pirata_nome;
    char *nomes_pirata[] = {

        "Bucaneiro",
        "Corsario",
        "Pirata Esqueleto",
        "Barba Negra"
        "Jack Sparrow"

    };

    X = rand() % 5;

    pirata_nome = (char*) malloc(sizeof(char) * strlen(nomes_pirata[X]));

    strcpy(pirata_nome, nomes_pirata[X]);

    meus_monstros = new_pirata(pirata_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}

Monstro *gerar_djinn(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *djinn_nome;
    char *nomes_djinn[] = {

        "Ghul",
        "Ifrit",
        "Marid",
        "Genio"

    };

    X = rand() % 4;

    djinn_nome = (char*) malloc(sizeof(char) * strlen(nomes_djinn[X]));

    strcpy(djinn_nome, nomes_djinn[X]);

    meus_monstros = new_djinn(djinn_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}

Monstro *gerar_dragao(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *dragao_nome;
    char *nomes_dragao[] = {

        "Death Dragon",
        "Lord Dragon",
        "Fire Dragon",
        "Frost Dragon",
        "Royal Dragon"

    };

    X = rand() % 5;

    dragao_nome = (char*) malloc(sizeof(char) * strlen(nomes_dragao[X]));

    strcpy(dragao_nome, nomes_dragao[X]);

    meus_monstros = new_dragao(dragao_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}

Monstro *gerar_demonio(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *demonio_nome;
    char *nomes_demonio[] = {

        "Rift Lord",
        "Spawn",
        "Eclipse Knight",
        "Juggernaut",
        "Nightmare",
        "Rift Shadow"

    };

    X = rand() % 6;

    demonio_nome = (char*) malloc(sizeof(char) * strlen(nomes_demonio[X]));

    strcpy(demonio_nome, nomes_demonio[X]);

    meus_monstros = new_demonio(demonio_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}

Monstro *gerar_animais(struct personagem *aventureiro){

    Monstro *meus_monstros;

    int X;
    char *animais_nome;
    char *nomes_animais[] = {

        "Raposa",
        "Lobo",
        "Cão",
        "Tigre",
        "Leão",
        "Pantera",
        "Lobisomen",
        "Doginho",
        "Cerberus",
        "Bad Wolf",
        "Passaro"

    };

    X = rand() % 11;

    animais_nome = (char*) malloc(sizeof(char) * strlen(nomes_animais[X]));

    strcpy(animais_nome, nomes_animais[X]);

    meus_monstros = new_animal(animais_nome, 1 + aventureiro->lvl, 10 +  (2 * aventureiro->lvl), 3 + (1 * aventureiro->lvl), 4, 3 + (1 * aventureiro->lvl) ,3 + (1 * aventureiro->lvl));

    return meus_monstros;

}
