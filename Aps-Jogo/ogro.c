#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void ogro_nome_monstro(struct monstros *ogro){

    printf("                              %s\n", ogro->nome);
    printf("                              LVL = %d\n", ogro->lvl);
    printf("                              HP = %d\n", ogro->HP);
    printf("                              Forca = %d\n", ogro->forca);
    printf("                              Armadura = %d\n", ogro->armadura);
    printf("                              Inteligencia = %d\n", ogro->inteligencia);
    printf("                              Agilidade = %d\n", ogro->agilidade);
    printf("\n");

}

static int ogro_ataque_fraco(struct monstros *ogro){

    int X;

    if(ogro->staminia < 1){

        return -1;

    }

    if(ogro->staminia >= 1){

        X = rand() % ogro->forca;

        return X;

    }

}

static int ogro_ataque_forte(struct monstros *ogro){

    int X;

    if(ogro->staminia < 2){

        return -1;

    }

    if(ogro->staminia >= 2){

        X = rand() % ogro->forca;

        return X;

    }

}

static int ogro_magia1(struct monstros *ogro){

    int X;

    if(ogro->staminia < 3){

        return -1;

    }

    if(ogro->staminia >= 3){

        X = rand() % ogro->forca;

        return X;

    }

}

static int ogro_magia2(struct monstros *ogro){

    int X;

    if(ogro->staminia < 4){

        return -1;

    }

    if(ogro->staminia >= 4){

        X = rand() % ogro->forca;

        return X;

    }

}

static void ogro_descanso(struct monstros *ogro){

    if(ogro->staminia == 10){
        printf("                              Impossivel descansar\n");
    }
    if(ogro->staminia == 9){
        ogro->staminia++;
        printf("                              Ogro descansou\n");
    }
    if(ogro->staminia < 9){
        ogro->staminia = ogro->staminia + 1;
        printf("                              Ogro descansou\n", ogro->staminia);
    }

}

static void ogro_menu(int A, int X){

    if(A == 0){
        printf("                              Soco = %d\n", X);
    }
    if(A == 1){
        printf("                              Arranhao = %d\n", X);
    }
    if(A == 2){
        printf("                              Tapa na orelha = %d\n", X);
    }
    if(A == 3){
        printf("                              Jogar pedra = %d\n", X);
    }

}

static void ogro_muda_staminia(struct monstros *ogro, int A){

    if(A == 0){
        ogro->staminia = ogro->staminia - 1;
    }
    if(A == 1){
        ogro->staminia = ogro->staminia - 2;
    }
    if(A == 2){
        ogro->staminia = ogro->staminia - 3;
    }
    if(A == 3){
        ogro->staminia = ogro->staminia - 4;
    }

}

static int ogro_verifica_staminia(struct monstros *ogro, int A){

    if(A == 10){
        return 4;
    }

    if(A == 0){
        return 1;
    }
    if(A == 1){
        return 2;
    }
    if(A == 2){
        return 3;
    }
    if(A == 3){
        return 4;
    }

}

Monstro *new_ogro(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *ogro = (Monstro *) malloc(sizeof(Monstro));

    ogro->nome = nome;
    ogro->lvl = lvl;
    ogro->HP = HP;
    ogro->forca = forca;
    ogro->armadura = armadura;
    ogro->inteligencia = inteligencia;
    ogro->agilidade = agilidade;
    ogro->staminia = 10;

    ogro->nome_monstro = ogro_nome_monstro;
    ogro->ataque_fraco = ogro_ataque_fraco;
    ogro->ataque_forte = ogro_ataque_forte;
    ogro->monstro_magia1 = ogro_magia1;
    ogro->monstro_magia2 = ogro_magia2;
    ogro->monstro_descanso = ogro_descanso;
    ogro->monstro_menu = ogro_menu;
    ogro->monstro_muda_staminia = ogro_muda_staminia;
    ogro->monstro_verifica_staminia = ogro_verifica_staminia;

    return ogro;

}
