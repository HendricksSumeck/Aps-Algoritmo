#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void troll_nome_monstro(struct monstros *troll){

    printf("                              %s\n", troll->nome);
    printf("                              LVL = %d\n", troll->lvl);
    printf("                              HP = %d\n", troll->HP);
    printf("                              Forca = %d\n", troll->forca);
    printf("                              Armadura = %d\n", troll->armadura);
    printf("                              Inteligencia = %d\n", troll->inteligencia);
    printf("                              Agilidade = %d\n", troll->agilidade);
    printf("\n");

}

static int troll_ataque_fraco(struct monstros *troll){

    int X;

    if(troll->staminia < 2){

        return -1;

    }

    if(troll->staminia >= 2){

        X = rand() % troll->forca;

        return X;

    }

}

static int troll_ataque_forte(struct monstros *troll){

    int X;

    if(troll->staminia < 2){

        return -1;

    }

    if(troll->staminia >= 2){

        X = rand() % troll->agilidade;

        return X;

    }

}

static int troll_magia1(struct monstros *troll){

    int X;

    if(troll->staminia < 4){

        return -1;

    }

    if(troll->staminia >= 4){

        X = rand() % troll->forca + troll->agilidade;

        return X;

    }

}

static int troll_magia2(struct monstros *troll){

    int X;

    if(troll->staminia < 4){

        return -1;

    }

    if(troll->staminia >= 4){

        X = 2 + rand() % troll->forca;

        return X;

    }

}

static void troll_descanso(struct monstros *troll){

    if(troll->staminia == 10){
        printf("                              Impossivel descansar\n");
    }
    if(troll->staminia == 9){
        troll->staminia++;
        printf("                              troll descansou\n");
    }
    if(troll->staminia < 9){
        troll->staminia = troll->staminia + 1;
        printf("                              troll descansou\n", troll->staminia);
    }

}

static void troll_menu(int A, int X){

    if(A == 0){
        printf("                              Soco = %d\n", X);
    }
    if(A == 1){
        printf("                              Esmagar = %d\n", X);
    }
    if(A == 2){
        printf("                              Agarramento = %d\n", X);
    }
    if(A == 3){
        printf("                              Espancar = %d\n", X);
    }

}

static void troll_muda_staminia(struct monstros *troll, int A){

    if(A == 0){
        troll->staminia = troll->staminia - 2;
    }
    if(A == 1){
        troll->staminia = troll->staminia - 2;
    }
    if(A == 2){
        troll->staminia = troll->staminia - 4;
    }
    if(A == 3){
        troll->staminia = troll->staminia - 4;
    }

}

static int troll_verifica_staminia(struct monstros *troll, int A){

    if(A == 10){
        return 4;
    }

    if(A == 0){
        return 2;
    }
    if(A == 1){
        return 2;
    }
    if(A == 2){
        return 4;
    }
    if(A == 3){
        return 4;
    }

}

Monstro *new_troll(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *troll = (Monstro *) malloc(sizeof(Monstro));

    troll->nome = nome;
    troll->lvl = lvl;
    troll->HP = HP;
    troll->forca = forca;
    troll->armadura = armadura;
    troll->inteligencia = inteligencia;
    troll->agilidade = agilidade;
    troll->staminia = 10;

    troll->nome_monstro = troll_nome_monstro;
    troll->ataque_fraco = troll_ataque_fraco;
    troll->ataque_forte = troll_ataque_forte;
    troll->monstro_magia1 = troll_magia1;
    troll->monstro_magia2 = troll_magia2;
    troll->monstro_descanso = troll_descanso;
    troll->monstro_menu = troll_menu;
    troll->monstro_muda_staminia = troll_muda_staminia;
    troll->monstro_verifica_staminia = troll_verifica_staminia;

    return troll;

}
