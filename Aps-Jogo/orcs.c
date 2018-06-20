#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void orcs_nome_monstro(struct monstros *orcs){

    printf("%s\n", orcs->nome);
    printf("LVL = %d\n", orcs->lvl);
    printf("HP = %d\n", orcs->HP);
    printf("Forca = %d\n", orcs->forca);
    printf("Armadura = %d\n", orcs->armadura);
    printf("Inteligencia = %d\n", orcs->inteligencia);
    printf("Agilidade = %d\n", orcs->agilidade);
    printf("\n");

}

static int orcs_ataque_fraco(struct monstros *orcs){

    int X;

    if(orcs->staminia < 4){

        return -1;

    }

    if(orcs->staminia >= 4){

        X = rand() % orcs->forca + orcs->lvl;

        return X;

    }

}

static int orcs_ataque_forte(struct monstros *orcs){

    int X;

    if(orcs->staminia < 2){

        return -1;

    }

    if(orcs->staminia >= 2){

        X = 2 + rand() % orcs->forca;

        return X;

    }

}

static int orcs_magia1(struct monstros *orcs){

    int X, Y;

    if(orcs->staminia < 4){

        return -1;

    }

    if(orcs->staminia >= 4){

        X = rand() % orcs->forca;
        Y = rand() % orcs->forca;

        X = X + Y;

        return X;

    }

}

static int orcs_magia2(struct monstros *orcs){

    int X, Y;

    if(orcs->staminia < 5){

        return -1;

    }

    if(orcs->staminia >= 5){

        X = rand() % orcs->agilidade;
        Y = rand() % orcs->forca;

        X = X + Y;

        return X;

    }

}

static void orcs_descanso(struct monstros *orcs){

    if(orcs->staminia == 10){
        printf("Impossivel descansar\n");
    }
    if(orcs->staminia == 9){
        orcs->staminia++;
        printf("orcs descansou\n");
    }
    if(orcs->staminia < 9){
        orcs->staminia = orcs->staminia + 1;
        printf("orcs descansou\n", orcs->staminia);
    }

}

static void orcs_menu(int A, int X){

    if(A == 0){
        printf("Machadada = %d\n", X);
    }
    if(A == 1){
        printf("Explosão de Furia = %d\n", X);
    }
    if(A == 2){
        printf("Corte Duplo = %d\n", X);
    }
    if(A == 3){
        printf("Pião de Laminas = %d\n", X);
    }

}

static void orcs_muda_staminia(struct monstros *orcs, int A){

    if(A == 0){
        orcs->staminia = orcs->staminia - 4;
    }
    if(A == 1){
        orcs->staminia = orcs->staminia - 2;
    }
    if(A == 2){
        orcs->staminia = orcs->staminia - 4;
    }
    if(A == 3){
        orcs->staminia = orcs->staminia - 5;
    }

}

static int orcs_verifica_staminia(struct monstros *orcs, int A){

    if(A == 10){
        return 5;
    }

    if(A == 0){
        return 4;
    }
    if(A == 1){
        return 2;
    }
    if(A == 2){
        return 4;
    }
    if(A == 3){
        return 5;
    }

}

Monstro *new_orcs(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *orcs = (Monstro *) malloc(sizeof(Monstro));

    orcs->nome = nome;
    orcs->lvl = lvl;
    orcs->HP = HP;
    orcs->forca = forca;
    orcs->armadura = armadura;
    orcs->inteligencia = inteligencia;
    orcs->agilidade = agilidade;
    orcs->staminia = 10;

    orcs->nome_monstro = orcs_nome_monstro;
    orcs->ataque_fraco = orcs_ataque_fraco;
    orcs->ataque_forte = orcs_ataque_forte;
    orcs->monstro_magia1 = orcs_magia1;
    orcs->monstro_magia2 = orcs_magia2;
    orcs->monstro_descanso = orcs_descanso;
    orcs->monstro_menu = orcs_menu;
    orcs->monstro_muda_staminia = orcs_muda_staminia;
    orcs->monstro_verifica_staminia = orcs_verifica_staminia;

    return orcs;

}
