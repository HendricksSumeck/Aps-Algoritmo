#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void pirata_nome_monstro(struct monstros *pirata){

    printf("                              %s\n", pirata->nome);
    printf("                              LVL = %d\n", pirata->lvl);
    printf("                              HP = %d\n", pirata->HP);
    printf("                              Forca = %d\n", pirata->forca);
    printf("                              Armadura = %d\n", pirata->armadura);
    printf("                              Inteligencia = %d\n", pirata->inteligencia);
    printf("                              Agilidade = %d\n", pirata->agilidade);
    printf("\n");

}

static int pirata_ataque_fraco(struct monstros *pirata){

    int X;

    if(pirata->staminia < 2){

        return -1;

    }

    if(pirata->staminia >= 2){

        X = rand() % pirata->agilidade;

        return X;

    }

}

static int pirata_ataque_forte(struct monstros *pirata){

    int X;

    if(pirata->staminia < 2){

        return -1;

    }

    if(pirata->staminia >= 2){

        X = rand() % pirata->forca;
        X = X/2;

        return X;

    }

}

static int pirata_magia1(struct monstros *pirata){

    int X;

    if(pirata->staminia < 3){

        return -1;

    }

    if(pirata->staminia >= 3){

        X = 2 + rand() % pirata->forca;

        return X;

    }

}

static int pirata_magia2(struct monstros *pirata){

    int X, Y, Z;

    if(pirata->staminia < 6){

        return -1;

    }

    if(pirata->staminia >= 6){

        X = pirata->forca / 2;
        Y = pirata->agilidade / 2;
        Z = pirata->inteligencia / 2;

        X = X + Y + Z;

        return X;

    }

}

static void pirata_descanso(struct monstros *pirata){

    if(pirata->staminia == 10){
        printf("                              Impossivel descansar\n");
    }
    if(pirata->staminia == 9){
        pirata->staminia++;
        printf("                              pirata descansou\n");
    }
    if(pirata->staminia < 9){
        pirata->staminia = pirata->staminia + 1;
        printf("                              pirata descansou\n", pirata->staminia);
    }

}

static void pirata_menu(int A, int X){

    if(A == 0){
        printf("                              Golpe com Espada = %d\n", X);
    }
    if(A == 1){
        printf("                              Golpe com a perna de pau = %d\n", X);
    }
    if(A == 2){
        printf("                              Golpe com o gancho = %d\n", X);
    }
    if(A == 3){
        printf("                              Motim dos piratas = %d\n", X);
    }

}

static void pirata_muda_staminia(struct monstros *pirata, int A){

    if(A == 0){
        pirata->staminia = pirata->staminia - 2;
    }
    if(A == 1){
        pirata->staminia = pirata->staminia - 2;
    }
    if(A == 2){
        pirata->staminia = pirata->staminia - 2;
    }
    if(A == 3){
        pirata->staminia = pirata->staminia - 6;
    }

}

static int pirata_verifica_staminia(struct monstros *pirata, int A){

    if(A == 10){
        return 6;
    }

    if(A == 0){
        return 2;
    }
    if(A == 1){
        return 2;
    }
    if(A == 2){
        return 2;
    }
    if(A == 3){
        return 6;
    }

}

Monstro *new_pirata(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *pirata = (Monstro *) malloc(sizeof(Monstro));

    pirata->nome = nome;
    pirata->lvl = lvl;
    pirata->HP = HP;
    pirata->forca = forca;
    pirata->armadura = armadura;
    pirata->inteligencia = inteligencia;
    pirata->agilidade = agilidade;
    pirata->staminia = 10;

    pirata->nome_monstro = pirata_nome_monstro;
    pirata->ataque_fraco = pirata_ataque_fraco;
    pirata->ataque_forte = pirata_ataque_forte;
    pirata->monstro_magia1 = pirata_magia1;
    pirata->monstro_magia2 = pirata_magia2;
    pirata->monstro_descanso = pirata_descanso;
    pirata->monstro_menu = pirata_menu;
    pirata->monstro_muda_staminia = pirata_muda_staminia;
    pirata->monstro_verifica_staminia = pirata_verifica_staminia;

    return pirata;

}
