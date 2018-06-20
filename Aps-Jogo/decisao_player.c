#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "Monstros.h"
#include "Personagem.h"



void decisao_player(struct personagem *aventureiro, struct monstros *monstro){

        char escolha;
        int Dano_aventureiro, resistencia_armadura;
        int flag = 0, B;

        while(flag == 0){
            flag = 1;
            aventureiro->aventureiro_menu(aventureiro);

            //scanf("%d", &escolha);
            printf("Digite sua escolha: ");
            escolha = getch();
            printf("\n");

            while(escolha <  49 || escolha > 53){

                printf("Digite um valor valido");
                escolha = getch();
                printf("\n");
            }

            if(escolha == '5'){
                aventureiro->descansar(aventureiro);
            }

            if(escolha != '5'){

                Dano_aventureiro = escolha_ataque(escolha, aventureiro);
                B = 10 + rand() % (50 - 10 + 1);

                if(Dano_aventureiro >= 0){

                    resistencia_armadura = (monstro->armadura * B) / 100;
                    Dano_aventureiro = Dano_aventureiro - resistencia_armadura;
                    printf("%s: Defendeu %d de dano\n", monstro->nome, resistencia_armadura);
                    if(Dano_aventureiro <= 0){
                        printf("%s: nao sofreu dano\n", monstro->nome);
                    }else{
                        monstro->HP = monstro->HP - Dano_aventureiro;
                        printf("%s: Sofreu %d de dano\n", monstro->nome, Dano_aventureiro);
                    }

                }else{
                    flag = 0;
                }

            }
        }

}
