#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void gigante_nome_monstro(struct monstros *gigante){

    printf("%s\n", gigante->nome);
    printf("LVL = %d\n", gigante->lvl);
    printf("HP = %d\n", gigante->HP);
    printf("Forca = %d\n", gigante->forca);
    printf("Armadura = %d\n", gigante->armadura);
    printf("Inteligencia = %d\n", gigante->inteligencia);
    printf("Agilidade = %d\n", gigante->agilidade);
    printf("\n");

}

static int gigante_ataque_fraco(struct monstros *gigante){

    int X;

    if(gigante->staminia < 1){

        return -1;

    }

    if(gigante->staminia >= 1){

        X = rand() % gigante->forca;

        return X;

    }

}

static int gigante_ataque_forte(struct monstros *gigante){

    int X;

    if(gigante->staminia < 2){

        return -1;

    }

    if(gigante->staminia >= 2){

        X = rand() % gigante->forca;

        return X;

    }

}

static int gigante_magia1(struct monstros *gigante){

    int X;

    if(gigante->staminia < 3){

        return -1;

    }

    if(gigante->staminia >= 3){

        X = rand() % gigante->forca;

        return X;

    }

}

static int gigante_magia2(struct monstros *gigante){

    int X;

    if(gigante->staminia < 4){

        return -1;

    }

    if(gigante->staminia >= 4){

        X = rand() % gigante->forca;

        return X;

    }

}

static int gigante_passiva(struct monstros *gigante){



}

static void gigante_descanso(struct monstros *gigante){

    if(gigante->staminia == 10){
        printf("Impossivel descansar\n");
    }
    if(gigante->staminia == 9){
        gigante->staminia++;
        printf("gigante descansou\n");
    }
    if(gigante->staminia < 9){
        gigante->staminia = gigante->staminia + 1;
        printf("gigante descansou\n", gigante->staminia);
    }

}

static void gigante_menu(int A, int X){

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

static void gigante_muda_staminia(struct monstros *gigante, int A){

    if(A == 0){
        gigante->staminia = gigante->staminia - 1;
    }
    if(A == 1){
        gigante->staminia = gigante->staminia - 2;
    }
    if(A == 2){
        gigante->staminia = gigante->staminia - 3;
    }
    if(A == 3){
        gigante->staminia = gigante->staminia - 4;
    }

}

static int gigante_verifica_staminia(struct monstros *gigante, int A){

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

Monstro *new_gigante(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *gigante = (Monstro *) malloc(sizeof(Monstro));

    gigante->nome = nome;
    gigante->lvl = lvl;
    gigante->HP = HP;
    gigante->forca = forca;
    gigante->armadura = armadura;
    gigante->inteligencia = inteligencia;
    gigante->agilidade = agilidade;
    gigante->staminia = 10;

    gigante->nome_monstro = gigante_nome_monstro;
    gigante->ataque_fraco = gigante_ataque_fraco;
    gigante->ataque_forte = gigante_ataque_forte;
    gigante->monstro_magia1 = gigante_magia1;
    gigante->monstro_magia2 = gigante_magia2;
    gigante->monstro_passiva = gigante_passiva;
    gigante->monstro_descanso = gigante_descanso;
    gigante->monstro_menu = gigante_menu;
    gigante->monstro_muda_staminia = gigante_muda_staminia;
    gigante->monstro_verifica_staminia = gigante_verifica_staminia;

    return gigante;

}
