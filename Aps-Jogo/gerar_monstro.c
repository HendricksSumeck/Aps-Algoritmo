#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Monstros.h"
#include "Personagem.h"

Monstro *gerar_monstro(struct personagem *aventureiro){

    int X;
    X = rand() % 11;

    Monstro *meus_monstros;

    if(X == 0){
        meus_monstros = gerar_ogro(aventureiro);
    }
    if(X == 1){
        meus_monstros = gerar_troll(aventureiro);
    }
    if(X == 2){
        meus_monstros = gerar_orc(aventureiro);
    }
    if(X == 3){
        meus_monstros = gerar_animais(aventureiro);
    }
    if(X == 4){
        meus_monstros = gerar_pirata(aventureiro);
    }
    if(X == 5){
        meus_monstros = gerar_djinn(aventureiro);
    }
    if(X == 6){
        meus_monstros = gerar_gigante(aventureiro);
    }
    if(X == 7){
        meus_monstros = gerar_goblin(aventureiro);
    }
    if(X == 8){
        meus_monstros = gerar_minotauro(aventureiro);
    }
    if(X == 9){
        meus_monstros = gerar_dragao(aventureiro);
    }
    if(X == 10){
        meus_monstros = gerar_demonio(aventureiro);
    }


    return meus_monstros;

}

Monstro *ver_monstros(struct personagem *aventureiro){

    int X;

    Monstro *meus_monstros[11];

    for(X=0; X<11; X++){
    if(X == 0){
        meus_monstros[0] = gerar_animais(aventureiro);
        meus_monstros[0]->nome_monstro(meus_monstros[0]);
    }
    if(X == 1){
        meus_monstros[1] = gerar_demonio(aventureiro);
        meus_monstros[1]->nome_monstro(meus_monstros[1]);
    }
    if(X == 2){
        meus_monstros[2] = gerar_djinn(aventureiro);
        meus_monstros[2]->nome_monstro(meus_monstros[2]);
    }
    if(X == 3){
        meus_monstros[3] = gerar_dragao(aventureiro);
        meus_monstros[3]->nome_monstro(meus_monstros[3]);
    }
    if(X == 4){
        meus_monstros[4] = gerar_gigante(aventureiro);
        meus_monstros[4]->nome_monstro(meus_monstros[4]);
    }
    if(X == 5){
        meus_monstros[5] = gerar_goblin(aventureiro);
        meus_monstros[5]->nome_monstro(meus_monstros[5]);
    }
    if(X == 6){
        meus_monstros[6] = gerar_minotauro(aventureiro);
        meus_monstros[6]->nome_monstro(meus_monstros[6]);
    }
    if(X == 7){
        meus_monstros[7] = gerar_ogro(aventureiro);
        meus_monstros[7]->nome_monstro(meus_monstros[7]);
    }
    if(X == 8){
        meus_monstros[8] = gerar_orc(aventureiro);
        meus_monstros[8]->nome_monstro(meus_monstros[8]);
    }
    if(X == 9){
        meus_monstros[9] = gerar_pirata(aventureiro);
        meus_monstros[9]->nome_monstro(meus_monstros[9]);
    }
    if(X == 10){
        meus_monstros[10] = gerar_troll(aventureiro);
        meus_monstros[9]->nome_monstro(meus_monstros[10]);
    }
    }


}
