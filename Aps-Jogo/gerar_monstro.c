#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Monstros.h"
#include "Personagem.h"

Monstro *gerar_monstro(struct personagem *aventureiro){

    int X;
    X = rand() % 10;
    Monstro *meus_monstros;

    if(X == 0){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 1){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 2){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 3){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 4){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 5){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 6){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 7){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 8){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 9){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 10){
        meus_monstros = gerar_ogro(aventureiro);
    }


    return meus_monstros;

}
