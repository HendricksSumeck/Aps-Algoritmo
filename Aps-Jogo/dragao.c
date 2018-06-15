#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void dragao_nome_monstro(struct monstros *dragao){

    printf("%s\n", dragao->nome);
    printf("LVL = %d\n", dragao->lvl);
    printf("HP = %d\n", dragao->HP);
    printf("Forca = %d\n", dragao->forca);
    printf("Armadura = %d\n", dragao->armadura);
    printf("Inteligencia = %d\n", dragao->inteligencia);
    printf("Agilidade = %d\n", dragao->agilidade);
    printf("\n");

}

static int dragao_ataque_fraco(struct monstros *dragao){

    int X;

    if(dragao->staminia < 1){

        return -1;

    }

    if(dragao->staminia >= 1){

        X = rand() % dragao->forca;

        return X;

    }

}

static int dragao_ataque_forte(struct monstros *dragao){

    int X;

    if(dragao->staminia < 2){

        return -1;

    }

    if(dragao->staminia >= 2){

        X = rand() % dragao->forca;

        return X;

    }

}

static int dragao_magia1(struct monstros *dragao){

    int X;

    if(dragao->staminia < 3){

        return -1;

    }

    if(dragao->staminia >= 3){

        X = rand() % dragao->forca;

        return X;

    }

}

static int dragao_magia2(struct monstros *dragao){

    int X;

    if(dragao->staminia < 4){

        return -1;

    }

    if(dragao->staminia >= 4){

        X = rand() % dragao->forca;

        return X;

    }

}

static void dragao_descanso(struct monstros *dragao){

    if(dragao->staminia == 10){
        printf("Impossivel descansar\n");
    }
    if(dragao->staminia == 9){
        dragao->staminia++;
        printf("dragao descansou\n");
    }
    if(dragao->staminia < 9){
        dragao->staminia = dragao->staminia + 1;
        printf("dragao descansou\n", dragao->staminia);
    }

}

static void dragao_menu(int A, int X){

    if(A == 0){
        printf("Soco = %d\n", X);
    }
    if(A == 1){
        printf("Arranhao = %d\n", X);
    }
    if(A == 2){
        printf("Tapa na orelha = %d\n", X);
    }
    if(A == 3){
        printf("Jogar pedra = %d\n", X);
    }

}

static void dragao_muda_staminia(struct monstros *dragao, int A){

    if(A == 0){
        dragao->staminia = dragao->staminia - 1;
    }
    if(A == 1){
        dragao->staminia = dragao->staminia - 2;
    }
    if(A == 2){
        dragao->staminia = dragao->staminia - 3;
    }
    if(A == 3){
        dragao->staminia = dragao->staminia - 4;
    }

}

static int dragao_verifica_staminia(struct monstros *dragao, int A){

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

Monstro *new_dragao(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *dragao = (Monstro *) malloc(sizeof(Monstro));

    dragao->nome = nome;
    dragao->lvl = lvl;
    dragao->HP = HP;
    dragao->forca = forca;
    dragao->armadura = armadura;
    dragao->inteligencia = inteligencia;
    dragao->agilidade = agilidade;
    dragao->staminia = 10;

    dragao->nome_monstro = dragao_nome_monstro;
    dragao->ataque_fraco = dragao_ataque_fraco;
    dragao->ataque_forte = dragao_ataque_forte;
    dragao->monstro_magia1 = dragao_magia1;
    dragao->monstro_magia2 = dragao_magia2;
    dragao->monstro_descanso = dragao_descanso;
    dragao->monstro_menu = dragao_menu;
    dragao->monstro_muda_staminia = dragao_muda_staminia;
    dragao->monstro_verifica_staminia = dragao_verifica_staminia;

    return dragao;

}
