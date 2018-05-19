#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "Monstros.h"
#include "Personagem.h"



void decisao_player(struct personagem *aventureiro, struct monstros *monstro){

        int escolha;
        int Dano_aventureiro;
        int flag = 0;

        while(flag == 0){
            flag = 1;
            aventureiro->aventureiro_menu(aventureiro);

            scanf("%d", &escolha);
            printf("\n");

            if(escolha == 5){
                aventureiro->descansar(aventureiro);
            }

            if(escolha != 5){
                Dano_aventureiro = escolha_ataque(escolha, aventureiro);
                if(Dano_aventureiro >= 0){

                    monstro->HP = monstro->HP - Dano_aventureiro;
                    printf("%s: Sofreu %d de dano\n", monstro->nome, Dano_aventureiro);

                }else flag = 0;

            }
        }

        verifica_death(aventureiro, monstro);

}
