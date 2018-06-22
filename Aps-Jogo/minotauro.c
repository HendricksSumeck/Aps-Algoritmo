#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void minotauro_nome_monstro(struct monstros *minotauro){

    printf("                              %s\n", minotauro->nome);
    printf("                              LVL = %d\n", minotauro->lvl);
    printf("                              HP = %d\n", minotauro->HP);
    printf("                              Forca = %d\n", minotauro->forca);
    printf("                              Armadura = %d\n", minotauro->armadura);
    printf("                              Inteligencia = %d\n", minotauro->inteligencia);
    printf("                              Agilidade = %d\n", minotauro->agilidade);
    printf("\n");

}

static int minotauro_ataque_fraco(struct monstros *minotauro){

    int X;

    if(minotauro->staminia < 3){

        return -1;

    }

    if(minotauro->staminia >= 3){

        X = rand() % minotauro->forca + minotauro->agilidade;

        return X;

    }

}

static int minotauro_ataque_forte(struct monstros *minotauro){

    int X, Y, Z;

    if(minotauro->staminia < 4){

        return -1;

    }

    if(minotauro->staminia >= 4){

        X = rand() % 4 + minotauro->lvl;
        Y = rand() % 4 + minotauro->lvl;
        Z = rand() % 4 + minotauro->lvl;

        X = X + Y + Z;

        return X;

    }

}

static int minotauro_magia1(struct monstros *minotauro){

    int X;

    if(minotauro->staminia < 3){

        return -1;

    }

    if(minotauro->staminia >= 3){

        X = 2 + rand() % minotauro->forca ;

        return X;

    }

}

static int minotauro_magia2(struct monstros *minotauro){

    int X;

    if(minotauro->staminia < 4){

        return -1;

    }

    if(minotauro->staminia >= 4){

        X = minotauro->lvl + rand() % minotauro->forca;

        return X;

    }

}

static void minotauro_descanso(struct monstros *minotauro){

    if(minotauro->staminia == 10){
        printf("                              Impossivel descansar\n");
    }
    if(minotauro->staminia == 9){
        minotauro->staminia++;
        printf("                              minotauro descansou\n");
    }
    if(minotauro->staminia < 9){
        minotauro->staminia = minotauro->staminia + 1;
        printf("                              minotauro descansou\n", minotauro->staminia);
    }

}

static void minotauro_menu(int A, int X){

    if(A == 0){
        printf("                              Investida Sangrenta = %d\n", X);
    }
    if(A == 1){
        printf("                              Pancada Tripla = %d\n", X);
    }
    if(A == 2){
        printf("                              Arremesso Sísmico = %d\n", X);
    }
    if(A == 3){
        printf("                              Guilhotina = %d\n", X);
    }

}

static void minotauro_muda_staminia(struct monstros *minotauro, int A){

    if(A == 0){
        minotauro->staminia = minotauro->staminia - 3;
    }
    if(A == 1){
        minotauro->staminia = minotauro->staminia - 4;
    }
    if(A == 2){
        minotauro->staminia = minotauro->staminia - 3;
    }
    if(A == 3){
        minotauro->staminia = minotauro->staminia - 4;
    }

}

static int minotauro_verifica_staminia(struct monstros *minotauro, int A){

    if(A == 10){
        return 4;
    }

    if(A == 0){
        return 3;
    }
    if(A == 1){
        return 4;
    }
    if(A == 2){
        return 3;
    }
    if(A == 3){
        return 4;
    }

}

Monstro *new_minotauro(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *minotauro = (Monstro *) malloc(sizeof(Monstro));

    minotauro->nome = nome;
    minotauro->lvl = lvl;
    minotauro->HP = HP;
    minotauro->forca = forca;
    minotauro->armadura = armadura;
    minotauro->inteligencia = inteligencia;
    minotauro->agilidade = agilidade;
    minotauro->staminia = 10;

    minotauro->nome_monstro = minotauro_nome_monstro;
    minotauro->ataque_fraco = minotauro_ataque_fraco;
    minotauro->ataque_forte = minotauro_ataque_forte;
    minotauro->monstro_magia1 = minotauro_magia1;
    minotauro->monstro_magia2 = minotauro_magia2;
    minotauro->monstro_descanso = minotauro_descanso;
    minotauro->monstro_menu = minotauro_menu;
    minotauro->monstro_muda_staminia = minotauro_muda_staminia;
    minotauro->monstro_verifica_staminia = minotauro_verifica_staminia;

    return minotauro;

}
