#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void djinn_nome_monstro(struct monstros *djinn){

    printf("                              %s\n", djinn->nome);
    printf("                              LVL = %d\n", djinn->lvl);
    printf("                              HP = %d\n", djinn->HP);
    printf("                              Forca = %d\n", djinn->forca);
    printf("                              Armadura = %d\n", djinn->armadura);
    printf("                              Inteligencia = %d\n", djinn->inteligencia);
    printf("                              Agilidade = %d\n", djinn->agilidade);
    printf("\n");

}

static int djinn_ataque_fraco(struct monstros *djinn){

    int X;

    if(djinn->staminia < 4){

        return -1;

    }

    if(djinn->staminia >= 4){

        X = rand() % djinn->inteligencia;

        return X;

    }

}

static int djinn_ataque_forte(struct monstros *djinn){

    int X;

    if(djinn->staminia < 4){

        return -1;

    }

    if(djinn->staminia >= 4){

        X = 1 + rand() % djinn->inteligencia;

        return X;

    }

}

static int djinn_magia1(struct monstros *djinn){

    int X;

    if(djinn->staminia < 5){

        return -1;

    }

    if(djinn->staminia >= 5){

        X = 2 + rand() % djinn->inteligencia;

        return X;

    }

}

static int djinn_magia2(struct monstros *djinn){

    int X;

    if(djinn->staminia < 6){

        return -1;

    }

    if(djinn->staminia >= 6){

        X = djinn->inteligencia / 2;

        return X;

    }

}

static void djinn_descanso(struct monstros *djinn){

    if(djinn->staminia == 10){
        printf("                              Impossivel descansar\n");
    }
    if(djinn->staminia == 9){
        djinn->staminia++;
        printf("                              djinn descansou\n");
    }
    if(djinn->staminia < 9){
        djinn->staminia = djinn->staminia + 1;
        printf("                              djinn descansou\n", djinn->staminia);
    }

}

static void djinn_menu(int A, int X){

    if(A == 0){
        printf("                              Choque Psíquico = %d\n", X);
    }
    if(A == 1){
        printf("                              Raio Psíquico = %d\n", X);
    }
    if(A == 2){
        printf("                              Poder Cósmico = %d\n", X);
    }
    if(A == 3){
        printf("                              Comedor de Sonhos = %d\n", X);
    }

}

static void djinn_muda_staminia(struct monstros *djinn, int A){

    if(A == 0){
        djinn->staminia = djinn->staminia - 4;
    }
    if(A == 1){
        djinn->staminia = djinn->staminia - 4;
    }
    if(A == 2){
        djinn->staminia = djinn->staminia - 5;
    }
    if(A == 3){
        djinn->staminia = djinn->staminia - 6;
    }

}

static int djinn_verifica_staminia(struct monstros *djinn, int A){

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
        return 5;
    }
    if(A == 3){
        return 6;
    }

}

Monstro *new_djinn(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *djinn = (Monstro *) malloc(sizeof(Monstro));

    djinn->nome = nome;
    djinn->lvl = lvl;
    djinn->HP = HP;
    djinn->forca = forca;
    djinn->armadura = armadura;
    djinn->inteligencia = inteligencia;
    djinn->agilidade = agilidade;
    djinn->staminia = 10;

    djinn->nome_monstro = djinn_nome_monstro;
    djinn->ataque_fraco = djinn_ataque_fraco;
    djinn->ataque_forte = djinn_ataque_forte;
    djinn->monstro_magia1 = djinn_magia1;
    djinn->monstro_magia2 = djinn_magia2;
    djinn->monstro_descanso = djinn_descanso;
    djinn->monstro_menu = djinn_menu;
    djinn->monstro_muda_staminia = djinn_muda_staminia;
    djinn->monstro_verifica_staminia = djinn_verifica_staminia;

    return djinn;

}
