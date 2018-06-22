#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "Monstros.h"
#include "Personagem.h"

int escolha_ataque(char A, struct personagem *aventureiro){

        int X;

        if(A == '1'){
           X = aventureiro->ataque_fraco(aventureiro);
        }

        if(A == '2'){
           X = aventureiro->ataque_forte(aventureiro);
        }

        if(A == '3'){
          X = aventureiro->aventureiro_magia1(aventureiro);
        }

        if(A == '4'){
          X = aventureiro->aventureiro_magia2(aventureiro);
        }

        return X;

}

void verifica_death(struct personagem *aventureiro, struct monstros *monstro){

    if(aventureiro->HP <= 0){

        died();
        exit(0);

    }

    if(monstro->HP <= 0){

        printf("\n                              %s foi derrotado\n\n", monstro->nome);

    }

}

void *ataque1_monstro(struct personagem *aventureiro, struct monstros *monstro){
    int i = 1, X = 0;
    int Dano_aventureiro, Dano_monstro;
    while(aventureiro->HP > 0 && monstro->HP > 0){
        printf("                              Turno: %d\n\n", i);
        printf("                              Vida %s = %d \t Stamina = %d\n", aventureiro->nome, aventureiro->HP, aventureiro->staminia);
        printf("                              Vida %s = %d \t Stamina = %d\n\n", monstro->nome, monstro->HP, monstro->staminia);
        X = aventureiro->aventureiro_passiva(aventureiro, monstro);
        if(aventureiro->HP > 0 && monstro->HP > 0){
            decisao_monstro(aventureiro, monstro);//Monstro
            verifica_death(aventureiro, monstro);
            if(X==0){
                decisao_player(aventureiro, monstro);
            }
        }
        verifica_death(aventureiro, monstro);
        limpa_tela();
        i++;
        }
}

void *ataque1_plyaer(struct personagem *aventureiro, struct monstros *monstro){
    int i = 1, X = 0;
    char A;
    while(aventureiro->HP > 0 && monstro->HP > 0){
        printf("                              Turno: %d\n\n", i);
        printf("                              Vida %s = %d \t Stamina = %d\n", aventureiro->nome, aventureiro->HP, aventureiro->staminia);
        printf("                               Vida %s = %d \t Stamina = %d\n\n", monstro->nome, monstro->HP, monstro->staminia);
        X = aventureiro->aventureiro_passiva(aventureiro, monstro);
        if(aventureiro->HP > 0 && monstro->HP > 0){
            if(X==0){
                decisao_player(aventureiro, monstro);
            }
            decisao_monstro(aventureiro, monstro);//Monstro
        }
        verifica_death(aventureiro, monstro);
        limpa_tela();
        i++;
        }
}

void limpa_tela(void){
    char A;
    printf("   Press enter...\n");
    A = getch();
    if(A == 13){
        system("cls");
    }
    while(A != 13){
        printf("   Press enter...\n");
        A = getch();
        if(A == 13){
        system("cls");
        }
    }
}


void iniciar_batalha(struct personagem *aventureiro, struct monstros *monstro){

    if(monstro->agilidade > aventureiro->agilidade){

        ataque1_monstro(aventureiro, monstro);

    }

    if(aventureiro->agilidade > monstro->agilidade){

        ataque1_plyaer(aventureiro, monstro);

    }

    aventureiro->aventureiro_passiva(aventureiro, monstro);

    if(monstro->HP <= 0){
        aventureiro->subir_lvl(aventureiro);
    }

    //Ponteiro de struck ->
    //Só ponteiro *

}

void torre_negra(struct personagem *aventureiro){

    static int i;
    i = 0;
    Monstro *meus_monstros[11];

    meus_monstros[i] = gerar_monstro(aventureiro);
    iniciar_batalha(aventureiro, meus_monstros[i]);//Função

    i++;

}
