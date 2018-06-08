#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "Monstros.h"
#include "Personagem.h"



void decisao_player(struct personagem *aventureiro, struct monstros *monstro){

        int escolha;
        int Dano_aventureiro, resistencia_armadura;
        int flag = 0;

        while(flag == 0){
            flag = 1;
            aventureiro->aventureiro_menu(aventureiro);

            scanf("%d", &escolha);
            printf("\n");

            while(escolha > 5 || escolha < 1){

                printf("Nao existe esta opcao!!!\n");
                printf("Escolha uma opcao valida\n");
                aventureiro->aventureiro_menu(aventureiro);
                scanf("%d", &escolha);
                printf("\n");

            }

            if(escolha == 5){
                aventureiro->descansar(aventureiro);
            }

            if(escolha != 5){

                Dano_aventureiro = escolha_ataque(escolha, aventureiro);

                if(Dano_aventureiro >= 0){

                    resistencia_armadura = (monstro->armadura * 50) / 100;
                    Dano_aventureiro = Dano_aventureiro - resistencia_armadura;
                    monstro->HP = monstro->HP - Dano_aventureiro;
                    printf("%s: Sofreu %d de dano\n", monstro->nome, Dano_aventureiro);


                }else{
                    flag = 0;
                }

            }
        }

        verifica_death(aventureiro, monstro);

}
