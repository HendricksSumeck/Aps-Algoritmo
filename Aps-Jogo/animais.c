#include <stdio.h>
#include <stdlib.h>
#include "Monstros.h"

static void animal_nome_monstro(struct monstros *animal){

    printf("%s\n", animal->nome);
    printf("LVL = %d\n", animal->lvl);
    printf("HP = %d\n", animal->HP);
    printf("Forca = %d\n", animal->forca);
    printf("Armadura = %d\n", animal->armadura);
    printf("Inteligencia = %d\n", animal->inteligencia);
    printf("Agilidade = %d\n", animal->agilidade);
    printf("\n");

}

static int animal_ataque_fraco(struct monstros *animal){

    int X;

    if(animal->staminia < 1){

        return -1;

    }

    if(animal->staminia >= 1){

        X = rand() % animal->forca;

        return X;

    }

}

static int animal_ataque_forte(struct monstros *animal){

    int X;

    if(animal->staminia < 2){

        return -1;

    }

    if(animal->staminia >= 2){

        X = rand() % animal->forca;

        return X;

    }

}

static int animal_magia1(struct monstros *animal){

    int X;

    if(animal->staminia < 3){

        return -1;

    }

    if(animal->staminia >= 3){

        X = rand() % animal->forca;

        return X;

    }

}

static int animal_magia2(struct monstros *animal){

    int X;

    if(animal->staminia < 4){

        return -1;

    }

    if(animal->staminia >= 4){

        X = rand() % animal->forca;

        return X;

    }

}

static void animal_descanso(struct monstros *animal){

    if(animal->staminia == 10){
        printf("Impossivel descansar\n");
    }
    if(animal->staminia == 9){
        animal->staminia++;
        printf("animal descansou\n");
    }
    if(animal->staminia < 9){
        animal->staminia = animal->staminia + 1;
        printf("animal descansou\n", animal->staminia);
    }

}

static void animal_menu(int A, int X){

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

static void animal_muda_staminia(struct monstros *animal, int A){

    if(A == 0){
        animal->staminia = animal->staminia - 1;
    }
    if(A == 1){
        animal->staminia = animal->staminia - 2;
    }
    if(A == 2){
        animal->staminia = animal->staminia - 3;
    }
    if(A == 3){
        animal->staminia = animal->staminia - 4;
    }

}

static int animal_verifica_staminia(struct monstros *animal, int A){

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

Monstro *new_animal(char *nome, int lvl, int HP, int forca, int armadura, int inteligencia, int agilidade){

    Monstro *animal = (Monstro *) malloc(sizeof(Monstro));

    animal->nome = nome;
    animal->lvl = lvl;
    animal->HP = HP;
    animal->forca = forca;
    animal->armadura = armadura;
    animal->inteligencia = inteligencia;
    animal->agilidade = agilidade;
    animal->staminia = 10;

    animal->nome_monstro = animal_nome_monstro;
    animal->ataque_fraco = animal_ataque_fraco;
    animal->ataque_forte = animal_ataque_forte;
    animal->monstro_magia1 = animal_magia1;
    animal->monstro_magia2 = animal_magia2;
    animal->monstro_descanso = animal_descanso;
    animal->monstro_menu = animal_menu;
    animal->monstro_muda_staminia = animal_muda_staminia;
    animal->monstro_verifica_staminia = animal_verifica_staminia;

    return animal;

}
