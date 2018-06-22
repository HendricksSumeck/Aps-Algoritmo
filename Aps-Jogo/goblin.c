#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void goblin_nome_monstro(struct monstros *goblin){

    printf("                              %s\n", goblin->nome);
    printf("                              LVL = %d\n", goblin->lvl);
    printf("                              HP = %d\n", goblin->HP);
    printf("                              Forca = %d\n", goblin->forca);
    printf("                              Armadura = %d\n", goblin->armadura);
    printf("                              Inteligencia = %d\n", goblin->inteligencia);
    printf("                              Agilidade = %d\n", goblin->agilidade);
    printf("\n");

}

static int goblin_ataque_fraco(struct monstros *goblin){

    int X;

    if(goblin->staminia < 1){

        return -1;

    }

    if(goblin->staminia >= 1){

        X = rand() % goblin->forca;

        return X;

    }

}

static int goblin_ataque_forte(struct monstros *goblin){

    int X;

    if(goblin->staminia < 2){

        return -1;

    }

    if(goblin->staminia >= 2){

        X = rand() % goblin->agilidade;

        return X;

    }

}

static int goblin_magia1(struct monstros *goblin){

    int X;

    if(goblin->staminia < 2){

        return -1;

    }

    if(goblin->staminia >= 2){

        X = rand() % goblin->forca + goblin->agilidade;

        return X;

    }

}

static int goblin_magia2(struct monstros *goblin){

    int X;

    if(goblin->staminia < 1){

        return -1;

    }

    if(goblin->staminia >= 1){

        X = 2 + goblin->lvl;

        return X;

    }

}

static void goblin_descanso(struct monstros *goblin){

    if(goblin->staminia == 10){
        printf("                              Impossivel descansar\n");
    }
    if(goblin->staminia == 9){
        goblin->staminia++;
        printf("                              goblin descansou\n");
    }
    if(goblin->staminia < 9){
        goblin->staminia = goblin->staminia + 1;
        printf("                              goblin descansou\n", goblin->staminia);
    }

}

static void goblin_menu(int A, int X){

    if(A == 0){
        printf("                              Facada = %d\n", X);
    }
    if(A == 1){
        printf("                              Chute Baixo = %d\n", X);
    }
    if(A == 2){
        printf("                              Flechada = %d\n", X);
    }
    if(A == 3){
        printf("                              Granada De Bosta = %d\n", X);
    }

}

static void goblin_muda_staminia(struct monstros *goblin, int A){

    if(A == 0){
        goblin->staminia = goblin->staminia - 1;
    }
    if(A == 1){
        goblin->staminia = goblin->staminia - 2;
    }
    if(A == 2){
        goblin->staminia = goblin->staminia - 2;
    }
    if(A == 3){
        goblin->staminia = goblin->staminia - 1;
    }

}

static int goblin_verifica_staminia(struct monstros *goblin, int A){

    if(A == 10){
        return 2;
    }

    if(A == 0){
        return 1;
    }
    if(A == 1){
        return 2;
    }
    if(A == 2){
        return 2;
    }
    if(A == 3){
        return 1;
    }

}

Monstro *new_goblin(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *goblin = (Monstro *) malloc(sizeof(Monstro));

    goblin->nome = nome;
    goblin->lvl = lvl;
    goblin->HP = HP;
    goblin->forca = forca;
    goblin->armadura = armadura;
    goblin->inteligencia = inteligencia;
    goblin->agilidade = agilidade;
    goblin->staminia = 10;

    goblin->nome_monstro = goblin_nome_monstro;
    goblin->ataque_fraco = goblin_ataque_fraco;
    goblin->ataque_forte = goblin_ataque_forte;
    goblin->monstro_magia1 = goblin_magia1;
    goblin->monstro_magia2 = goblin_magia2;
    goblin->monstro_descanso = goblin_descanso;
    goblin->monstro_menu = goblin_menu;
    goblin->monstro_muda_staminia = goblin_muda_staminia;
    goblin->monstro_verifica_staminia = goblin_verifica_staminia;

    return goblin;

}
