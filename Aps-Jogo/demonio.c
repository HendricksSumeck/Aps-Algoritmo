#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void demonio_nome_monstro(struct monstros *demonio){

    printf("%s\n", demonio->nome);
    printf("LVL = %d\n", demonio->lvl);
    printf("HP = %d\n", demonio->HP);
    printf("Forca = %d\n", demonio->forca);
    printf("Armadura = %d\n", demonio->armadura);
    printf("Inteligencia = %d\n", demonio->inteligencia);
    printf("Agilidade = %d\n", demonio->agilidade);
    printf("\n");

}

static int demonio_ataque_fraco(struct monstros *demonio){

    int X;

    if(demonio->staminia < 4){

        return -1;

    }

    if(demonio->staminia >= 4){

        X = rand() % demonio->forca + demonio->inteligencia;

        return X;

    }

}

static int demonio_ataque_forte(struct monstros *demonio){

    int X;

    if(demonio->staminia < 4){

        return -1;

    }

    if(demonio->staminia >= 4){

        X = demonio->forca;

        return X;

    }

}

static int demonio_magia1(struct monstros *demonio){

    int X;

    if(demonio->staminia < 4){

        return -1;

    }

    if(demonio->staminia >= 4){

        X = demonio->inteligencia;

        return X;

    }

}

static int demonio_magia2(struct monstros *demonio){

    int X;

    if(demonio->staminia < 6){

        return -1;

    }

    if(demonio->staminia >= 6){

        X = (demonio->forca + demonio->agilidade + demonio->inteligencia) / 3;
        demonio->HP = demonio->HP + (X/2);

        return X;

    }

}

static void demonio_descanso(struct monstros *demonio){

    if(demonio->staminia == 10){
        printf("Impossivel descansar\n");
    }
    if(demonio->staminia == 9){
        demonio->staminia++;
        printf("demonio descansou\n");
    }
    if(demonio->staminia < 9){
        demonio->staminia = demonio->staminia + 1;
        printf("demonio descansou\n", demonio->staminia);
    }

}

static void demonio_menu(int A, int X){

    if(A == 0){
        printf("Hellblaze = %d\n", X);
    }
    if(A == 1){
        printf("Chicote Flamejante = %d\n", X);
    }
    if(A == 2){
        printf("Corromper Alma = %d\n", X);
    }
    if(A == 3){
        printf("Ceifar vida = %d\n", X);
        printf("Você teve %d de sua vida roubada\n", X);
    }

}

static void demonio_muda_staminia(struct monstros *demonio, int A){

    if(A == 0){
        demonio->staminia = demonio->staminia - 4;
    }
    if(A == 1){
        demonio->staminia = demonio->staminia - 4;
    }
    if(A == 2){
        demonio->staminia = demonio->staminia - 4;
    }
    if(A == 3){
        demonio->staminia = demonio->staminia - 6;
    }

}

static int demonio_verifica_staminia(struct monstros *demonio, int A){

    if(A == 10){
        return 6;
    }

    if(A == 0){
        return 4;
    }
    if(A == 1){
        return 4;
    }
    if(A == 2){
        return 4;
    }
    if(A == 3){
        return 6;
    }

}

Monstro *new_demonio(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *demonio = (Monstro *) malloc(sizeof(Monstro));

    demonio->nome = nome;
    demonio->lvl = lvl;
    demonio->HP = HP;
    demonio->forca = forca;
    demonio->armadura = armadura;
    demonio->inteligencia = inteligencia;
    demonio->agilidade = agilidade;
    demonio->staminia = 10;

    demonio->nome_monstro = demonio_nome_monstro;
    demonio->ataque_fraco = demonio_ataque_fraco;
    demonio->ataque_forte = demonio_ataque_forte;
    demonio->monstro_magia1 = demonio_magia1;
    demonio->monstro_magia2 = demonio_magia2;
    demonio->monstro_descanso = demonio_descanso;
    demonio->monstro_menu = demonio_menu;
    demonio->monstro_muda_staminia = demonio_muda_staminia;
    demonio->monstro_verifica_staminia = demonio_verifica_staminia;

    return demonio;

}
