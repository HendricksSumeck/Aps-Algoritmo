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

        printf("\n%s foi derrotado\n\n", aventureiro->nome);

    }

    if(monstro->HP <= 0){

        printf("\n%s foi derrotado\n\n", monstro->nome);

    }

}

int verifica_passiva(struct personagem *aventureiro, struct monstros *monstro){

    aventureiro->aventureiro_passiva(aventureiro, monstro);


}

void *ataque1_monstro(struct personagem *aventureiro, struct monstros *monstro){
    int i = 1, escolha;
    int Dano_aventureiro, Dano_monstro;
    int X;
    while(aventureiro->HP > 0 && monstro->HP > 0){
        printf("Turno: %d\n\n", i);
        printf("Vida %s = %d \t Stamina = %d\n", aventureiro->nome, aventureiro->HP, aventureiro->staminia);
        printf("Vida %s = %d \t Stamina = %d\n\n", monstro->nome, monstro->HP, monstro->staminia);
        verifica_passiva(aventureiro, monstro);
        decisao_monstro(aventureiro, monstro);//Monstro
        decisao_player(aventureiro, monstro);
        limpa_tela();
        i++;
        }
}

void *ataque1_plyaer(struct personagem *aventureiro, struct monstros *monstro){
    int i = 1;
    char A;
    while(aventureiro->HP > 0 && monstro->HP > 0){
        printf("Turno: %d\n\n", i);
        printf("Vida %s = %d \t Stamina = %d\n", aventureiro->nome, aventureiro->HP, aventureiro->staminia);
        printf("Vida %s = %d \t Stamina = %d\n\n", monstro->nome, monstro->HP, monstro->staminia);
        verifica_passiva(aventureiro, monstro);
        decisao_player(aventureiro, monstro);
        decisao_monstro(aventureiro, monstro);//Monstro
        limpa_tela();
        i++;
        }
}

void limpa_tela(void){
    char A;
    printf("Precione enter para continuar\n");
    A = getch();
    if(A == 13){
        system("cls");
    }
    while(A != 13){
        printf("Precione enter para continuar!!!\n");
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

    verifica_passiva(aventureiro, monstro);

    if(monstro->HP <= 0){
        aventureiro->subir_lvl(aventureiro);
    }

    //Ponteiro de struck ->
    //Só ponteiro *

}
